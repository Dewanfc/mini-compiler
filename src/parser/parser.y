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
    char *str_val;
    struct ASTNode *node;
}


%token <int_val> INT_VAL
%token <float_val> FLOAT_VAL
%token <str_val> IDENTIFIER



%token INT FLOAT BOOL

%token IF ELSE WHILE PRINT

%token TRUE_CONST FALSE_CONST



%token PLUS MINUS MULT DIV MOD

%token ASSIGN



%token LT GT LE GE EQ NEQ

%token AND OR NOT



%token LBRACE RBRACE

%token LPAREN RPAREN

%token SEMI

%type <node> program
%type <node> statements
%type <node> statement

%type <node> block

%type <node> declaration

%type <node> assignment

%type <node> print_statement

%type <node> if_statement

%type <node> while_statement

%type <node> expression
