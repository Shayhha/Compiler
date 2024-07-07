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

%type<nodeval> assign_statement expression math_expression value for_statement function_return function_block function_static func_many_id func_args_decleration function_args function_return_type function_type function if_statement else_statement block statement_recursive statement program condition while_statement do_while_statement var_assignment many_id param_type string_assignment many_string string_assign_statement 
%%


program : function {$$ = $1; printtree($$, 0);};


function : function_type function_return_type ID '(' function_args ')' function_static function_block 
            {$$ = mknode("Function", $1, mknode("return type", $2, mknode("name", mknode($3, NULL, NULL), mknode("args", $5, mknode("static", $7, mknode("func block", $8, NULL))))));}
        | function_type function_return_type ID '(' function_args ')' function_block
            {$$ = mknode("Function", $1, mknode("return type", $2, mknode("name", mknode($3, NULL, NULL), mknode("args", $5, mknode("func block", $7, NULL)))));}
        | function_type function_return_type ID '(' ')' function_block
            {$$ = mknode("Function", $1, mknode("return type", $2, mknode("name", mknode($3, NULL, NULL), mknode("func block", $6, NULL))));}


function_type : PRIVATE {$$ = $1;}
                | PUBLIC {$$ = $1;}

function_return_type : param_type {$$ = $1;}
                        | STRING {$$ = mknode($1, NULL, NULL);}
                        | VOID {$$ = mknode($1, NULL, NULL);}

function_args : ARGS func_args_decleration {$$ = mknode("args>>", $2, NULL);} 

func_args_decleration : param_type ':' func_many_id ';' func_args_decleration {$$ = mknode("new vars", mknode("params", $1, $3), $5);} 
                        | param_type ':' func_many_id {$$ = mknode("new var", $1, $3);}

func_many_id : ID ',' func_many_id {$$ = mknode($1, $3, NULL);}
                | ID {$$ = mknode($1, NULL, NULL);};

function_static : ':' STATIC {$$ = mknode(":", $2, NULL);} 

function_block : '{' statement_recursive function_return '}' {$$ = mknode("func block", $2, $3);}
                | '{' statement_recursive '}' {$$ = mknode("func block", $2, NULL);}
                | '{' function_return '}' {$$ = mknode("func block", $2, NULL);};

function_return : RETURN expression ';' {$$ = mknode("RETURN", $2, NULL);}
                | RETURN condition ';' {$$ = mknode("RETURN", $2, NULL);;}; 

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
                | function {$$ = $1;}
                | COMMENT {$$ = $1;} 

string_assignment : STRING many_string ';' {$$ = mknode("new string", $2, NULL);}
                        | ID string_assign_statement ';' {$$ = mknode("assign string", mknode($1, NULL, NULL), $2);}
                        | ID '[' math_expression ']' ASSIGN CHAR_VAL ';' {$$ = mknode("assign string index", mknode("id", mknode($1, NULL, NULL), $3), mknode("assign", mknode($6, NULL, NULL), NULL));}             
                        
many_string : ID '[' INT_VAL ']' string_assign_statement 
                {$$ = mknode("string2", mknode("id", mknode($1, NULL, NULL), mknode($3, NULL, NULL)), $5);}
            | ID '[' INT_VAL ']'
                {$$ = mknode("string1", mknode($1, NULL, NULL), mknode($3, NULL, NULL));}
            | ID '[' INT_VAL ']' string_assign_statement ',' many_string 
                {$$ = mknode("list1", mknode("id", mknode($1, NULL, NULL), mknode($3, NULL, NULL)), mknode("value", $5, $7));};
            | ID '[' INT_VAL ']' ',' many_string
                {$$ = mknode("list2", mknode("id", mknode($1, NULL, NULL), mknode($3, NULL, NULL)), $6);}
            
string_assign_statement : ASSIGN STRING_VAL {$$ = mknode($2, NULL, NULL);};


var_assignment : VAR param_type ':' many_id ';' {$$ = mknode("new var", $2, $4);}
                 | ID ASSIGN expression ';' {$$ = mknode("assign", mknode($1, $3, NULL), NULL);}            
                 | MULT ID ASSIGN expression ';' {$$ = mknode("ptr assign", mknode($2, $4, NULL), NULL);};      

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
                | NULL_VALUE {$$ = $1;}
                | ADDRESS ID {$$ = mknode("&", mknode($2,NULL,NULL), NULL);}
                | MULT ID {$$ = mknode("*", mknode($2,NULL,NULL), NULL);}
                | CHAR_VAL {$$ = mknode($1, NULL, NULL);}
                | STRING_VAL {$$ = mknode($1, NULL, NULL);};

condition : value LESSER value {$$ = mknode("<", $1, $3);}
                | value LESSER_EQ value {$$ = mknode("<=", $1, $3);}
                | value GREATER value {$$ = mknode(">", $1, $3);}
                | value GREATER_EQ value {$$ = mknode(">=", $1, $3);}
                | value EQUAL value {$$ = mknode("==", $1, $3);}
                | value NOT_EQ value {$$ = mknode("!=", $1, $3);}
                | NOT value {$$ = mknode("! (not)", $2, NULL);}
                | value {$$ = $1;}
                | '(' condition ')' {$$ = mknode("( )", $2, NULL);}
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
        | TRUE_VAL {$$ = $1;}
        | FALSE_VAL {$$ = $1;}
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
