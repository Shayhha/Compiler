#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Helper.c"

//* # # # # # # # # # # # # # Declerations # # # # # # # # # # # # # *//

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
int addLineToFile(const char* line);
void printFileContents();

char* getNextVar();
char* getNextLabel();
void make3AC(Stack* stack, node* tree); // Recursive func
void generateCode(node* tree); // Called from YACC

FILE* file;
const char* filename = "output";
static int t = 0; // Number of temporary variable
static int l = 0; // Number of label
static int line = 0; // Number of lines in output file //? not sure if we need it

//* # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # *//



//* # # # # # # # # # # # # # Stack Definition # # # # # # # # # # # # # *//

// Define a node in the stack
typedef struct StackNode {
    char *data;
    struct StackNode *next;
} StackNode;

// Define the stack structure
typedef struct {
    StackNode *top;
} Stack;

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
    printf("Pushed \"%s\"\n", str);
}

// Function to pop a string from the stack
char* pop(Stack *s) {
    if (s->top == NULL) {
        printf("Stack is empty!\n");
        return NULL; // Return NULL to indicate the stack is empty
    }
    StackNode *temp = s->top;
    char *item = temp->data;
    s->top = s->top->next;
    free(temp);
    return item;
}

// Function to peek at the top string of the stack
char* peek(Stack *s) {
    if (s->top == NULL) {
        printf("Stack is empty!\n");
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
    file = fopen(filename, "w");  // Open file for writing
    if (file == NULL) {
        perror("Failed to open file");
        return NULL;  // Indicate failure
    }
    return file;  // Return the file pointer
}

// Function to close the file
void closeFile() {
    if (file != NULL) {
        fclose(file);
    }
}

// Function to add a line to the file
int addLineToFile(const char *line) {
    if (file == NULL) {
        fprintf(stderr, "File is not open.\n");
        return -1;  // Indicate failure
    }
    if (fprintf(file, "%s\n", line) < 0) {
        perror("Failed to write to file");
        return -1;  // Indicate failure
    }
    return 0;  // Indicate success
}

// Function to print the contents of a file
void printFileContents() {
    char buffer[256];  // Buffer to hold file contents
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);  // Print each line
    }
}

//* # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # *//

 


//* # # # # # # # # # # # # # # New Label & New Variable # # # # # # # # # # # # # # *//

// Function to generate the next temporary variable name
char* getNextVar() {
    char *tempVar;
    asprintf(&tempVar, "t%d", t++);
    return tempVar;  // Return the generated name
}

// Function to generate the next label name
char* getNextLabel() {
    char *label;
    asprintf(&label, "L%d", l++);
    return label;  // Return the generated name
}

//* # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # *//




//* # # # # # # # # # # # # # # 3AC Generation # # # # # # # # # # # # # # *//

// Function for generating 3AC and saving it into a file given a AST
void generateCode(node* tree) {
    // Opening the file
    file = openFile();

    // Create 3AC Stack
    Stack* stack = initStack();

    // Make 3AC from AST
    make3AC(stack, tree);

    // Print the file contents for testing, remove later
    printf("\n # # # # # # # # # # FILE CONTENTS # # # # # # # # # # \n");
    printFileContents();
    
    // Print a success message
    printf("\nCreated 3-Address-Code successfuly 🐱‍🚀\n");
    
    // Freeing the global scope
    closeFile();
    freeStack(stack);
}

// Function for converting sub-trees to 3AC and saving it into a file in a recursive manner
void make3AC(Stack* stack, node* tree) { 
    
}

//* 🐤 🐤 🐤 🐤 🐤 🐤 🐤 🐤 🐤 🐤 🐤 🐤 🐤 🐤 🐤 🐤 🐤 🐤 🐤 🐤 🐤 *//
