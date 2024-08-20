#ifndef HELPER_H
#define HELPER_H

/*
    Maxim Subotin - 207695479
    Shay Hahiashvili - 206423840
*/

// node struct as given to us, not modified
typedef struct node {
    char* token;
    struct node* left;
    struct node* right;
} node;

node* mknode(char* token, node* left, node* right);
void printtree(node* node, int indent);
char* concat(const char* str1, const char* str2);

#endif // HELPER_H