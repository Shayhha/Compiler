#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// node struct as given to us, not modified
typedef struct node {
    char* token;
    struct node* left;
    struct node* right;
} node;

// mknode function as given to us, not modified
node* mknode(char* token, node* left, node* right) {
    node* newnode = (node*)malloc(sizeof(node));
    char* newstr = (char*)malloc(sizeof(token)+1);
    strcpy(newstr, token);
    newnode->left = left;
    newnode->right = right;
    newnode->token = newstr;
    return newnode;
}

// Modified printtree function that handles indetations, and adds brackets to show the scope of the nodes. 
void printtree(node* node, int indent) {
    // Base case: if node is NULL, just return
    if (node == NULL) {
        return;
    }

    // Print current node with indentation
    if (strcmp(node->token,"") != 0) {
        for (int i = 0; i < indent; i++) { // Adding tabulations
            printf("\t");
        }

        // Recursively print left and right children with increased indentation
        if (node->left == NULL && node->right == NULL)
            printf("%s\n", node->token); // If there are no sons we dont want to print brakets
        else {
            printf("(%s\n", node->token);
            printtree(node->left, indent + 1);
            printtree(node->right, indent + 1);

            for (int i = 0; i < indent; i++) { // Adding tabulations
                printf("\t"); 
            }
            printf(")\n"); // Closing the brakets
        }
    }
    else {
        // Recursively print left and right children with increased indentation
        printtree(node->left, indent);
        printtree(node->right, indent);
    }
}

// A helper function for concatinating two strings, for example: concat("abc", "def") => "abcdef"
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
