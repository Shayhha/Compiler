#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    char* token;
    struct node* left;
    struct node* right;
} node;

node* mknode(char* token, node* left, node* right) {
    node* newnode = (node*)malloc(sizeof(node));
    char* newstr = (char*)malloc(sizeof(token)+1);
    strcpy(newstr, token);
    newnode->left = left;
    newnode->right = right;
    newnode->token = newstr;
    return newnode;
}

void printtree(node* node, int indent) {
    // Base case: if node is NULL, just return
    if (node == NULL) {
        return;
    }

    // Print current node with indentation
    for (int i = 0; i < indent; i++) {
        printf("\t");
    }
    printf("%s\n", node->token);

    // Recursively print left and right children with increased indentation
    printtree(node->left, indent + 1);
    printtree(node->right, indent + 1);
}


// char* intToString(int value) {
//     int counter = 0;
//     char* returnValue = NULL;

//     while(value != 0) {
//         value = value%10;
//         counter++;
//         returnValue = (char*)realloc(sizeof(int), sizeof(int)*counter);
//     }

//     sprintf(returnValue, "%d", value);

//     return returnValue;
// }