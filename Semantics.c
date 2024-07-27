#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h> 
#include "Helper.c"

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
	char* value;
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
LinkedListNode* makeVarNode(char* name, char* value, char* type, char* len);
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
Function* getCurrentFunction(Scope* scope);
int findMainFunction(Scope* scope);

int checkVar(char* type, char* value);
char* checkArithmetics(char* operator, char* type1, char* type2);
char* semanticChecks(Scope* scope, node* Node);
void checktree(node* Node);

void printLinkedList(LinkedListNode* list);
void printScope(Scope* stack);



//? # # # # # # # # # # Linked-List Functions # # # # # # # # # # //

/* function to create a new linked list node */
LinkedListNode* makeVarNode(char* name, char* value, char* type, char* len) {
    Variable* newVar = (Variable*)malloc(sizeof(Variable));
    LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    if (newVar != NULL && newNode != NULL) {
        //initialize new var
        newVar->name = name;
        newVar->value = value;
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
            //!! check for redeclaration, need to add: " Scope* scope " to signiture
            // char* currentArg = variables->token;
            // if (findVarInFuncArgs(scope, currentArg) != NULL) {
            //     printf("ERROR: redeclaration of identifier '%s', it has already been declared as a function argument in this scope.\n", currentArg);
            //     free(item);
            //     free(temp);
            //     free(variables);
            //     free(scope);
            //     exit(1);
            // }
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

// function for adding a new variable to the scope
void findAndInitVars(Scope* scope, node* Node, char* type) {
    // check if the variable we are declaring is used in the function argument declaration
    Function* currentFunc = getCurrentFunction(scope);
    if (currentFunc != NULL) {
        for (size_t i = 0; i < currentFunc->countArgs; i++) {
            if (strcmp(currentFunc->args[i]->name, Node->token) == 0) {
                printf("ERROR: redeclaration of identifier '%s', it has already been declared in current function arguments.\n", Node->token);
                free(Node);
                free(currentFunc);
                free(scope);
                exit(1); 
            }
        }
    }

    // check if the variable is already declared in the current scope
    if (findVarNodeInCurrentScope(scope, Node->token) != NULL) {
        printf("ERROR: redeclaration of identifier '%s', it has already been declared in this scope.\n", Node->token);
        free(Node);
        free(scope);
        exit(1); 
    }

    // check if has assignment or not
    if (Node->left == NULL) { 
        addLinkedListNode(scope, makeVarNode(Node->token, NULL, type, NULL));
    }
    else {
        if (strcmp(Node->left->token, "ASSIGN") == 0) { 
            char* foundType = semanticChecks(scope, Node->left->left);
            if (strcmp(type, foundType) != 0) {
                printf("ERROR: type mismatch at declaration of identifier '%s', expected '%s' but found '%s'.\n", Node->token, type, foundType);
                free(Node);
                free(scope);
                exit(1);
            }
            addLinkedListNode(scope, makeVarNode(Node->token, Node->left->left->left->left->left->token, type, NULL));
        }
    }

    // check if there are more variables to declare in this declaration statement
    if (Node->right != NULL) { 
        findAndInitVars(scope, Node->right, type);
    }
}

/* function for adding a new STRING variable to the scope */
void findAndInitStrings(Scope* scope, node* Node, char* type) {
    // check if the variable is already declared in the current scope
    if (findVarNodeInCurrentScope(scope, Node->left->left->left->token) != NULL) {
        printf("ERROR: redeclaration of identifier '%s', it has already been declared.\n", Node->left->left->left->token);
        free(Node);
        free(scope);
        exit(1); 
    }

    // check that string size is not zero
    if (atoi(Node->left->left->right->token) == 0) {
        printf("ERROR: string size of identifier '%s' can't be 0.\n", Node->left->left->left->token);
        free(Node);
        free(scope);
        exit(1); 
    }

    // check if there is assignment, if == NULL then no assignment
    if (Node->left->right->left == NULL) 
        addLinkedListNode(scope, makeVarNode(Node->left->left->left->token, NULL, type, Node->left->left->right->token));
    else {
        // checking that the assignment value is of type STRING
        node* val = Node->left->right->left->left;
        if (strcmp("NULL", semanticChecks(scope, val)) != 0) {

            if (strcmp("STRING", semanticChecks(scope, val)) != 0) {
                printf("ERROR: type mismatch for identifier '%s'.\n", Node->left->left->left->token);
                free(Node);
                free(scope);
                exit(1);
            }

            // check that assignment value len is no longer than the declared max len
            char* stringMaxLen = Node->left->left->right->token;
            if (strcmp("NULL", val->left->token) != 0) {
                // -2 is because we want to disregard the "" symbols.
                if ((strlen(val->left->left->left->token) - 2) >= atoi(stringMaxLen)) { //? >= because we leave space for '\0'
                    printf("ERROR: assignment string length of identifier '%s' exceeded the max length that was declared.\n", Node->left->left->left->token);
                    free(Node);
                    free(scope);
                    exit(1);
                }
            }
        }
    
        addLinkedListNode(scope, makeVarNode(Node->left->left->left->token, val->token, type, Node->left->left->right->token));
    }

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

            if ((strcmp(current->variable->name, node->variable->name) == 0) && current->variable->type != NULL) {

                if (node->variable->value != NULL) {
                    if (!checkVar(current->variable->type, node->variable->value))
                        return NULL;
                }
                return current->variable;
            } 

            current = current->next;
        }
        return findVarNodeInScope(scope->father, node); //call recursively again to search in father's list
    }
    return NULL;
}


