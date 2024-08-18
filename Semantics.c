#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Helper.h"


//!!! part 3 starts here:


#ifndef HAVE_ASPRINTF
int asprintf(char **strp, const char *fmt, ...);
#endif

//* # # # # # # # # # # # # # Declerations # # # # # # # # # # # # # *//

// Define a node in the stack
typedef struct StackNode {
    char *data;
    struct StackNode *next;
} StackNode;

// Define the stack structure
typedef struct {
    StackNode *top;
} Stack;

// Define functions
Stack* initStack();
void push(Stack* s, const char* str);
char* pop(Stack* s);
char* peek(Stack* s);
int isEmpty(Stack* s);
int getStackSize(Stack* s);
void freeStack(Stack* s);
void printStack(Stack* s);

FILE* openFile();
void closeFile();
void cleanAndCloseFile();
long addLineToFile(const char *line);
void replaceNInFile(long posN, long posEnd);

void assignVars(Stack* stack, node* Node);
char* getNextVar();
char* getNextLabel();
char* checkLabel(Stack* stack);
void generateCode(node* Node); // Called from YACC

// Define variables
FILE* file;
const char* filename = "output";
static int t = 0; // Number of temporary variable
static int l = 1; // Number of label
static int funcSize = 0; // Variable for counting the size of a function

//* # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # *//



//* # # # # # # # # # # # # # Stack Functions # # # # # # # # # # # # # *//

// Function to initialize the stack
Stack* initStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

// Function to push a string onto the stack
void push(Stack *s, const char *str) {
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    newNode->data = strdup(str); // Copy the string into the new node
    newNode->next = s->top;
    s->top = newNode;
    //printf("Pushed \"%s\"\n", str);
}

// Function to pop a string from the stack
char* pop(Stack *s) {
    if (s->top == NULL) {
        //printf("Stack is empty!\n");
        return NULL; // Return NULL to indicate the stack is empty
    }
    StackNode *temp = s->top;
    char *item = temp->data;
    s->top = s->top->next;
    free(temp);
    //printf("Poped \"%s\"\n", item);
    return item;
}

// Function to peek at the top string of the stack
char* peek(Stack *s) {
    if (s->top == NULL) {
        //printf("Stack is empty!\n");
        return NULL; // Return NULL to indicate the stack is empty
    }
    return s->top->data;
}

// Function to check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == NULL;
}

// Function to get the number of elements in the stack
int getStackSize(Stack *s) {
    int size = 0;
    StackNode *current = s->top;
    while (current != NULL) {
        size++;
        current = current->next;
    }
    return size;
}

// Function to display the stack elements
void printStack(Stack *s) {
    if (s->top == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements are:\n");
    StackNode *current = s->top;
    while (current != NULL) {
        printf("\"%s\"\n", current->data);
        current = current->next;
    }
}

// Function to free all allocated memory in the stack
void freeStack(Stack *s) {
    while (s->top != NULL) {
        StackNode *temp = s->top;
        s->top = s->top->next;
        free(temp->data); // Free the string data
        free(temp); // Free the node
    }
}

//* # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # *//


 

//* # # # # # # # # # # # # # File Definition # # # # # # # # # # # # # *//

// Function to open a file for writing
FILE* openFile() {
    file = fopen(filename, "w"); // Open file for writing
    if (file == NULL) {
        perror("Failed to open file");
        return NULL; // Indicate failure
    }
    return file; // Return the file pointer
}

// Function to close the file
void closeFile() {
    if (file != NULL) {
        fclose(file);
    }
}

void cleanAndCloseFile() {
    // Ensure the file pointer is not NULL
    if (file == NULL) {
        return; // or handle the error appropriately
    }

    fseek(file, 0, SEEK_SET); // Go to beginning of the file
    freopen(NULL, "w", file); // Clean the file
    fclose(file);
}

// Function to add a line to the file and get the position of the line in the file
long addLineToFile(const char *line) {
    long position;
    if (file == NULL) {
        fprintf(stderr, "File is not open.\n");
        return -1; // Indicate failure
    }

    position = ftell(file); // Save the current file position
    if (fprintf(file, "%s\n", line) < 0) {
        perror("Failed to write to file");
        return -1; // Indicate failure
    }
    return position; // Return the position where 'N' was written
}

// Function to replace 'N' with the actual function size
void replaceNInFile(long posN, long posEnd) {
    if (file == NULL) {
        fprintf(stderr, "File is not open.\n");
        return;
    }
    
    fseek(file, posN, SEEK_SET); // Move to the saved position of N

    // Replace 'N' with funcSize
    if (fprintf(file, "\t\tBeginFunc %d", funcSize) < 0) { 
        perror("Failed to write to file");
    }

    fseek(file, posEnd, SEEK_SET); // jump to the position of the last line in the file
    funcSize = 0; // reset counter for next functions

    fflush(file); // Ensure the changes are written to the file
}

//* # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # *//

 


//* # # # # # # # # # # # # # # New Label & New Variable # # # # # # # # # # # # # # *//

// Function to generate the next temporary variable name
char* getNextVar() {
    char *tempVar;
    asprintf(&tempVar, "t%d", t++);
    return tempVar; // Return the generated temp var
}

// Function to generate the next label name
char* getNextLabel() {
    char *label;
    asprintf(&label, "L%d", l++);
    return label; // Return the generated label
}

//* # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # *//




//* # # # # # # # # # # # # # # 3AC Generation # # # # # # # # # # # # # # *//

// funcSize is the N in the BeginFunc, here we increment that value given a type
int incrementFunctionSize(char* type) {
    int value = 0;
    if (strcmp(type, "INT") == 0) {
        value += 4;
    }
    else if (strcmp(type, "FLOAT") == 0) {
        value += 8;
    }
    else if (strcmp(type, "DOUBLE") == 0) {
        value += 8;
    }
    else if (strcmp(type, "CHAR") == 0) {
        value += 1;
    }
    else if (strcmp(type, "BOOL") == 0) { 
        value += 4; //? Churkin saied it's 4 bytes
    }
    else if (strcmp(type, "INT*") == 0 || strcmp(type, "FLOAT*") == 0 || strcmp(type, "DOUBLE*") == 0 || strcmp(type, "CHAR*") == 0) {
        value += 4; //? Churkin saied it's 4 bytes
    }
    funcSize += value;
    return value;
}

// Function for checking if we should print a label or not
char* checkLabel(Stack* stack) {
    // Check if the first item in the stack starts with letter 'L', like 'L4', 'L12'
    char* labelVal = peek(stack);
    if ((labelVal != NULL) && (labelVal[0] == 'L')) // check if its indeed a label
        return pop(stack); // Return the acctual lable 
    return NULL; // Return NULL if the top item is not a label
}








//!!! part 2 starts now:



// represents an argument like int num 
typedef struct Argument {
	char* name;
	char* type;
} Argument;

// represents a function like foo(a, b) 
typedef struct Function {
	char* name;
	struct Argument** args;
    int countArgs;
    int isPrivate;
    int isStatic;
	char* returnType;
} Function;

// represents a variable like int count = 0 
typedef struct Variable {
    char* name;
	char* type;
    char* len;
    int flag; //!!! maybe add this?
} Variable;

// represents a node in linked list of scope 
typedef struct LinkedListNode {
    struct Variable* variable;
    struct Function* function;
    struct LinkedListNode* next;
} LinkedListNode;

// represents a scope like for, if etc. 
typedef struct Scope {
    LinkedListNode* list;
    struct Scope* father;
} Scope;


// # # # # # # # # # # function declarations # # # # # # # # # # //


Scope* makeScope(Scope* father);
LinkedListNode* makeVarNode(char* name, char* type, char* len);
LinkedListNode* makeFuncNode(char* name, char* returnType, int isStatic, int isPrivate);

Argument* makeFuncArg(char* name, char* type);
void addArg(Function* func, Argument* newArg);
void addLinkedListNode(Scope* scope, LinkedListNode* listNode);

void findAndInitVars(Scope* scope, Stack* stack, node* Node, char* type);
void findAndInitStrings(Scope* scope, Stack* stack, node* Node, char* type);
void findAndInitForLoopVars(Scope* scope, Stack* stack, node* Node, char* type);
Variable* findVarNodeInScope(Scope* scope, LinkedListNode* node);
Variable* findVarNodeInCurrentScope(Scope* scope, char* name);
char* findVarInFuncArgs(Scope* scope, char* arg);

void findAndInitFuncArgs(LinkedListNode* item, node* temp);
Function* findFuncNodeInScope(Scope* scope, LinkedListNode* node);
Function* findFuncNodeInCurrentScope(Scope* scope, char* name);
int findMainFunction(Scope* scope);
Function* getCurrentFunction(Scope* scope, Scope** currentFuncScope);

char* checkArithmetics(char* operator, char* type1, char* type2);
char* checkSemantics(Scope* scope, Stack* stack, node* Node);
void checktree(node* Node);

void printLinkedList(LinkedListNode* list);
void printScope(Scope* stack);



//? # # # # # # # # # # Linked-List Functions # # # # # # # # # # //

// function to create a new linked list node 
LinkedListNode* makeVarNode(char* name, char* type, char* len) {
    Variable* newVar = (Variable*)malloc(sizeof(Variable));
    LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    if (newVar != NULL && newNode != NULL) {
        //initialize new var
        newVar->name = name;
        newVar->type = type;
        newVar->len = len;
        newVar->flag = 0;
        //initialize new node with var 
        newNode->variable = newVar;
        newNode->function = NULL;
        newNode->next = NULL;
    }
    return newNode;
}

// function to create a new function node 
LinkedListNode* makeFuncNode(char* name, char* returnType, int isStatic, int isPrivate) {
    Function* newFunc = (Function*)malloc(sizeof(Function));
    LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    if (newFunc != NULL && newNode != NULL) {
        //initialize new func
        newFunc->name = name;
        newFunc->args = NULL;
        newFunc->countArgs = 0;
        newFunc->isPrivate = isPrivate;
        newFunc->isStatic = isStatic;
        newFunc->returnType = returnType;
        //initialize new node with func
        newNode->variable = NULL;
        newNode->function = newFunc;
        newNode->next = NULL;
    }
    return newNode;
}

// function to create a new argument 
Argument* makeFuncArg(char* name, char* type) {
    Argument* newArg = (Argument*)malloc(sizeof(Argument));
    if (newArg != NULL) {
        newArg->name = name;
        newArg->type = type;
    }
    return newArg;
}

// function to add an argument to function node 
void addArg(Function* func, Argument* newArg) {
    func->countArgs += 1; //we increase the var counter of func
    func->args = (Argument**)realloc(func->args, sizeof(Argument*) * func->countArgs);
    if (func->args == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE); 
    }
    func->args[func->countArgs-1] = newArg; //set the new argument in function
}

// function to create a new argument 
void addLinkedListNode(Scope* scope, LinkedListNode* listNode) {
    if (scope->list == NULL) { //if we don't have elements we add new node
        scope->list = listNode;
    }
    else { //else we search for the last element and assign the new node to the next
        LinkedListNode* tempList = scope->list;
        while (tempList->next != NULL) 
            tempList = tempList->next;
        tempList->next = listNode;
    }
}


//? # # # # # # # # # # Search Scope Functions # # # # # # # # # # //

// function to create a new scope that points to the previous scope (father) 
Scope* makeScope(Scope* father) {
    Scope* newScope = (Scope*)malloc(sizeof(Scope));
    if (newScope != NULL) {
        newScope->father = father;
        newScope->list = NULL;
    }
    return newScope;
}

// function for finding and initializing all the arguments from a function's signiture
void findAndInitFuncArgs(LinkedListNode* item, node* temp) {
    char* tempType;
    node* variables;

    // if we only have one type of arguments: foo(args>> int: x, y)      
    if (strcmp(temp->left->token, "") != 0) { 
        tempType = temp->left->token;
        variables = temp->right;
        do {
            addArg(item->function, makeFuncArg(variables->token, tempType));
            variables = variables->left;
        } while (variables != NULL);  
    }
    else { // in the case we have multiple types of arguments: foo(args>> int: x, y ; float: a,b,c)
        tempType = temp->left->left->token;
        variables = temp->left->right;
        do {
            addArg(item->function, makeFuncArg(variables->token, tempType));
            variables = variables->left;
        } while (variables != NULL);
        findAndInitFuncArgs(item, temp->right);
    }
}

