%{
#include "parser.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int line_num = 1;
%}

%option noyywrap
%option nounput
%option noinput


DIGIT          [0-9]
LETTER         [a-zA-Z_]

ID             {LETTER}({LETTER}|{DIGIT})*
INT_CONST      {DIGIT}+
FLOAT_CONST    {DIGIT}+"."{DIGIT}+


%%


int                 { return INT; }
float               { return FLOAT; }
bool                { return BOOL; }

if                  { return IF; }
else                { return ELSE; }
while               { return WHILE; }
print               { return PRINT; }

true                { return TRUE_CONST; }
false               { return FALSE_CONST; }



"+"                 { return PLUS; }
"-"                 { return MINUS; }
"*"                 { return MULT; }
"/"                 { return DIV; }
"%"                 { return MOD; }

"="                 { return ASSIGN; }


"<="                { return LE; }
">="                { return GE; }
"=="                { return EQ; }
"!="                { return NEQ; }

"<"                 { return LT; }
">"                 { return GT; }

"&&"                { return AND; }
"||"                { return OR; }
"!"                 { return NOT; }



"{"                 { return LBRACE; }
"}"                 { return RBRACE; }

"("                 { return LPAREN; }
")"                 { return RPAREN; }

";"                 { return SEMI; }



{FLOAT_CONST} {
    yylval.float_val = atof(yytext);
    return FLOAT_VAL;
}

{INT_CONST} {
    yylval.int_val = atoi(yytext);
    return INT_VAL;
}

{ID} {
    yylval.str_val = strdup(yytext);
    return IDENTIFIER;
}


[ \t\r]+ {
}


\n {
    line_num++;
}


"//".* {
}


. {
    fprintf(stderr,
            "Lexical Error at line %d: %s\n",
            line_num,
            yytext);
}


%%