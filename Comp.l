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
/* =========Keywords Lexemes======== */
bool {return BOOL;}
char {return CHAR;}
int {return INT;}
real {return REAL;}
string {return STRING;}
int* {return INT_PTR;}
char* {return CHAR_PTR;}
real* {return REAL_PTR;}
if {return IF;}
else {return ELSE;}
while {return WHILE;}
for {return FOR;}
var {return VAR;}
arg-> {return ARG;}
function {return FUNC;}
return {return RETURN;}
null {return NULL;}
void {return VOID;}
do {return DO;}
/* ================================= */
/* =========Operator Lexemes======== */
&& {return AND;}
/ {return DIVIDE;}
= {return ASSIGN;}
== {return EQUAL;}
> {return GREATER;}
>= {return GREATER_EQ;}
< {return LESSER;}
<= {return LESSER_EQ;}
- {return SUB;}
! {return NOT;}
!= {return NOT_EQ;}
|| {return OR;}
+ {return ADD;}
* {return MULT;}
& {return ADDRESS;}
/* ================================= */
/* =========Literal Lexemes======== */
true | false {yylval.strval = strdup(yytext); return BOOL;}
'[a-zA-Z]' {yylval.strval = strdup(yytext); return CHAR;}
(-)?[1-9]+[0-9]* {yylval.intval = atoi(yytext); return INT;}
(0x|0X)[0-9A-F]+ {yylval.strval = strdup(yytext); return INT;}
\.[0-9]* | \.[1-9][0-9]*([eE][+-]?[0-9]+)? | \.[0-9]+([eE][+-]?[0-9]+)? {yylval.strval = strdup(yytext); return REAL;}
"[a-zA-Z0-9_\s\n]*" {yylval.strval = strdup(yytext); return STRING;}
[a-zA-z][a-zA-z0-9_]* {yylval.strval = strdup(yytext); return VAR;} 
/* add pointers */
/* ================================= */
/* ===========Other Lexemes========= */
/* {return START_COMM;}
*/ {return END_COMM;}
; {return SEMI;}   
, {return COMMA;}
{ {return LEFT_BRACE;}  
} {return RIGHT_BRACE;} 
( {return LEFT_PAREN;}  
) {return RIGHT_PAREN;} 
[ {return LEFT_BRACKET;}  
] {return RIGHT_BRACKET;} 
/* ================================= */
. return yytext[0];
%%
