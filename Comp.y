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

%debug

%token<strval> CHAR INT DOUBLE FLOAT STRING INT_PTR CHAR_PTR DOUBLE_PTR FLOAT_PTR BOOL FOR  
%token<nodeval> IF ELSE VAR ARGS PUBLIC PRIVATE STATIC RETURN NULL_VALUE VOID COMMENT DO WHILE
%token<nodeval> ADD SUB MULT DIVIDE ASSIGN EQUAL GREATER GREATER_EQ LESSER LESSER_EQ NOT NOT_EQ AND OR ADDRESS
%token<nodeval> TRUE_VAL FALSE_VAL 
%token<strval> HEX_VAL STRING_VAL ID CHAR_VAL INT_VAL FLOAT_VAL DOUBLE_VAL 

%left ADD SUB
%left MULT DIVIDE
%left EQUAL NOT_EQ LESSER GREATER LESSER_EQ GREATER_EQ  
%left OR AND
%left ';' ','
%right NOT ADDRESS ASSIGN 
%nonassoc non_else
%nonassoc ELSE

%type<nodeval> assign_statement expression math_expression value for_statement if_statement else_statement block statement_recursive statement program condition while_statement do_while_statement var_assignment many_id param_type string_assignment many_string string_assign_statement 
%%


program : string_assignment {$$ = $1; printtree($$, 0);};

do_while_statement : DO block WHILE '(' condition ')' ';' {$$ = mknode("do_while_statement", $2, $5);};

while_statement : WHILE '(' condition ')' block {$$ = mknode("while_statement", $3, $5);};

for_statement : FOR '(' var_assignment condition ';' math_expression ')' block 
                        {$$ = mknode("for", mknode("var_assignment", $3, mknode("condition", $4, mknode("math_expression", $6, NULL))), mknode("for_block", $8, NULL));};

if_statement : IF '(' condition ')' block %prec non_else {$$ = mknode("if", $3, $5);}
                | IF '(' condition ')' block else_statement {$$ = mknode("if", $3, mknode(" ", $5, $6));};

else_statement : ELSE block {$$ = mknode("else", $2, NULL);}

block : statement {$$ = $1;} 
        | '{' statement_recursive '}' {$$ = mknode("block", $2,NULL);};

statement_recursive : statement {$$ = $1;}
                    | statement_recursive statement {$$ = mknode("statements", $1, $2);};

statement : var_assignment {$$ = $1;} 
                | string_assignment {$$ = $1;}
                | math_expression ';' {$$ = $1;} 
                | if_statement {$$ = $1;} 
                | for_statement {$$ = $1;} 
                | while_statement {$$ = $1;} 
                | do_while_statement {$$ = $1;} 
                | COMMENT {$$ = $1;} ;



string_assignment : STRING many_string ';' {$$ = mknode("new string", $2, NULL);}
                        | ID string_assign_statement ';' {$$ = mknode("assign string", mknode($1, NULL, NULL), $2);}
                        | ID '[' math_expression ']' ASSIGN CHAR_VAL ';' {$$ = mknode("assign string index", mknode("id", mknode($1, NULL, NULL), $3), mknode("assign", mknode($6, NULL, NULL), NULL));}
                         
                        
many_string : ID '[' INT_VAL ']'
                {$$ = mknode("string", mknode($1, NULL, NULL), mknode($3, NULL, NULL));}
            | ID '[' INT_VAL ']' string_assign_statement ',' many_string 
                {$$ = mknode("list", mknode("id", mknode($1, NULL, NULL), mknode($3, NULL, NULL)), mknode("value", $5, $7));};
            | ID '[' INT_VAL ']' ',' many_string
                {$$ = mknode("list", mknode("id", mknode($1, NULL, NULL), mknode($3, NULL, NULL)), $6);}
            | ID '[' INT_VAL ']' string_assign_statement 
                {$$ = mknode("string", mknode("id", mknode($1, NULL, NULL), mknode($3, NULL, NULL)), $5);}
           
string_assign_statement : ASSIGN STRING_VAL {$$ = mknode($2, NULL, NULL);};

var_assignment : VAR param_type ':' many_id ';' {$$ = mknode("new var", $2, $4);}
                 | ID ASSIGN expression ';' {$$ = mknode("assign", mknode($1, $3, NULL), NULL);};            

many_id : ID assign_statement ',' many_id {$$ = mknode($1, $2, $4);}
          | ID ',' many_id {$$ = mknode($1, $3, NULL);}
          | ID assign_statement {$$ = mknode($1, $2, NULL);}
          | ID {$$ = mknode($1, NULL, NULL);};

assign_statement : ASSIGN expression {$$ = mknode("assign", $2, NULL);};

param_type : INT {$$ = mknode($1,NULL,NULL);} 
             | FLOAT {$$ = mknode($1,NULL,NULL);}
             | DOUBLE {$$ = mknode($1,NULL,NULL);}
             | CHAR {$$ = mknode($1,NULL,NULL);}
             | INT_PTR {$$ = mknode($1,NULL,NULL);}
             | FLOAT_PTR {$$ = mknode($1,NULL,NULL);}
             | DOUBLE_PTR {$$ = mknode($1,NULL,NULL);}
             | CHAR_PTR {$$ = mknode($1,NULL,NULL);}
             | BOOL {$$ = mknode($1,NULL,NULL);};

expression : math_expression {$$ = $1;}
                | CHAR_VAL {$$ = mknode($1, NULL, NULL);}
                | STRING_VAL {$$ = mknode($1, NULL, NULL);}
                | NULL_VALUE {$$ = mknode($1, NULL, NULL);};

condition : value LESSER value {$$ = mknode("<", $1, $3);}
                | value LESSER_EQ value {$$ = mknode("<=", $1, $3);}
                | value GREATER value {$$ = mknode(">", $1, $3);}
                | value GREATER_EQ value {$$ = mknode(">=", $1, $3);}
                | value EQUAL value {$$ = mknode("==", $1, $3);}
                | value NOT_EQ value {$$ = mknode("!=", $1, $3);}
                | condition OR condition {$$ = mknode("||", $1, $3);}
                | condition AND condition {$$ = mknode("&&", $1, $3);}

math_expression : value ADD value {$$ = mknode("+", $1, $3);}
                    | value SUB value {$$ = mknode("-", $1, $3);}
                    | value MULT value {$$ = mknode("*", $1, $3);}
                    | value DIVIDE value {$$ = mknode("/", $1, $3);}
                    | '|' value '|' {$$ = mknode("length of array", $2, NULL);}
                    | value {$$ = $1;};


value : INT_VAL {$$ = mknode($1, NULL, NULL);}
        | FLOAT_VAL {$$ = mknode($1, NULL, NULL);}
        | DOUBLE_VAL {$$ = mknode($1, NULL, NULL);}
        | ID {$$ = mknode($1, NULL, NULL);};

%%
#include "lex.yy.c"
int main() {
        //yydebug = 1;  // Enable debugging output
        return yyparse();
}
int yyerror(const char* error){
        printf("syntax error, line: %d\n", yylineno);
        return 0;
}