/* function to find function in any scope, recursively */
Function* findFuncNodeInScope(Scope* scope, LinkedListNode* node) {
    if (scope != NULL && node != NULL) {
        LinkedListNode* current = scope->list;
        // go through all elements in linked list node
        while (current != NULL) {
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

/* function to find variable in a given scope only, not recursive */
Variable* findVarNodeInCurrentScope(Scope* scope, char* name) {
    if (scope != NULL) {
        LinkedListNode* current = scope->list; //set the current node
        // go through all elements in linked list node
        while (current != NULL) {
            if ((current->variable != NULL) && (strcmp(current->variable->name, name) == 0)) {
                return current->variable;
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

        if (current->function == NULL) {
            return getCurrentFunction(scope->father);
        }
        return current->function; 
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
    
        while (current != NULL) { // go through all elements in linked list node
            if ((current->function != NULL) && (strcmp(current->function->name, "main") == 0)) {
                return 1;
            }            
            current = current->next; 
        }
    }
    return 0; 
}



//? # # # # # # # # # # Semantic Functions # # # # # # # # # # //

/* function to check if variables match valid types */
int checkVar(char* type, char* value) {
    regex_t regex;
    int result;
    char* pattern = ""; 

    if (strcmp(type, "INT") == 0) // combined hex and int
        pattern = "^(([1-9][0-9]*|0)|(0x|0X)[0-9A-F]+)$";
    else if (strcmp(type, "FLOAT") == 0 )
        pattern = "^([0-9]+\\.[0-9]+f|[0-9]+f)$";
    else if (strcmp(type, "DOUBLE") == 0 )
        pattern = "^([0-9]*(\\.[0-9]*)?([Ee][+-]?[0-9]+)?)$";
    else if (strcmp(type, "CHAR") == 0 )
        pattern = "^(\'.\')$";
    else if (strcmp(type, "STRING") == 0 )
        pattern = "^(\".*\")$";
    else if (strcmp(type, "ID") == 0 )
        pattern = "^([a-zA-Z][a-zA-Z0-9_]*)$";
    else if (strcmp(type, "FUNCTION CALL") == 0 ) // was 'func'
        pattern = "^()$";
    else 
        return 0;

    //compile regular expression
    regcomp(&regex, pattern, REG_EXTENDED);
    //execute regular expression match
    result = regexec(&regex, value, 0, NULL, 0);

    return !result;
}


/* function that checks arithmetic operations on given types and operator and returns result type */
char* checkArithmetics(char* operator, char* type1, char* type2) {
    if (operator != NULL && type1 != NULL) {
        if (type2 != NULL) {
            if (strcmp(operator, "+")==0 || strcmp(operator, "-")==0 || strcmp(operator, "*")==0 || strcmp(operator, "/")==0) {
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
            else if (strcmp(operator, "==")==0 || strcmp(operator, "!=")==0) {
                if ((strcmp(type1, "INT")==0 && strcmp(type2, "INT")==0) || (strcmp(type1, "INT*")==0 && strcmp(type2, "INT*")==0) || (strcmp(type1, "DOUBLE")==0 && strcmp(type2, "DOUBLE")==0) 
                    || (strcmp(type1, "DOUBLE*")==0 && strcmp(type2, "DOUBLE*")==0) || (strcmp(type1, "FLOAT")==0 && strcmp(type2, "FLOAT")==0) || (strcmp(type1, "FLOAT*")==0 && strcmp(type2, "FLOAT*")==0) 
                    || (strcmp(type1, "CHAR")==0 && strcmp(type2, "CHAR")==0) || (strcmp(type1, "CHAR*")==0 && strcmp(type2, "CHAR*")==0) || (strcmp(type1, "BOOL")==0 && strcmp(type2, "BOOL")==0))
                    return "BOOL";
            }
        }
        else {
            if (strcmp(operator, "||")==0 && strcmp(type1, "STRING")==0) {
                return "INT";
            }
            else if (strcmp(operator, "!")==0 && strcmp(type1, "BOOL")==0) {
                return "BOOL";
            }
            else if ((strcmp(operator, "&")==0) && (strcmp(type1, "INT")==0 || strcmp(type1, "DOUBLE")==0 
                || strcmp(type1, "FLOAT")==0 || strcmp(type1, "CHAR")==0)) {
                return "INT";
            }
            else if (strcmp(operator, "*")==0) {
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
    semanticChecks(programScope, Node);

    // checking if a main function was declared in the program
    if (findMainFunction(programScope) == 0) {
        printf("ERROR: no main function found, program must have one main function.\n");
        free(programScope);
        exit(1);
    }
    //printScope(programScope);
    
    // freeing the global scope
    free(programScope);
}

/* main part 2 function that traverses the AST, creates scopes, creates symbol tables for variables and functions,
    checks all of the semantics of the code and prints error messages if an issue was found */
char* semanticChecks(Scope* scope, node* Node) {

    if (Node == NULL) { 
        return NULL; // stopping the recursion
    }

    //? * * * * * * Blocks and Scopes * * * * * * *//

    else if (strcmp(Node->token, "") == 0 || strcmp(Node->token, "CODE") == 0) {
        if (Node->left != NULL)
            semanticChecks(scope, Node->left);
        if (Node->right != NULL)
            semanticChecks(scope, Node->right);
    }

    else if (strcmp(Node->token, "FUNCTION") == 0) {
        int isStatic = 0, isPrivate = 0;
        if (strcmp(Node->left->left->left->token, "PRIVATE") == 0)
            isPrivate = 1;
        if ((Node->left->left->right != NULL) && strcmp(Node->left->left->right->token, "STATIC") == 0)
            isStatic = 1;

        LinkedListNode* item = makeFuncNode(Node->left->token, Node->right->left->token, isStatic, isPrivate);

        if (strcmp(item->function->name, "main") == 0) {
            int flag = 0;
            if (findMainFunction(scope) == 1) {
                printf("ERROR: function declaration error, there can only be one main function.\n");
                flag = 1;
            }
            else if (scope->father != NULL) { //* not in global scope
                printf("ERROR: function declaration error, main function must be declared in global scope.\n");
                flag = 1;
            }
            else if (strcmp(item->function->returnType, "VOID") != 0) {
                printf("ERROR: function declaration error, main function must return void.\n");
                flag = 1;
            }
            else if (isPrivate == 1) {
                printf("ERROR: function declaration error, main function must be public.\n");
                flag = 1;
            }
            else if (isStatic == 0) {
                printf("ERROR: function declaration error, main function must be static.\n");
                flag = 1;
            }
            else if (Node->left->right != NULL) {
                printf("ERROR: function declaration error, main function can't have arguments.\n");
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
            printf("ERROR: redeclaration error, function '%s' is already declared.\n", item->function->name);
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
            semanticChecks(makeScope(scope), temp);
        }
    }

    else if (strcmp(Node->token, "BLOCK") == 0) { 
        semanticChecks(makeScope(scope), Node->left); 
    }

    else if (strcmp(Node->token, "IF") == 0) { 
        // check that condition is of type bool
        char* conditionType = semanticChecks(scope, Node->left->left);
        if (strcmp("BOOL", conditionType) != 0) {
            printf("ERROR: if statement condition must be of type 'BOOL', instead it is '%s'.\n", conditionType);
            free(Node);
            free(scope);
            exit(1);
        }

        LinkedListNode* item = makeVarNode("if", NULL, NULL, NULL);
        addLinkedListNode(scope, item);

        if (strcmp(Node->right->token, "BLOCK") == 0)
            semanticChecks(scope, Node->right); // if - single line statement
        else
            semanticChecks(makeScope(scope), Node->right); // if - multi line block
    }

    else if (strcmp(Node->token, "ELSE") == 0) {
        // adding else block into scope
        LinkedListNode* item = makeVarNode("else", NULL, NULL, NULL);
        addLinkedListNode(scope, item);

        if (strcmp(Node->left->left->token, "BLOCK") == 0)
            semanticChecks(scope, Node->left); // if - single line statement
        else
            semanticChecks(makeScope(scope), Node->left); // if - multi line block 
    }

    else if (strcmp(Node->token, "DO WHILE") == 0) {
        // adding do while block into scope
        LinkedListNode* item = makeVarNode("do", NULL, NULL, NULL);
        addLinkedListNode(scope, item);

        // check that condition is of type bool
        char* conditionType = semanticChecks(scope, Node->right);
        if (strcmp("BOOL", conditionType) != 0) {
            printf("ERROR: do-while loop statement condition must be of type 'BOOL', instead found '%s'.\n", conditionType);
            free(Node);
            free(scope);
            exit(1);
        }
        semanticChecks(scope, Node->left); 
    }

    else if (strcmp(Node->token, "WHILE") == 0) {
        // adding while block into scope
        LinkedListNode* item = makeVarNode("while", NULL, NULL, NULL);
        addLinkedListNode(scope, item);

        char* conditionType = semanticChecks(scope, Node->left);
        if (strcmp("BOOL", conditionType) != 0) {
            printf("ERROR: while loop statement condition must be of type 'BOOL', instead found '%s'.\n", conditionType);
            free(Node);
            free(scope);
            exit(1);
        }

        if (strcmp(Node->right->token, "BLOCK") == 0)
            semanticChecks(scope, Node->right); // while - single line statement
        else
            semanticChecks(makeScope(scope), Node->right); // while - multi line block
    }

    else if (strcmp(Node->token, "FOR") == 0) {
        // adding for block into scope
        LinkedListNode* item = makeVarNode("for", NULL, NULL, NULL);
        addLinkedListNode(scope, item);

        // creating a scope for the for loop manualy
        Scope* forLoopScope = makeScope(scope);

        // checking if for loop has a variable declaration statement
        if (strcmp("ASSIGN", Node->left->token) == 0) {
            // check the assign statement
            if (strcmp(Node->left->left->token, "VAR") == 0)
                semanticChecks(forLoopScope, Node->left->left);

            // check condition type
            char* conditionType = semanticChecks(forLoopScope, Node->left->right);
            if (strcmp("BOOL", conditionType) != 0) {
                printf("ERROR: for loop condition must be of type 'BOOL', instead found '%s'.\n", conditionType);
                free(Node);
                free(forLoopScope);
                free(scope);
                exit(1);
            }

            // check if there is an update statement
            if (Node->left->right->right != NULL) {
                semanticChecks(forLoopScope, Node->left->right->right);
            }
        }
        else { // if there is no var declaration statement then the expression and update pointers are different
            // check condition type
            char* conditionType = semanticChecks(forLoopScope, Node->left);
            if (strcmp("BOOL", conditionType) != 0) {
                printf("ERROR: for loop condition must be of type 'BOOL', instead found '%s'.\n", conditionType);
                free(Node);
                free(forLoopScope);
                free(scope);
                exit(1);
            }

            // check if there is an update statement
            if (Node->left->right != NULL) {
                semanticChecks(forLoopScope, Node->left->right);
            }
        }

        // check the semantics of the for loop block
        semanticChecks(forLoopScope, Node->right->left->left);
    }


    else if (strcmp(Node->token, "UPDATE") == 0) {
        // if there is only one update statement without ','
        if (strcmp(Node->left->token, "EXPRESSION") == 0 
            || strcmp(Node->left->token, "ID ASSIGN") == 0) {
            semanticChecks(scope, Node->left);
        }
        else { // if there are multiple update statements seperated by ','
            semanticChecks(scope, Node->left->left); // check the current update statement
            semanticChecks(scope, Node->left->right); // recursive call to the next update statement
        }
    }



    //? * * * * * * Expressions and Other * * * * * * *//

    else if (strcmp(Node->token, "DECLERATION") == 0) {
        semanticChecks(scope, Node->left);
        if (Node->right != NULL)
            semanticChecks(scope, Node->right);
    }

    else if (strcmp(Node->token, "VAR") == 0) { 
        findAndInitVars(scope, Node->right, Node->left->token);
    }

    else if (strcmp(Node->token, "STRING") == 0) {
        findAndInitStrings(scope, Node->left, Node->token);
    }

    else if (strcmp(Node->token, "ASSIGN") == 0) {
        char* type = semanticChecks(scope, Node->left);
        return type;
    }

    else if (strcmp(Node->token, "ID ASSIGN") == 0) {
        LinkedListNode* varNode = makeVarNode(Node->left->token, NULL, NULL, NULL);
        Variable* var = findVarNodeInScope(scope, varNode);
        if (var == NULL) {
            printf("ERROR: identifier '%s' was not found.\n", Node->left->token);
            free(var);
            free(scope);
            exit(1);
        }
        char* foundType = semanticChecks(scope, Node->right);
        if (strcmp(var->type, foundType) != 0) {
            printf("ERROR: type mismatch for identifier '%s', expected '%s' but found '%s'.\n", Node->left->token, var->type, foundType);
            free(var);
            free(scope);
            exit(1);
        }
        //! saving the token as if its VALUE, need to make it work for every expression
        //var->value = Node->right->left->left->left->left->token; 
    }




    else if (strcmp(Node->token, "EXPRESSION") == 0) {
        // expressions have many options...

        if (strcmp(Node->left->token, "NULL") == 0) {
            return "NULL";
        }
        else if (strcmp(Node->left->left->token, "FUNCTION CALL") == 0) {
            char* type = semanticChecks(scope, Node->left->left);
            return type; 
        }
        else if (strcmp(Node->left->left->token, "ID") == 0) {
            // try to find var in a function argument
            char* typeIfFound = findVarInFuncArgs(scope->father, Node->left->left->left->token);
            if (typeIfFound != NULL) {
                return typeIfFound;
            }
            // otherwise try to find it in a scope
            LinkedListNode* varNode = makeVarNode(Node->left->left->left->token, NULL, NULL, NULL);
            Variable* var = findVarNodeInScope(scope, varNode);
            if (var == NULL) {
                printf("ERROR: identifier '%s' was not found.\n", Node->left->left->left->token);
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
            return semanticChecks(scope, Node->left->left); //* this is the type of the value from yacc
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
            //! check if we need to check for division by zero
            if (strcmp(Node->left->token, "/") == 0) {
                if (strcmp(Node->left->right->left->left->left->token, "0") == 0) {
                    printf("ERROR: division by zero detected.\n");
                    free(scope);
                    exit(1);
                }
            }

            char* leftType = semanticChecks(scope, Node->left->left);
            char* rightType = semanticChecks(scope, Node->left->right);
            char* resType = checkArithmetics(Node->left->token, leftType, rightType);

            if (resType == NULL) {
                printf("ERROR: type mismatch on '%s' operator.\n", Node->left->token);
                free(scope);
                exit(1);
            }
            return resType;
        }

        //todo: other types of expressions.....
    }



    else if (strcmp(Node->token, "FUNCTION CALL") == 0) {
        LinkedListNode* funcNode = makeFuncNode(Node->left->token, NULL, -1, -1);
        Function* func = findFuncNodeInScope(scope, funcNode);
        if (func == NULL) {
            printf("ERROR: function '%s' is not declared.\n", funcNode->function->name);
            free(funcNode);
            free(scope);
            exit(1);
        }

        Function* currentFunction = getCurrentFunction(scope);
        if (currentFunction == NULL) {
            exit(1); //! add print for error mes
        }

        if (currentFunction->isStatic == 1 && func->isStatic == 0) {
            printf("ERROR: static function '%s' cannot call a non-static function '%s'\n", currentFunction->name, func->name);
            exit(1);
        }

        if (currentFunction->isPrivate == 0 && func->isPrivate == 1) {
            Function* funcInCurrentScope = findFuncNodeInCurrentScope(scope->father, funcNode->function->name);    
            if (funcInCurrentScope == NULL) {
                printf("ERROR: public function '%s' cannot call a private function '%s' because they are not in the same scope.\n", currentFunction->name, func->name);
                exit(1);
            } 
        }

        if (Node->right != NULL) { // has params
            node* temp = Node->right;
            int paramCounter = 0;

            do {
                if (paramCounter == func->countArgs) {
                    printf("ERROR: to many arguments in function call '%s()'\n", funcNode->function->name);
                    free(funcNode);
                    free(scope);
                    exit(1); 
                }

                char* paramType = semanticChecks(scope, temp);

                if (strcmp(paramType, func->args[paramCounter]->type) != 0) {
                    printf("ERROR: param type mismatch in function call '%s()' on param '%s'\n",
                        funcNode->function->name, func->args[paramCounter]->name);
                    free(funcNode);
                    free(scope);
                    exit(1); 
                }

                paramCounter++;
                temp = temp->right;
            } while (temp != NULL);

            if (paramCounter < func->countArgs) {
                printf("ERROR: too few arguments in function call '%s()'\n", funcNode->function->name);
                free(funcNode);
                free(scope);
                exit(1); 
            }
        }

        return func->returnType;
    }

    else if (strcmp(Node->token, "RETURN") == 0) {
        Function* currentFunction = getCurrentFunction(scope);
        if (currentFunction == NULL) {
            printf("ERROR: could not find function signiture for in current scope.\n");
            free(scope);
            exit(1); 
        }

        if (Node->left == NULL) {
            if (strcmp(currentFunction->name, "main") != 0) {
                printf("ERROR: return void: 'return ;' can only be in main function. \n");
                free(scope);
                exit(1);
            }
        }
        else {
            char* type = semanticChecks(scope, Node->left);
            if (strcmp(type, currentFunction->returnType) != 0) {
                printf("ERROR: return type mismatch in function '%s', expected '%s' but found '%s'.\n", currentFunction->name, currentFunction->returnType, type);
                free(scope);
                exit(1); 
            }
            return type;
        }
    }


    // printing the scopes for debugging, remove before final submission
    printScope(scope);
    printf("------------------------------------------------------------------\n");
}


/* function to print a linked list */
void printLinkedList(LinkedListNode* list) {
    LinkedListNode* current = list;
    while (current != NULL) {
        if (current->variable != NULL) {
            Variable* var = current->variable;
            printf("%s, %s, %s, %s\t", var->name, var->type, var->value, var->len); //len is for strings [32]
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
