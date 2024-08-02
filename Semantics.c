#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Helper.h"

/* represents an argument like int num */
typedef struct Argument {
	char* name;
	char* type;
} Argument;

/* represents a function like foo(a, b) */
typedef struct Function {
	char* name;
	struct Argument** args;
    int countArgs;
    int isPrivate;
    int isStatic;
	char* returnType;
} Function;

/* represents a variable like int count = 0 */
typedef struct Variable {
    char* name;
	char* type;
    char* len;
} Variable;

/* represents a node in linked list of scope */
typedef struct LinkedListNode {
    struct Variable* variable;
    struct Function* function;
    struct LinkedListNode* next;
} LinkedListNode;

/* represents a scope like for, if etc. */
typedef struct Scope {
    LinkedListNode* list;
    struct Scope* father;
} Scope;

/* # # # # # # # # # # function declarations # # # # # # # # # # */
Scope* makeScope(Scope* father);
LinkedListNode* makeVarNode(char* name, char* type, char* len);
LinkedListNode* makeFuncNode(char* name, char* returnType, int isStatic, int isPrivate);

Argument* makeFuncArg(char* name, char* type);
void addArg(Function* func, Argument* newArg);
void addLinkedListNode(Scope* scope, LinkedListNode* listNode);

void findAndInitVars(Scope* scope, node* Node, char* type);
Variable* findVarNodeInScope(Scope* scope, LinkedListNode* node);
Variable* findVarNodeInCurrentScope(Scope* scope, char* name);
char* findVarInFuncArgs(Scope* scope, char* arg);

void findAndInitFuncArgs(LinkedListNode* item, node* temp);
Function* findFuncNodeInScope(Scope* scope, LinkedListNode* node);
Function* findFuncNodeInCurrentScope(Scope* scope, char* name);
int findMainFunction(Scope* scope);
Function* getCurrentFunction(Scope* scope);

char* checkArithmetics(char* operator, char* type1, char* type2);
char* checkSemantics(Scope* scope, node* Node);
void checktree(node* Node);

void printLinkedList(LinkedListNode* list);
void printScope(Scope* stack);



//? # # # # # # # # # # Linked-List Functions # # # # # # # # # # //

/* function to create a new linked list node */
LinkedListNode* makeVarNode(char* name, char* type, char* len) {
    Variable* newVar = (Variable*)malloc(sizeof(Variable));
    LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    if (newVar != NULL && newNode != NULL) {
        //initialize new var
        newVar->name = name;
        newVar->type = type;
        newVar->len = len;
        //initialize new node with var 
        newNode->variable = newVar;
        newNode->function = NULL;
        newNode->next = NULL;
    }
    return newNode;
}

/* function to create a new function node */
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

/* function to create a new argument */
Argument* makeFuncArg(char* name, char* type) {
    Argument* newArg = (Argument*)malloc(sizeof(Argument));
    if (newArg != NULL) {
        newArg->name = name;
        newArg->type = type;
    }
    return newArg;
}

/* function to add an argument to function node */
void addArg(Function* func, Argument* newArg) {
    func->countArgs += 1; //we increase the var counter of func
    func->args = (Argument**)realloc(func->args, sizeof(Argument*) * func->countArgs);
    if (func->args == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE); 
    }
    func->args[func->countArgs-1] = newArg; //set the new argument in function
}

/* function to create a new argument */
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

