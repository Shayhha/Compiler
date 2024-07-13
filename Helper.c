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
    if (strcmp(node->token,"") != 0) {
        for (int i = 0; i < indent; i++) {
            printf("\t");
        }

        // Recursively print left and right children with increased indentation
        if (node->left == NULL && node->right == NULL)
            printf("%s\n", node->token);
        else {
            printf("(%s\n", node->token);
            printtree(node->left, indent + 1);
            printtree(node->right, indent + 1);

            for (int i = 0; i < indent; i++) {
                printf("\t");
            }
            printf(")\n");
        }
        

    }
    else {
        // Recursively print left and right children with increased indentation
        printtree(node->left, indent);
        printtree(node->right, indent);
    }
}

char* concat(const char* str1, const char* str2) {
    int size1 = strlen(str1), size2 = strlen(str2);
    int newSize = size1 + size2;
 
    char* newStr = (char*)malloc((newSize + 1) * sizeof(char));
    if (strcpy(newStr, str1) == 0)
        return "";
    if (strcat(newStr, str2) == 0)
        return "";

    return newStr; 
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