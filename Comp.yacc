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

%token<strval> CHAR INT DOUBLE FLOAT STRING INT_PTR CHAR_PTR DOUBLE_PTR FLOAT_PTR BOOL   
%token<nodeval> IF ELSE VAR ARGS PUBLIC PRIVATE STATIC RETURN NULL_VALUE VOID COMMENT DO WHILE FOR
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

%type<nodeval> assign_statement code functions function_call update function_params for_init_many for_init expression value for_statement function_return function_block function_static func_many_id func_args_decleration function_args function_return_type function_type function if_statement else_statement block statement_recursive statement program  while_statement do_while_statement var_assignment many_id param_type string_assignment many_string 
%%


program : code {$$ = $1; printtree($$, 0);};

code : functions {$$ = mknode("CODE", $1, NULL);}

functions : function functions {$$ = mknode("", $1, $2);}
        | function {$$ = $1;};

function : function_type function_return_type ID '(' function_args ')' function_static function_block 
            {$$ = mknode("FUNCTION", $1, mknode("RETURN", $2, mknode("", mknode($3, NULL, NULL), mknode("ARGS>>", $5, mknode("", $7, mknode("FUNCTION BLOCK", $8, NULL))))));}
        | function_type function_return_type ID '(' function_args ')' function_block
            {$$ = mknode("FUNCTION", $1, mknode("RETURN", $2, mknode("", mknode($3, NULL, NULL), mknode("ARGS>>", $5, mknode("FUNCTION BLOCK", $7, NULL)))));}
        | function_type function_return_type ID '(' ')' function_static function_block
            {$$ = mknode("FUNCTION", $1, mknode("RETURN", $2, mknode("", mknode($3, NULL, NULL), mknode("", $6, mknode("FUNCTION BLOCK", $7, NULL)))));}
        | function_type function_return_type ID '(' ')' function_block
            {$$ = mknode("FUNCTION", $1, mknode("RETURN", $2, mknode("", mknode($3, NULL, NULL), mknode("FUNCTION BLOCK", $6, NULL))));}

function_type : PRIVATE {$$ = $1;}
                | PUBLIC {$$ = $1;}

function_return_type : param_type {$$ = $1;}
                        | STRING {$$ = mknode($1, NULL, NULL);}
                        | VOID {$$ = $1;}

function_args : ARGS func_args_decleration {$$ = mknode("", $2, NULL);} 

func_args_decleration : param_type ':' func_many_id ';' func_args_decleration {$$ = mknode("VAR", mknode("", $1, $3), $5);} 
                        | param_type ':' func_many_id {$$ = mknode("VAR", $1, $3);}
                        | STRING ':' func_many_id ';' func_args_decleration {$$ = mknode("STRING", mknode("", $3, NULL), $5);} 
                        | STRING ':' func_many_id {$$ = mknode("STRING", $3, NULL);}


func_many_id : ID ',' func_many_id {$$ = mknode($1, $3, NULL);}
                | ID {$$ = mknode($1, NULL, NULL);};

function_static : ':' STATIC {$$ = mknode(":", $2, NULL);} 

function_block : '{' statement_recursive function_return '}' {$$ = mknode("", $2, $3);}
                | '{' statement_recursive '}' {$$ = mknode("", $2, NULL);}
                | '{' function_return '}' {$$ = mknode("", $2, NULL);};
                | '{' '}' {$$ = NULL;};

function_return : RETURN expression ';' {$$ = mknode("RETURN", $2, NULL);};




function_call : ID '(' function_params ')' {$$ = mknode(concat($1,"( params: ... )"), $3, NULL);}
                | ID '(' ')' {$$ = mknode(concat($1,"()"), NULL, NULL);}

function_params : expression ',' function_params {$$ = mknode("", $1, $3);}
                | expression {$$ = $1;}
                






do_while_statement : DO block WHILE '(' expression ')' ';' {$$ = mknode("DO WHILE", $2, $5);};

while_statement : WHILE '(' expression ')' block {$$ = mknode("WHILE", $3, $5);};

