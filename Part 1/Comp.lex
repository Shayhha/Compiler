%{
    /*
        Maxim Subotin - 207695479
        Shay Hahiashvili - 206423840
    */
    #include <stdio.h>
%}
%%

"bool" {yylval.strval = strdup("bool"); return BOOL;}
"char" {yylval.strval = strdup("char"); return CHAR;}
"int" {yylval.strval = strdup("int"); return INT;}
"double" {yylval.strval = strdup("double"); return DOUBLE;}
"float" {yylval.strval = strdup("float"); return FLOAT;}
"string" {yylval.strval = strdup("string"); return STRING;}
"int*" {yylval.strval = strdup("int*"); return INT_PTR;}
"char*" {yylval.strval = strdup("char*"); return CHAR_PTR;}
"double*" {yylval.strval = strdup("double*"); return DOUBLE_PTR;}
"float*" {yylval.strval = strdup("float*"); return FLOAT_PTR;}
"if" {yylval.nodeval = mknode("IF",NULL,NULL); return IF;}
"else" {yylval.nodeval = mknode("ELSE",NULL,NULL); return ELSE;}
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

"true" {yylval.nodeval = mknode("TRUE",NULL,NULL); return TRUE_VAL;}
"false" {yylval.nodeval = mknode("FALSE",NULL,NULL); return FALSE_VAL;}

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
