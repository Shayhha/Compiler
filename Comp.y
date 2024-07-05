 %{
    #include "Helper.c"
%}
%union {
    int intval;
    int* intptr;
    float floatval;
    float* floatptr;
    double doubleval;
    double* doubleptr;
    char charval;
    char* strval;
    node* nodeval;
}

%token<strval> CHAR INT DOUBLE FLOAT STRING INT_PTR CHAR_PTR DOUBLE_PTR FLOAT_PTR BOOL
%token<nodeval> IF ELSE WHILE FOR VAR ARGS PUBLIC PRIVATE STATIC RETURN NULL_VALUE VOID DO COMMENT
%token<nodeval> ADD SUB MULT DIVIDE ASSIGN EQUAL GREATER GREATER_EQ LESSER LESSER_EQ NOT NOT_EQ AND OR ADDRESS
%token<nodeval> TRUE_VAL FALSE_VAL 
%token<strval> HEX_VAL STRING_VAL ID CHAR_VAL INT_VAL FLOAT_VAL DOUBLE_VAL 

%left ADD SUB
%type<nodeval> assign_statement expression math_expression value if_statement block else_statement statement_recursive statement
%type<strval> param_type
%%

if_statement : IF '(' math_expression ')' block {$$ = mknode("if", $3, $5); printtree($$, 0);}
                | IF '(' math_expression ')' block else_statement {$$ = mknode("if", $3, mknode(" ", $5, $6)); printtree($$, 0);};

block : statement {$$ = $1;} 
        | '{' statement_recursive '}' {$$ = mknode("block", $2,NULL);};

statement_recursive : statement {$$ = $1;}
                    | statement_recursive statement {$$ = mknode("statements", $1, $2);};

statement : assign_statement | if_statement;

else_statement : ELSE block {$$ = $2;}

assign_statement : param_type ID ASSIGN expression {$$ = mknode($1, mknode($2, NULL, NULL), $4);}
                     | ID ASSIGN expression {$$ = mknode("assign", mknode($1, NULL, NULL), $3);};

param_type : INT | FLOAT | DOUBLE | CHAR | INT_PTR | FLOAT_PTR | DOUBLE_PTR 
                 | CHAR_PTR | BOOL | STRING {$$ = mknode($1,NULL,NULL);};

expression : math_expression ';' {$$ = $1;}
                | CHAR_VAL ';' {$$ = mknode($1, NULL, NULL);}
                | STRING_VAL ';' {$$ = mknode($1, NULL, NULL);}
                | NULL_VALUE ';' {$$ = mknode($1, NULL, NULL);};

math_expression : value ADD value {$$ = mknode("+", $1, $3);}
                    | value SUB value {$$ = mknode("-", $1, $3);}
                    | value MULT value {$$ = mknode("*", $1, $3);}
                    | value DIVIDE value {$$ = mknode("/", $1, $3);}
                    | value {$$ = $1;}

value : INT_VAL {$$ = mknode($1, NULL, NULL);}
        | FLOAT_VAL {$$ = mknode($1, NULL, NULL);}
        | DOUBLE_VAL {$$ = mknode($1, NULL, NULL);}
        | ID {$$ = mknode($1, NULL, NULL);};

%%
#include "lex.yy.c"
int main() {
 return yyparse();
}
int yyerror(const char* error){
 printf("syntax error, line: %d\n", yylineno);
 return 0;
}
