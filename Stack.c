#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Helper.c"

// Constants representing data types
// typedef enum {
//     INT = 0,
//     FLOAT = 1,
//     DOUBLE = 2,
//     CHAR = 3,
//     STRING = 4,
//     BOOL = 5,
//     INT_PTR = 6,
//     FLOAT_PTR = 7,
//     DOUBLE_PTR = 8,
//     FUNC = 9,
// } DataType;

// typedef enum {
//     INT = 0,
//     FLOAT = 1,
//     DOUBLE = 2,
//     CHAR = 3,
//     STRING = 4,
//     BOOL = 5,
//     INT_PTR = 6,
//     FLOAT_PTR = 7,
//     DOUBLE_PTR = 8,
//     VOID = 9,
// } ReturnType;

typedef struct Argument
{
	char* name;
	char* type;
} Argument;

typedef struct Function
{
	char* name;
	struct Argument** args;
    int countArgs;
	char* returnType;
} Function;

typedef struct Varaiables
{
    char* name;
	char* value;
	char* type;
    char* len;
} Varaiable;

typedef struct LinkedListNode {
    struct Variable* variable;
    struct Function* function;
    struct LinkedListNode* next;
} LinkedListNode;

// typedef struct LinkedListNode {
//     char* data;
//     char* type;
//     char* returnType;
//     struct LinkedListNode* next;
// } LinkedListNode;

typedef struct StackNode {
    LinkedListNode* list;
    struct StackNode* next;
} StackNode;

typedef struct {
    StackNode* top;
} Stack;

void checktree(node* Node);
void initStack(Stack* programStack, node* Node);

//function to create a new linked list node
LinkedListNode* makeVarNode(char* name, char* value, char* type, char* len) {
    Varaiable* newVar = (Varaiable*)malloc(sizeof(Varaiable));
    LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));

    newVar->name = name; 
    newVar->value = value;
    newVar->type = type;
    newVar->len = len;

    newNode->variable = newVar;
    newNode->function = NULL;
    newNode->next = NULL;
    return newNode;
}

//function to create a new linked list node
LinkedListNode* makeFuncNode(char* name, char* returnType) {
    Function* newFunc = (Function*)malloc(sizeof(Function));
    LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    
    newFunc->name = name; 
    newFunc->args = NULL;
    newFunc->countArgs = 0;
    newFunc->returnType = returnType;

    newNode->variable = NULL;
    newNode->function = newFunc;
    newNode->next = NULL;
    return newNode;
}

Argument* makeFuncArg(char* name, char* type) {
    Argument* newArg = (Argument*)malloc(sizeof(Argument));
    newArg->name = name;
    newArg->type = type;
    return newArg;
}

void addFuncArguments(Function* func, Argument* newArg) {
    func->args = (Argument**)realloc(func->args, sizeof(Argument*) * (++func->countArgs));
    if (func->args == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE); // Example of error handling, adjust as needed
    }
    func->args[func->countArgs-1] = newArg;
}

// //function to create a new linked list node
// LinkedListNode* makeLinkedListNode(char* data, char* type, char* returnType) {
//     LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
//     newNode->data = data; //set the data inside linked list node
//     newNode->type = type;
//     newNode->returnType = returnType;
//     newNode->next = NULL; //set the next of new node to point to null
//     return newNode;
// }

void addLinkedListNode(StackNode* stackNode, LinkedListNode* listNode) {
    if (stackNode->list == NULL) {
        stackNode->list = listNode;
    }
    else {
        LinkedListNode* temp = stackNode->list;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = listNode;
    }
}

//function to push a new linked list onto the stack
void push(Stack* stack, LinkedListNode* list) {
    StackNode* newStackNode = (StackNode*)malloc(sizeof(StackNode));
    newStackNode->list = list; //set given list into new stack node
    newStackNode->next = stack->top; //set next of new node to point to stack top
    stack->top = newStackNode; //set the top of stack to point to new node
}

//function to pop a linked list from the stack
LinkedListNode* pop(Stack* stack) {
    if (stack->top == NULL) 
        return NULL;
    StackNode* currentNode = stack->top; //get current stackNode
    LinkedListNode* list = currentNode->list; //get linked list of currentNode
    stack->top = stack->top->next; //set the top of stack to point to next stackNode
    free(currentNode); //free popped node
    return list; 
}


//function for checking if the AST is correct semanticly, if so then print success message to the screen, else print where it failed
void checktree(node* Node) {
    Stack* programStack = (Stack*)malloc(sizeof(Stack));

    initStack(programStack, Node);
    printStack(programStack);
    
    free(programStack);
}