/* function to create a new scope that points to the previous scope (father) */
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
    if (strcmp(temp->left->token, "") != 0) { // if we only have one type of arguments: foo(args>> int: x, y)      
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
void findAndInitForLoopVars(Scope* scope, node* Node, char* type) {

    // check if there are more variables to declare in this declaration statement
    if (strcmp(Node->token, "") == 0) {
        findAndInitForLoopVars(scope, Node->left, type);
        findAndInitForLoopVars(scope, Node->right->left, type);
    }
    else {
        char* id;
        if (strcmp(Node->token, "ID ASSIGN") == 0) 
            id = Node->left->token;
        else if (strcmp(Node->token, "EXPRESSION") == 0) 
            id = Node->left->left->left->token; 


        // check if the variable we are declaring is used in the function argument declaration
        Function* currentFunc = getCurrentFunction(scope);
        if (currentFunc != NULL) {
            for (size_t i = 0; i < currentFunc->countArgs; i++) {
                if (strcmp(currentFunc->args[i]->name, id) == 0) {
                    printf("SEMANTIC ERROR: redeclaration of identifier '%s', it has already been declared in current function arguments.\n", id);
                    free(Node);
                    free(currentFunc);
                    free(scope);
                    exit(1); 
                }
            }
        }

        // check if the variable is already declared in the current scope
        if (findVarNodeInCurrentScope(scope->father, id) != NULL) {
            printf("SEMANTIC ERROR: redeclaration of identifier '%s', it has already been declared in this scope.\n", id);
            free(Node);
            free(scope);
            exit(1); 
        }

        // check if has assignment or not
        if (strcmp(Node->token, "ID ASSIGN") != 0) { 
            addLinkedListNode(scope, makeVarNode(id, type, NULL));
        }
        else {
            char* foundType = checkSemantics(scope, Node->right);
            //check if given type is of type pointer and if so we need to check its value type
            if ((strcmp(type, "INT*") == 0) || (strcmp(type, "DOUBLE*") == 0) || (strcmp(type, "FLOAT*") == 0) || (strcmp(type, "CHAR*") == 0)) {
                char* expectedType = checkArithmetics("*", type, NULL);
                if (strcmp(foundType, "NULL") != 0) {
                    if (strcmp(expectedType, foundType) != 0) {
                        printf("SEMANTIC ERROR: type mismatch at declaration of identifier '%s', expected '%s' but found '%s'.\n", id, expectedType, foundType);
                        free(Node);
                        free(scope);
                        exit(1);
                    }
                }
            }
            //else we are doing regular assignment so we only check if the value type matches the declaration type
            else if (strcmp(type, foundType) != 0) {
                printf("SEMANTIC ERROR: type mismatch at declaration of identifier '%s', expected '%s' but found '%s'.\n", id, type, foundType);
                free(Node);
                free(scope);
                exit(1);
            }
            addLinkedListNode(scope, makeVarNode(id, type, NULL)); 
        }
    }
}

// function for adding a new variable to the scope
void findAndInitVars(Scope* scope, node* Node, char* type) {
    // check if the variable we are declaring is used in the function argument declaration
    Function* currentFunc = getCurrentFunction(scope);
    if (currentFunc != NULL) {
        for (size_t i = 0; i < currentFunc->countArgs; i++) {
            if (strcmp(currentFunc->args[i]->name, Node->token) == 0) {
                printf("SEMANTIC ERROR: redeclaration of identifier '%s', it has already been declared in current function arguments.\n", Node->token);
                free(Node);
                free(currentFunc);
                free(scope);
                exit(1); 
            }
        }
    }

    // check if the variable is already declared in the current scope
    if (findVarNodeInCurrentScope(scope, Node->token) != NULL) {
        printf("SEMANTIC ERROR: redeclaration of identifier '%s', it has already been declared in this scope.\n", Node->token);
        free(Node);
        free(scope);
        exit(1); 
    }

    // check if has assignment or not
    if (Node->left == NULL) { 
        addLinkedListNode(scope, makeVarNode(Node->token, type, NULL));
    }
    else {
        if (strcmp(Node->left->token, "ASSIGN") == 0) { 
            char* foundType = checkSemantics(scope, Node->left->left);
            //check if given type is of type pointer and if so we need to check its value type
            if ((strcmp(type, "INT*") == 0) || (strcmp(type, "DOUBLE*") == 0) || (strcmp(type, "FLOAT*") == 0) || (strcmp(type, "CHAR*") == 0)) {
                char* expectedType = checkArithmetics("*", type, NULL);
                if (strcmp(foundType, "NULL") != 0) {
                    if (strcmp(expectedType, foundType) != 0) {
                        printf("SEMANTIC ERROR: type mismatch at declaration of identifier '%s', expected '%s' but found '%s'.\n", Node->token, expectedType, foundType);
                        free(Node);
                        free(scope);
                        exit(1);
                    }
                }
            }
            //else we are doing regular assignment so we only check if the value type matches the declaration type
            else if (strcmp(type, foundType) != 0) {
                printf("SEMANTIC ERROR: type mismatch at declaration of identifier '%s', expected '%s' but found '%s'.\n", Node->token, type, foundType);
                free(Node);
                free(scope);
                exit(1);
            }
            addLinkedListNode(scope, makeVarNode(Node->token, type, NULL));
        }
    }


    if (Node->right != NULL) { 
        findAndInitVars(scope, Node->right, type);
    }
}

/* function for adding a new STRING variable to the scope */
void findAndInitStrings(Scope* scope, node* Node, char* type) {
    // check if the variable is already declared in the current scope
    if (findVarNodeInCurrentScope(scope, Node->left->left->left->token) != NULL) {
        printf("SEMANTIC ERROR: redeclaration of identifier '%s', it has already been declared.\n", Node->left->left->left->token);
        free(Node);
        free(scope);
        exit(1); 
    }

    // check if the string size is of type int
    char* stringSizeType = checkSemantics(scope, Node->left->left->right);
    if (strcmp(stringSizeType, "INT") != 0) {
        printf("SEMANTIC ERROR: string size of identifier '%s' must be of type 'INT', but found '%s'.\n", Node->left->left->left->token, stringSizeType);
        free(Node);
        free(scope);
        exit(1); 
    }

    // check that string size is not explicit zero
    if ((Node->left->left->right->left->token != NULL) && (strcmp(Node->left->left->right->left->token, "VALUE") == 0) && (Node->left->left->right->left->right == NULL) && (Node->left->left->right->left->left->left != NULL) && (atoi(Node->left->left->right->left->left->left->token)) == 0) {
        printf("SEMANTIC ERROR: string size of identifier '%s' can't be 0.\n", Node->left->left->left->token);
        free(Node);
        free(scope);
        exit(1); 
    }
    
    // checking that the assignment value is of type STRING or NULL           
    if (Node->left->right->left != NULL) { 
        char* assignemtType = checkSemantics(scope, Node->left->right->left->left);
        if ((strcmp("NULL",assignemtType) != 0) && (strcmp("STRING", assignemtType) != 0)) {
            printf("SEMANTIC ERROR: type mismatch for identifier '%s', expected 'STRING' or 'NULL' but found '%s'.\n", Node->left->left->left->token, assignemtType);
            free(Node);
            free(scope);
            exit(1);
        }
    }

    // check that string size is not an expression but a simple value to check if that index is valid
    if ((strcmp(Node->left->left->right->left->token, "VALUE") == 0) && (strcmp(Node->left->left->right->left->left->token, "INT") == 0)) {
        // check that index expression is less than or equal to the declared length and that its not negative
        int indexValue = atoi(Node->left->left->right->left->left->left->token);
        if (indexValue < 0) {
            printf("SEMANTIC ERROR: string size is invalid for identifier '%s', size must be greater than zero.\n", Node->left->left->left->token);
            free(Node);
            free(scope);
            exit(1); 
        }

        // checking that the index is valid only if the value is a simple integer, if its an expression then dont check
        char* stringMaxLen = Node->left->left->right->left->left->left->token;
        if (Node->left->right->left) {
            node* val = Node->left->right->left->left;
            if (strcmp("NULL", val->left->token) != 0) {
                if (strcmp("NULL", checkSemantics(scope, val)) != 0) { 
                    int maxLen = atoi(stringMaxLen), assignemntStringLen = (strlen(val->left->left->left->token) - 2); // -2 is because we want to disregard the "" symbols.
                    if (assignemntStringLen > maxLen) { //? >= because we leave space for '\0'
                        printf("SEMANTIC ERROR: assignment string is too long for identifier '%s', expected length <= '%d' but found string of length '%d'.\n", Node->left->left->left->token, maxLen, assignemntStringLen);
                        free(Node);
                        free(scope);
                        exit(1);
                    }
                }
            }
        }

        addLinkedListNode(scope, makeVarNode(Node->left->left->left->token, type, stringMaxLen));
    }
    else
        addLinkedListNode(scope, makeVarNode(Node->left->left->left->token, type, NULL));
    

    // check if there are more declarations in this declaration
    if (Node->right->left != NULL) {
        findAndInitStrings(scope, Node->right->left, type);
    }
}

/* function to find variable in any scope, recursively */
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

/* function to find variable in a given scope only, not recursive */
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

/* function for finding a variable in function arguments */
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

/* function for finding if the main function has been declared, returns 1 if exists */
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
    //*note*  When declaring a function with the name 'main' we are checking if a main function exists in the current scope
    //*       and also that the current scope is the global scope, otherwise we return error.    
    //*       This function is also used to insure that a 'main' function was indeed declared in the program.
}


