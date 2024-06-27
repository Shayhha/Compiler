%{
    #include <stdio.h>
%}
%union {
    int intval;
    int* intptr;
    float floatval;
    float* floatptr;
    char charval;
    char* strval;
}
%%






%%
#include "lex.yy.c"

int main() {
 return yyparse();
}

int yyerror(){
 printf("syntax error\n");
 return 0;
}