for_statement : FOR '(' for_init ';' expression ';' update ')' block 
                        {$$ = mknode("FOR", mknode("ASSIGN", $3, mknode("EXPRESSION", $5, mknode("UPDATE", $7, NULL))), mknode("FOR BLOCK", $9, NULL));};
                | FOR '(' for_init ';' expression ';' ')' block 
                        {$$ = mknode("FOR", mknode("ASSIGN", $3, mknode("EXPRESSION", $5, NULL)), mknode("FOR BLOCK", $8, NULL));};
                | FOR '(' ';' expression ';' update ')' block 
                        {$$ = mknode("FOR", mknode("EXPRESSION", $4, mknode("UPDATE", $6, NULL)), mknode("FOR BLOCK", $8, NULL));};
                | FOR '(' ';' expression ';' ')' block 
                        {$$ = mknode("FOR", mknode("EXPRESSION", $4, NULL), mknode("FOR BLOCK", $7, NULL));};



for_init : VAR param_type ':' for_init_many {$$ = mknode("", $2, $4);}
            | MULT ID ASSIGN expression {$$ = mknode("", mknode($2, $4, NULL), NULL);}
            | for_init_many {$$ = $1;};

for_init_many : ID assign_statement ',' for_init_many {$$ = mknode($1, $2, $4);}
          | ID ',' for_init_many {$$ = mknode($1, $3, NULL);}
          | ID assign_statement {$$ = mknode($1, $2, NULL);}
          | ID {$$ = mknode($1, NULL, NULL);};

update : expression ',' update {$$ = mknode("", $1, $3);}
        | expression {$$ = $1;}
        | ID assign_statement ',' update {$$ = mknode(concat("ASSIGN  ",$1), $2, $4);}
        | ID assign_statement {$$ = mknode(concat("ASSIGN  ",$1), $2, NULL);}
        

if_statement : IF '(' expression ')' block %prec non_else {$$ = mknode("IF", mknode("CONDITION",$3, NULL), $5);}
                | IF '(' expression ')' block else_statement {$$ = mknode("", mknode("IF", mknode("CONDITION",$3, NULL), $5), mknode("ELSE", $6, NULL));};

else_statement : ELSE block {$$ = mknode("", $2, NULL);}




block : statement {$$ = mknode("STATEMENT", $1, NULL);} 
        | '{' statement_recursive '}' {$$ = mknode("BLOCK", $2,NULL);};

statement_recursive : statement {$$ = $1;}
                    | statement_recursive statement {$$ = mknode("", $1, $2);};

statement : var_assignment {$$ = $1;} 
                | string_assignment {$$ = $1;}
                | if_statement {$$ = $1;} 
                | for_statement {$$ = $1;} 
                | while_statement {$$ = $1;} 
                | do_while_statement {$$ = $1;} 
                | function {$$ = $1;}
                | COMMENT {$$ = $1;} 
                | expression ';' {$$ = $1;}
                

                    

string_assignment : STRING many_string ';' {$$ = mknode("STRING", $2, NULL);}
                    | ID '[' expression ']' ASSIGN CHAR_VAL ';' {$$ = mknode("ASSIGN[]", mknode("ID", mknode($1, NULL, NULL), $3), mknode("assign", mknode($6, NULL, NULL), NULL));} 
                    | ID '[' expression ']' ASSIGN ID ';' {$$ = mknode("ASSIGN[]", mknode("ID", mknode($1, NULL, NULL), $3), mknode("assign", mknode($6, NULL, NULL), NULL));}                         
                        
many_string : ID '[' INT_VAL ']' assign_statement ',' many_string 
                {$$ = mknode("", mknode("ID", mknode($1, NULL, NULL), mknode(concat(concat("[",$3),"]"), NULL, NULL)), mknode("ASSIGN", $5, $7));}
            | ID '[' INT_VAL ']' assign_statement 
                {$$ = mknode("", mknode("ID", mknode($1, NULL, NULL), mknode(concat(concat("[",$3),"]"), NULL, NULL)), mknode("ASSIGN",$5,NULL));}
            | ID '[' INT_VAL ']' ',' many_string
                {$$ = mknode("", mknode("ID", mknode($1, NULL, NULL), mknode(concat(concat("[",$3),"]"), NULL, NULL)), $6);}
            | ID '[' INT_VAL ']'
                {$$ = mknode("", mknode($1, NULL, NULL), mknode(concat(concat("[",$3),"]"), NULL, NULL));};
             


var_assignment : VAR param_type ':' many_id ';' {$$ = mknode("ASSIGN", $2, $4);}
                 | ID assign_statement ';' {$$ = mknode("ASSIGN", mknode($1, NULL, NULL), $2);}            
                 | MULT ID assign_statement ';' {$$ = mknode("ASSIGN", mknode($2, NULL, NULL), $3);};      

