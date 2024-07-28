 %{
    #include "Semantics.c" // This is a file that contans the linked list and stack implementations for part 2 of the project
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
%token<strval> IF ELSE VAR ARGS PUBLIC PRIVATE STATIC RETURN NULL_VALUE VOID COMMENT DO WHILE FOR
%token<strval> ADD SUB MULT DIVIDE ASSIGN EQUAL GREATER GREATER_EQ LESSER LESSER_EQ NOT NOT_EQ AND OR ADDRESS
%token<strval> TRUE_VAL FALSE_VAL 
%token<strval> HEX_VAL STRING_VAL ID CHAR_VAL INT_VAL FLOAT_VAL DOUBLE_VAL 

%left ADD SUB
%left MULT DIVIDE
%left EQUAL NOT_EQ LESSER GREATER LESSER_EQ GREATER_EQ  
%left OR AND
%left ';' ','
%right NOT ADDRESS ASSIGN 
%nonassoc non_else
%nonassoc ELSE

%type<nodeval> declaration declarations statement statements assignment code functions function_call update function_params for_init_many for_init expression value for_statement return_statement function_block function_static func_many_id func_args_decleration function_args function_return_type function_type function if_statement else_statement block block_contents program while_statement do_while_statement var_declaration many_id param_type string_declaration many_string 
%%

program : code {$$ = $1; checktree($$); printtree($$, 0);};

code : functions {$$ = mknode("CODE", $1, NULL);}

functions : function functions {$$ = mknode("", $1, $2);}
        | function {$$ = mknode("", $1, NULL);};

function : function_type function_return_type ID '(' function_args ')' function_static function_block 
            {$$ = mknode("FUNCTION", mknode($3, mknode("", $1, $7), mknode("ARGS>>", $5, NULL)), mknode("RETURN", $2, mknode("FUNCTION BLOCK", $8, NULL)));}
        | function_type function_return_type ID '(' function_args ')' function_block
            {$$ = mknode("FUNCTION", mknode($3, mknode("", $1, NULL), mknode("ARGS>>", $5, NULL)), mknode("RETURN", $2, mknode("FUNCTION BLOCK", $7, NULL)));}
        | function_type function_return_type ID '(' ')' function_static function_block
            {$$ = mknode("FUNCTION", mknode($3, mknode("", $1, $6), NULL), mknode("RETURN", $2, mknode("FUNCTION BLOCK", $7, NULL)));}
        | function_type function_return_type ID '(' ')' function_block
            {$$ = mknode("FUNCTION", mknode($3, mknode("", $1, NULL), NULL), mknode("RETURN", $2, mknode("FUNCTION BLOCK", $6, NULL)));}

function_type : PRIVATE {$$ = mknode($1, NULL, NULL);} | PUBLIC {$$ = mknode($1, NULL, NULL);}

function_return_type : param_type {$$ = $1;}
                        | VOID {$$ = mknode($1, NULL, NULL);}

function_args : ARGS func_args_decleration {$$ = mknode("", $2, NULL);} 

func_args_decleration : param_type ':' func_many_id ';' func_args_decleration {$$ = mknode("VAR", mknode("", $1, $3), $5);} 
                        | param_type ':' func_many_id {$$ = mknode("VAR", $1, $3);};


func_many_id : ID ',' func_many_id {$$ = mknode($1, $3, NULL);}
                | ID {$$ = mknode($1, NULL, NULL);};

function_static : ':' STATIC {$$ = mknode($2, NULL, NULL);} 

function_block : '{' block_contents '}' {$$ = $2;}
                | '{' '}' {$$ = NULL;};



function_call : ID '(' function_params ')' {$$ = mknode("FUNCTION CALL", mknode($1, NULL, NULL), $3);}
                | ID '(' ')' {$$ = mknode("FUNCTION CALL", mknode($1, NULL, NULL), NULL);}

function_params : expression ',' function_params {$$ = mknode("EXPRESSION", $1, $3);}
                | expression {$$ = mknode("EXPRESSION", $1, NULL);}



do_while_statement : DO block WHILE '(' expression ')' ';' {$$ = mknode("DO WHILE", $2, mknode("EXPRESSION", $5, NULL));};

while_statement : WHILE '(' expression ')' statement {$$ = mknode($1, mknode("EXPRESSION", $3, NULL), $5);}
                | WHILE '(' expression ')' block {$$ = mknode($1, mknode("EXPRESSION", $3, NULL), $5);};

for_statement : FOR '(' for_init ';' expression ';' update ')' block 
                        {$$ = mknode($1, mknode("ASSIGN", $3, mknode("EXPRESSION", $5, mknode("UPDATE", $7, NULL))), mknode("FOR BLOCK", $9, NULL));}
                | FOR '(' for_init ';' expression ';' ')' block 
                        {$$ = mknode($1, mknode("ASSIGN", $3, mknode("EXPRESSION", $5, NULL)), mknode("FOR BLOCK", $8, NULL));}
                | FOR '(' ';' expression ';' update ')' block 
                        {$$ = mknode($1, mknode("EXPRESSION", $4, mknode("UPDATE", $6, NULL)), mknode("FOR BLOCK", $8, NULL));}
                | FOR '(' ';' expression ';' ')' block 
                        {$$ = mknode($1, mknode("EXPRESSION", $4, NULL), mknode("FOR BLOCK", $7, NULL));}
                | FOR '(' for_init ';' expression ';' update ')' statement
                        {$$ = mknode($1, mknode("ASSIGN", $3, mknode("EXPRESSION", $5, mknode("UPDATE", $7, NULL))), mknode("FOR BLOCK", $9, NULL));}
                | FOR '(' for_init ';' expression ';' ')' statement 
                        {$$ = mknode($1, mknode("ASSIGN", $3, mknode("EXPRESSION", $5, NULL)), mknode("FOR BLOCK", $8, NULL));}
                | FOR '(' ';' expression ';' update ')' statement 
                        {$$ = mknode($1, mknode("EXPRESSION", $4, mknode("UPDATE", $6, NULL)), mknode("FOR BLOCK", $8, NULL));}
                | FOR '(' ';' expression ';' ')' statement 
                        {$$ = mknode($1, mknode("EXPRESSION", $4, NULL), mknode("FOR BLOCK", $7, NULL));};



for_init : VAR param_type ':' for_init_many {$$ = mknode("VAR", $2, $4);}
            | MULT ID ASSIGN expression {$$ = mknode("", mknode($2, mknode("EXPRESSION", $4, NULL), NULL), NULL);}
            | for_init_many {$$ = $1;};

for_init_many : ID assignment ',' for_init_many {$$ = mknode($1, $2, $4);}
          | ID ',' for_init_many {$$ = mknode($1, NULL, $3);}
          | ID assignment {$$ = mknode($1, $2, NULL);}
          | ID {$$ = mknode($1, NULL, NULL);};

update : expression ',' update {$$ = mknode("", mknode("EXPRESSION", $1, NULL), mknode("UPDATE", $3, NULL));}
        | expression {$$ = mknode("EXPRESSION", $1, NULL);}
        | ID assignment ',' update {$$ = mknode("", mknode("ID ASSIGN", mknode($1, NULL, NULL), $2), mknode("UPDATE", $4, NULL));}
        | ID assignment {$$ = mknode("ID ASSIGN", mknode($1, NULL, NULL), $2);}
        


if_statement : IF '(' expression ')' statement %prec non_else {$$ = mknode($1, mknode("CONDITION", mknode("EXPRESSION", $3, NULL), NULL), $5);}
                | IF '(' expression ')' statement else_statement {$$ = mknode("", mknode($1, mknode("CONDITION",mknode("EXPRESSION", $3, NULL), NULL), $5), mknode("ELSE", $6, NULL));};
                | IF '(' expression ')' block %prec non_else {$$ = mknode($1, mknode("CONDITION",mknode("EXPRESSION", $3, NULL), NULL), $5);}
                | IF '(' expression ')' block else_statement {$$ = mknode("", mknode($1, mknode("CONDITION",mknode("EXPRESSION", $3, NULL), NULL), $5), mknode("ELSE", $6, NULL));};

else_statement : ELSE statement {$$ = mknode("", $2, NULL);}
                | ELSE block {$$ = mknode("", $2, NULL);}

return_statement : RETURN expression ';' {$$ = mknode($1, mknode("EXPRESSION", $2, NULL), NULL);}
                 | RETURN ';' {$$ = mknode($1, NULL, NULL);};



block : '{' block_contents '}' {$$ = mknode("BLOCK", $2, NULL);}

block_contents : declarations functions statements {$$ = mknode("", mknode("", $1, $2), $3);}
                | declarations functions {$$ = mknode("", $1, $2);}
                | declarations statements {$$ = mknode("", $1, $2);}
                | functions statements {$$ = mknode("", $1, $2);}
                | declarations {$$ = $1;}
                | functions {$$ = $1;}
                | statements {$$ = $1;}



statement : if_statement {$$ = mknode("",$1,NULL);} 
        | for_statement {$$ = mknode("",$1,NULL);} 
        | while_statement {$$ = mknode("",$1,NULL);} 
        | do_while_statement {$$ = mknode("",$1,NULL);} 
        | COMMENT {$$ = mknode($1, NULL, NULL);} 
        | expression ';' {$$ = mknode("EXPRESSION", $1, NULL);}
        | return_statement {$$ = mknode("",$1,NULL);}
        | '{' '}' {$$ = mknode("",NULL,NULL);};
        | ID assignment ';' {$$ = mknode("ID ASSIGN", mknode($1, NULL, NULL), $2);}            
        | MULT ID assignment ';' {$$ = mknode("* ID ASSIGN", mknode($2, NULL, NULL), $3);}; 
        | ID '[' expression ']' ASSIGN CHAR_VAL ';' {$$ = mknode("ASSIGN[]", mknode("ID", mknode($1, NULL, NULL), mknode("EXPRESSION", $3, NULL)), mknode("ASSIGN", mknode($6, NULL, NULL), NULL));} 
        | ID '[' expression ']' ASSIGN ID ';' {$$ = mknode("ASSIGN[]", mknode("ID", mknode($1, NULL, NULL), mknode("EXPRESSION", $3, NULL)), mknode("ASSIGN", mknode($6, NULL, NULL), NULL));}                          

statements : statement statements {$$ = mknode("", $1, $2);}
        | statement {$$ = $1;}
        | block statements {$$ = mknode("", $1, $2);}
        | block {$$ = $1;}
        


declarations : declaration declarations {$$ = mknode("DECLERATION", $1, $2);} 
        | declaration {$$ = $1;}

declaration : var_declaration {$$ = $1;} 
        | string_declaration {$$ = $1;}

                

string_declaration  : STRING many_string ';' {$$ = mknode("STRING", $2, NULL);}        
                        
many_string : ID '[' INT_VAL ']' assignment ',' many_string 
                {$$ = mknode("", 
                                mknode("", 
                                        mknode(concat($1, concat(concat(" [",$3),"]")), 
                                                mknode($1, NULL, NULL), 
                                                mknode($3, NULL, NULL)),
                                        mknode("", $5, NULL)), 
                                mknode("", $7, NULL));}
            | ID '[' INT_VAL ']' assignment 
                {$$ = mknode("", 
                                mknode("", 
                                        mknode(concat($1, concat(concat(" [",$3),"]")), 
                                                mknode($1, NULL, NULL), 
                                                mknode($3, NULL, NULL)),
                                        mknode("", $5, NULL)), 
                                mknode("", NULL, NULL));}
            | ID '[' INT_VAL ']' ',' many_string
                {$$ = mknode("", 
                                mknode("", 
                                        mknode(concat($1, concat(concat(" [",$3),"]")), 
                                                mknode($1, NULL, NULL), 
                                                mknode($3, NULL, NULL)),
                                        mknode("", NULL, NULL)), 
                                mknode("", $6, NULL));}
            | ID '[' INT_VAL ']'
                {$$ = mknode("", 
                                mknode("", 
                                        mknode(concat($1, concat(concat(" [",$3),"]")), 
                                                mknode($1, NULL, NULL), 
                                                mknode($3, NULL, NULL)),
                                        mknode("", NULL, NULL)), 
                                mknode("", NULL, NULL));}
             


var_declaration : VAR param_type ':' many_id ';' {$$ = mknode("VAR", $2, $4);}

many_id : ID assignment ',' many_id {$$ = mknode($1, $2, $4);}
          | ID ',' many_id {$$ = mknode($1, NULL, $3);} //mknode($1, $3, NULL)
          | ID assignment {$$ = mknode($1, $2, NULL);}
          | ID {$$ = mknode($1, NULL, NULL);};

assignment : ASSIGN expression {$$ = mknode("ASSIGN",mknode("EXPRESSION", $2, NULL),NULL);}
        | ASSIGN ADDRESS ID '[' expression ']' {$$ = mknode(concat("&",$3), mknode("EXPRESSION", $5, NULL), NULL);}



param_type : INT {$$ = mknode($1,NULL,NULL);} 
             | FLOAT {$$ = mknode($1,NULL,NULL);}
             | DOUBLE {$$ = mknode($1,NULL,NULL);}
             | CHAR {$$ = mknode($1,NULL,NULL);}
             | INT_PTR {$$ = mknode($1,NULL,NULL);}
             | FLOAT_PTR {$$ = mknode($1,NULL,NULL);}
             | DOUBLE_PTR {$$ = mknode($1,NULL,NULL);}
             | CHAR_PTR {$$ = mknode($1,NULL,NULL);}
             | BOOL {$$ = mknode($1,NULL,NULL);};


expression : NULL_VALUE {$$ = mknode($1, NULL, NULL);}
            | ADDRESS ID {$$ = mknode("&", mknode($2,NULL,NULL), NULL);} 
            | MULT ID {$$ = mknode("*", mknode($2,NULL,NULL), NULL);}
            | NOT expression {$$ = mknode("! (not)", mknode("EXPRESSION", $2, NULL), NULL);}
            | expression LESSER expression {$$ = mknode("<", mknode("EXPRESSION", $1, NULL), mknode("EXPRESSION", $3, NULL));}
            | expression LESSER_EQ expression {$$ = mknode("<=", mknode("EXPRESSION", $1, NULL), mknode("EXPRESSION", $3, NULL));}
            | expression GREATER expression {$$ = mknode(">", mknode("EXPRESSION", $1, NULL), mknode("EXPRESSION", $3, NULL));}
            | expression GREATER_EQ expression {$$ = mknode(">=", mknode("EXPRESSION", $1, NULL), mknode("EXPRESSION", $3, NULL));}
            | expression EQUAL expression {$$ = mknode("==", mknode("EXPRESSION", $1, NULL), mknode("EXPRESSION", $3, NULL));}
            | expression NOT_EQ expression {$$ = mknode("!=", mknode("EXPRESSION", $1, NULL), mknode("EXPRESSION", $3, NULL));}
            | expression OR expression {$$ = mknode("||", mknode("EXPRESSION", $1, NULL), mknode("EXPRESSION", $3, NULL));}
            | expression AND expression {$$ = mknode("&&", mknode("EXPRESSION", $1, NULL), mknode("EXPRESSION", $3, NULL));}
            | expression ADD expression {$$ = mknode("+", mknode("EXPRESSION", $1, NULL), mknode("EXPRESSION", $3, NULL));}
            | expression SUB expression {$$ = mknode("-", mknode("EXPRESSION", $1, NULL), mknode("EXPRESSION", $3, NULL));}
            | expression MULT expression {$$ = mknode("*", mknode("EXPRESSION", $1, NULL), mknode("EXPRESSION", $3, NULL));}
            | expression DIVIDE expression {$$ = mknode("/", mknode("EXPRESSION", $1, NULL), mknode("EXPRESSION", $3, NULL));}
            | MULT '(' expression ')' {$$ = mknode("*( )", mknode("EXPRESSION", $3, NULL), NULL);}
            | ADDRESS '(' ID ')' {$$ = mknode("&( )", mknode("EXPRESSION", mknode($3, NULL, NULL), NULL), NULL);}
            | '(' expression ')' {$$ = mknode("( )", mknode("EXPRESSION", $2, NULL), NULL);}
            | '|' expression '|' {$$ = mknode("| |", mknode("EXPRESSION", $2, NULL), NULL);}
            | value {$$ = mknode("VALUE", $1, NULL);}
            | function_call {$$ = mknode("", $1, NULL);}
         
           
value : INT_VAL {$$ = mknode("INT", mknode($1, NULL, NULL), NULL);}
        | FLOAT_VAL {$$ = mknode("FLOAT", mknode($1, NULL, NULL), NULL);}
        | DOUBLE_VAL {$$ = mknode("DOUBLE", mknode($1, NULL, NULL), NULL);}
        | SUB INT_VAL {$$ = mknode("INT", mknode(concat("-",$2), NULL, NULL), NULL);}
        | SUB FLOAT_VAL {$$ = mknode("FLOAT", mknode(concat("-",$2), NULL, NULL), NULL);}
        | SUB DOUBLE_VAL {$$ = mknode("DOUBLE", mknode(concat("-",$2), NULL, NULL), NULL);}
        | ADD INT_VAL {$$ = mknode("INT", mknode(concat("+",$2), NULL, NULL), NULL);}
        | ADD FLOAT_VAL {$$ = mknode("FLOAT", mknode(concat("+",$2), NULL, NULL), NULL);}
        | ADD DOUBLE_VAL {$$ = mknode("DOUBLE", mknode(concat("+",$2), NULL, NULL), NULL);}
        | ID {$$ = mknode("ID", mknode($1, NULL, NULL), NULL);}
        | TRUE_VAL {$$ = mknode("BOOL", mknode($1, NULL, NULL), NULL);}
        | FALSE_VAL {$$ = mknode("BOOL", mknode($1, NULL, NULL), NULL);}
        | CHAR_VAL {$$ = mknode("CHAR", mknode($1, NULL, NULL), NULL);}
        | STRING_VAL {$$ = mknode("STRING", mknode($1, NULL, NULL), NULL);}
        | HEX_VAL {$$ = mknode("INT", mknode($1, NULL, NULL), NULL);};

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
