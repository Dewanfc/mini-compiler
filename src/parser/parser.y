%{

#include <stdio.h>
#include <stdlib.h>

#include "src/ast/ast.h"


extern int yylex();

extern int line_num;


void yyerror(const char *s);



ASTNode *root = NULL;


%}



%union
{

    int int_val;

    float float_val;

    int bool_val;

    char *str_val;


    ASTNode *node;

}




/* ======================
        TOKENS
   ====================== */
