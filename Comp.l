%{
    #include <stdio.h>
%}
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
true {yylval = 1; return BOOL;}
false {yylval = 0; return BOOL;}
'[a-zA-Z]' {yylval.str = _strdup(yytext); return CHAR;}
(-)?[1-9]+[0-9]* {yylval = atoi(yytext); return INT;}
(0x|0X)[0-9A-F]+ {yylval.str = _strdup(yytext); return INT;}
\.[0-9]* | \.[1-9][0-9]*([eE][+-]?[0-9]+)? | \.[0-9]+([eE][+-]?[0-9]+)? {yylval.str = _strdup(yytext); return REAL;}
"[a-zA-Z0-9_\s\n]*" {yylval.str = _strdup(yytext); return STRING;}
[a-zA-z][a-zA-z_0-9]* {return VAR;} 
/* add pointers */
/* ================================= */
/* ===========Other Lexemes========= */



/* ================================= */
. return yytext[0];
%%