// function for adding a new variable to the for loop scope
void findAndInitForLoopVars(Scope* scope, Stack* stack, node* Node, char* type) {

    // check if there are more variables to declare in this declaration statement
    if (strcmp(Node->token, "") == 0) {
        findAndInitForLoopVars(scope, stack, Node->left, type);
        findAndInitForLoopVars(scope, stack, Node->right->left, type);
    }
    else {
        char* id;
        if (strcmp(Node->token, "ID ASSIGN") == 0) 
            id = Node->left->token;
        else if (strcmp(Node->token, "EXPRESSION") == 0) 
            id = Node->left->left->left->token; 

        // check if the variable we are declaring is used in the function argument declaration
        Function* currentFunc = getCurrentFunction(scope, NULL);
        if (currentFunc != NULL) {
            for (size_t i = 0; i < currentFunc->countArgs; i++) {
                if (strcmp(currentFunc->args[i]->name, id) == 0) {
                    printf("SEMANTIC ERROR: redeclaration of identifier '%s', it has already been declared in current function arguments.\n", id);
                    free(Node);
                    free(currentFunc);
                    free(scope);
                    cleanAndCloseFile();
                    exit(1); 
                }
            }
        }

        // check if the variable is already declared in the current scope
        if (findVarNodeInCurrentScope(scope->father, id) != NULL) {
            printf("SEMANTIC ERROR: redeclaration of identifier '%s', it has already been declared in this scope.\n", id);
            free(Node);
            free(scope);
            cleanAndCloseFile();
            exit(1); 
        }

        LinkedListNode* varNode = makeVarNode(id, type, NULL);

        // check if has assignment or not
        if (strcmp(Node->token, "ID ASSIGN") == 0){
            char* foundType = checkSemantics(scope, stack, Node->right);

            //check if given type is of type pointer and if so we need to check its value type
            if ((strcmp(type, "INT*") == 0) || (strcmp(type, "DOUBLE*") == 0) || (strcmp(type, "FLOAT*") == 0) || (strcmp(type, "CHAR*") == 0)) {
                char* expectedType = checkArithmetics("*", type, NULL);
                if (strcmp(foundType, "NULL") != 0) {
                    if (strcmp(expectedType, foundType) != 0) {
                        printf("SEMANTIC ERROR: type mismatch at declaration of identifier '%s', expected '%s' but found '%s'.\n", id, expectedType, foundType);
                        free(Node);
                        free(scope);
                        cleanAndCloseFile();
                        exit(1);
                    }
                }
            }
            //else we are doing regular assignment so we only check if the value type matches the declaration type
            else if (strcmp(type, foundType) != 0) {
                printf("SEMANTIC ERROR: type mismatch at declaration of identifier '%s', expected '%s' but found '%s'.\n", id, type, foundType);
                free(Node);
                free(scope);
                cleanAndCloseFile();
                exit(1);
            }

            //todo: Part 3
            // Check if we need to print label
            char* labelVal = checkLabel(stack);
            char *temp;

            // Pop the result of the recursive call on the right side of the assignment, save the left side token
            char* rightVal = pop(stack);
            char* leftVal = id;
           
            // Print the assignment
            if (labelVal != NULL) { // If there is a label to print, print it
                asprintf(&temp, "\t%s:\t%s = %s", labelVal, leftVal, rightVal);
            }
            else { // otherwise print 't = {value}' without a label
                asprintf(&temp, "\t\t%s = %s", leftVal, rightVal);
            }
            addLineToFile(temp);

            // Count the assignment ONLY if we havn't counted that variable before 
            if (varNode->variable->flag == 0) {
                incrementFunctionSize(type); 
                varNode->variable->flag = 1;
            }
        }
        addLinkedListNode(scope, varNode); // add the new variable to the scope
    }
}

// function for adding a new variable to the scope
void findAndInitVars(Scope* scope, Stack* stack, node* Node, char* type) {
    LinkedListNode* prevScopeList = scope->father->list;
    while (prevScopeList->next != NULL) {     
        prevScopeList = prevScopeList->next; 
    }

    if (prevScopeList->function != NULL) {
        Function* currentFunc = prevScopeList->function;
        // look for arg in the function arguments
        if (currentFunc != NULL) {
            for (size_t i = 0; i < currentFunc->countArgs; i++) {
                if (strcmp(currentFunc->args[i]->name, Node->token) == 0) {
                    printf("SEMANTIC ERROR: redeclaration of identifier '%s', it has already been declared in this scope.\n", Node->token);
                    free(Node);
                    free(scope);
                    cleanAndCloseFile();
                    exit(1); 
                }
            }
        }
    }

    // check if the variable is already declared in the current scope
    if (findVarNodeInCurrentScope(scope, Node->token) != NULL) {
        printf("SEMANTIC ERROR: redeclaration of identifier '%s', it has already been declared in this scope.\n", Node->token);
        free(Node);
        free(scope);
        cleanAndCloseFile();
        exit(1); 
    }

    // check if has assignment or not
    if (Node->left == NULL) { 
        addLinkedListNode(scope, makeVarNode(Node->token, type, NULL));
    }
    else {
        if (strcmp(Node->left->token, "ASSIGN") == 0) { 
            LinkedListNode* varNode = makeVarNode(Node->token, type, NULL);

            // checking for assignment of complex bool statemenets into variables
            if (strcmp(varNode->variable->type, "BOOL") == 0) {

            //! checking if the assignment value is complex or not
            if ((strcmp(Node->left->left->left->token, "&&") == 0) 
                || (strcmp(Node->left->left->left->token, "||") == 0)
                || ((strcmp(Node->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->token, "&&") == 0))
                || ((strcmp(Node->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->token, "||") == 0))
                || ((strcmp(Node->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->left->left->token, "&&") == 0))
                || ((strcmp(Node->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->left->left->token, "||") == 0))
                || ((strcmp(Node->left->left->left->token, "! (not)") == 0) && (strcmp(Node->left->left->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->left->left->token, "&&") == 0))
                || ((strcmp(Node->left->left->left->token, "! (not)") == 0) && (strcmp(Node->left->left->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->left->left->token, "||") == 0))
                || ((strcmp(Node->left->left->left->token, "! (not)") == 0) && (strcmp(Node->left->left->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->left->left->left->left->token, "&&") == 0))
                || ((strcmp(Node->left->left->left->token, "! (not)") == 0) && (strcmp(Node->left->left->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->left->left->left->left->token, "||") == 0))
                || ((strcmp(Node->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->token, "! (not)") == 0) && (strcmp(Node->left->left->left->left->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->left->left->left->left->token, "&&") == 0))
                || ((strcmp(Node->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->token, "! (not)") == 0) && (strcmp(Node->left->left->left->left->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->left->left->left->left->token, "||") == 0))

                ) {     
                    // sending two labels into the recursive call as well as the var->name to know that we have an assignment
                    char* trueLabel = getNextLabel();
                    char* falseLabel = getNextLabel();
                    push(stack, varNode->variable->name); 
                    push(stack, trueLabel); 
                    push(stack, falseLabel); 
                }
            }

            char* foundType = checkSemantics(scope, stack, Node->left->left);
            // check if given type is of type pointer and if so we need to check its value type
            if ((strcmp(type, "INT*") == 0) || (strcmp(type, "DOUBLE*") == 0) || (strcmp(type, "FLOAT*") == 0) || (strcmp(type, "CHAR*") == 0)) {
                char* expectedType = checkArithmetics("*", type, NULL);
                if (strcmp(foundType, "NULL") != 0) {
                    if (strcmp(expectedType, foundType) != 0) {
                        printf("SEMANTIC ERROR: type mismatch at declaration of identifier '%s', expected '%s' but found '%s'.\n", Node->token, expectedType, foundType);
                        free(Node);
                        free(scope);
                        cleanAndCloseFile();
                        exit(1);
                    }
                }
            }
            // else we are doing regular assignment so we only check if the value type matches the declaration type
            else {
                if (strcmp(type, foundType) != 0) {
                    printf("SEMANTIC ERROR: type mismatch at declaration of identifier '%s', expected '%s' but found '%s'.\n", Node->token, type, foundType);
                    free(Node);
                    free(scope);
                    cleanAndCloseFile();
                    exit(1);
                }
            }

            //todo: Part 3
            // Check if we need to print label
            char* labelVal = checkLabel(stack);
            char *temp;

            // Pop the result of the recursive call on the right side of the assignment, save the left side token
            char* rightVal = pop(stack);
            char* leftVal = Node->token;
           
            // Print the assignment
            if (labelVal != NULL) { // If there is a label to print, print it
                asprintf(&temp, "\t%s:\t%s = %s", labelVal, leftVal, rightVal);
            }
            else { // otherwise print 't = {value}' without a label
                asprintf(&temp, "\t\t%s = %s", leftVal, rightVal);
            }
            addLineToFile(temp);

            // Count the assignment ONLY if we havn't counted that variable before 
            if (varNode->variable->flag == 0) {
                incrementFunctionSize(type); 
                varNode->variable->flag = 1;
            }

            addLinkedListNode(scope, varNode); // add the new variable to the scope
            free(rightVal);
            free(temp);
        }
    }


    if (Node->right != NULL) { 
        findAndInitVars(scope, stack, Node->right, type);
    }
}

// function for adding a new STRING variable to the scope 
void findAndInitStrings(Scope* scope, Stack* stack, node* Node, char* type) {
    // check if the variable is already declared in the current scope
    if (findVarNodeInCurrentScope(scope, Node->left->left->left->token) != NULL) {
        printf("SEMANTIC ERROR: redeclaration of identifier '%s', it has already been declared.\n", Node->left->left->left->token);
        free(Node);
        free(scope);
        cleanAndCloseFile();
        exit(1); 
    }

    // check that index expression is less than or equal to the declared length and that its not negative
    int indexValue = atoi(Node->left->left->right->token);
    if (indexValue < 0) {
        printf("SEMANTIC ERROR: string size is invalid for identifier '%s', size must be greater than zero.\n", Node->left->left->left->token);
        free(Node);
        free(scope);
        cleanAndCloseFile();
        exit(1); 
    }
    
    // check that string size is not explicit zero
    if (indexValue == 0) {
        printf("SEMANTIC ERROR: string size of identifier '%s' can't be 0.\n", Node->left->left->left->token);
        free(Node);
        free(scope);
        cleanAndCloseFile();
        exit(1); 
    }
    
    // checking that the assignment value is of type STRING or NULL          
    if (Node->left->right->left != NULL) { 
        char* assignemtType = checkSemantics(scope, stack, Node->left->right->left->left);

        if ((strcmp("NULL",assignemtType) != 0) && (strcmp("STRING", assignemtType) != 0)) {
            printf("SEMANTIC ERROR: type mismatch for identifier '%s', expected 'STRING' or 'NULL' but found '%s'.\n", Node->left->left->left->token, assignemtType);
            free(Node);
            free(scope);
            cleanAndCloseFile();
            exit(1);
        }
        // checking that the index is valid only if the value is a simple integer, if its an expression then dont check
        else if (strcmp("STRING", assignemtType) == 0) { 
            int assignemntStringLen = (strlen(Node->left->right->left->left->left->left->token) - 2); // -2 is because we want to disregard the "" symbols.
            if (assignemntStringLen > indexValue) { //? >= because we leave space for '\0'
                printf("SEMANTIC ERROR: assignment string is too long for identifier '%s', expected length <= '%d' but found string of length '%d'.\n", Node->left->left->left->token, indexValue, assignemntStringLen);
                free(Node);
                free(scope);
                cleanAndCloseFile();
                exit(1);
            }
        }

        //todo: Part 3
        // Check if we need to print label
        char* labelVal = checkLabel(stack);
        char *temp;

        // Pop the result of the recursive call on the right side of the assignment, save the left side token
        char* rightVal = pop(stack);
        char* leftVal = Node->left->left->left->token;
        
        // Print the assignment
        if (labelVal != NULL) { // If there is a label to print, print it
            asprintf(&temp, "\t%s:\t%s = %s", labelVal, leftVal, rightVal);
        }
        else { // otherwise print 't = {value}' without a label
            asprintf(&temp, "\t\t%s = %s", leftVal, rightVal);
        }
        push(stack, leftVal);
        addLineToFile(temp);
        free(rightVal);
        free(temp);
    }

    LinkedListNode* stringNode = makeVarNode(Node->left->left->left->token, type, Node->left->left->right->token);

    // count the string into the funcSize ONLY if it has not been counted yet
    if (stringNode->variable->flag == 0) {
        funcSize += indexValue; //* here we are counting the string size as the index value given to the string at decleration: string message[20] ==> +20 bytes to funcSize
        stringNode->variable->flag = 1;
    }

    // add the string variable into the scope
    addLinkedListNode(scope, stringNode);
    
    // check if there are more declarations in this declaration
    if (Node->right->left != NULL) {
        findAndInitStrings(scope, stack, Node->right->left, type);
    }
}

// function to find variable in any scope, recursively 
Variable* findVarNodeInScope(Scope* scope, LinkedListNode* node) {
    if (scope != NULL && node != NULL) {
        LinkedListNode* current = scope->list; 
        //go through all elements in linked list node
        while (current != NULL && current->variable != NULL) { // added  && current->variable != NULL  for the case that there are not variables declared in the scopes
            // go through all elements and check if the item is a variable and if so then check if the name is the same as the one we are looking for
            if ((strcmp(current->variable->name, node->variable->name) == 0) && current->variable->type != NULL) {
                return current->variable;
            } 

            current = current->next;
        }
        return findVarNodeInScope(scope->father, node); //call recursively again to search in father's list
    }
    return NULL;
}

// function to find variable in a given scope only, not recursive 
Variable* findVarNodeInCurrentScope(Scope* scope, char* name) {
    if (scope != NULL) {
        LinkedListNode* current = scope->list; 
        // go through all elements and check if the item is a function and if so then check if it's name matches the name we are looking for
        while (current != NULL) {
            if ((current->variable != NULL) && (strcmp(current->variable->name, name) == 0)) {
                return current->variable;
            }            
            current = current->next; 
        } 
    }
    return NULL; 
}

// function for finding a variable in function arguments 
char* findVarInFuncArgs(Scope* scope, char* arg) { 
    if (scope != NULL) {
        LinkedListNode* current = scope->list; 
        // go through all elements in linked list node
        while (current->next != NULL) { 
            current = current->next; 
        }

        // look for arg in the function arguments
        if (current->function != NULL) {
            for (size_t i = 0; i < current->function->countArgs; i++) {
                if (strcmp(current->function->args[i]->name, arg) == 0) {
                    return current->function->args[i]->type;
                }
            }
        }
        return findVarInFuncArgs(scope->father, arg); // if not found call recursivly 
    }
    return NULL; 
}

// function for finding if the main function has been declared, returns 1 if exists 
int findMainFunction(Scope* scope) { 
    if (scope != NULL) {
        LinkedListNode* current = scope->list;
        // go through all elements and check if the item is a function and if so then check if its named 'main'
        while (current != NULL) { 
            if ((current->function != NULL) && (strcmp(current->function->name, "main") == 0)) {
                return 1;
            }            
            current = current->next; 
        }
    }
    return 0; 
    //*note*:  When declaring a function with the name 'main' we are checking if a main function exists in the current scope
    //*        and also that the current scope is the global scope, otherwise we return error.    
    //*        This function is also used to insure that a 'main' function was indeed declared in the program.
}


// function to find function in any scope, recursively 
Function* findFuncNodeInScope(Scope* scope, LinkedListNode* node) {
    if (scope != NULL && node != NULL) {
        LinkedListNode* current = scope->list;
        // go through all elements in linked list node
        while (current != NULL) {
            // check if the current item in a function and that it has the correct name
            if ((current->function != NULL) && (strcmp(current->function->name, node->function->name) == 0)) {
                return current->function;
            }            
            current = current->next; 
        }
        return findFuncNodeInScope(scope->father, node); //call recursively again to search in father's list
    }
    return NULL; 
}