many_id : ID assign_statement ',' many_id {$$ = mknode($1, $2, $4);}
          | ID ',' many_id {$$ = mknode($1, $3, NULL);}
          | ID assign_statement {$$ = mknode($1, $2, NULL);}
          | ID {$$ = mknode($1, NULL, NULL);};

assign_statement : ASSIGN expression {$$ = $2;}
                  | ASSIGN ADDRESS ID '[' expression ']' {$$ = mknode(concat("&",$3), $5, NULL);}



param_type : INT {$$ = mknode($1,NULL,NULL);} 
             | FLOAT {$$ = mknode($1,NULL,NULL);}
             | DOUBLE {$$ = mknode($1,NULL,NULL);}
             | CHAR {$$ = mknode($1,NULL,NULL);}
             | INT_PTR {$$ = mknode($1,NULL,NULL);}
             | FLOAT_PTR {$$ = mknode($1,NULL,NULL);}
             | DOUBLE_PTR {$$ = mknode($1,NULL,NULL);}
             | CHAR_PTR {$$ = mknode($1,NULL,NULL);}
             | BOOL {$$ = mknode($1,NULL,NULL);};

expression : NULL_VALUE {$$ = $1;}
            | ADDRESS ID {$$ = mknode("&", mknode($2,NULL,NULL), NULL);}
            | MULT ID {$$ = mknode("*", mknode($2,NULL,NULL), NULL);}
            | NOT expression {$$ = mknode("! (not)", $2, NULL);}
            | expression LESSER expression {$$ = mknode("<", $1, $3);}
            | expression LESSER_EQ expression {$$ = mknode("<=", $1, $3);}
            | expression GREATER expression {$$ = mknode(">", $1, $3);}
            | expression GREATER_EQ expression {$$ = mknode(">=", $1, $3);}
            | expression EQUAL expression {$$ = mknode("==", $1, $3);}
            | expression NOT_EQ expression {$$ = mknode("!=", $1, $3);}
            | expression OR expression {$$ = mknode("||", $1, $3);}
            | expression AND expression {$$ = mknode("&&", $1, $3);}
            | expression ADD expression {$$ = mknode("+", $1, $3);}
            | expression SUB expression {$$ = mknode("-", $1, $3);}
            | expression MULT expression {$$ = mknode("*", $1, $3);}
            | expression DIVIDE expression {$$ = mknode("/", $1, $3);}
            | MULT '(' expression ')' {$$ = mknode("*( )", $3, NULL);}
            | ADDRESS '(' ID ')' {$$ = mknode("&( )", mknode($3,NULL,NULL), NULL);}
            | '(' expression ')' {$$ = mknode("( )", $2, NULL);}
            | '|' expression '|' {$$ = mknode("| |", $2, NULL);}
            | value {$$ = $1;}
            | function_call {$$ = $1;}
         

           
value : INT_VAL {$$ = mknode($1, NULL, NULL);}
        | FLOAT_VAL {$$ = mknode($1, NULL, NULL);}
        | DOUBLE_VAL {$$ = mknode($1, NULL, NULL);}
        | SUB INT_VAL {$$ = mknode(concat("-",$2), NULL, NULL);}
        | SUB FLOAT_VAL {$$ = mknode(concat("-",$2), NULL, NULL);}
        | SUB DOUBLE_VAL {$$ = mknode(concat("-",$2), NULL, NULL);}
        | ADD INT_VAL {$$ = mknode(concat("+",$2), NULL, NULL);}
        | ADD FLOAT_VAL {$$ = mknode(concat("+",$2), NULL, NULL);}
        | ADD DOUBLE_VAL {$$ = mknode(concat("+",$2), NULL, NULL);}
        | ID {$$ = mknode($1, NULL, NULL);}
        | TRUE_VAL {$$ = $1;}
        | FALSE_VAL {$$ = $1;}
        | CHAR_VAL {$$ = mknode($1, NULL, NULL);}
        | STRING_VAL {$$ = mknode($1, NULL, NULL);}
        | HEX_VAL {$$ = mknode($1, NULL, NULL);};

%%
#include "lex.yy.c"
int main() {
        //yydebug = 1;  // Enable debugging output
        return yyparse();
}
int yyerror(const char* error){
        int yydebug = 1;
        fflush(stdout);
        fprintf(stderr, "ERROR\n");
        fprintf(stderr, "%s at line %d\n", error, yylineno);
        fprintf(stderr, "rejected token: %s\n", yytext);
        return 0;
}