void initStack(Stack* programStack, node* Node) {
    printf("current node->token: %s\n", Node->token);

    if (strcmp(Node->token, "}") == 0) {
        //close scope
    }

    else if (strcmp(Node->token, "") == 0) {
        if (Node->left != NULL)
            initStack(programStack, Node->left);
        if (Node->right != NULL)
            initStack(programStack, Node->right);
    }

    else if (strcmp(Node->token, "CODE") == 0) {
        if (Node->left != NULL)
            initStack(programStack, Node->left);
        if (Node->right != NULL)
            initStack(programStack, Node->right);
    }

    else if (strcmp(Node->token, "FUNCTION") == 0) {
        
        if (programStack->top == NULL) {
            LinkedListNode* item = makeFuncNode(Node->left->token, Node->right->left->token);
            // look to see if there are arguments to this function
            if (Node->left->right != NULL) {
                node* temp = Node->left->right;
                if (strcmp(temp->left->left->token, "VAR") == 0) {
                    addFuncArguments(item->function, makeFuncArg(temp->left->left->right->token, temp->left->left->left->token));
                }
                else {
                    addFuncArguments(item->function, makeFuncArg(temp->left->left->left->token, "STRING"));
                }
            }
            push(programStack, item);
        }
        else {
            // look to see if there are arguments to this function before calling addLinkedListNode
            LinkedListNode* item = makeFuncNode(Node->left->token, Node->right->left->token);
            if (Node->left->right != NULL) {
                node* temp = Node->left->right;
                if (strcmp(temp->left->left->token, "VAR") == 0) {
                    addFuncArguments(item->function, makeFuncArg(temp->left->left->right->token, temp->left->left->left->token));
                }
                else {
                    addFuncArguments(item->function, makeFuncArg(temp->left->left->left->token, "STRING"));
                }
            }
            addLinkedListNode(programStack->top, item);
        }
  
        
        node* temp = Node->right->right->left;
        if (temp != NULL) {
            initStack(programStack, temp);
        }
    }

    else if (strcmp(Node->token, "{") == 0) {
        node* temp = Node->left;
        if (temp != NULL) {
            push(programStack, NULL);
            initStack(programStack, temp);
        }
    }

    else if (strcmp(Node->token, "DECLERATION") == 0) {
        initStack(programStack, Node->left);
        if (Node->right != NULL)
            initStack(programStack, Node->right);
    }

    else if (strcmp(Node->token, "VAR") == 0) { // need to think about var int: x,y,z; .....
        if (Node->right->left == NULL)
            addLinkedListNode(programStack->top, makeVarNode(Node->right->token, NULL, Node->left->token, NULL));
        else {
            if (strcmp(Node->right->left->token, "ASSIGN") == 0) {
                addLinkedListNode(programStack->top, makeVarNode(Node->right->token, Node->right->left->left->token, Node->left->token, NULL));
            }
        }
    }

    else if (strcmp(Node->token, "STRING") == 0) {
        if (strcmp(Node->left->left->token, "ID") == 0)
            addLinkedListNode(programStack->top, makeVarNode(Node->left->left->left->token, Node->left->right->left->left->token, "STRING", Node->left->left->right->token));
        else
            addLinkedListNode(programStack->top, makeVarNode(Node->left->left->token, Node->left->right->left->left->token, "STRING", Node->left->right->token));
    }

    // else if (strcmp(Node->token, "ASSIGN") == 0) {
    //     node* temp = Node->left;
    //     addLinkedListNode(programStack->top, makeLinkedListNode(temp->token, "ID", NULL));
    //     initStack(programStack, Node->right);
    // }


}


// During initStack:
// declaring a var that already exists
// redecleration the same var with a different type
// reserved identifier misuse
// assigning wrong type to a var ??

// During checkStack:
// using a var that is not declared / ?initialized?
// calling a function that does not exist
// check that there is only ONE main function
// check static function calls only static functions


// //function to print a linked list
// void printLinkedList(LinkedListNode* list) {
//     LinkedListNode* current = list;
//     while (current != NULL) {
//         printf("%s -> ", current->data);
//         printf("%s -> ", current->type);
//         printf("%s -> ", current->returnType);
//         printf("\t");
//         current = current->next;
//     }
//     printf("NULL\n");
// }

//function to print a linked list
void printLinkedList(LinkedListNode* list) {
    LinkedListNode* current = list;
    while (current != NULL) {
        if (current->variable != NULL) {
            Varaiable* var = current->variable;
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

//function to print the stack of linked lists
void printStack(Stack* stack) {
    StackNode* current = stack->top;
    while (current != NULL) {
        printLinkedList(current->list);
        printf("\n");
        current = current->next;
    }
}


