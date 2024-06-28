%{
    #include <stdio.h>
%}
%%
/* =========Keywords Lexemes======== */
bool {return BOOL;}
char {return CHAR;}
int {return INT;}
double {return DOUBLE;}
float {return FLOAT};
string {return STRING;}
int* {return INT_PTR;}
char* {return CHAR_PTR;}
double* {return DOUBLE_PTR;}
float* {return FOLAT_PTR;}
if {return IF;}
else {return ELSE;}
while {return WHILE;}
for {return FOR;}
var {return VAR;}
args>> {return ARGS;}
public {return PUBLIC;}
private {return PRIVATE;}
static {return STATIC;}
return {return RETURN;}
null {return NULL;}
void {return VOID;}
do {return DO;}
/* ================================= */
/* =========Operator Lexemes======== */
&& {return AND;}
/ {return DIVIDE;}
<- {return ASSIGN;}
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
true {return TRUE;}
false {return FALSE;}
\'.\'       {
    yylval = mknode1(yytext);
    if(print) printf("CHAR_VALUE\n");
    return CHAR_VALUE;
    }
(-)?[1-9]+[0-9]* {yylval.intval = atoi(yytext); return INT_VAL;}
(0x|0X)[0-9A-F]+ {yylval.strval = strdup(yytext); return HEX_VAL;}
\.[0-9]* | \.[1-9][0-9]*([eE][+-]?[0-9]+)? | \.[0-9]+([eE][+-]?[0-9]+)? {yylval.strval = strdup(yytext); return FLOAT_VAL;}
\".*\"      {
    int len = 0, i = 0;
    while(yytext[len]!='\0'){    
        len++;
    }
    while(yytext[i]!='\0'){
        if(yytext[i] == '"' && i != 0 && i != len-1)
            return 0;
        i++;
    }
    return STRING_VAL;
}
[a-zA-z][a-zA-z0-9_]* {yylval.strval = strdup(yytext); return ID;} 
/* ================================= */
/* ===========Other Lexemes========= */
"/*"([^*]*|(\*+[^/]))*"*/" {return COMMENT;}
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