/* function to find function in any scope, recursively */
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


/* function to find function in a given scope only, not recursive */
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

/* function for getting the current function, the one we are currently in the scope of */
Function* getCurrentFunction(Scope* scope) { 
    if (scope != NULL) {
        LinkedListNode* current = scope->father->list; 
        // go through all elements in linked list node
        while (current->next != NULL) { 
            current = current->next; 
        }

        // check if the last item is indeed a function, else keep looking in the next scope
        if (current->function == NULL) {
            return getCurrentFunction(scope->father);
        }
        return current->function; 
    }
    return NULL; 
}

//? # # # # # # # # # # Semantic Functions # # # # # # # # # # //

/* function that checks arithmetic operations on given types and operator and returns result type */
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

/* function for checking if the AST is correct semanticly, if so then print 
    success message to the screen, else print where it failed */
void checktree(node* Node) {
    // creating the global scope
    Scope* programScope = (Scope*)malloc(sizeof(Scope));

    // checking the semantics of the program
    checkSemantics(programScope, Node);

    // checking if a main function was declared in the program
    if (findMainFunction(programScope) == 0) {
        printf("SEMANTIC ERROR: no main function found, program must have one main function.\n");
        free(programScope);
        exit(1);
    }
    //printScope(programScope);
    
    // freeing the global scope
    free(programScope);
}