Function* findFuncNodeUntillGivenScope(Scope* scope, Scope* finalScope, char* name) {
    // look for function in all scopes untill the final scope that was provieded
    Scope* temp1 = scope;
    while ((temp1 != NULL) && (temp1->list != NULL) && (finalScope != temp1)) {
        LinkedListNode* temp2 = temp1->list;
        while (temp2 != NULL) {
            if ((temp2->function != NULL) && (strcmp(temp2->function->name, name) == 0)) {
                return temp2->function;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->father;
    }
    return NULL;
}

// function to find function in a given scope only, not recursive 
Function* findFuncNodeInCurrentScope(Scope* scope, char* name) {
    if (scope != NULL) {
        LinkedListNode* current = scope->list;
        // go through all elements in linked list node
        while (current != NULL) {
            if ((current->function != NULL) && (strcmp(current->function->name, name) == 0)) {
                return current->function;
            }            
            current = current->next; 
        }
    }
    return NULL; 
}

// function for getting the current function, the one we are currently in the scope of 
Function* getCurrentFunction(Scope* scope, Scope** currentFuncScope) { 
    if (scope != NULL) {
        LinkedListNode* current = scope->father->list; 
        // go through all elements in linked list node
        while (current->next != NULL) { 
            current = current->next; 
        }

        // check if the last item is indeed a function, else keep looking in the next scope
        if (current->function == NULL) {
            return getCurrentFunction(scope->father, currentFuncScope);
        }

        // save the pointer to the scope where the function was found in
        if (currentFuncScope != NULL)
            *currentFuncScope = scope->father; 
        return current->function; 
    }
    return NULL; 
}

//? # # # # # # # # # # Semantic Functions # # # # # # # # # # //

// function that checks arithmetic operations on given types and operator and returns result type 
char* checkArithmetics(char* operator, char* type1, char* type2) {
    if (operator != NULL && type1 != NULL) {
        if (type2 != NULL) {
            if ((strcmp(operator, "+")==0 || strcmp(operator, "-")==0) && ((strcmp(type1, "CHAR*")==0 && strcmp(type2, "INT")==0) || (strcmp(type1, "INT")==0 && strcmp(type2, "CHAR*")==0))) {
                return "CHAR*"; // can only perform pointer aritmetics on char pointers, and can only perform + and - 
            }
            // on operators +,-,*,/ we give precedence to double, then to float and only if both are int then return int. these operators dont work on type char, bool, string
            else if (strcmp(operator, "+")==0 || strcmp(operator, "-")==0 || strcmp(operator, "*")==0 || strcmp(operator, "/")==0) {
                if (strcmp(type1, "INT")==0 && strcmp(type2, "INT")==0)
                    return "INT";
                else if ((strcmp(type1, "INT")==0 && strcmp(type2, "DOUBLE")==0) || (strcmp(type1, "FLOAT")==0 && strcmp(type2, "DOUBLE")==0) || (strcmp(type1, "DOUBLE")==0 && strcmp(type2, "INT")==0)
                            || (strcmp(type1, "DOUBLE")==0 && strcmp(type2, "FLOAT")==0) || (strcmp(type1, "DOUBLE")==0 && strcmp(type2, "DOUBLE")==0))
                    return "DOUBLE";
                else if ((strcmp(type1, "INT")==0 && strcmp(type2, "FLOAT")==0) || (strcmp(type1, "FLOAT")==0 && strcmp(type2, "INT")==0)
                            || (strcmp(type1, "FLOAT")==0 && strcmp(type2, "FLOAT")==0))
                    return "FLOAT";
            }
            else if (strcmp(operator, "&&")==0 || strcmp(operator, "||")==0) { 
                if (strcmp(type1, "BOOL")==0 && strcmp(type2, "BOOL")==0)
                    return "BOOL";
            }
            else if (strcmp(operator, "<")==0 || strcmp(operator, ">")==0 || strcmp(operator, "<=")==0 || strcmp(operator, ">=")==0) {
                if ((strcmp(type1, "INT")==0 || strcmp(type1, "DOUBLE")==0 || strcmp(type1, "FLOAT")==0) && (strcmp(type2, "INT")==0 || strcmp(type2, "DOUBLE")==0 || strcmp(type2, "FLOAT")==0))
                    return "BOOL";
            }
            else if (strcmp(operator, "==")==0 || strcmp(operator, "!=")==0) { // checking that both types are the exact same, then return bool
                if ((strcmp(type1, "INT")==0 && strcmp(type2, "INT")==0) || (strcmp(type1, "INT*")==0 && strcmp(type2, "INT*")==0) || (strcmp(type1, "DOUBLE")==0 && strcmp(type2, "DOUBLE")==0) 
                    || (strcmp(type1, "DOUBLE*")==0 && strcmp(type2, "DOUBLE*")==0) || (strcmp(type1, "FLOAT")==0 && strcmp(type2, "FLOAT")==0) || (strcmp(type1, "FLOAT*")==0 && strcmp(type2, "FLOAT*")==0) 
                    || (strcmp(type1, "CHAR")==0 && strcmp(type2, "CHAR")==0) || (strcmp(type1, "CHAR*")==0 && strcmp(type2, "CHAR*")==0) || (strcmp(type1, "BOOL")==0 && strcmp(type2, "BOOL")==0))
                    return "BOOL";
            }
        }
        else {
            if (strcmp(operator, "||")==0 && strcmp(type1, "STRING")==0) { // operator size '| string |' can only be performed on strings
                return "INT";
            }
            else if (strcmp(operator, "!")==0 && strcmp(type1, "BOOL")==0) { // operator not '!' can only be performed on bools
                return "BOOL";
            }
            else if (strcmp(operator, "&")==0) { // getting the address of a variable will return the pointer to the base type
                if (strcmp(type1, "INT")==0) 
                    return "INT*";
                else if (strcmp(type1, "DOUBLE")==0) 
                    return "DOUBLE*";
                else if (strcmp(type1, "FLOAT")==0) 
                    return "FLOAT*";
                else if (strcmp(type1, "CHAR")==0) 
                    return "CHAR*";
            }
            else if (strcmp(operator, "*")==0) { // getting the variable of a pointer will return the base type
                if (strcmp(type1, "INT*")==0) 
                    return "INT";
                else if (strcmp(type1, "DOUBLE*")==0) 
                    return "DOUBLE";
                else if (strcmp(type1, "FLOAT*")==0) 
                    return "FLOAT";
                else if (strcmp(type1, "CHAR*")==0) 
                    return "CHAR";
            }
        }
    }
    return NULL;
}

// function for checking if the AST is correct semanticly, if so then print 
// success message to the screen, else print where it failed 
void checktree(node* Node) {
    // opening the file
    file = openFile();

    // create 3AC Stack
    Stack* stack = initStack();

    // creating the global scope
    Scope* programScope = (Scope*)malloc(sizeof(Scope));

    // checking the semantics of the program
    checkSemantics(programScope, stack, Node);

    // checking if a main function was declared in the program
    if (findMainFunction(programScope) == 0) {
        printf("SEMANTIC ERROR: no main function found, program must have one main function.\n");
        free(programScope);
        cleanAndCloseFile();
        exit(1);
    }
    //printScope(programScope);
    
    // freeing the global scope
    free(programScope);
}

// main part 2 function that traverses the AST, creates scopes, creates symbol tables for variables and functions,
// checks all of the semantics of the code and prints error messages if an issue was found 
char* checkSemantics(Scope* scope, Stack* stack, node* Node) {

    if (Node == NULL) { 
        return NULL; // stopping the recursion
    }

    //? * * * * * * Blocks and Scopes * * * * * * *//

    else if (strcmp(Node->token, "") == 0 || strcmp(Node->token, "CODE") == 0) {
        if (Node->left != NULL)
            checkSemantics(scope, stack, Node->left);
        if (Node->right != NULL)
            checkSemantics(scope, stack, Node->right);
    }

    else if (strcmp(Node->token, "FUNCTION") == 0) {
        // getting the private and static of the declared function
        int isStatic = 0, isPrivate = 0;
        if (strcmp(Node->left->left->left->token, "PRIVATE") == 0)
            isPrivate = 1;
        if ((Node->left->left->right != NULL) && strcmp(Node->left->left->right->token, "STATIC") == 0)
            isStatic = 1;

        // creating a function node
        LinkedListNode* item = makeFuncNode(Node->left->token, Node->right->left->token, isStatic, isPrivate);

        // performing checks if we are declaring a main function
        if (strcmp(item->function->name, "main") == 0) {
            int flag = 0;
            if (findMainFunction(scope) == 1) {
                printf("SEMANTIC ERROR: function declaration error, there can only be one main function.\n");
                flag = 1;
            }
            else if (scope->father != NULL) { //* not in global scope
                printf("SEMANTIC ERROR: function declaration error, main function must be declared in global scope.\n");
                flag = 1;
            }
            else if (strcmp(item->function->returnType, "VOID") != 0) {
                printf("SEMANTIC ERROR: function declaration error, main function must return void.\n");
                flag = 1;
            }
            else if (isPrivate == 1) {
                printf("SEMANTIC ERROR: function declaration error, main function must be public.\n");
                flag = 1;
            }
            else if (isStatic == 0) {
                printf("SEMANTIC ERROR: function declaration error, main function must be static.\n");
                flag = 1;
            }
            else if (Node->left->right != NULL) {
                printf("SEMANTIC ERROR: function declaration error, main function can't have arguments.\n");
                flag = 1;
            }
            
            if (flag == 1) {
                free(item);
                free(Node);
                free(scope);
                cleanAndCloseFile();
                exit(1); 
            }
        }

        // look if the function is already declared
        Function* func = findFuncNodeInCurrentScope(scope, item->function->name);
        if (func != NULL) {
            printf("SEMANTIC ERROR: redeclaration error, function '%s' is already declared.\n", item->function->name);
            free(item);
            free(func);
            free(scope);
            cleanAndCloseFile();
            exit(1);
        }
        free(func);

        // check if there are arguments in the declaration, if so init them
        if (Node->left->right != NULL) { 
            node* temp = Node->left->right->left->left;
            findAndInitFuncArgs(item, temp);
        }

        // add the function linked-list node into the scope list and go to func block
        addLinkedListNode(scope, item);
        node* temp = Node->right->right->left;
        if (temp != NULL) {

            //todo: Part 3
            // print function name label and begin line
            addLineToFile(concat(Node->left->token, ":"));

            // write "BeginFunc N" and save the position of this line
            long posN = addLineToFile("\t\tBeginFunc N\t\t\n"); // the '\t' is for when the N is large
            if (posN == -1) {
                fclose(file);
                cleanAndCloseFile();
                exit(1);
            }

            // handle function body
            checkSemantics(makeScope(scope), stack, temp);
            
            // print end of function and save the position of this line
            addLineToFile("\t\tEndFunc\n");
            long posEnd = addLineToFile(""); // adding a spacer line and saving the position of this line
            if (posEnd == -1) {
                fclose(file);
                cleanAndCloseFile();
                exit(1);
            }
            
            // update the N to be the actual function size
            replaceNInFile(posN, posEnd);
        }
    }

    else if (strcmp(Node->token, "BLOCK") == 0) { 
        // adding if block into scope
        LinkedListNode* item = makeVarNode("block", NULL, NULL);
        addLinkedListNode(scope, item);

        checkSemantics(makeScope(scope), stack, Node->left); 

        //todo: Part 3 
        // pop all elements from stack untill you reach a label 
        char* popVal;
        do {
            popVal = peek(stack);
            if ((popVal != NULL) && (popVal[0] != 'L')) {
                pop(stack);
            }
            else break;
        } while (popVal != NULL);
    }

    else if (strcmp(Node->token, "IF") == 0) { 
        //todo: Part 3
        char* labelIf = getNextLabel(); 
        char* labelEnd = getNextLabel();
        char* line;

        //! check if the condition is complex or simple, and handle both cases accordingly   
        if ((strcmp(Node->left->left->left->token, "||") == 0 )
            || (strcmp(Node->left->left->left->token, "&&") == 0)
            || ((strcmp(Node->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->token, "&&") == 0))
            || ((strcmp(Node->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->token, "||") == 0))
            || ((strcmp(Node->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->left->left->token, "&&") == 0))
            || ((strcmp(Node->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->left->left->token, "||") == 0))
            || ((strcmp(Node->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->token, "! (not)") == 0) && (strcmp(Node->left->left->left->left->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->left->left->left->left->token, "&&") == 0))
            || ((strcmp(Node->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->token, "! (not)") == 0) && (strcmp(Node->left->left->left->left->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->left->left->left->left->token, "||") == 0))
            || ((strcmp(Node->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->left->left->token, "! (not)") == 0) && (strcmp(Node->left->left->left->left->left->left->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->left->left->left->left->left->left->token, "&&") == 0))
            || ((strcmp(Node->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->left->left->token, "! (not)") == 0) && (strcmp(Node->left->left->left->left->left->left->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->left->left->left->left->left->left->token, "&&") == 0))
            || ((strcmp(Node->left->left->left->token, "! (not)") == 0) && (strcmp(Node->left->left->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->left->left->token, "&&") == 0))
            || ((strcmp(Node->left->left->left->token, "! (not)") == 0) && (strcmp(Node->left->left->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->left->left->token, "||") == 0))
            || ((strcmp(Node->left->left->left->token, "! (not)") == 0) && (strcmp(Node->left->left->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->left->left->left->left->token, "&&") == 0))
            || ((strcmp(Node->left->left->left->token, "! (not)") == 0) && (strcmp(Node->left->left->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->left->left->left->left->token, "||") == 0)) 
            ) {

            // push both labels into the stack to be used later
            push(stack, labelEnd);
            push(stack, labelIf);

            // check that condition is of type bool using a recursive call
            char* conditionType = checkSemantics(scope, stack, Node->left->left);
            if (strcmp("BOOL", conditionType) != 0) {
                printf("SEMANTIC ERROR: if statement condition must be of type 'BOOL', instead it is '%s'.\n", conditionType);
                free(Node);
                free(scope);
                cleanAndCloseFile();
                exit(1);
            }
        }
        else {
            // check that condition is of type bool using a recursive call
            char* conditionType = checkSemantics(scope, stack, Node->left->left);
            if (strcmp("BOOL", conditionType) != 0) {
                printf("SEMANTIC ERROR: if statement condition must be of type 'BOOL', instead it is '%s'.\n", conditionType);
                free(Node);
                free(scope);
                cleanAndCloseFile();
                exit(1);
            }

            // finish the 3AC condition print by printing the 'ifz' line 
            asprintf(&line, "\t\tif %s == 0 goto %s", pop(stack), labelEnd);
            addLineToFile(line);
        }
        
        // insert a new linked list node into the scope, at the end, in order to be able to find the correct current function later on
        LinkedListNode* item = makeVarNode("if", NULL, NULL);
        addLinkedListNode(scope, item);

        // print the label to indicate the start of the IF statement
        asprintf(&line, "\t%s:", labelIf);
        addLineToFile(line);

        if (strcmp(Node->left->right->token, "BLOCK") == 0)
            checkSemantics(scope, stack, Node->left->right); // if - single line statement
        else
            checkSemantics(makeScope(scope), stack, Node->left->right); // if - multi line block


        // check if there is an ELSE block, if so handle it
        if (Node->right != NULL) {
            //todo: Part 3
            char* labelElseStart = labelEnd; 
            char* labelIfEnd = getNextLabel(); 
          
            asprintf(&line, "\t\tgoto %s", labelIfEnd);
            addLineToFile(line);

            // handle else block (also handles print else label)
            asprintf(&line, "\t%s:", labelElseStart);
            addLineToFile(line);
            push(stack, labelIfEnd);

            // adding else block into scope
            LinkedListNode* item = makeVarNode("else", NULL, NULL);
            addLinkedListNode(scope, item);

            if (strcmp(Node->right->left->left->token, "BLOCK") == 0)
                checkSemantics(scope, stack, Node->right->left); // ELSE - multi line block 
            else
                checkSemantics(makeScope(scope), stack, Node->right->left); // ELSE - single line statement 

            asprintf(&line, "\t%s:", labelIfEnd);
            addLineToFile(line);
        }
        else {
            asprintf(&line, "\t%s:", labelEnd);
            addLineToFile(line);
        }
    }

    else if (strcmp(Node->token, "DO WHILE") == 0) {
        //todo: Part 3
        char* startLabel = getNextLabel();
        char* endLabel = getNextLabel();   
        char* line;

        asprintf(&line, "\t%s:", startLabel);
        addLineToFile(line);

        // adding do while block into scope
        LinkedListNode* item = makeVarNode("do", NULL, NULL);
        addLinkedListNode(scope, item);

        // handle do while block
        checkSemantics(scope, stack, Node->left); 

        //! check if the condition is complex or simple, and handle both cases accordingly   
        if ((strcmp(Node->right->left->token, "||") == 0 )
            || (strcmp(Node->right->left->token, "&&") == 0)
            || ((strcmp(Node->right->left->token, "( )") == 0) && (strcmp(Node->right->left->left->left->token, "&&") == 0))
            || ((strcmp(Node->right->left->token, "( )") == 0) && (strcmp(Node->right->left->left->left->token, "||") == 0))
            || ((strcmp(Node->right->left->token, "( )") == 0) && (strcmp(Node->right->left->left->left->token, "( )") == 0) && (strcmp(Node->right->left->left->left->left->left->token, "&&") == 0))
            || ((strcmp(Node->right->left->token, "( )") == 0) && (strcmp(Node->right->left->left->left->token, "( )") == 0) && (strcmp(Node->right->left->left->left->left->left->token, "||") == 0))
            || ((strcmp(Node->right->left->token, "( )") == 0) && (strcmp(Node->right->left->left->left->token, "! (not)") == 0) && (strcmp(Node->right->left->left->left->left->left->token, "( )") == 0) && (strcmp(Node->right->left->left->left->left->left->left->left->token, "&&") == 0))
            || ((strcmp(Node->right->left->token, "( )") == 0) && (strcmp(Node->right->left->left->left->token, "! (not)") == 0) && (strcmp(Node->right->left->left->left->left->left->token, "( )") == 0) && (strcmp(Node->right->left->left->left->left->left->left->left->token, "||") == 0))
            || ((strcmp(Node->right->left->token, "( )") == 0) && (strcmp(Node->right->left->left->left->token, "( )") == 0) && (strcmp(Node->right->left->left->left->left->left->token, "! (not)") == 0) && (strcmp(Node->right->left->left->left->left->left->left->left->token, "( )") == 0) && (strcmp(Node->right->left->left->left->left->left->left->left->left->left->token, "&&") == 0))
            || ((strcmp(Node->right->left->token, "( )") == 0) && (strcmp(Node->right->left->left->left->token, "( )") == 0) && (strcmp(Node->right->left->left->left->left->left->token, "! (not)") == 0) && (strcmp(Node->right->left->left->left->left->left->left->left->token, "( )") == 0) && (strcmp(Node->right->left->left->left->left->left->left->left->left->left->token, "&&") == 0))
            || ((strcmp(Node->right->left->token, "! (not)") == 0) && (strcmp(Node->right->left->left->left->token, "( )") == 0) && (strcmp(Node->right->left->left->left->left->left->token, "&&") == 0))
            || ((strcmp(Node->right->left->token, "! (not)") == 0) && (strcmp(Node->right->left->left->left->token, "( )") == 0) && (strcmp(Node->right->left->left->left->left->left->token, "||") == 0))
            || ((strcmp(Node->right->left->token, "! (not)") == 0) && (strcmp(Node->right->left->left->left->token, "( )") == 0) && (strcmp(Node->right->left->left->left->left->left->token, "( )") == 0) && (strcmp(Node->right->left->left->left->left->left->left->left->token, "&&") == 0))
            || ((strcmp(Node->right->left->token, "! (not)") == 0) && (strcmp(Node->right->left->left->left->token, "( )") == 0) && (strcmp(Node->right->left->left->left->left->left->token, "( )") == 0) && (strcmp(Node->right->left->left->left->left->left->left->left->token, "||") == 0)) 
            ) {

            // push both labels into the stack to be used later
            push(stack, endLabel);
            push(stack, startLabel);

            // check that condition is of type bool using a recursive call
            char* conditionType = checkSemantics(scope, stack,  Node->right);
            if (strcmp("BOOL", conditionType) != 0) {
                printf("SEMANTIC ERROR: do while statement condition must be of type 'BOOL', instead it is '%s'.\n", conditionType);
                free(Node);
                free(scope);
                cleanAndCloseFile();
                exit(1);
            }
        }
        else {
            // check that condition is of type bool using a recursive call
            char* conditionType = checkSemantics(scope, stack,  Node->right);
            if (strcmp("BOOL", conditionType) != 0) {
                printf("SEMANTIC ERROR: do while statement condition must be of type 'BOOL', instead it is '%s'.\n", conditionType);
                free(Node);
                free(scope);
                cleanAndCloseFile();
                exit(1);
            }

            // finish the 3AC condition print by printing the 'ifz' line 
            asprintf(&line, "\t\tif %s == 0 goto %s", pop(stack), endLabel);
            addLineToFile(line);
        }

        asprintf(&line, "\t\tgoto %s", startLabel);
        addLineToFile(line);

        asprintf(&line, "\t%s:", endLabel);
        addLineToFile(line);
    }

    else if (strcmp(Node->token, "WHILE") == 0) {
        //todo: Part 3
        char* startLabel = getNextLabel();
        char* blockLabel = getNextLabel();
        char* endLabel = getNextLabel();  
        char* line;

        asprintf(&line, "\t%s:", startLabel);
        addLineToFile(line);
        
        //! check if the condition is complex or simple, and handle both cases accordingly
        if ((strcmp(Node->left->left->token, "||") == 0 )
            || (strcmp(Node->left->left->token, "&&") == 0)
            || ((strcmp(Node->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->token, "&&") == 0))
            || ((strcmp(Node->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->token, "||") == 0))
            || ((strcmp(Node->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->left->token, "&&") == 0))
            || ((strcmp(Node->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->left->token, "||") == 0))
            || ((strcmp(Node->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->token, "! (not)") == 0) && (strcmp(Node->left->left->left->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->left->left->left->token, "&&") == 0))
            || ((strcmp(Node->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->token, "! (not)") == 0) && (strcmp(Node->left->left->left->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->left->left->left->token, "||") == 0))
            || ((strcmp(Node->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->left->token, "! (not)") == 0) && (strcmp(Node->left->left->left->left->left->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->left->left->left->left->left->token, "&&") == 0))
            || ((strcmp(Node->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->left->token, "! (not)") == 0) && (strcmp(Node->left->left->left->left->left->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->left->left->left->left->left->token, "&&") == 0))
            || ((strcmp(Node->left->left->token, "! (not)") == 0) && (strcmp(Node->left->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->left->token, "&&") == 0))
            || ((strcmp(Node->left->left->token, "! (not)") == 0) && (strcmp(Node->left->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->left->token, "||") == 0))
            || ((strcmp(Node->left->left->token, "! (not)") == 0) && (strcmp(Node->left->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->left->left->left->token, "&&") == 0))
            || ((strcmp(Node->left->left->token, "! (not)") == 0) && (strcmp(Node->left->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->left->left->left->token, "||") == 0)) 
            ) {

            // push both labels into the stack to be used later
            push(stack, endLabel);
            push(stack, blockLabel);

            // check that condition is of type bool using a recursive call
            char* conditionType = checkSemantics(scope, stack, Node->left);
            if (strcmp("BOOL", conditionType) != 0) {
                printf("SEMANTIC ERROR: while statement condition must be of type 'BOOL', instead it is '%s'.\n", conditionType);
                free(Node);
                free(scope);
                cleanAndCloseFile();
                exit(1);
            }
        }
        else {
            // check that condition is of type bool using a recursive call
            char* conditionType = checkSemantics(scope, stack, Node->left);
            if (strcmp("BOOL", conditionType) != 0) {
                printf("SEMANTIC ERROR: while statement condition must be of type 'BOOL', instead it is '%s'.\n", conditionType);
                free(Node);
                free(scope);
                cleanAndCloseFile();
                exit(1);
            }

            // finish the 3AC condition print by printing the 'ifz' line 
            asprintf(&line, "\t\tif %s == 0 goto %s", pop(stack), endLabel);
            addLineToFile(line);
        }

        // adding while block into scope
        LinkedListNode* item = makeVarNode("while", NULL, NULL);
        addLinkedListNode(scope, item);

        asprintf(&line, "\t%s:", blockLabel);
        addLineToFile(line);

        if (strcmp(Node->right->token, "BLOCK") == 0)
            checkSemantics(scope, stack, Node->right); // while - multi line block 
        else
            checkSemantics(makeScope(scope), stack, Node->right); // while - single line statement

        asprintf(&line, "\t\tgoto %s", startLabel);
        addLineToFile(line);

        asprintf(&line, "\t%s:", endLabel);
        addLineToFile(line);
    }

    else if (strcmp(Node->token, "FOR") == 0) {
        //todo: Part 3
        char* startLabel = getNextLabel();
        char* blockLabel = getNextLabel();
        char* endLabel = getNextLabel(); 
        char* line;

        // adding for block into scope
        LinkedListNode* item = makeVarNode("for", NULL, NULL);
        addLinkedListNode(scope, item);

        // creating a scope for the for loop manualy
        Scope* forLoopScope = makeScope(scope);

        // checking if for loop has a variable declaration statement
        if (strcmp("FOR INIT", Node->left->token) == 0 || strcmp("* ID ASSIGN", Node->left->token) == 0) {
            
            // check the assign statement
            if (strcmp(Node->left->left->token, "VAR") == 0)
                findAndInitForLoopVars(forLoopScope, stack, Node->left->left->right, Node->left->left->left->token);
            else
                checkSemantics(forLoopScope, stack, Node->left->left);

            asprintf(&line, "\t%s:", startLabel);
            addLineToFile(line);
            
            
            //! check if the condition is complex or simple, and handle both cases accordingly   
            if ((strcmp(Node->left->right->left->token, "||") == 0 )
                || (strcmp(Node->left->right->left->token, "&&") == 0)
                || ((strcmp(Node->left->right->left->token, "( )") == 0) && (strcmp(Node->left->right->left->left->left->token, "&&") == 0))
                || ((strcmp(Node->left->right->left->token, "( )") == 0) && (strcmp(Node->left->right->left->left->left->token, "||") == 0))
                || ((strcmp(Node->left->right->left->token, "( )") == 0) && (strcmp(Node->left->right->left->left->left->token, "( )") == 0) && (strcmp(Node->left->right->left->left->left->left->left->token, "&&") == 0))
                || ((strcmp(Node->left->right->left->token, "( )") == 0) && (strcmp(Node->left->right->left->left->left->token, "( )") == 0) && (strcmp(Node->left->right->left->left->left->left->left->token, "||") == 0))
                || ((strcmp(Node->left->right->left->token, "( )") == 0) && (strcmp(Node->left->right->left->left->left->token, "! (not)") == 0) && (strcmp(Node->left->right->left->left->left->left->left->token, "( )") == 0) && (strcmp(Node->left->right->left->left->left->left->left->left->left->token, "&&") == 0))
                || ((strcmp(Node->left->right->left->token, "( )") == 0) && (strcmp(Node->left->right->left->left->left->token, "! (not)") == 0) && (strcmp(Node->left->right->left->left->left->left->left->token, "( )") == 0) && (strcmp(Node->left->right->left->left->left->left->left->left->left->token, "||") == 0))
                || ((strcmp(Node->left->right->left->token, "( )") == 0) && (strcmp(Node->left->right->left->left->left->token, "( )") == 0) && (strcmp(Node->left->right->left->left->left->left->left->token, "! (not)") == 0) && (strcmp(Node->left->right->left->left->left->left->left->left->left->token, "( )") == 0) && (strcmp(Node->left->right->left->left->left->left->left->left->left->left->left->token, "&&") == 0))
                || ((strcmp(Node->left->right->left->token, "( )") == 0) && (strcmp(Node->left->right->left->left->left->token, "( )") == 0) && (strcmp(Node->left->right->left->left->left->left->left->token, "! (not)") == 0) && (strcmp(Node->left->right->left->left->left->left->left->left->left->token, "( )") == 0) && (strcmp(Node->left->right->left->left->left->left->left->left->left->left->left->token, "&&") == 0))
                || ((strcmp(Node->left->right->left->token, "! (not)") == 0) && (strcmp(Node->left->right->left->left->left->token, "( )") == 0) && (strcmp(Node->left->right->left->left->left->left->left->token, "&&") == 0))
                || ((strcmp(Node->left->right->left->token, "! (not)") == 0) && (strcmp(Node->left->right->left->left->left->token, "( )") == 0) && (strcmp(Node->left->right->left->left->left->left->left->token, "||") == 0))
                || ((strcmp(Node->left->right->left->token, "! (not)") == 0) && (strcmp(Node->left->right->left->left->left->token, "( )") == 0) && (strcmp(Node->left->right->left->left->left->left->left->token, "( )") == 0) && (strcmp(Node->left->right->left->left->left->left->left->left->left->token, "&&") == 0))
                || ((strcmp(Node->left->right->left->token, "! (not)") == 0) && (strcmp(Node->left->right->left->left->left->token, "( )") == 0) && (strcmp(Node->left->right->left->left->left->left->left->token, "( )") == 0) && (strcmp(Node->left->right->left->left->left->left->left->left->left->token, "||") == 0)) 
                ) {

                // push both labels into the stack to be used later
                push(stack, endLabel);
                push(stack, blockLabel);

                // check that condition is of type bool using a recursive call
                char* conditionType = checkSemantics(forLoopScope, stack, Node->left->right);
                if (strcmp("BOOL", conditionType) != 0) {
                    printf("SEMANTIC ERROR: for statement condition must be of type 'BOOL', instead it is '%s'.\n", conditionType);
                    free(Node);
                    free(forLoopScope);
                    cleanAndCloseFile();
                    exit(1);
                }
            }
            else {
                // check that condition is of type bool using a recursive call
                char* conditionType = checkSemantics(forLoopScope, stack, Node->left->right);
                if (strcmp("BOOL", conditionType) != 0) {
                    printf("SEMANTIC ERROR: for statement condition must be of type 'BOOL', instead it is '%s'.\n", conditionType);
                    free(Node);
                    free(forLoopScope);
                    cleanAndCloseFile();
                    exit(1);
                }

                // finish the 3AC condition print by printing the 'ifz' line 
                asprintf(&line, "\t\tif %s == 0 goto %s", pop(stack), endLabel);
                addLineToFile(line);
            }

            asprintf(&line, "\t%s:", blockLabel);
            addLineToFile(line);

            // handle for block
            checkSemantics(forLoopScope, stack, Node->right->left->left); 

            // check if there is an update statement
            if (Node->left->right->right != NULL) {
                checkSemantics(forLoopScope, stack, Node->left->right->right);
            }
        }
        else { // if there is no var declaration statement then the expression and update pointers are different
            asprintf(&line, "\t%s:", startLabel);
            addLineToFile(line);

            //! check if the condition is complex or simple, and handle both cases accordingly   
            if ((strcmp(Node->left->right->left->token, "||") == 0 )
                || (strcmp(Node->left->right->left->token, "&&") == 0)
                || ((strcmp(Node->left->right->left->token, "( )") == 0) && (strcmp(Node->left->right->left->left->left->token, "&&") == 0))
                || ((strcmp(Node->left->right->left->token, "( )") == 0) && (strcmp(Node->left->right->left->left->left->token, "||") == 0))
                || ((strcmp(Node->left->right->left->token, "( )") == 0) && (strcmp(Node->left->right->left->left->left->token, "( )") == 0) && (strcmp(Node->left->right->left->left->left->left->left->token, "&&") == 0))
                || ((strcmp(Node->left->right->left->token, "( )") == 0) && (strcmp(Node->left->right->left->left->left->token, "( )") == 0) && (strcmp(Node->left->right->left->left->left->left->left->token, "||") == 0))
                || ((strcmp(Node->left->right->left->token, "( )") == 0) && (strcmp(Node->left->right->left->left->left->token, "! (not)") == 0) && (strcmp(Node->left->right->left->left->left->left->left->token, "( )") == 0) && (strcmp(Node->left->right->left->left->left->left->left->left->left->token, "&&") == 0))
                || ((strcmp(Node->left->right->left->token, "( )") == 0) && (strcmp(Node->left->right->left->left->left->token, "! (not)") == 0) && (strcmp(Node->left->right->left->left->left->left->left->token, "( )") == 0) && (strcmp(Node->left->right->left->left->left->left->left->left->left->token, "||") == 0))
                || ((strcmp(Node->left->right->left->token, "( )") == 0) && (strcmp(Node->left->right->left->left->left->token, "( )") == 0) && (strcmp(Node->left->right->left->left->left->left->left->token, "! (not)") == 0) && (strcmp(Node->left->right->left->left->left->left->left->left->left->token, "( )") == 0) && (strcmp(Node->left->right->left->left->left->left->left->left->left->left->left->token, "&&") == 0))
                || ((strcmp(Node->left->right->left->token, "( )") == 0) && (strcmp(Node->left->right->left->left->left->token, "( )") == 0) && (strcmp(Node->left->right->left->left->left->left->left->token, "! (not)") == 0) && (strcmp(Node->left->right->left->left->left->left->left->left->left->token, "( )") == 0) && (strcmp(Node->left->right->left->left->left->left->left->left->left->left->left->token, "&&") == 0))
                || ((strcmp(Node->left->right->left->token, "! (not)") == 0) && (strcmp(Node->left->right->left->left->left->token, "( )") == 0) && (strcmp(Node->left->right->left->left->left->left->left->token, "&&") == 0))
                || ((strcmp(Node->left->right->left->token, "! (not)") == 0) && (strcmp(Node->left->right->left->left->left->token, "( )") == 0) && (strcmp(Node->left->right->left->left->left->left->left->token, "||") == 0))
                || ((strcmp(Node->left->right->left->token, "! (not)") == 0) && (strcmp(Node->left->right->left->left->left->token, "( )") == 0) && (strcmp(Node->left->right->left->left->left->left->left->token, "( )") == 0) && (strcmp(Node->left->right->left->left->left->left->left->left->left->token, "&&") == 0))
                || ((strcmp(Node->left->right->left->token, "! (not)") == 0) && (strcmp(Node->left->right->left->left->left->token, "( )") == 0) && (strcmp(Node->left->right->left->left->left->left->left->token, "( )") == 0) && (strcmp(Node->left->right->left->left->left->left->left->left->left->token, "||") == 0)) 
                ) {

                // push both labels into the stack to be used later
                push(stack, endLabel);
                push(stack, blockLabel);

                // check that condition is of type bool using a recursive call
                char* conditionType = checkSemantics(forLoopScope, stack, Node->left->right);
                if (strcmp("BOOL", conditionType) != 0) {
                    printf("SEMANTIC ERROR: for statement condition must be of type 'BOOL', instead it is '%s'.\n", conditionType);
                    free(Node);
                    free(forLoopScope);
                    cleanAndCloseFile();
                    exit(1);
                }
            }
            else {
                // check that condition is of type bool using a recursive call
                char* conditionType = checkSemantics(forLoopScope, stack, Node->left->right);
                if (strcmp("BOOL", conditionType) != 0) {
                    printf("SEMANTIC ERROR: for statement condition must be of type 'BOOL', instead it is '%s'.\n", conditionType);
                    free(Node);
                    free(forLoopScope);
                    cleanAndCloseFile();
                    exit(1);
                }

                // finish the 3AC condition print by printing the 'ifz' line 
                asprintf(&line, "\t\tif %s == 0 goto %s", pop(stack), endLabel);
                addLineToFile(line);
            }
     
            asprintf(&line, "\t%s:", blockLabel);
            addLineToFile(line);

            // check the semantics of the for loop block
            checkSemantics(forLoopScope, stack, Node->right->left->left);

            // check if there is an update statement
            if (Node->left->right != NULL) {
                checkSemantics(forLoopScope, stack, Node->left->right);
            }
        }

        asprintf(&line, "\t\tgoto %s", startLabel);
        addLineToFile(line);

        asprintf(&line, "\t%s:", endLabel);
        addLineToFile(line);
    }

    else if (strcmp(Node->token, "FOR INIT") == 0) {
        if (strcmp(Node->left->token, "") != 0) // if no more recursion
            checkSemantics(scope, stack, Node->left);
        else { 
            checkSemantics(scope, stack, Node->left->left); // check current item semantics
            checkSemantics(scope, stack, Node->left->right); // recursive call
        }
    }

    else if (strcmp(Node->token, "UPDATE") == 0) {
        // if there is only one update statement without ','
        if (strcmp(Node->left->token, "EXPRESSION") == 0 
            || strcmp(Node->left->token, "ID ASSIGN") == 0) {
            checkSemantics(scope, stack, Node->left);
        }
        else { // if there are multiple update statements seperated by ','
            checkSemantics(scope, stack, Node->left->left); // check the current update statement
            checkSemantics(scope, stack, Node->left->right); // recursive call to the next update statement
        }
    }



    //? * * * * * * Expressions and Other * * * * * * *//

    else if (strcmp(Node->token, "DECLERATION") == 0) {
        checkSemantics(scope, stack, Node->left);
        if (Node->right != NULL)
            checkSemantics(scope, stack, Node->right);
    }

    else if (strcmp(Node->token, "VAR") == 0) { 
        // call a helper function that will go over all the variables that where declared, recursivly, and
        // add them to the scope one by one, also checking their types.
        findAndInitVars(scope, stack, Node->right, Node->left->token);
    }

    else if (strcmp(Node->token, "STRING") == 0) {
        // call a helper function that will go over all the strings that where declared, recursivly, and add them to the scope
        findAndInitStrings(scope, stack, Node->left, Node->token);
    }

    else if (strcmp(Node->token, "ASSIGN") == 0) {
        // recursive call to check and return the type of the assignment value
        return checkSemantics(scope, stack, Node->left);
    }

    else if (strcmp(Node->token, "ID ASSIGN") == 0) {
        char* typeIfFound = NULL;
        Variable* var = NULL;
        LinkedListNode* varNode = makeVarNode(Node->left->token, NULL, NULL);

        var = findVarNodeInScope(scope, varNode);
        if (var == NULL) {
            typeIfFound = findVarInFuncArgs(scope->father, Node->left->token);
            if (typeIfFound != NULL) {
                var = varNode->variable;
                var->type = typeIfFound;
            }
            else {
                printf("SEMANTIC ERROR: identifier '%s' was not found.\n", Node->left->token);
                free(var);
                free(scope);
                cleanAndCloseFile();
                exit(1);
            }
        }

        //! checking for assignment of complex bool statemenets into variables
        if (strcmp(var->type, "BOOL") == 0) {
            
            if ((strcmp(Node->right->left->left->token, "&&") == 0) 
                || (strcmp(Node->right->left->left->token, "||") == 0)
                || ((strcmp(Node->right->left->left->token, "( )") == 0) && (strcmp(Node->right->left->left->left->left->token, "&&") == 0))
                || ((strcmp(Node->right->left->left->token, "( )") == 0) && (strcmp(Node->right->left->left->left->left->token, "||") == 0))
                || ((strcmp(Node->right->left->left->token, "( )") == 0) && (strcmp(Node->right->left->left->left->left->token, "( )") == 0) && (strcmp(Node->right->left->left->left->left->left->left->token, "&&") == 0))
                || ((strcmp(Node->right->left->left->token, "( )") == 0) && (strcmp(Node->right->left->left->left->left->token, "( )") == 0) && (strcmp(Node->right->left->left->left->left->left->left->token, "||") == 0))
                || ((strcmp(Node->right->left->left->token, "! (not)") == 0) && (strcmp(Node->right->left->left->left->left->token, "( )") == 0) && (strcmp(Node->right->left->left->left->left->left->left->token, "&&") == 0))
                || ((strcmp(Node->right->left->left->token, "! (not)") == 0) && (strcmp(Node->right->left->left->left->left->token, "( )") == 0) && (strcmp(Node->right->left->left->left->left->left->left->token, "||") == 0))
                || ((strcmp(Node->right->left->left->token, "! (not)") == 0) && (strcmp(Node->right->left->left->left->left->token, "( )") == 0) && (strcmp(Node->right->left->left->left->left->left->left->token, "( )") == 0) && (strcmp(Node->right->left->left->left->left->left->left->left->left->token, "&&") == 0))
                || ((strcmp(Node->right->left->left->token, "! (not)") == 0) && (strcmp(Node->right->left->left->left->left->token, "( )") == 0) && (strcmp(Node->right->left->left->left->left->left->left->token, "( )") == 0) && (strcmp(Node->right->left->left->left->left->left->left->left->left->token, "||") == 0))
                || ((strcmp(Node->right->left->left->token, "( )") == 0) && (strcmp(Node->right->left->left->left->left->token, "! (not)") == 0) && (strcmp(Node->right->left->left->left->left->left->left->token, "( )") == 0) && (strcmp(Node->right->left->left->left->left->left->left->left->left->token, "&&") == 0))
                || ((strcmp(Node->right->left->left->token, "( )") == 0) && (strcmp(Node->right->left->left->left->left->token, "! (not)") == 0) && (strcmp(Node->right->left->left->left->left->left->left->token, "( )") == 0) && (strcmp(Node->right->left->left->left->left->left->left->left->left->token, "||") == 0))

                ) {

                // sending two labels into the recursive call as well as the var->name to know that we have an assignment
                char* trueLabel = getNextLabel();
                char* falseLabel = getNextLabel();
                push(stack, var->name); 
                push(stack, trueLabel); 
                push(stack, falseLabel); 
            }
        }
        
        // find the type of the variable and if its a pointer there is special attention to the assignmet
        char* foundType = checkSemantics(scope, stack, Node->right);
        
        if (strcmp(Node->right->token, "&ID[]") != 0) { // without this line there is a glitch in the matrix... ¯\_(ツ)_/¯

            if ((strcmp(var->type, "INT*") == 0) || (strcmp(var->type, "DOUBLE*") == 0) || (strcmp(var->type, "FLOAT*") == 0) || (strcmp(var->type, "CHAR*") == 0)) {
                
                // checking for cases such as: &y, (&y)
                if (strcmp(Node->right->left->left->token, "&") == 0
                    || strcmp(Node->right->left->left->left->left->token, "&") == 0) { 

                    // check that the type of the identifier we want to get the address of matches the type of the pointer
                    char* expectedType = checkArithmetics("&", foundType, NULL); //? t0 = x
                    if (expectedType == NULL) {
                        if (strcmp(foundType, "NULL") != 0) {
                            if (strcmp(expectedType, foundType) != 0) {
                                printf("SEMANTIC ERROR: type mismatch at declaration of identifier '%s', expected '%s' but found '%s'.\n", var->name, expectedType, foundType);
                                free(Node);
                                free(scope);
                                cleanAndCloseFile();
                                exit(1);
                            }
                        }
                    }
                    else { // checking for type mismatch error
                        if (strcmp(var->type, expectedType) != 0) {
                            printf("SEMANTIC ERROR: type mismatch at declaration of identifier '%s', expected '%s' but found '%s'.\n", var->name, var->type, expectedType);
                            free(Node);
                            free(scope);
                            cleanAndCloseFile();
                            exit(1);
                        }
                    }

                    //todo: Part 3
                    // pop the result of the recursive call on the right side of the assignment, save the left side token
                    char* rightVal = pop(stack); // gets 't0' from stack
                    char* leftVal = var->name;
                    char* line;

                    // print the assignment 
                    asprintf(&line, "\t\t%s = &%s", leftVal, rightVal);
                    addLineToFile(line);

                    // count the assignment ONLY if we havn't counted that variable before 
                    if (var->flag == 0) {
                        incrementFunctionSize(var->type);
                        var->flag = 1;
                    }

                    free(rightVal);
                    free(line);
                    return NULL;
                }
                else if (strcmp(foundType, "NULL") == 0) {
                    return NULL;
                }
            }
        }

        // checking for mismatch error in a general case when the left side operand is not a pointer
        if (strcmp(var->type, foundType) != 0) {
            printf("SEMANTIC ERROR: type mismatch for identifier '%s', expected '%s' but found '%s'.\n", Node->left->token, var->type, foundType);
            free(var);
            free(scope);
            cleanAndCloseFile();
            exit(1);
        }

        //todo: Part 3
        // pop the result of the recursive call on the right side of the assignment, save the left side token
        char* rightVal = pop(stack);
        char* leftVal = var->name;
        char* temp;

        // print the assignment 
        asprintf(&temp, "\t\t%s = %s", leftVal, rightVal);
        addLineToFile(temp);

        // count the assignment ONLY if we havn't counted that variable before 
        if (var->flag == 0) {
            incrementFunctionSize(var->type);
            var->flag = 1;
        }

        free(rightVal);
        free(temp);
    }
    
    else if (strcmp(Node->token, "* ID ASSIGN") == 0) {
        // find var in current scope and then in func args
        char* typeIfFound;
        LinkedListNode* varNode = makeVarNode(Node->left->token, NULL, NULL);
        Variable* var = findVarNodeInScope(scope, varNode);
        if (var == NULL) {
            typeIfFound = findVarInFuncArgs(scope->father, Node->left->token);
            if (typeIfFound != NULL) {
                var = varNode->variable;
                var->type = typeIfFound;
            }
            else {
                printf("SEMANTIC ERROR: identifier '%s' was not found.\n", Node->left->token);
                free(var);
                free(scope);
                cleanAndCloseFile();
                exit(1);
            }
        }
        else if (strcmp(var->type, "STRING") == 0) { // check if the variable is of type string
            printf("SEMANTIC ERROR: type mismatch on identifier '*%s', cannot use '*' operator on identifiers of type 'STRING'.\n", var->name);
            free(Node);
            free(scope);
            cleanAndCloseFile();
            exit(1);
        }

        //check if given type is of type pointer and if so we need to check its value type
        char* foundType = checkSemantics(scope, stack, Node->right); //pushes into stack: push("*c");

        // getting the expected type of '*' operator on the variable using a helper function checkArithmetics
        char* expectedType = checkArithmetics("*", var->type, NULL);
        if (expectedType != NULL) {
            if ((strcmp(foundType, "NULL") == 0) || (strcmp(expectedType, foundType) != 0)) {
                printf("SEMANTIC ERROR: type mismatch at declaration of identifier '*%s', expected '%s' but found '%s'.\n", var->name, expectedType, foundType);
                free(Node);
                free(scope);
                cleanAndCloseFile();
                exit(1);
            }
        }

        //todo: Part 3
        // pop the result of the recursive call on the right side of the assignment, save the left side token
        char* rightVal = pop(stack);
        char* leftVal = var->name;
        char* temp;

        // print the assignment 
        asprintf(&temp, "\t\t*%s = %s", leftVal, rightVal);
        addLineToFile(temp);

        // count the assignment ONLY if we havn't counted that variable before 
        if (var->flag == 0) {
            incrementFunctionSize(var->type);
            var->flag = 1;
        }

        free(rightVal);
        free(temp);
    }

    else if (strcmp(Node->token, "ASSIGN[]") == 0) {
        // find the variable in the scopes
        LinkedListNode* varNode = makeVarNode(Node->left->left->token, NULL, NULL);
        Variable* var = findVarNodeInScope(scope, varNode);
        if (var == NULL) {
            printf("SEMANTIC ERROR: identifier '%s' was not found.\n", Node->left->token);
            free(var);
            free(scope);
            cleanAndCloseFile();
            exit(1);
        }

        // check that the id is of type string
        if (strcmp(var->type, "STRING") != 0) {
            printf("SEMANTIC ERROR: can't assign index value to identifier of type '%s', it is only possible for type 'STRING'.\n", var->type);
            free(Node);
            free(scope);
            cleanAndCloseFile();
            exit(1);
        }
        
        // check that expression is of type int 
        char* indexType = checkSemantics(scope, stack, Node->left->right); //? t0 = 5
        if (strcmp(indexType, "INT") != 0) {
            printf("SEMANTIC ERROR: string size of identifier '%s' must be of type 'INT', but found '%s'.\n", var->name, indexType);
            free(Node);
            free(scope);
            cleanAndCloseFile();
            exit(1); 
        }

        // check that string size is not an expression but a simple value to check if that index is valid
        if ((Node->left->right->left->token != NULL) && (strcmp(Node->left->right->left->token, "VALUE") == 0) && 
            (Node->left->right->left->right == NULL) && (Node->left->right->left->left != NULL))  { // the pointers help against segmenration faults
            
            // check that index expression is less than or equal to the declared length and that its not negative
            int indexValue = atoi(Node->left->right->left->left->left->token);
            if (indexValue < 0) {
                printf("SEMANTIC ERROR: index is out of bounds for identifier '%s', index '%d' is invalid.\n", var->name, indexValue);
                free(Node);
                free(scope);
                cleanAndCloseFile();
                exit(1); 
            }
            
            if (var->len != NULL) {
                int maxStringLen = atoi(var->len);
                if (indexValue > maxStringLen) {
                    printf("SEMANTIC ERROR: index is out of bounds for identifier '%s', expected index <= '%d' but found index '%d'.\n", var->name, maxStringLen, indexValue);
                    free(Node);
                    free(scope);
                    cleanAndCloseFile();
                    exit(1); 
                }
            }
        }

        //todo: Part 3
        // temp var for printing into the file
        char* line;
        // print the pointer to the string start
        char* nextVarTemp1 = getNextVar();
        asprintf(&line, "\t\t%s = %s", nextVarTemp1, var->name); //? t1 = message
        addLineToFile(line);

        // print the 't' that will hold the address of the string with the offset
        char* nextVarTemp2 = getNextVar();
        asprintf(&line, "\t\t%s = %s + %s", nextVarTemp2, nextVarTemp1, pop(stack)); //? t2 = t1 + t0
        addLineToFile(line);

        // check that if we assing an id then it is of type char
        char* assignemtType = checkSemantics(scope, stack, Node->right->left); //? t3 = 'c'
        if ((strcmp("NULL",assignemtType) != 0) && (strcmp("CHAR", assignemtType) != 0)) {
            printf("SEMANTIC ERROR: type mismatch for identifier '%s', expected 'CHAR' or 'NULL' but found '%s'.\n", var->name, assignemtType);
            free(Node);
            free(scope);
            cleanAndCloseFile();
            exit(1);
        }

        // print the acctual assignment into the string index
        asprintf(&line, "\t\t*%s = %s", nextVarTemp2, pop(stack)); //? *t2 = t3
        addLineToFile(line);
        free(line);
    }

    else if (strcmp(Node->token, "&ID[]") == 0) {
        // find the variable in the scopes
        LinkedListNode* varNode = makeVarNode(Node->left->left->token, NULL, NULL);
        Variable* var = findVarNodeInScope(scope, varNode);
        if (var == NULL) {
            printf("SEMANTIC ERROR: identifier '%s' was not found.\n", Node->left->left->token);
            free(var);
            free(scope);
            cleanAndCloseFile();
            exit(1);
        }

        // check that the id is of type string
        if (strcmp(var->type, "STRING") != 0) {
            printf("SEMANTIC ERROR: can't assign index value to identifier of type '%s', it is only possible for type 'STRING'.\n", var->type);
            free(Node);
            free(scope);
            cleanAndCloseFile();
            exit(1);
        }

        // check that expression is of type int
        char* indexType = checkSemantics(scope, stack, Node->left->right); //? t0 = 7
        if (strcmp(indexType, "INT") != 0) {
            printf("SEMANTIC ERROR: string size of identifier '%s' must be of type 'INT', but found '%s'.\n", var->name, indexType);
            free(Node);
            free(scope);
            cleanAndCloseFile();
            exit(1); 
        }

        // check that string size is not an expression but a simple value to check if that index is valid
        if ((Node->left->right->left->token != NULL) && (strcmp(Node->left->right->left->token, "VALUE") == 0) && 
            (Node->left->right->left->right == NULL) && (Node->left->right->left->left != NULL))  { // the pointers help against segmenration faults

            // check that index expression is less than or equal to the declared length and that its not negative
            int indexValue = atoi(Node->left->right->left->left->left->token);
            if (indexValue < 0) {
                printf("SEMANTIC ERROR: index is out of bounds for identifier '%s', index '%d' is invalid.\n", var->name, indexValue);
                free(Node);
                free(scope);
                cleanAndCloseFile();
                exit(1); 
            }

            if (var->len != NULL) {
                int maxStringLen = atoi(var->len);
                if (indexValue > maxStringLen) {
                    printf("SEMANTIC ERROR: index is out of bounds for identifier '%s', expected index <= '%d' but found index '%d'.\n", var->name, maxStringLen, indexValue);
                    free(Node);
                    free(scope);
                    cleanAndCloseFile();
                    exit(1); 
                }
            }
        }

        //todo: Part 3
        // temp var for printing into the file
        char* line;
        // print the pointer to the string start
        char* nextVarTemp1 = getNextVar();
        asprintf(&line, "\t\t%s = %s", nextVarTemp1, var->name); //? t1 = password
        addLineToFile(line);

        // print the 't' that will hold the address of the string with the offset
        char* nextVarTemp2 = getNextVar();
        asprintf(&line, "\t\t%s = %s + %s", nextVarTemp2, nextVarTemp1, pop(stack)); //? t2 = t1 + t0
        addLineToFile(line);
        free(line);

        // push the last temp var that holds the value in the string offset to be used later
        push(stack, nextVarTemp2);
        printf("top = %s\n", peek(stack));

        return "CHAR*";
    }



    else if (strcmp(Node->token, "EXPRESSION") == 0) { // 🛑 🛑 🛑 🛑 🛑 🛑  EXPRESSION  🛑 🛑 🛑 🛑 🛑 🛑 //
        // expressions have many options...

        if (strcmp(Node->left->token, "NULL") == 0) {
            //todo: Part 3
            char* nextVarTemp = getNextVar();
            char *temp; 
            asprintf(&temp, "\t\t%s = %s", nextVarTemp, "NULL");
            addLineToFile(temp);
            push(stack, nextVarTemp);
            
            return "NULL";
        }

        else if (strcmp(Node->left->token, "&") == 0) { 
            char* type = checkSemantics(scope, stack, Node->left->left); //? t0 = a 
            if ((strcmp(type, "INT*") == 0) || (strcmp(type, "FLOAT*") == 0) || (strcmp(type, "DOUBLE*") == 0) || (strcmp(type, "CHAR*") == 0)) {
                printf("SEMANTIC ERROR: using '&' on identifier of type '%s' is undefined.\n", type);
                free(Node);
                free(scope);
                cleanAndCloseFile();
                exit(1);
            }
            return type;
        }

        else if (strcmp(Node->left->token, "* (pointer)") == 0) { 
            // checking that the type under the '*' is correct
            char* type = checkSemantics(scope, stack, Node->left->left);
            if ((strcmp(type, "INT") == 0) || (strcmp(type, "FLOAT") == 0) || (strcmp(type, "DOUBLE") == 0) || (strcmp(type, "CHAR") == 0) || (strcmp(type, "BOOL") == 0)) {
                printf("SEMANTIC ERROR: using '*' on identifier of type '%s' is undefined.\n", type);
                free(Node);
                free(scope);
                cleanAndCloseFile();
                exit(1);
            }

            //todo: Part 3
            // add the '*' to the variable so that we will print it correctly in the recursive call
            char* nextVarTemp = getNextVar();
            char *line; 
            asprintf(&line, "\t\t%s = *%s", nextVarTemp, pop(stack));
            addLineToFile(line);
            push(stack, nextVarTemp); 

            // add the '*' to the variable so that we will print it correctly in the recursive call
            // push(stack, concat("*", pop(stack))); 

            return checkArithmetics("*", type, NULL); // returning the correct value using a helper function
        }

        else if (strcmp(Node->left->left->token, "FUNCTION CALL") == 0) {
            // recursivly calling the checkSemantics function because it already has a solution to it (outside of expressions)
            return checkSemantics(scope, stack, Node->left->left);
        }

        else if (strcmp(Node->left->token, "ID[]") == 0) {
            // find the variable in the scopes
            LinkedListNode* varNode = makeVarNode(Node->left->left->left->token, NULL, NULL);
            Variable* var = findVarNodeInScope(scope, varNode);
            if (var == NULL) {
                printf("SEMANTIC ERROR: identifier '%s' was not found.\n", Node->left->left->left->token);
                free(var);
                free(scope);
                cleanAndCloseFile();
                exit(1);
            }

            // check that the id is of type string
            if (strcmp(var->type, "STRING") != 0) {
                printf("SEMANTIC ERROR: can't assign index value to identifier of type '%s', it is only possible for type 'STRING'.\n", var->type);
                free(Node);
                free(scope);
                cleanAndCloseFile();
                exit(1);
            }

            // check that expression is of type int
            char* indexType = checkSemantics(scope, stack, Node->left->left->right);
            if (strcmp(indexType, "INT") != 0) {
                printf("SEMANTIC ERROR: string size of identifier '%s' must be of type 'INT', but found '%s'.\n", var->name, indexType);
                free(Node);
                free(scope);
                cleanAndCloseFile();
                exit(1); 
            }

            //todo: Part 3
            // temp var for printing into the file
            char* line;
            // print the pointer to the string start
            char* nextVarTemp1 = getNextVar();
            asprintf(&line, "\t\t%s = %s", nextVarTemp1, var->name); //? t1 = password
            addLineToFile(line);

            // print the 't' that will hold the address of the string with the offset
            char* nextVarTemp2 = getNextVar();
            asprintf(&line, "\t\t%s = %s + %s", nextVarTemp2, nextVarTemp1, pop(stack)); //? t2 = t1 + t0
            addLineToFile(line);

            // print the 't' that holds the value of the string at the given offset
            char* nextVarTemp3 = getNextVar();
            asprintf(&line, "\t\t%s = *%s", nextVarTemp3, nextVarTemp2); //? t3 = *t2
            addLineToFile(line);
            free(line);

            // push the last temp var that holds the value in the string offset to be used later
            push(stack, nextVarTemp3);
            
            return "CHAR"; 
        }

        else if (strcmp(Node->left->left->token, "ID") == 0) {
            // try to find var in a function argument
            char* typeIfFound;
            LinkedListNode* varNode = makeVarNode(Node->left->left->left->token, NULL, NULL);
            Variable* var = findVarNodeInScope(scope, varNode);
            if (var == NULL) {
                typeIfFound = findVarInFuncArgs(scope->father, Node->left->left->left->token);
                if (typeIfFound != NULL) {
                    var = varNode->variable;
                    var->type = typeIfFound;
                }
                else {
                    printf("SEMANTIC ERROR: identifier '%s' was not found.\n", Node->left->left->left->token);
                    free(var);
                    free(scope);
                    cleanAndCloseFile();
                    exit(1);
                }
            }

            //todo: Part 3
            // push the id value to the stack to be used later
            push(stack, Node->left->left->left->token);

            return var->type;
        }

        else if (strcmp(Node->left->token, "VALUE") == 0) {
            //todo: Part 3
            // create a new temporary variable t, and check if we need to print a label
            char* nextVarTemp = getNextVar();
            char *temp; 
            char* value = Node->left->left->left->token;

            asprintf(&temp, "\t\t%s = %s", nextVarTemp, value);
            addLineToFile(temp);

            // push the new temp var to the stack to be used later
            push(stack, nextVarTemp);

            incrementFunctionSize(Node->left->left->token);
            
            return Node->left->left->token; //* this is the type of the value from yacc
        }

        else if (strcmp(Node->left->token, "( )") == 0) {
            return checkSemantics(scope, stack, Node->left->left); 
        }

        else if (strcmp(Node->left->token, "| |") == 0) {
            // checking the type of the value inside the '| |' operator
            char* type = checkSemantics(scope, stack, Node->left->left);
            char* resType = checkArithmetics("||", type, NULL);
            if (resType == NULL) {
                printf("SEMANTIC ERROR: type mismatch on '%s' operator, expected expression of type 'STRING', but found '%s'.\n", Node->left->token, type);
                free(scope);
                cleanAndCloseFile();
                exit(1);
            }

            //todo: Part 3
            // find the string in the scope inorder to get it's length
            LinkedListNode* varNode = makeVarNode(Node->left->left->left->left->left->token, "STRING", NULL);
            Variable* var = findVarNodeInScope(scope, varNode);

            // create a new temp var
            char* tempVar = getNextVar();
            char* line;

            // print the assignment of the string length
            asprintf(&line, "\t\t%s = %s", tempVar, var->len);
            addLineToFile(line);

            // push the temp var to the stack to be used later
            push(stack, tempVar);
            free(line);
            return resType;
        }
        else if (strcmp(Node->left->token, "! (not)") == 0) {
            //todo: Part 3
            // checking for complex bool statemenets into variables
            if ((strcmp(Node->left->left->left->token, "&&") == 0) 
                || (strcmp(Node->left->left->left->token, "||") == 0)
                || ((strcmp(Node->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->token, "&&") == 0))
                || ((strcmp(Node->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->token, "||") == 0))
                || ((strcmp(Node->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->left->left->token, "&&") == 0))
                || ((strcmp(Node->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->token, "( )") == 0) && (strcmp(Node->left->left->left->left->left->left->left->token, "&&") == 0))) {
                
                // pushing '!' into the stack to be used as a flag, such that the conditions will check it and print it
                push(stack, "!"); 

                // checking the type of the value under the '!' operator
                char* type = checkSemantics(scope, stack, Node->left->left);
                
                char* resType = checkArithmetics("!", type, NULL);
                if (resType == NULL) {
                    printf("SEMANTIC ERROR: type mismatch on '%s' operator, expected expression of type 'BOOL', but found '%s'.\n", Node->left->token, type);
                    free(scope);
                    cleanAndCloseFile();
                    exit(1);
                }
                return resType;
            }
            else {
                // checking the type of the value under the '!' operator
                char* type = checkSemantics(scope, stack, Node->left->left);
                char* line;
                if ((stack != NULL) && (peek(stack)[0] != 'L')) {
                    char* temp = pop(stack);
                    char* tempVar = getNextVar();
                    asprintf(&line, "\t\t%s = !%s", tempVar, temp);
                    addLineToFile(line);
                    push(stack, tempVar);
                }

                char* resType = checkArithmetics("!", type, NULL);
                if (resType == NULL) {
                    printf("SEMANTIC ERROR: type mismatch on '%s' operator, expected expression of type 'BOOL', but found '%s'.\n", Node->left->token, type);
                    free(scope);
                    cleanAndCloseFile();
                    exit(1);
                }
                return resType;
            }

        }
        else if (strcmp(Node->left->token, "+") == 0
                || strcmp(Node->left->token, "-") == 0
                || strcmp(Node->left->token, "*") == 0
                || strcmp(Node->left->token, "/") == 0) {

            // check explicit division by zero
            if (strcmp(Node->left->token, "/") == 0) {
                if (strcmp(Node->left->right->left->left->left->token, "0") == 0) {
                    printf("SEMANTIC ERROR: division by zero detected.\n");
                    free(scope);
                    cleanAndCloseFile();
                    exit(1);
                }
            }

            // using a helper function to check if the aritmetic expression is correct and valid by checking the types of the operands
            char* leftType = checkSemantics(scope, stack, Node->left->left);
            char* rightType = checkSemantics(scope, stack, Node->left->right);
            char* resType = checkArithmetics(Node->left->token, leftType, rightType);
            if (resType == NULL) {
                printf("SEMANTIC ERROR: type mismatch on '%s' operator.\n", Node->left->token);
                free(scope);
                cleanAndCloseFile();
                exit(1);
            } 

            //todo: Part 3
            // pop right and then left sides of the operator from the stack and get the operator from AST
            char* rightVal = pop(stack);
            char* leftVal = pop(stack);
            char* opVal = Node->left->token;

            // create a new temp var
            char* tempVar = getNextVar();
            char* computeLine;

            // print the condition: t0 = a + b
            asprintf(&computeLine, "\t\t%s = %s %s %s", tempVar, leftVal, opVal, rightVal);
            addLineToFile(computeLine);
            
            incrementFunctionSize(resType);

            // push the temp var to the stack to be used later
            push(stack, tempVar);
            free(computeLine);
            free(rightVal);
            free(leftVal);

            return resType;
        }
        else if (strcmp(Node->left->token, "<") == 0
                || strcmp(Node->left->token, "<=") == 0
                || strcmp(Node->left->token, ">") == 0
                || strcmp(Node->left->token, ">=") == 0
                || strcmp(Node->left->token, "==") == 0
                || strcmp(Node->left->token, "!=") == 0) {

            // check explicit division by zero
            if (strcmp(Node->left->token, "/") == 0) {
                if (strcmp(Node->left->right->left->left->left->token, "0") == 0) {
                    printf("SEMANTIC ERROR: division by zero detected.\n");
                    free(scope);
                    cleanAndCloseFile();
                    exit(1);
                }
            }

            // using a helper function to check if the aritmetic expression is correct and valid by checking the types of the operands
            char* leftType = checkSemantics(scope, stack, Node->left->left);
            char* rightType = checkSemantics(scope, stack, Node->left->right);
            char* resType = checkArithmetics(Node->left->token, leftType, rightType);
            if (resType == NULL) {
                printf("SEMANTIC ERROR: type mismatch on '%s' operator.\n", Node->left->token);
                free(scope);
                cleanAndCloseFile();
                exit(1);
            } 

            //todo: Part 3
            // pop right and then left sides of the operator from the stack and get the operator from AST
            char* rightVal = pop(stack);
            char* leftVal = pop(stack);
            char* opVal = Node->left->token;

            // create a new temp var
            char* tempVar = getNextVar();
            char* computeLine;

            // print the condition: t0 = a < b
            asprintf(&computeLine, "\t\t%s = %s %s %s", tempVar, leftVal, opVal, rightVal);
            addLineToFile(computeLine);
            incrementFunctionSize(resType); // counting the t that holds the condition result 

            // push the temp var to the stack to be used later
            push(stack, tempVar);
            free(computeLine);
            free(rightVal);
            free(leftVal);  
            return resType;
        }
        else if (strcmp(Node->left->token, "&&") == 0) {
            char* line;
            char* variable = NULL;
            int isNotFlag = 0;
            if ((stack != NULL) && (peek(stack) != NULL) && (peek(stack)[0] != 'L') && (peek(stack)[0] == '!')) { 
                //! checks for the end of the recursion
                if ((strcmp(Node->left->right->left->token, "&&") != 0)) {
                    pop(stack);
                    isNotFlag = 1;
                }
                else {
                    isNotFlag = 0; 
                }
            }
            char* trueLabel = getNextLabel();
            char* falseLabel = NULL;
            char* ifLabel = pop(stack); // get the labels out of the stack
            char* elseLabel = pop(stack);
            
            if ((stack != NULL) && (peek(stack) != NULL) && (peek(stack)[0] != 'L') && (peek(stack)[0] != '!') && (peek(stack)[0] != 't')) {
                variable = pop(stack);
            }

            //* checking if the LEFT side has a complex condition, in that case we want to push the trueLabel such that if the left condition is true it will know to jump to the right side of the '&&' and not to the 'IF'
            if ((Node->left->left->left != NULL) && 
                    ((strcmp(Node->left->left->left->token, "( )") == 0)
                    && ((strcmp(Node->left->left->left->left->left->token, "||") == 0)
                        || (strcmp(Node->left->left->left->left->left->token, "&&") == 0)))
                ) { 
                push(stack, elseLabel);   
                push(stack, trueLabel);
            }
            else {
                push(stack, elseLabel);   
                push(stack, ifLabel);
            }

            // checking the left side type recursively
            char* leftType = checkSemantics(scope, stack, Node->left->left);

            // print labels to the file
            if (peek(stack)[0] != 'L') {
                asprintf(&line, "\t\tif %s goto %s", pop(stack), trueLabel);
                addLineToFile(line);
                asprintf(&line, "\t\tgoto %s", elseLabel);
                addLineToFile(line);   
            }
            asprintf(&line, "\t%s:", trueLabel);
            addLineToFile(line); 

            if ((strcmp(Node->left->right->left->token, "&&") == 0)
                || (strcmp(Node->left->right->left->token, "( )") == 0)) {
                trueLabel = pop(stack);
                push(stack, ifLabel);
            }

            // checking the right side type recursively
            char* rightType = checkSemantics(scope, stack, Node->left->right);
           
            // print labels to the file
            if ((stack != NULL) && (peek(stack)[0] != 'L') ) {
                if ( (isNotFlag == 0) && (strcmp(ifLabel, "!") != 0) ) {
                    asprintf(&line, "\t\tif %s goto %s", pop(stack), ifLabel);
                    addLineToFile(line); 
                    asprintf(&line, "\t\tgoto %s", elseLabel);
                    addLineToFile(line); 
                    
                } else if (isNotFlag == 1) {
                    //! print not on last condition to the file
                    char* popVal = pop(stack);
                    char* nextTempVar = getNextVar();
                    asprintf(&line, "\t\t%s = !%s", nextTempVar, popVal);
                    addLineToFile(line);
                    asprintf(&line, "\t\tif %s goto %s", nextTempVar, ifLabel);
                    addLineToFile(line); 
                    asprintf(&line, "\t\tgoto %s", elseLabel);
                    addLineToFile(line); 
                    push(stack, nextTempVar);
                }
            }

            if (variable != NULL) {
                if (isNotFlag == 1) {
                    //! print not on last condition to the file
                    char* popVal = pop(stack);
                    asprintf(&line, "\t\tif %s goto %s", popVal, ifLabel);
                    addLineToFile(line); 
                    asprintf(&line, "\t\tgoto %s", elseLabel);
                    addLineToFile(line); 
                    push(stack, popVal);
                }
                char* nextLabel = getNextLabel();
                char* nextTempVar = getNextVar();
                asprintf(&line, "\t%s:", ifLabel);
                addLineToFile(line);  
                asprintf(&line, "\t\t%s = true", nextTempVar);
                addLineToFile(line); 
                asprintf(&line, "\t\tgoto %s", nextLabel);
                addLineToFile(line); 
                asprintf(&line, "\t%s:", elseLabel);
                addLineToFile(line); 
                asprintf(&line, "\t\t%s = false", nextTempVar);
                addLineToFile(line); 
                asprintf(&line, "\t%s:", nextLabel);
                addLineToFile(line);
                push(stack, nextTempVar);
            }
            
            // using a helper function to check if the aritmetic expression is correct and valid by checking the types of the operands
            char* resType = checkArithmetics(Node->left->token, leftType, rightType);
            if (resType == NULL) {
                printf("SEMANTIC ERROR: type mismatch on '%s' operator.\n", Node->left->token);
                free(scope);
                cleanAndCloseFile();
                exit(1);
            } 

            // return the result type of this '&&' condition as part of the semantic checks
            return resType;
        }
        else if (strcmp(Node->left->token, "||") == 0) {
            char* line;
            char* variable = NULL;
            int isNotFlag = 0;
            if ((stack != NULL) && (peek(stack) != NULL) && (peek(stack)[0] != 'L') && (peek(stack)[0] == '!')) { 
                //! checks for the end of the recursion
                if ((strcmp(Node->left->right->left->token, "||") != 0)) {
                    pop(stack);
                    isNotFlag = 1;
                }
                else {
                    isNotFlag = 0; 
                }
            }
            char* trueLabel = NULL;
            char* falseLabel = NULL;
            char* ifLabel = pop(stack);
            char* elseLabel = pop(stack);

            if ((stack != NULL) && (peek(stack) != NULL) && (peek(stack)[0] != 'L') && (peek(stack)[0] != '!') && (peek(stack)[0] != 't'))
                variable = pop(stack);
            
            //* check if there is an '&&' on the LEFT side, if so then push the falseLabel into the stack instead of the original elseLabel, that way the left side will know to jump to the next condition in line correctly
            if ((strcmp(Node->left->left->left->token, "&&") == 0)
                || ((strcmp(Node->left->left->left->token, "( )") == 0)
                    )) {
                falseLabel = getNextLabel();
                push(stack, falseLabel);
            }
            else {
                push(stack, elseLabel);
            }

            if ((strcmp(Node->left->left->left->token, "( )") == 0)
                && (strcmp(Node->left->left->left->left->left->token, "&&") == 0)) {
                trueLabel = getNextLabel();
                push(stack, trueLabel);
            }
            else {
                push(stack, ifLabel);
            }
   
            // checking the left side type recursively
            char* leftType = checkSemantics(scope, stack, Node->left->left);
        
            if ((stack != NULL) && (peek(stack) != NULL) && (peek(stack)[0] != 'L') && (peek(stack)[0] != '!') && (peek(stack)[0] == 't')) {
                if (strcmp(ifLabel, "!") == 0) {
                    asprintf(&line, "\t\tif %s goto %s", pop(stack), elseLabel);
                    addLineToFile(line);
                }
                else {
                    asprintf(&line, "\t\tif %s goto %s", pop(stack), ifLabel);
                    addLineToFile(line);
                }
            }

            // print the false label if it exists
            if (falseLabel != NULL) {
                asprintf(&line, "\t%s:", falseLabel);
                addLineToFile(line); 
            }

            //! checks for not in the stack
            if ((stack != NULL) && (peek(stack) != NULL) && (peek(stack)[0] != 'L') && (peek(stack)[0] == '!')) {
                pop(stack);
                ifLabel = pop(stack);
                falseLabel = pop(stack);
                push(stack, elseLabel);
                push(stack, ifLabel);
                push(stack, "!");
            }
            else { //! if there is no not
                ifLabel = pop(stack);
                falseLabel = pop(stack);
                push(stack, elseLabel);
                push(stack, ifLabel);
            }

  
            // checking the right side type recursively
            char* rightType = checkSemantics(scope, stack, Node->left->right);

            //! print labels to the file
            if ((stack != NULL) && (peek(stack)[0] != 'L') ) {
                if ( (isNotFlag == 0) && (strcmp(ifLabel, "!") != 0) ) {
                    asprintf(&line, "\t\tif %s goto %s", pop(stack), ifLabel);
                    addLineToFile(line); 
                    asprintf(&line, "\t\tgoto %s", elseLabel);
                    addLineToFile(line); 
                    
                } else if (isNotFlag == 1) {
                    // print labels to the file
                    char* popVal = pop(stack);
                    char* nextTempVar = getNextVar();
                    asprintf(&line, "\t\t%s = !%s", nextTempVar, popVal);
                    addLineToFile(line);
                    asprintf(&line, "\t\tif %s goto %s", nextTempVar, ifLabel);
                    addLineToFile(line); 
                    asprintf(&line, "\t\tgoto %s", elseLabel);
                    addLineToFile(line); 
                    push(stack, nextTempVar);
                }
            }

            if (trueLabel != NULL) {
                asprintf(&line, "\t%s:", trueLabel);
                addLineToFile(line); 
            }

            
            if (variable != NULL) {
                char* nextLabel = getNextLabel();
                char* nextTempVar = getNextVar();
                if (isNotFlag == 1) {
                    char* popVal = pop(stack);
                    asprintf(&line, "\t\tif %s goto %s", popVal, ifLabel);
                    addLineToFile(line); 
                    asprintf(&line, "\t\tgoto %s", elseLabel);
                    addLineToFile(line); 
                    push(stack, popVal);
                }
                if (trueLabel == NULL) {
                    asprintf(&line, "\t%s:", ifLabel);
                    addLineToFile(line); 
                } 
                asprintf(&line, "\t\t%s = true", nextTempVar);
                addLineToFile(line); 
                asprintf(&line, "\t\tgoto %s", nextLabel);
                addLineToFile(line); 
                asprintf(&line, "\t%s:", elseLabel);
                addLineToFile(line); 
                asprintf(&line, "\t\t%s = false", nextTempVar);
                addLineToFile(line); 
                asprintf(&line, "\t%s:", nextLabel);
                addLineToFile(line);
                push(stack, nextTempVar);
            }

            // using a helper function to check if the aritmetic expression is correct and valid by checking the types of the operands
            char* resType = checkArithmetics(Node->left->token, leftType, rightType);
            if (resType == NULL) {
                printf("SEMANTIC ERROR: type mismatch on '%s' operator.\n", Node->left->token);
                free(scope);
                cleanAndCloseFile();
                exit(1);
            } 

            // return the result type of this '||' condition as part of the semantic checks
            return resType;
        }
    }


    else if (strcmp(Node->token, "FUNCTION CALL") == 0) {
        // finding the function that was called in the scopes
        LinkedListNode* funcNode = makeFuncNode(Node->left->token, NULL, -1, -1);
        Function* func = findFuncNodeInScope(scope, funcNode);
        if (func == NULL) {
            printf("SEMANTIC ERROR: function '%s' is not declared.\n", funcNode->function->name);
            free(funcNode);
            free(scope);
            cleanAndCloseFile();
            exit(1);
        }

        // checking if we can call that function from our current function
        Scope* scopePtr = NULL; // getting the address of the scope that holds the current function
        Function* currentFunction = getCurrentFunction(scope, &scopePtr);

        // checking that the static declerations match
        if (currentFunction->isStatic == 1 && func->isStatic == 0) {
            printf("SEMANTIC ERROR: static function '%s' cannot call a non-static function '%s'\n", currentFunction->name, func->name);
            cleanAndCloseFile();
            exit(1);
        }

        // checking that the private/public declerations match
        if (currentFunction->isPrivate == 0 && func->isPrivate == 1) {
            // finding the function that is been called in the scope of the function from which the call is been made, thats why: 'scopePtr'
            Function* funcInCurrentScope = findFuncNodeUntillGivenScope(scope, scopePtr, funcNode->function->name);    
            if (funcInCurrentScope == NULL) {
                printf("SEMANTIC ERROR: public function '%s' cannot call a private function '%s' because they are not in the same scope.\n", currentFunction->name, func->name);
                cleanAndCloseFile();
                exit(1);
            } 
        }

        // temp variable for printing lines into the file, part of Part 3, used in the following IF statement
        char *line;

        if ((func->countArgs != 0) && (Node->right == NULL)) {
            printf("SEMANTIC ERROR: function '%s' expects '%d' arguments, but no arguments were given.\n", funcNode->function->name, func->countArgs);
            free(funcNode);
            free(scope);
            cleanAndCloseFile();
            exit(1); 
        }

        // checking if the function needs to get any params
        if (Node->right != NULL) { // has params
            node* temp = Node->right;
            int paramCounter = 0;

            do {
                // checking if the number of arduments is correct
                if (paramCounter == func->countArgs) {
                    printf("SEMANTIC ERROR: too many arguments in function call '%s()'\n", funcNode->function->name);
                    free(funcNode);
                    free(scope);
                    cleanAndCloseFile();
                    exit(1); 
                }

                // checking that the param types are correct
                char* paramType = checkSemantics(scope, stack, temp);
                if (strcmp(paramType, func->args[paramCounter]->type) != 0) {
                    printf("SEMANTIC ERROR: param type mismatch in function call '%s()' on param '%s'\n",
                        funcNode->function->name, func->args[paramCounter]->name);
                    free(funcNode);
                    free(scope);
                    cleanAndCloseFile();
                    exit(1); 
                }

                paramCounter++;
                temp = temp->right;
            } while (temp != NULL);

            // checking if the number of arduments is correct
            if (paramCounter < func->countArgs) {
                printf("SEMANTIC ERROR: too few arguments in function call '%s()'\n", funcNode->function->name);
                free(funcNode);
                free(scope);
                cleanAndCloseFile();
                exit(1); 
            }

            //todo: Part 3
            // go over the func params from back to start and print: PushParam x

            // print PushParam based on the amount of the params we need to send to the function
            for (int i = paramCounter-1; i >= 0; i--) {
                char* arg = pop(stack);
                asprintf(&line, "\t\tPushParam %s", arg);
                addLineToFile(line);
            }

            // print the correct LCall based on the return type of the function
            if (strcmp(func->returnType, "VOID") == 0) {
                asprintf(&line, "\t\tLCall %s", func->name);
                addLineToFile(line);
            }
            else {
                char* t = getNextVar();
                asprintf(&line, "\t\t%s = LCall %s", t, func->name);
                addLineToFile(line);
                push(stack, t);
                incrementFunctionSize(func->returnType);
            }

            // print the PopParams based on the amount of argument the function received
            int totalArgsValue = 0;
            for (int i = 0; i < paramCounter; i++) {
                totalArgsValue = totalArgsValue + incrementFunctionSize(func->args[i]->type);
            }
            funcSize -= totalArgsValue; //* since the increment function automaticali updates the funcSize, we want to use its if-else statement but not increment
            asprintf(&line, "\t\tPopParams %d", totalArgsValue);
            addLineToFile(line);
        }
        else { // if there are NO aguments to the function
            
            //todo: Part 3
            // print the correct LCall based on the return type of the function
            if (strcmp(func->returnType, "VOID") == 0) {
                asprintf(&line, "\t\tLCall %s", func->name);
                addLineToFile(line);
            }
            else {
                char* t = getNextVar();
                asprintf(&line, "\t\t%s = LCall %s", t, func->name);
                addLineToFile(line);
                push(stack, t);
                incrementFunctionSize(func->returnType);
            }
        }

        // return the return type of the function to the recurive call
        free(line);
        return func->returnType;
    }

    else if (strcmp(Node->token, "RETURN") == 0) {
        char* returnLine;

        // finding the current function that we are in
        Function* currentFunction = getCurrentFunction(scope, NULL);
        if (currentFunction == NULL) {
            printf("SEMANTIC ERROR: could not find function signiture for in current scope.\n");
            free(scope);
            cleanAndCloseFile();
            exit(1); 
        }

        // if we see 'return ;' then we want to check if the current function is of type VOID
        if (Node->left == NULL) {
            if (strcmp(currentFunction->returnType, "VOID") != 0) {
                printf("SEMANTIC ERROR: return void: 'return ;' can only be in a function with return type VOID. \n");
                free(scope);
                cleanAndCloseFile();
                exit(1);
            }

            //todo: Part 3
            asprintf(&returnLine, "\t\treturn ;");
            addLineToFile(returnLine);
        }
        else {
            // if there is an expression after the return then check that the type of the expression matches the return type of the current function
            char* type = checkSemantics(scope, stack, Node->left);
            if (strcmp(type, currentFunction->returnType) != 0) {
                printf("SEMANTIC ERROR: return type mismatch in function '%s', expected '%s' but found '%s'.\n", currentFunction->name, currentFunction->returnType, type);
                free(scope);
                cleanAndCloseFile();
                exit(1); 
            }

            //todo: Part 3
            // pop the temp val from the stack
            char* val = pop(stack);

            // print the return statement 
            asprintf(&returnLine, "\t\treturn %s", val);
            addLineToFile(returnLine);
            free(val);

            return type;
        }
        free(returnLine);
    }


    // printing the scopes for debugging, remove before final submission
    // printScope(scope);
    // printf("------------------------------------------------------------------\n");
    //* 🐤 🐤 🐤 🐤 🐤 🐤 🐤 🐤 🐤 🐤 🐤 🐤 🐤 🐤 🐤 🐤 🐤 🐤 🐤 🐤 🐤 *//
}


// function to print a linked list 
void printLinkedList(LinkedListNode* list) {
    LinkedListNode* current = list;
    while (current != NULL) {
        if (current->variable != NULL) {
            Variable* var = current->variable;
            printf("%s, %s, %s\t", var->name, var->type, var->len); //len is for strings [32]
        }
        else {
            Function* func = current->function;
            printf("%s, %s, ", func->name, func->returnType); 

            if (func->args != NULL) {
                printf("(");
                for (int i = 0; i < func->countArgs; i++) {
                    printf("%s:%s | ", func->args[i]->type, func->args[i]->name); 
                }
                printf("), %d\t", func->countArgs);
            }
            else 
                printf("NULL\t"); 
        }

        current = current->next;
    }
    printf("NULL\n");
}

// function to print the stack of linked lists 
void printScope(Scope* stack) {
    Scope* current = stack;
    while (current != NULL) {
        printLinkedList(current->list);
        printf("\n");
        current = current->father;
    }
}
