%{
    #include <stdio.h>
%}
%%

"bool" {yylval.nodeval = mknode("BOOL",NULL,NULL); return BOOL;}
"char" {yylval.nodeval = mknode("CHAR",NULL,NULL); return CHAR;}
"int" {yylval.nodeval = mknode("INT",NULL,NULL); return INT;}
"double" {yylval.nodeval = mknode("DOUBLE",NULL,NULL); return DOUBLE;}
"float" {yylval.nodeval = mknode("FLOAT",NULL,NULL); return FLOAT;}
"string" {yylval.nodeval = mknode("STRING",NULL,NULL); return STRING;}
"int*" {yylval.nodeval = mknode("INT_PTR",NULL,NULL); return INT_PTR;}
"char*" {yylval.nodeval = mknode("CHAR_PTR",NULL,NULL); return CHAR_PTR;}
"double*" {yylval.nodeval = mknode("DOUBLE_PTR",NULL,NULL); return DOUBLE_PTR;}
"float*" {yylval.nodeval = mknode("FLOAT_PTR",NULL,NULL); return FLOAT_PTR;}
"if" {yylval.strval = strdup(yytext); return IF;}
"else" {yylval.strval = strdup(yytext); return ELSE;}
"while" {yylval.nodeval = mknode("WHILE",NULL,NULL); return WHILE;}
"for" {yylval.nodeval = mknode("FOR",NULL,NULL); return FOR;}
"var" {yylval.nodeval = mknode("VAR",NULL,NULL); return VAR;}
"args>>" {yylval.nodeval = mknode("ARGS",NULL,NULL); return ARGS;}
"public" {yylval.nodeval = mknode("PUBLIC",NULL,NULL); return PUBLIC;}
"private" {yylval.nodeval = mknode("PRIVATE",NULL,NULL); return PRIVATE;}
"static" {yylval.nodeval = mknode("STATIC",NULL,NULL); return STATIC;}
"return" {yylval.nodeval = mknode("RETURN",NULL,NULL); return RETURN;}
"null" {yylval.nodeval = mknode("NULL",NULL,NULL); return NULL_VALUE;}
"void" {yylval.nodeval = mknode("VOID",NULL,NULL); return VOID;}
"do" {yylval.nodeval = mknode("DO",NULL,NULL); return DO;}


"&&" {return AND;}
\/ {return DIVIDE;}
"<-" {return ASSIGN;}
"==" {return EQUAL;}
\> {return GREATER;}
">=" {return GREATER_EQ;}
\< {return LESSER;}
"<=" {return LESSER_EQ;}
\- {return SUB;}
\! {return NOT;}
"!=" {return NOT_EQ;}
"||" {return OR;}
\+ {return ADD;}
\* {return MULT;}
\& {return ADDRESS;}


"true" {yylval.strval = strdup(yytext); return TRUE_VAL;}
"false" {yylval.strval = strdup(yytext); return FALSE_VAL;}

\'.\' { yylval.charval = yytext[0]; return CHAR_VALUE; }
(-)?[1-9]+[0-9]* {yylval.intval = atoi(yytext); return INT_VAL;}
(0x|0X)[0-9A-F]+ {yylval.strval = strdup(yytext); return HEX_VAL;}
\.[0-9]* | \.[1-9][0-9]*([eE][+-]?[0-9]+)? | \.[0-9]+([eE][+-]?[0-9]+)? {yylval.floatval = atoi(yytext); return FLOAT_VAL;}
[a-zA-Z][a-zA-Z0-9]* {yylval.strval = strdup(yytext); return ID;} 
"/*"([^*]*|(\*+[^/]))*"*/" {return COMMENT;}
\".*\" {
    int len = 0, i = 0;
    while(yytext[len] != '\0') { len++; }
    while(yytext[i] != '\0') {
        if(yytext[i] == '"' && i != 0 && i != len - 1) {
            return 0;  // Invalid string format
        }
        i++;
    }
    yylval.strval = strdup(yytext);
    return STRING_VAL;
}
[ \t] {printf("");}
. {return yytext[0];}
%%
