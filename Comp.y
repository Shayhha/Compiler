 
%{
    #include "Helper.c"
%}
%union {
    int intval;
    int* intptr;
    float floatval;
    float* floatptr;
    char charval;
    char* strval;
    node* nodeval;
}

%token<strval> BOOL CHAR INT DOUBLE FLOAT STRING INT_PTR CHAR_PTR DOUBLE_PTR FLOAT_PTR
%token<strval> IF ELSE WHILE FOR VAR ARGS PUBLIC PRIVATE STATIC RETURN NULL_VALUE VOID DO ID COMMENT
%token<strval> ADD SUB MULT DIVIDE ASSIGN EQUAL GREATER GREATER_EQ LESSER LESSER_EQ NOT NOT_EQ AND OR ADDRESS
%token<strval> TRUE_VAL FALSE_VAL HEX_VAL STRING_VAL

%token<charval> CHAR_VALUE
%token<intval> INT_VAL
%token<floatval> FLOAT_VAL

%left ADD SUB
%type<nodeval> if_st EXPR
%%

if_st : IF '(' EXPR ')' {$$ = mknode("if", $3, NULL); printtree($$);};
EXPR : TRUE_VAL {$$ = mknode("true", NULL, NULL);} | FALSE_VAL {$$ = mknode("false", NULL, NULL);};

%%
#include "lex.yy.c"
int main() {
 return yyparse();
}
int yyerror(const char* error){
 printf("syntax error\n");
 return 0;
}

