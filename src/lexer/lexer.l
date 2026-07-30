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



DIGIT       [0-9]

LETTER      [a-zA-Z_]

ID          {LETTER}({LETTER}|{DIGIT})*

INT_CONST   {DIGIT}+

FLOAT_CONST {DIGIT}+"."{DIGIT}+


WHITESPACE  [ \t\r]+



%%






"int"           { return INT; }

"float"         { return FLOAT; }

"bool"          { return BOOL; }


"if"            { return IF; }

"else"          { return ELSE; }


"while"         { return WHILE; }

"for"           { return FOR; }

"do"            { return DO; }



"switch"        { return SWITCH; }

"case"          { return CASE; }

"default"       { return DEFAULT; }



"return"        { return RETURN; }


"print"         { return PRINT; }


"true"          { 
                    yylval.bool_val = 1;
                    return TRUE_CONST;
                }


"false"         { 
                    yylval.bool_val = 0;
                    return FALSE_CONST;
                }






"++"            { return INC; }

"--"            { return DEC; }








"+"             { return PLUS; }

"-"             { return MINUS; }

"*"             { return MULT; }

"/"             { return DIV; }

"%"             { return MOD; }



"="             { return ASSIGN; }



"=="            { return EQ; }

"!="            { return NEQ; }



"<="            { return LE; }

">="            { return GE; }


"<"             { return LT; }

">"             { return GT; }



"&&"            { return AND; }

"||"            { return OR; }

"!"             { return NOT; }






"{"             { return LBRACE; }

"}"             { return RBRACE; }



"("             { return LPAREN; }

")"             { return RPAREN; }



"["             { return LBRACKET; }

"]"             { return RBRACKET; }



";"             { return SEMI; }

","             { return COMMA; }



":"             { return COLON; }









{FLOAT_CONST}
{
    yylval.float_val = atof(yytext);

    return FLOAT_VAL;
}



{INT_CONST}
{
    yylval.int_val = atoi(yytext);

    return INT_VAL;
}



{ID}
{
    yylval.str_val = strdup(yytext);

    return IDENTIFIER;
}





"//".*
{
}


"/*"([^*]|\*+[^*/])*\*+"/"
{
}








{WHITESPACE}
{
}



\n
{
    line_num++;
}








.
{
    printf("Lexical Error at line %d: %s\n",
           line_num,
           yytext);
}



%%