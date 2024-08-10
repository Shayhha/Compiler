#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Helper.h"

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
long addLineToFile(const char *line);
void replaceNInFile(long posN, long posEnd);

void assignVars(Stack* stack, node* Node);
char* getNextVar();
char* getNextLabel();
char* checkLabel(Stack* stack);
void make3AC(Stack* stack, node* Node); // Recursive func
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

// Function for performing assignment to new variables on decleration
void assignVars(Stack* stack, node* Node) {
    // Check if has assignment or not
    if (Node->left != NULL) { 
        if (strcmp(Node->left->token, "ASSIGN") == 0) { 
            // Handle assignment
            make3AC(stack, Node->left);
            
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
            push(stack, leftVal);
            addLineToFile(temp);
            free(rightVal);
            free(temp);
        }
    }

    // Check if there are more assignment in a recursive manner
    if (Node->right != NULL) { 
        assignVars(stack, Node->right);
    }
}

// Function for performing assignment to new strings on decleration
void assignStrnigs(Stack* stack, node* Node) {

    // Check if there is assignment
    if (Node->left->right->left != NULL) { 
        // Handle assignment
        make3AC(stack, Node->left->right->left);
        
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

    // check if there are more declarations in this declaration
    if (Node->right->left != NULL) {
        assignStrnigs(stack, Node->right->left);
    }
}

// Function for performing assignment to new variables in for loop declerations
void assignForVars(Stack* stack, node* Node) {
    // check if there are more variables to declare in this declaration statement
    if (strcmp(Node->token, "") == 0) {
        assignForVars(stack, Node->left);
        assignForVars(stack, Node->right->left);
    }
    else { 
        if (strcmp(Node->token, "ID ASSIGN") == 0) { 
            // Handle assignment
            make3AC(stack, Node);
        }
    }
}

int incrementFunctionSize(char* type) {
    if (strcmp(type, "INT") == 0) {
        funcSize += 4;
    }
    else if (strcmp(type, "FLOAT") == 0) {
        funcSize += 8;
    }
    else if (strcmp(type, "DOUBLE") == 0) {
        funcSize += 8;
    }
    else if (strcmp(type, "CHAR") == 0) {
        funcSize += 1;
    }
    else if (strcmp(type, "STRING") == 0) {
        funcSize += 4; //? assuming its a pointer and pointers are sizeof 4 byte
    }
    else if (strcmp(type, "BOOL") == 0) {
        funcSize += 1; //? assuming its 1 or 0 then only sizeof 1 byte
    }
}


// Function for checking if we should print a label or not
char* checkLabel(Stack* stack) {
    // Check if the first item in the stack starts with letter 'L', like 'L4', 'L12'
    char* labelVal = peek(stack);
    if ((labelVal != NULL) && (labelVal[0] == 'L')) // check if its indeed a label
        return pop(stack); // Return the acctual lable 
    return NULL; // Return NULL if the top item is not a label
}


// Function for generating 3AC and saving it into a file given a AST
void generateCode(node* tree) {
    // Opening the file
    file = openFile();

    // Create 3AC Stack
    Stack* stack = initStack();

    // Make 3AC from AST
    make3AC(stack, tree);
    
    // Freeing the stack and closing the file
    closeFile();
    freeStack(stack);
}

// Function for converting sub-trees to 3AC and saving it into a file in a recursive manner
void make3AC(Stack* stack, node* Node) { 
    
    if (Node == NULL) { 
        return; // stopping the recursion
    }

    //? * * * * * * Blocks and Scopes * * * * * * *//

    else if (strcmp(Node->token, "") == 0 || strcmp(Node->token, "CODE") == 0) {
        // Go over all left and right sons before stopping the recursion
        if (Node->left != NULL)
            make3AC(stack, Node->left);
        if (Node->right != NULL)
            make3AC(stack, Node->right);
    }

    else if (strcmp(Node->token, "FUNCTION") == 0) {
        // Print function name label and begin line
        addLineToFile(concat(Node->left->token, ":"));

        // Write "BeginFunc N" and save the position of this line
        long posN = addLineToFile("\t\tBeginFunc N\n");
        if (posN == -1) {
            fclose(file);
            exit(1);
        }

        // Handle function body
        make3AC(stack, Node->right->right->left);
        
        // Print end of function and save the position of this line
        addLineToFile("\t\tEndFunc\n");
        long posEnd = addLineToFile(""); // adding a spacer line and saving the position of this line
        if (posEnd == -1) {
            fclose(file);
            exit(1);
        }
        
        // Update the N to be the actual function size
        replaceNInFile(posN, posEnd);
    }

    else if (strcmp(Node->token, "BLOCK") == 0) { 
        // Handle block statements
        make3AC(stack, Node->left);

        // Pop all elements from stack untill you reach a label
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
        int ifAndElseFlag = 0;
        if (Node->right != NULL) 
            ifAndElseFlag = 1;

        char* labelIf = getNextLabel(); 
        char* labelEnd = getNextLabel();
        char* line;

        // Handle condition
        push(stack, labelEnd);
        if (strcmp(Node->left->left->left->token, "||") == 0 || strcmp(Node->left->left->left->token, "&&") == 0)
            push(stack, labelIf);
 
        make3AC(stack, Node->left->left); 

        if (strcmp(Node->left->left->left->token, "||") == 0 || strcmp(Node->left->left->left->token, "&&") == 0)
            pop(stack);

        // Handle if block
        asprintf(&line, "\t%s:", labelIf);
        addLineToFile(line);
        make3AC(stack, Node->left->right);

        if (ifAndElseFlag == 1) {
            char* labelElseStart = labelEnd; 
            char* labelIfEnd = getNextLabel(); 
          
            asprintf(&line, "\t\tgoto %s", labelIfEnd);
            addLineToFile(line);

            // Handle else block (also handles print else label)
            asprintf(&line, "\t%s:", labelElseStart);
            addLineToFile(line);
            push(stack, labelIfEnd);

            make3AC(stack, Node->right->left->left);

            asprintf(&line, "\t%s:", labelIfEnd);
            addLineToFile(line);
        }
        else {
            asprintf(&line, "\t%s:", labelEnd);
            addLineToFile(line);
        }
    }


    else if (strcmp(Node->token, "DO WHILE") == 0) {
        char* doStartLabel = getNextLabel();
        char* doEndLabel = getNextLabel();  
        char* line;

        asprintf(&line, "\t%s:", doStartLabel);
        addLineToFile(line);
        push(stack, doEndLabel);

        // Handle do while block
        make3AC(stack, Node->left);
        
        // Handle condition
        make3AC(stack, Node->right); 
        
        asprintf(&line, "\t\tgoto %s", doStartLabel);
        addLineToFile(line);

        asprintf(&line, "\t%s:", doEndLabel);
        addLineToFile(line);
    }

    else if (strcmp(Node->token, "WHILE") == 0) {
        char* whileStartLabel = getNextLabel();
        char* whileEndLabel = getNextLabel();  
        char* line;

        asprintf(&line, "\t%s:", whileStartLabel);
        addLineToFile(line);
        push(stack, whileEndLabel);
        
        // Handle condition
        make3AC(stack, Node->right);

        // Handle while block
        make3AC(stack, Node->left); 
        
        asprintf(&line, "\t\tgoto %s", whileStartLabel);
        addLineToFile(line);

        asprintf(&line, "\t%s:", whileEndLabel);
        addLineToFile(line);
    }

    else if (strcmp(Node->token, "FOR") == 0) {
        char* forStartLabel = getNextLabel();
        char* forEndLabel = getNextLabel();  
        char* line;

        push(stack, forEndLabel);

        // Handle for init, checking if for loop has a variable declaration statement
        if (strcmp("FOR INIT", Node->left->token) == 0 || strcmp("* ID ASSIGN", Node->left->token) == 0) {
            
            // Handle for var declerations
            if (strcmp(Node->left->left->token, "VAR") == 0)
                assignForVars(stack, Node->left->left->right);
            else
                make3AC(stack, Node->left->left);

            asprintf(&line, "\t%s:", forStartLabel);
            addLineToFile(line);
            
            // Handle for condition
            make3AC(stack, Node->left->right);

            // Handle for block
            make3AC(stack, Node->right->left->left); 

            // Handle for update
            if (Node->left->right->right != NULL) {
                make3AC(stack, Node->left->right->right);
            }
        }
        else { // if there is no var declaration statement then the expression and update pointers are different

            asprintf(&line, "\t%s:", forStartLabel);
            addLineToFile(line);

            // Handle for condition
            make3AC(stack, Node->left);

            // Handle for block
            make3AC(stack, Node->right->left->left); 

            // check if there is an update statement
            if (Node->left->right != NULL) {
                make3AC(stack, Node->left->right);
            }
        }

        asprintf(&line, "\t\tgoto %s", forStartLabel);
        addLineToFile(line);

        asprintf(&line, "\t%s:", forEndLabel);
        addLineToFile(line);
    }

    else if (strcmp(Node->token, "FOR INIT") == 0) {
        if (strcmp(Node->left->token, "") != 0) // if no more recursion
            make3AC(stack, Node->left);
    
        make3AC(stack, Node->left->left); // check current item semantics
        make3AC(stack, Node->left->right); // recursive call
    }

    else if (strcmp(Node->token, "UPDATE") == 0) {
        // if there is only one update statement without ','
        if (strcmp(Node->left->token, "EXPRESSION") == 0 
            || strcmp(Node->left->token, "ID ASSIGN") == 0) {
            make3AC(stack, Node->left);
        }
        else { // if there are multiple update statements seperated by ','
            make3AC(stack, Node->left->left); // check the current update statement
            make3AC(stack, Node->left->right); // recursive call to the next update statement
        }
    }



    //? * * * * * * Expressions and Other * * * * * * *//

    else if (strcmp(Node->token, "DECLERATION") == 0) {
        make3AC(stack, Node->left);
        if (Node->right != NULL)
            make3AC(stack, Node->right);
    }

    else if (strcmp(Node->token, "VAR") == 0) { 
        assignVars(stack, Node->right);
    }

    else if (strcmp(Node->token, "STRING") == 0) {
        assignStrnigs(stack, Node->left);
    }

    else if (strcmp(Node->token, "ASSIGN") == 0) {
        make3AC(stack, Node->left); // Handle assignment statement (will be one of the following 'else if' statements)
    }

    else if (strcmp(Node->token, "ID ASSIGN") == 0) {
        // Handle the right side of the assignment                    
        make3AC(stack, Node->right); 

        // Pop the result of the recursive call on the right side of the assignment, save the left side token
        char* rightVal = pop(stack);
        char* leftVal = Node->left->token;
        char* temp;

        // Print the assignment 
        asprintf(&temp, "\t\t%s = %s", leftVal, rightVal);
        addLineToFile(temp);

        // Count the assignment as well
        incrementFunctionSize(Node->right->left->left->left->token);

        free(rightVal);
        free(temp);
    }
    
    else if (strcmp(Node->token, "* ID ASSIGN") == 0) {

    }

    else if (strcmp(Node->token, "ASSIGN[]") == 0) {

    }

    else if (strcmp(Node->token, "&ID[]") == 0) {
     
    }

    else if (strcmp(Node->token, "ID[]") == 0) {
      
    }


    else if (strcmp(Node->token, "EXPRESSION") == 0) {
        // expressions have many options...

        if (strcmp(Node->left->token, "NULL") == 0) {

        }
        else if (strcmp(Node->left->token, "&") == 0) { 

        }
        else if (strcmp(Node->left->token, "* (pointer)") == 0) { 

        }
        else if (strcmp(Node->left->left->token, "FUNCTION CALL") == 0) {
         
        }
        else if (strcmp(Node->left->left->token, "ID") == 0) {
            // Push the id value to the stack to be used later
            push(stack, Node->left->left->left->token);
        }
        else if (strcmp(Node->left->token, "VALUE") == 0) {
            // Create a new temporary variable t, and check if we need to print a label
            char* nextVarTemp = getNextVar();
            char *temp; 
            char* value = Node->left->left->left->token;

            asprintf(&temp, "\t\t%s = %s", nextVarTemp, value);
            addLineToFile(temp);

            // Push the new temp var to the stack to be used later
            push(stack, nextVarTemp);

            incrementFunctionSize(Node->left->left->token);
        }
        else if (strcmp(Node->left->token, "( )") == 0) {
            make3AC(stack, Node->left->left);
        }
        else if (strcmp(Node->left->token, "| |") == 0) {
            
        }
        else if (strcmp(Node->left->token, "! (not)") == 0) {
            
        }
        else if (strcmp(Node->left->token, "+") == 0
                || strcmp(Node->left->token, "-") == 0
                || strcmp(Node->left->token, "*") == 0
                || strcmp(Node->left->token, "/") == 0) {

            // Handle both sides of the operator, first the left and then the right side
            make3AC(stack, Node->left->left);
            make3AC(stack, Node->left->right);


            // printf("test: %s\n", Node->left->left->left->left->token);
            // printf("test: %s\n", Node->left->right->left->left->token); exit(0);
            // incrementFunctionSize(the value type);
            // incrementFunctionSize(the value type);
            //! problem, if the items are IDs then we cant know their types. 
            //? solution: hold two arrays where the first is all the params (t1, t2, x, y, ...) and the second is their size (4, 4, 8, 1, ...)
            //? then we will be able to search for the id in the first array, and get its size from the second array.

            // Pop right and then left sides of the operator from the stack and get the operator from AST
            char* rightVal = pop(stack);
            char* leftVal = pop(stack);
            char* opVal = Node->left->token;

            // Create a new temp var
            char* tempVar = getNextVar();
            char* computeLine;

            // Print the condition: t0 = a + b
            asprintf(&computeLine, "\t\t%s = %s %s %s", tempVar, leftVal, opVal, rightVal);
 
            // Push the temp var to the stack to be used later
            addLineToFile(computeLine);
            push(stack, tempVar);
            free(computeLine);
            free(rightVal);
            free(leftVal);
        }
        else if (strcmp(Node->left->token, "<") == 0
                || strcmp(Node->left->token, ">") == 0
                || strcmp(Node->left->token, "==") == 0 ) {
                    
            // Handle the left and right side of the condition token
            make3AC(stack, Node->left->left);
            make3AC(stack, Node->left->right);

            // Pop right and then left sides of the operator from the stack and get the operator from AST
            char* rightVal = pop(stack);
            char* leftVal = pop(stack);
            char* opVal = Node->left->token;

            // Create a new temp var
            char* tempVar = getNextVar();
            char* computeLine;

            // Print the condition: t0 = a < b
            asprintf(&computeLine, "\t\t%s = %s %s %s", tempVar, leftVal, opVal, rightVal);
            addLineToFile(computeLine);
            funcSize += 1; // counting the t that holds the condition result 

            char* elseLabel = peek(stack);
            if (elseLabel != NULL) {
                if ((strcmp(elseLabel, "&&") != 0) && (strcmp(elseLabel, "||") != 0)) {
                    asprintf(&computeLine, "\t\tif %s == 0 goto %s", tempVar, elseLabel);
                    addLineToFile(computeLine);
                    push(stack, elseLabel);
                }
                else {
                    pop(stack);
                }
            } 

            // Push the temp var to the stack to be used later
            push(stack, tempVar);
            free(computeLine);
            free(rightVal);
            free(leftVal);  
        }
        else if ( strcmp(Node->left->token, "<=") == 0
                || strcmp(Node->left->token, ">=") == 0 
                || strcmp(Node->left->token, "!=") == 0 ) {




        }
        else if (strcmp(Node->left->token, "&&") == 0) {
            // Get the labels from the stack and push it back into the stack 
            //char* ifLabel = checkLabel(stack);
            // char* elseLabel = checkLabel(stack);
            // push(stack, elseLabel);
            //push(stack, ifLabel);
            
            char* opVal = Node->left->token;
            char* computeLine;

            push(stack, "&&");
            // Handle both sides of the operator, first the left and then the right side
            make3AC(stack, Node->left->left);
            if (strcmp(peek(stack), "&&") != 0) {
                char* leftVal = pop(stack);

                pop(stack);
                char* label1 = pop(stack);
                push(stack, label1);
                asprintf(&computeLine, "\t\tif %s == 0 goto %s", leftVal, label1);
                addLineToFile(computeLine);
            }
            else {
                pop(stack);
            }
            // We only want to print goto if the top of the stack is not a label
            // if ((peek(stack) != NULL) && (peek(stack)[0] != 'L')) {
            //     char* leftVal = pop(stack);
            //     asprintf(&computeLine, "\t\tif %s == 0 goto %s", leftVal, elseLabel);
            //     addLineToFile(computeLine);
            // }
            
            // Right side
            push(stack, "&&");
            make3AC(stack, Node->left->right);
            if (strcmp(peek(stack), "&&") != 0) {
                char* rightVal = pop(stack);

                pop(stack);
                char* label2 = pop(stack);
                push(stack, label2);
                asprintf(&computeLine, "\t\tif %s == 0 goto %s", rightVal, label2);
                addLineToFile(computeLine);
            }
            else {
                pop(stack);
            }
            // We only want to print goto if the top of the stack is not a label
            // if ((peek(stack) != NULL) && (peek(stack)[0] != 'L')) {
            //     char* rightVal = pop(stack);
            //     asprintf(&computeLine, "\t\tif %s == 0 goto %s", rightVal, elseLabel);
            //     addLineToFile(computeLine);
            // }
        }
        else if (strcmp(Node->left->token, "||") == 0) {
            // Get the labels from the stack and push it back into the stack 
            // char* ifLabel = checkLabel(stack);
            // char* elseLabel = checkLabel(stack);
            // push(stack, elseLabel);
            // push(stack, ifLabel);
            
            char* opVal = Node->left->token;
            char* computeLine;

            // Handle both sides of the operator, first the left and then the right side
            push(stack, "||");
            make3AC(stack, Node->left->left);
            if (strcmp(peek(stack), "||") != 0) {
                printf("inside || => ");
                printStack(stack);
                char* leftVal = pop(stack);

                if (strcmp(peek(stack), "||") == 0) {
                    pop(stack);
                }
                char* label1 = pop(stack);
                push(stack, label1);
                asprintf(&computeLine, "\t\tif %s goto %s", leftVal, label1);
                addLineToFile(computeLine);
            }
            // else {
            //     pop(stack);
            // }
            
            // We only want to print goto if the top of the stack is not a label
            // if ((peek(stack) != NULL) && (peek(stack)[0] != 'L')) {
            //     char* leftVal = pop(stack);
            //     asprintf(&computeLine, "\t\tif %s goto %s", leftVal, ifLabel);
            //     addLineToFile(computeLine);
            // }
            
            // Right side
            push(stack, "||");
            make3AC(stack, Node->left->right);
            if (strcmp(peek(stack), "||") != 0) {
                char* rightVal = pop(stack);

                if (strcmp(peek(stack), "||") == 0) {
                    pop(stack);
                }
                printf("right side test1\n");
                char* label2 = pop(stack);
                printf("right side test2\n");
                push(stack, label2);
                printf("right side test3\n");
                asprintf(&computeLine, "\t\tif %s == 0 goto %s", rightVal, label2);
                addLineToFile(computeLine);
            }
            // else {
            //     pop(stack);
            // }
            // We only want to print goto if the top of the stack is not a label
            // if ((peek(stack) != NULL) && (peek(stack)[0] != 'L')) {
            //     char* rightVal = pop(stack);
            //     asprintf(&computeLine, "\t\tif %s == 0 goto %s", rightVal, elseLabel);
            //     addLineToFile(computeLine);
            // }
        }
    }

    else if (strcmp(Node->token, "FUNCTION CALL") == 0) {

    }

    else if (strcmp(Node->token, "RETURN") == 0) {
        char* returnLine;

        // Check if the return has an expression and is not just 'return ;'
        if (Node->left != NULL) {
            char* label = checkLabel(stack);
            if (label != NULL) {
                asprintf(&returnLine, "\t%s:", label);
                addLineToFile(returnLine);
            }

            // Handle the return expression
            make3AC(stack, Node->left);

            // Pop the temp val from the stack
            char* val = pop(stack);

            // Print the return statement 
            asprintf(&returnLine, "\t\treturn %s", val);
            addLineToFile(returnLine);
            free(val);
        }
        else { // Handle the case where return doesnt have an expression
            asprintf(&returnLine, "\t\treturn ;");
            addLineToFile(returnLine);
        }
        free(returnLine);
    }
}

//* 🐤 🐤 🐤 🐤 🐤 🐤 🐤 🐤 🐤 🐤 🐤 🐤 🐤 🐤 🐤 🐤 🐤 🐤 🐤 🐤 🐤 *//
