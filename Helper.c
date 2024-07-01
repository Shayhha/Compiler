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

void printtree(node* tree) {
    printf("%s\n", tree->token);
    if (tree->left) printtree(tree->left);
    if (tree->right) printtree(tree->right);
}

