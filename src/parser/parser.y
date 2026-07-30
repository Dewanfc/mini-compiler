%{
#include <stdio.h>
#include <stdlib.h>

#include "src/ast/ast.h"

extern int yylex();
extern int line_num;

void yyerror(const char *s);

ASTNode *root = NULL;

%}
