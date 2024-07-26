%{
    #include <stdio.h>
%}
%%

"bool" {yylval.strval = strdup("BOOL"); return BOOL;}
"char" {yylval.strval = strdup("CHAR"); return CHAR;}
"int" {yylval.strval = strdup("INT"); return INT;}
"double" {yylval.strval = strdup("DOUBLE"); return DOUBLE;}
"float" {yylval.strval = strdup("FLOAT"); return FLOAT;}
"string" {yylval.strval = strdup("STRING"); return STRING;}
"int*" {yylval.strval = strdup("INT*"); return INT_PTR;}
"char*" {yylval.strval = strdup("CHAR*"); return CHAR_PTR;}
"double*" {yylval.strval = strdup("DOUBLE*"); return DOUBLE_PTR;}
"float*" {yylval.strval = strdup("FLOAT*"); return FLOAT_PTR;}
"if" {yylval.strval = strdup("IF"); return IF;}
"else" {yylval.strval = strdup("ELSE"); return ELSE;}
"while" {yylval.strval = strdup("WHILE"); return WHILE;}
"for" {yylval.strval = strdup("FOR"); return FOR;}
"var" {yylval.strval = strdup("VAR"); return VAR;}
"args>>" {yylval.strval = strdup("ARGS>>"); return ARGS;}
"public" {yylval.strval = strdup("PUBLIC"); return PUBLIC;}
"private" {yylval.strval = strdup("PRIVATE"); return PRIVATE;}
"static" {yylval.strval = strdup("STATIC"); return STATIC;}
"return" {yylval.strval = strdup("RETURN"); return RETURN;}
"null" {yylval.strval = strdup("NULL"); return NULL_VALUE;}
"void" {yylval.strval = strdup("VOID"); return VOID;}
"do" {yylval.strval = strdup("DO"); return DO;}

"true" {yylval.strval = strdup("TRUE"); return TRUE_VAL;}
"false" {yylval.strval = strdup("FALSE"); return FALSE_VAL;}

\/\*([^*]|(\*+[^*/]))*\*\/ ;

"&&" {return AND;}
"<-" {return ASSIGN;} 
"==" {return EQUAL;}
\> {return GREATER;}
">=" {return GREATER_EQ;}
\< {return LESSER;}
"<=" {return LESSER_EQ;}
\! {return NOT;}
"!=" {return NOT_EQ;}
"||" {return OR;}
\+ {return ADD;}
\- {return SUB;}
\* {return MULT;}
\/ {return DIVIDE;}
\& {return ADDRESS;}

[a-zA-Z][a-zA-Z0-9_]* {yylval.strval = strdup(yytext); return ID;} 

(0x|0X)[0-9A-F]+ {yylval.strval = strdup(yytext); return HEX_VAL;}

[0-9]+\.[0-9]+f|[0-9]+f {yylval.strval = strdup(yytext); return FLOAT_VAL;}

[1-9]+[0-9]*|0 {yylval.strval = strdup(yytext); return INT_VAL;}

[0-9]*(\.[0-9]*)?([Ee][+-]?[0-9]+)? {yylval.strval = strdup(yytext); return DOUBLE_VAL;}

\"[^"]*\" {
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

\'.\' { yylval.strval = strdup(yytext); return CHAR_VAL; }

[ \t]+ ;

[\n] { yylineno++; };

. {return yytext[0];}
%%
