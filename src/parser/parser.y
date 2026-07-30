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
%token <int_val> INT_VAL

%token <float_val> FLOAT_VAL

%token <bool_val> TRUE_CONST FALSE_CONST


%token <str_val> IDENTIFIER




%token INT FLOAT BOOL


%token IF ELSE

%token WHILE FOR DO


%token SWITCH CASE DEFAULT


%token RETURN


%token PRINT




%token PLUS MINUS MULT DIV MOD

%token ASSIGN


%token LT GT LE GE EQ NEQ

%token AND OR NOT


%token INC DEC



%token LBRACE RBRACE

%token LPAREN RPAREN


%token LBRACKET RBRACKET


%token SEMI COMMA COLON





/* ======================
        TYPES
   ====================== */


%type <node> program

%type <node> statements

%type <node> statement

%type <node> expression

%type <node> block

%type <node> declaration

%type <node> assignment


%type <node> if_statement

%type <node> while_statement

%type <node> for_statement

%type <node> do_statement


%type <node> print_statement


%type <node> function

%type <node> function_call

%type <node> return_statement


%type <node> array_access

%type <node> switch_statement



/* ======================
    PRECEDENCE
   ====================== */


%left OR

%left AND


%left EQ NEQ

%left LT GT LE GE


%left PLUS MINUS

%left MULT DIV MOD


%right NOT

%right UMINUS




%%

program:

    statements
    {
        root=$1;
    }

;




statements:


    statements statement
    {

        ASTNode *temp=$1;


        while(temp->next)
            temp=temp->next;


        temp->next=$2;


        $$=$1;

    }



    |

    statement
    {
        $$=$1;
    }

;





statement:


      declaration

    | assignment

    | print_statement

    | if_statement

    | while_statement

    | for_statement

    | do_statement

    | function

    | return_statement

    | switch_statement

    | block

;





/* ======================
        BLOCK
   ====================== */


block:


LBRACE statements RBRACE

{

    $$=create_node(NODE_BLOCK);

    $$->left=$2;

}


|

LBRACE RBRACE

{

    $$=create_node(NODE_BLOCK);

}

;



/* ======================
        DECLARATION
   ====================== */


declaration:


INT IDENTIFIER SEMI

{

    $$=create_var_decl($2);

}



|

INT IDENTIFIER LBRACKET INT_VAL RBRACKET SEMI

{

    $$=create_array_decl($2,$4);

}

;