/* main part 2 function that traverses the AST, creates scopes, creates symbol tables for variables and functions,
    checks all of the semantics of the code and prints error messages if an issue was found */
char* checkSemantics(Scope* scope, node* Node) {

    if (Node == NULL) { 
        return NULL; // stopping the recursion
    }

    //? * * * * * * Blocks and Scopes * * * * * * *//

    else if (strcmp(Node->token, "") == 0 || strcmp(Node->token, "CODE") == 0) {
        if (Node->left != NULL)
            checkSemantics(scope, Node->left);
        if (Node->right != NULL)
            checkSemantics(scope, Node->right);
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
            checkSemantics(makeScope(scope), temp);
        }
    }

    else if (strcmp(Node->token, "BLOCK") == 0) { 
        checkSemantics(makeScope(scope), Node->left); 
    }

    else if (strcmp(Node->token, "IF") == 0) { 
        // check that condition is of type bool
        char* conditionType = checkSemantics(scope, Node->left->left);
        if (strcmp("BOOL", conditionType) != 0) {
            printf("SEMANTIC ERROR: if statement condition must be of type 'BOOL', instead it is '%s'.\n", conditionType);
            free(Node);
            free(scope);
            exit(1);
        }

        LinkedListNode* item = makeVarNode("if", NULL, NULL);
        addLinkedListNode(scope, item);

        if (strcmp(Node->right->token, "BLOCK") == 0)
            checkSemantics(scope, Node->right); // if - single line statement
        else
            checkSemantics(makeScope(scope), Node->right); // if - multi line block
    }

    else if (strcmp(Node->token, "ELSE") == 0) {
        // adding else block into scope
        LinkedListNode* item = makeVarNode("else", NULL, NULL);
        addLinkedListNode(scope, item);

        if (strcmp(Node->left->left->token, "BLOCK") == 0)
            checkSemantics(scope, Node->left); // if - multi line block 
        else
            checkSemantics(makeScope(scope), Node->left); // if - single line statement 
    }

    else if (strcmp(Node->token, "DO WHILE") == 0) {
        // adding do while block into scope
        LinkedListNode* item = makeVarNode("do", NULL, NULL);
        addLinkedListNode(scope, item);

        // check that condition is of type bool
        char* conditionType = checkSemantics(scope, Node->right);
        if (strcmp("BOOL", conditionType) != 0) {
            printf("SEMANTIC ERROR: do-while loop statement condition must be of type 'BOOL', instead found '%s'.\n", conditionType);
            free(Node);
            free(scope);
            exit(1);
        }
        checkSemantics(scope, Node->left); 
    }

    else if (strcmp(Node->token, "WHILE") == 0) {
        // adding while block into scope
        LinkedListNode* item = makeVarNode("while", NULL, NULL);
        addLinkedListNode(scope, item);

        char* conditionType = checkSemantics(scope, Node->left);
        if (strcmp("BOOL", conditionType) != 0) {
            printf("SEMANTIC ERROR: while loop statement condition must be of type 'BOOL', instead found '%s'.\n", conditionType);
            free(Node);
            free(scope);
            exit(1);
        }

        if (strcmp(Node->right->token, "BLOCK") == 0)
            checkSemantics(scope, Node->right); // while - multi line block 
        else
            checkSemantics(makeScope(scope), Node->right); // while - single line statement
    }

    else if (strcmp(Node->token, "FOR") == 0) {
        // adding for block into scope
        LinkedListNode* item = makeVarNode("for", NULL, NULL);
        addLinkedListNode(scope, item);

        // creating a scope for the for loop manualy
        Scope* forLoopScope = makeScope(scope);

        // checking if for loop has a variable declaration statement
        if (strcmp("FOR INIT", Node->left->token) == 0 || strcmp("* ID ASSIGN", Node->left->token) == 0) {
            // check the assign statement
            
            if (strcmp(Node->left->left->token, "VAR") == 0)
                findAndInitForLoopVars(forLoopScope, Node->left->left->right, Node->left->left->left->token);
            else
                checkSemantics(forLoopScope, Node->left->left);
            
            // check condition type
            char* conditionType = checkSemantics(forLoopScope, Node->left->right);
            if (strcmp("BOOL", conditionType) != 0) {
                printf("SEMANTIC ERROR: for loop condition must be of type 'BOOL', instead found '%s'.\n", conditionType);
                free(Node);
                free(forLoopScope);
                free(scope);
                exit(1);
            }

            // check if there is an update statement
            if (Node->left->right->right != NULL) {
                checkSemantics(forLoopScope, Node->left->right->right);
            }
        }
        else { // if there is no var declaration statement then the expression and update pointers are different
            // check condition type
            char* conditionType = checkSemantics(forLoopScope, Node->left);
            if (strcmp("BOOL", conditionType) != 0) {
                printf("SEMANTIC ERROR: for loop condition must be of type 'BOOL', instead found '%s'.\n", conditionType);
                free(Node);
                free(forLoopScope);
                free(scope);
                exit(1);
            }

            // check if there is an update statement
            if (Node->left->right != NULL) {
                checkSemantics(forLoopScope, Node->left->right);
            }
        }

        // check the semantics of the for loop block
        checkSemantics(forLoopScope, Node->right->left->left);
    }

    else if (strcmp(Node->token, "FOR INIT") == 0) {
        if (strcmp(Node->left->token, "") != 0) // if no more recursion
            checkSemantics(scope, Node->left);
    
        checkSemantics(scope, Node->left->left); // check current item semantics
        checkSemantics(scope, Node->left->right); // recursive call
    }

    else if (strcmp(Node->token, "UPDATE") == 0) {
        // if there is only one update statement without ','
        if (strcmp(Node->left->token, "EXPRESSION") == 0 
            || strcmp(Node->left->token, "ID ASSIGN") == 0) {
            checkSemantics(scope, Node->left);
        }
        else { // if there are multiple update statements seperated by ','
            checkSemantics(scope, Node->left->left); // check the current update statement
            checkSemantics(scope, Node->left->right); // recursive call to the next update statement
        }
    }



    //? * * * * * * Expressions and Other * * * * * * *//

    else if (strcmp(Node->token, "DECLERATION") == 0) {
        checkSemantics(scope, Node->left);
        if (Node->right != NULL)
            checkSemantics(scope, Node->right);
    }

    else if (strcmp(Node->token, "VAR") == 0) { 
        findAndInitVars(scope, Node->right, Node->left->token);
    }

    else if (strcmp(Node->token, "STRING") == 0) {
        findAndInitStrings(scope, Node->left, Node->token);
    }

    else if (strcmp(Node->token, "ASSIGN") == 0) {
        return checkSemantics(scope, Node->left);
    }

    else if (strcmp(Node->token, "ID ASSIGN") == 0) {
        // find the variable in the scopes
        LinkedListNode* varNode = makeVarNode(Node->left->token, NULL, NULL);
        Variable* var = findVarNodeInScope(scope, varNode);
        if (var == NULL) {
            printf("SEMANTIC ERROR: identifier '%s' was not found.\n", Node->left->token);
            free(var);
            free(scope);
            exit(1);
        }

        // find the type of the variable and if its a pointer there is special attention to the assignmet
        char* foundType = checkSemantics(scope, Node->right);
        if ((strcmp(var->type, "INT*") == 0) || (strcmp(var->type, "DOUBLE*") == 0) || (strcmp(var->type, "FLOAT*") == 0) || (strcmp(var->type, "CHAR*") == 0)) {
            if (strcmp(Node->right->left->left->token, "&") == 0) {
                // check that the type of the identifier we want to get the address of matches the type of the pointer
                char* expectedType = checkArithmetics("&", foundType, NULL);
                if (expectedType == NULL) {
                    if (strcmp(foundType, "NULL") != 0) {
                        if (strcmp(expectedType, foundType) != 0) {
                            printf("SEMANTIC ERROR: type mismatch at declaration of identifier '%s', expected '%s' but found '%s'.\n", var->name, expectedType, foundType);
                            free(Node);
                            free(scope);
                            exit(1);
                        }
                    }
                }
                else {
                    if (strcmp(var->type, expectedType) != 0) {
                        printf("SEMANTIC ERROR: type mismatch at declaration of identifier '%s', expected '%s' but found '%s'.\n", var->name, var->type, expectedType);
                        free(Node);
                        free(scope);
                        exit(1);
                    }
                }
  
                return NULL;
            }
            else if (strcmp(Node->right->left->left->token, "* (pointer)") == 0) {
    
                // check that the type of the identifier we want to get the address of matches the type of the pointer
                char* expectedType = checkArithmetics("*", foundType, NULL);
                if (strcmp(foundType, "NULL") != 0) {
                    if (strcmp(expectedType, foundType) != 0) {
                        printf("SEMANTIC ERROR: type mismatch at declaration of identifier '%s', expected '%s' but found '%s'.\n", var->name, var->type, expectedType);
                        free(Node);
                        free(scope);
                        exit(1);
                    }
                }

                return NULL;
            }
            else if (strcmp(foundType, "NULL") == 0) {
                return NULL;
            }
        }
        else if ((strcmp(foundType, "INT*") == 0) || (strcmp(foundType, "DOUBLE*") == 0) || (strcmp(foundType, "FLOAT*") == 0) || (strcmp(foundType, "CHAR*") == 0)) {
            if (strcmp(Node->right->left->left->token, "* (pointer)") == 0) {
                // check that the type of the identifier we want to get the value of matches the type of the identifier we want to assign to
                char* expectedType = checkArithmetics("*", foundType, NULL);
                if ((expectedType != NULL) && (strcmp(foundType, "NULL") != 0)) {
                    if (strcmp(var->type, expectedType) != 0) {
                        printf("SEMANTIC ERROR: type mismatch at declaration of identifier '%s', expected '%s' but found '%s'.\n", var->name, var->type, expectedType);
                        free(Node);
                        free(scope);
                        exit(1);
                    }
                }
                return NULL;
            }
        }

        if (strcmp(var->type, foundType) != 0) {
            printf("SEMANTIC ERROR: type mismatch for identifier '%s', expected '%s' but found '%s'.\n", Node->left->token, var->type, foundType);
            free(var);
            free(scope);
            exit(1);
        }
    }
    
    else if (strcmp(Node->token, "* ID ASSIGN") == 0) {
        // find the variable in the scopes
        LinkedListNode* varNode = makeVarNode(Node->left->token, NULL, NULL);
        Variable* var = findVarNodeInScope(scope, varNode);
        if (var == NULL) {
            printf("SEMANTIC ERROR: identifier '%s' was not found.\n", Node->left->token);
            free(var);
            free(scope);
            exit(1);
        }
        //check if given type is of type pointer and if so we need to check its value type
        char* foundType = checkSemantics(scope, Node->right);
        if ((strcmp(foundType, "INT*") == 0) || (strcmp(foundType, "DOUBLE*") == 0) || (strcmp(foundType, "FLOAT*") == 0) || (strcmp(foundType, "CHAR*") == 0)) {
            if (strcmp(Node->right->left->left->token, "* (pointer)") == 0) {
                foundType = checkArithmetics("*", foundType, NULL);
            }
        }
        char* expectedType = checkArithmetics("*", var->type, NULL);
        if (expectedType != NULL) {
            if ((strcmp(foundType, "NULL") == 0) || (strcmp(expectedType, foundType) != 0)) {
                printf("SEMANTIC ERROR: type mismatch at declaration of identifier '*%s', expected '%s' but found '%s'.\n", var->name, expectedType, foundType);
                free(Node);
                free(scope);
                exit(1);
            }
        }
    }

    else if (strcmp(Node->token, "ASSIGN[]") == 0) {
        // find the variable in the scopes
        LinkedListNode* varNode = makeVarNode(Node->left->left->token, NULL, NULL);
        Variable* var = findVarNodeInScope(scope, varNode);
        if (var == NULL) {
            printf("SEMANTIC ERROR: identifier '%s' was not found.\n", Node->left->token);
            free(var);
            free(scope);
            exit(1);
        }

        // check that the id is of type string
        if (strcmp(var->type, "STRING") != 0) {
            printf("SEMANTIC ERROR: can't assign index value to identifier of type '%s', it is only possible for type 'STRING'.\n", var->type);
            free(Node);
            free(scope);
            exit(1);
        }

        // check that expression is of type int
        char* indexType = checkSemantics(scope, Node->left->right);
        if (strcmp(indexType, "INT") != 0) {
            printf("SEMANTIC ERROR: string size of identifier '%s' must be of type 'INT', but found '%s'.\n", var->name, indexType);
            free(Node);
            free(scope);
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
                exit(1); 
            }
            
            if (var->len != NULL) {
                int maxStringLen = atoi(var->len);
                if (indexValue > maxStringLen) {
                    printf("SEMANTIC ERROR: index is out of bounds for identifier '%s', expected index <= '%d' but found index '%d'.\n", var->name, maxStringLen, indexValue);
                    free(Node);
                    free(scope);
                    exit(1); 
                }
            }
        }

        // check that if we assing an id then it is of type char
        char* assignemtType = checkSemantics(scope, Node->right->left);
        if ((strcmp("NULL",assignemtType) != 0) && (strcmp("CHAR", assignemtType) != 0)) {
            printf("SEMANTIC ERROR: type mismatch for identifier '%s', expected 'CHAR' or 'NULL' but found '%s'.\n", var->name, assignemtType);
            free(Node);
            free(scope);
            exit(1);
        }
    }

    else if (strcmp(Node->token, "&ID[]") == 0) {
        // this action is only performed on strings and returns type CHAR*
        char* resType = checkSemantics(scope, Node->left); 
        return "CHAR*";
    }

    else if (strcmp(Node->token, "ID[]") == 0) {
        // find the variable in the scopes
        LinkedListNode* varNode = makeVarNode(Node->left->left->token, NULL, NULL);
        Variable* var = findVarNodeInScope(scope, varNode);
        if (var == NULL) {
            printf("SEMANTIC ERROR: identifier '%s' was not found.\n", Node->left->left->token);
            free(var);
            free(scope);
            exit(1);
        }

        // check that the id is of type string
        if (strcmp(var->type, "STRING") != 0) {
            printf("SEMANTIC ERROR: can't assign index value to identifier of type '%s', it is only possible for type 'STRING'.\n", var->type);
            free(Node);
            free(scope);
            exit(1);
        }

        // check that expression is of type int
        char* indexType = checkSemantics(scope, Node->left->right);
        if (strcmp(indexType, "INT") != 0) {
            printf("SEMANTIC ERROR: string size of identifier '%s' must be of type 'INT', but found '%s'.\n", var->name, indexType);
            free(Node);
            free(scope);
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
                exit(1); 
            }
            
            if (var->len != NULL) {
                int maxStringLen = atoi(var->len);
                if (indexValue > maxStringLen) {
                    printf("SEMANTIC ERROR: index is out of bounds for identifier '%s', expected index <= '%d' but found index '%d'.\n", var->name, maxStringLen, indexValue);
                    free(Node);
                    free(scope);
                    exit(1); 
                }
            }
        }

        return "CHAR";
    }



    else if (strcmp(Node->token, "EXPRESSION") == 0) {
        // expressions have many options...

        if (strcmp(Node->left->token, "NULL") == 0) {
            return "NULL";
        }
        else if (strcmp(Node->left->token, "&") == 0) { 
            char* type = checkSemantics(scope, Node->left->left);
            if ((strcmp(type, "INT*") == 0) || (strcmp(type, "FLOAT*") == 0) || (strcmp(type, "DOUBLE*") == 0) || (strcmp(type, "CHAR*") == 0)) {
                printf("SEMANTIC ERROR: using '&' on identifier of type '%s' is undefined.\n", type);
                free(Node);
                free(scope);
                exit(1);
            }
            return type;
        }
        else if (strcmp(Node->left->token, "* (pointer)") == 0) { 
            char* type = checkSemantics(scope, Node->left->left);
            if ((strcmp(type, "INT") == 0) || (strcmp(type, "FLOAT") == 0) || (strcmp(type, "DOUBLE") == 0) || (strcmp(type, "CHAR") == 0) || (strcmp(type, "BOOL") == 0)) {
                printf("SEMANTIC ERROR: using '*' on identifier of type '%s' is undefined.\n", type);
                free(Node);
                free(scope);
                exit(1);
            }

            return checkArithmetics("*", type, NULL);
        }
        else if (strcmp(Node->left->left->token, "FUNCTION CALL") == 0) {
            return checkSemantics(scope, Node->left->left);
        }
        else if (strcmp(Node->left->left->token, "ID") == 0) {
            // try to find var in a function argument
            char* typeIfFound = findVarInFuncArgs(scope->father, Node->left->left->left->token);
            if (typeIfFound != NULL) {
                return typeIfFound;
            }
            // otherwise try to find it in a scope
            LinkedListNode* varNode = makeVarNode(Node->left->left->left->token, NULL, NULL);
            Variable* var = findVarNodeInScope(scope, varNode);
            if (var == NULL) {
                printf("SEMANTIC ERROR: identifier '%s' was not found.\n", Node->left->left->left->token);
                free(var);
                free(scope);
                exit(1);
            }
            return var->type;
        }
        else if (strcmp(Node->left->token, "VALUE") == 0) {
            return Node->left->left->token; //* this is the type of the value from yacc
        }
        else if (strcmp(Node->left->token, "( )") == 0) {
            return checkSemantics(scope, Node->left->left); 
        }
        else if (strcmp(Node->left->token, "| |") == 0) {
            char* type = checkSemantics(scope, Node->left->left);
            char* resType = checkArithmetics("||", type, NULL);
            if (resType == NULL) {
                printf("SEMANTIC ERROR: type mismatch on '%s' operator, expected expression of type 'STRING', but found '%s'.\n", Node->left->token, type);
                free(scope);
                exit(1);
            }
            return resType;
        }
        else if (strcmp(Node->left->token, "! (not)") == 0) {
            char* type = checkSemantics(scope, Node->left->left);
            char* resType = checkArithmetics("!", type, NULL);
            if (resType == NULL) {
                printf("SEMANTIC ERROR: type mismatch on '%s' operator, expected expression of type 'BOOL', but found '%s'.\n", Node->left->token, type);
                free(scope);
                exit(1);
            }
            return resType;
        }
        else if (strcmp(Node->left->token, "+") == 0
                || strcmp(Node->left->token, "-") == 0
                || strcmp(Node->left->token, "*") == 0
                || strcmp(Node->left->token, "/") == 0
                || strcmp(Node->left->token, "&&") == 0
                || strcmp(Node->left->token, "||") == 0
                || strcmp(Node->left->token, "<") == 0
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
                    exit(1);
                }
            }

            // using a helper function to check if the aritmetic expression is correct and valid by checking the types of the operands
            char* leftType = checkSemantics(scope, Node->left->left);
            char* rightType = checkSemantics(scope, Node->left->right);
            char* resType = checkArithmetics(Node->left->token, leftType, rightType);
            if (resType == NULL) {
                printf("SEMANTIC ERROR: type mismatch on '%s' operator.\n", Node->left->token);
                free(scope);
                exit(1);
            } 
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
            exit(1);
        }

        // checking if we can call that function from our current function
        Function* currentFunction = getCurrentFunction(scope);
        if (currentFunction->isStatic == 1 && func->isStatic == 0) {
            printf("SEMANTIC ERROR: static function '%s' cannot call a non-static function '%s'\n", currentFunction->name, func->name);
            exit(1);
        }

        if (currentFunction->isPrivate == 0 && func->isPrivate == 1) {
            Function* funcInCurrentScope = findFuncNodeInCurrentScope(scope->father, funcNode->function->name);    
            if (funcInCurrentScope == NULL) {
                printf("SEMANTIC ERROR: public function '%s' cannot call a private function '%s' because they are not in the same scope.\n", currentFunction->name, func->name);
                exit(1);
            } 
        }

        // checking if the function needs to get any params
        if (Node->right != NULL) { // has params
            node* temp = Node->right;
            int paramCounter = 0;

            do {
                if (paramCounter == func->countArgs) {
                    printf("SEMANTIC ERROR: to many arguments in function call '%s()'\n", funcNode->function->name);
                    free(funcNode);
                    free(scope);
                    exit(1); 
                }

                // checking that the param types are correct
                char* paramType = checkSemantics(scope, temp);
                if (strcmp(paramType, func->args[paramCounter]->type) != 0) {
                    printf("SEMANTIC ERROR: param type mismatch in function call '%s()' on param '%s'\n",
                        funcNode->function->name, func->args[paramCounter]->name);
                    free(funcNode);
                    free(scope);
                    exit(1); 
                }

                paramCounter++;
                temp = temp->right;
            } while (temp != NULL);

            if (paramCounter < func->countArgs) {
                printf("SEMANTIC ERROR: too few arguments in function call '%s()'\n", funcNode->function->name);
                free(funcNode);
                free(scope);
                exit(1); 
            }
        }

        return func->returnType;
    }

    else if (strcmp(Node->token, "RETURN") == 0) {
        // finding the current function that we are in
        Function* currentFunction = getCurrentFunction(scope);
        if (currentFunction == NULL) {
            printf("SEMANTIC ERROR: could not find function signiture for in current scope.\n");
            free(scope);
            exit(1); 
        }

        // if we see 'return ;' then we want to check if the current function is of type VOID
        if (Node->left == NULL) {
            if (strcmp(currentFunction->returnType, "VOID") != 0) {
                printf("SEMANTIC ERROR: return void: 'return ;' can only be in a function with return type VOID. \n");
                free(scope);
                exit(1);
            }
        }
        else {
            char* type = checkSemantics(scope, Node->left);
            if (strcmp(type, currentFunction->returnType) != 0) {
                printf("SEMANTIC ERROR: return type mismatch in function '%s', expected '%s' but found '%s'.\n", currentFunction->name, currentFunction->returnType, type);
                free(scope);
                exit(1); 
            }
            return type;
        }
    }


    // printing the scopes for debugging, remove before final submission
    // printScope(scope);
    // printf("------------------------------------------------------------------\n");
}


/* function to print a linked list */
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

/* function to print the stack of linked lists */
void printScope(Scope* stack) {
    Scope* current = stack;
    while (current != NULL) {
        printLinkedList(current->list);
        printf("\n");
        current = current->father;
    }
}
