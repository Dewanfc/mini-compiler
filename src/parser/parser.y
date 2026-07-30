%{
#include <stdio.h>
#include <stdlib.h>

#include "src/ast/ast.h"

extern int yylex();
extern int line_num;

void yyerror(const char *s);

ASTNode* root = NULL;

%}


%union {
    int int_val;
    float float_val;
    char* str_val;
    struct ASTNode* node;
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
%type <node> expression
%type <node> if_statement
%type <node> while_statement



%left OR
%left AND
%left EQ NEQ
%left LT GT LE GE
%left PLUS MINUS
%left MULT DIV MOD
%right NOT



%%


program:
    statements
    {
        root = $1;
    }
;



statements:
      statements statement
      {
          ASTNode *current = $1;

          if(current != NULL)
          {
              while(current->next != NULL)
                  current = current->next;

              current->next = $2;
              $$ = $1;
          }
          else
          {
              $$ = $2;
          }
      }

    | statement
      {
          $$ = $1;
      }
;



statement:
      declaration
    | assignment
    | print_statement
    | if_statement
    | while_statement
    | block
;



declaration:
      INT IDENTIFIER SEMI
      {
          $$ = create_node(NODE_VAR_DECL);
          $$->name = $2;
      }

    | FLOAT IDENTIFIER SEMI
      {
          $$ = create_node(NODE_VAR_DECL);
          $$->name = $2;
      }

    | BOOL IDENTIFIER SEMI
      {
          $$ = create_node(NODE_VAR_DECL);
          $$->name = $2;
      }
;



assignment:
      IDENTIFIER ASSIGN expression SEMI
      {
          ASTNode *id =
              create_identifier($1);

          $$ = create_binop("=",
                            id,
                            $3);

          $$->type = NODE_ASSIGN;
      }
;



print_statement:
      PRINT expression SEMI
      {
          $$ = create_node(NODE_PRINT);
          $$->left = $2;
      }
;



if_statement:
      IF LPAREN expression RPAREN block
      {
          $$ = create_node(NODE_IF);

          $$->left = $3;
          $$->right = $5;
      }
;



while_statement:
      WHILE LPAREN expression RPAREN block
      {
          $$ = create_node(NODE_WHILE);

          $$->left = $3;
          $$->right = $5;
      }
;



block:
      LBRACE statements RBRACE
      {
          $$ = create_node(NODE_BLOCK);
          $$->left = $2;
      }

    | LBRACE RBRACE
      {
          $$ = create_node(NODE_BLOCK);
      }
;



expression:
      expression PLUS expression
      {
          $$ = create_binop("+",
                            $1,
                            $3);
      }

    | expression MINUS expression
      {
          $$ = create_binop("-",
                            $1,
                            $3);
      }

    | expression MULT expression
      {
          $$ = create_binop("*",
                            $1,
                            $3);
      }

    | expression DIV expression
      {
          $$ = create_binop("/",
                            $1,
                            $3);
      }

    | INT_VAL
      {
          $$ = create_int_const($1);
      }

    | IDENTIFIER
      {
          $$ = create_identifier($1);
      }
;



%%


void yyerror(const char *s)
{
    fprintf(stderr,
            "Syntax Error at line %d: %s\n",
            line_num,
            s);
}