%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "symtab.h"

extern int yylex();
extern int line_num;
extern char* yytext;
void yyerror(const char *s);

ASTNode* ast_root = NULL;
%}

%code requires {
    #include <stdbool.h>
    #include "ast.h"
}

%union {
    int int_val;
    float float_val;
    bool bool_val;
    char* str_val;
    ASTNode* node;
}

%token <int_val> INT_VAL
%token <float_val> FLOAT_VAL
%token <bool_val> TRUE_CONST FALSE_CONST
%token <str_val> IDENTIFIER

%token INT FLOAT BOOL
%token IF ELSE WHILE FOR DO SWITCH CASE DEFAULT RETURN PRINT

%token INC DEC EQ NEQ LE GE AND OR PLUS MINUS MULT DIV MOD ASSIGN LT GT NOT

%token LBRACE RBRACE LPAREN RPAREN LBRACKET RBRACKET SEMI COMMA COLON

%type <node> program stmt_list stmt block
%type <node> var_decl array_decl expr assign_stmt
%type <node> if_stmt while_stmt do_while_stmt for_stmt switch_stmt
%type <node> case_list case_stmt default_stmt
%type <node> func_decl func_call arg_list param_list param
%type <str_val> type

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%right ASSIGN
%left OR
%left AND
%left EQ NEQ
%left LT GT LE GE
%left PLUS MINUS
%left MULT DIV MOD
%right NOT
%right INC DEC

%%

program:
    stmt_list { ast_root = $1; }
    ;

stmt_list:
    stmt stmt_list { $$ = create_seq($1, $2); }
    |              { $$ = NULL; }
    ;

stmt:
    var_decl SEMI            { $$ = $1; }
    | array_decl SEMI        { $$ = $1; }
    | assign_stmt SEMI       { $$ = $1; }
    | if_stmt                { $$ = $1; }
    | while_stmt             { $$ = $1; }
    | do_while_stmt          { $$ = $1; }
    | for_stmt               { $$ = $1; }
    | switch_stmt            { $$ = $1; }
    | func_decl              { $$ = $1; }
    | func_call SEMI         { $$ = $1; }
    | RETURN expr SEMI       { $$ = create_return($2); }
    | PRINT expr SEMI        { $$ = create_print($2); }
    | block                  { $$ = $1; }
    | expr SEMI              { $$ = $1; }
    ;

block:
    LBRACE { enter_scope(); } stmt_list RBRACE { $$ = $3; exit_scope(); }
    ;

type:
    INT     { $$ = "int"; }
    | FLOAT { $$ = "float"; }
    | BOOL  { $$ = "bool"; }
    ;

var_decl:
    type IDENTIFIER { 
        DataType t = TYPE_UNKNOWN;
        if(strcmp($1, "int")==0) t = TYPE_INT;
        else if(strcmp($1, "float")==0) t = TYPE_FLOAT;
        else if(strcmp($1, "bool")==0) t = TYPE_BOOL;
        insert_symbol($2, t, line_num);
        $$ = create_var_decl($1, $2); 
        free($2); 
    }
    ;

array_decl:
    type IDENTIFIER LBRACKET INT_VAL RBRACKET { 
        DataType t = TYPE_UNKNOWN;
        if(strcmp($1, "int")==0) t = TYPE_INT;
        else if(strcmp($1, "float")==0) t = TYPE_FLOAT;
        else if(strcmp($1, "bool")==0) t = TYPE_BOOL;
        insert_symbol($2, t, line_num);
        $$ = create_array_decl($1, $2, create_int_const($4)); 
        free($2); 
    }
    ;

assign_stmt:
    IDENTIFIER ASSIGN expr { 
        Symbol* sym = lookup_symbol($1);
        if (!sym) {
            fprintf(stderr, "Semantic Error at line %d: Variable '%s' not declared or out of scope\n", line_num, $1);
        } else {
            check_type(sym->type, get_type($3), line_num);
        }
        $$ = create_assign(create_identifier($1), $3); 
        free($1); 
    }
    | IDENTIFIER LBRACKET expr RBRACKET ASSIGN expr { 
        Symbol* sym = lookup_symbol($1);
        if (!sym) {
            fprintf(stderr, "Semantic Error at line %d: Array '%s' not declared or out of scope\n", line_num, $1);
        } else {
            check_type(sym->type, get_type($6), line_num);
        }
        $$ = create_assign(create_array_access($1, $3), $6); 
        free($1); 
    }
    ;

if_stmt:
    IF LPAREN expr RPAREN block %prec LOWER_THAN_ELSE { $$ = create_if($3, $5); }
    | IF LPAREN expr RPAREN block ELSE block          { $$ = create_if_else($3, $5, $7); }
    ;

while_stmt:
    WHILE LPAREN expr RPAREN block { $$ = create_while($3, $5); }
    ;

do_while_stmt:
    DO block WHILE LPAREN expr RPAREN SEMI { $$ = create_do_while($5, $2); }
    ;

for_stmt:
    FOR LPAREN assign_stmt SEMI expr SEMI assign_stmt RPAREN block { $$ = create_for($3, $5, $7, $9); }
    | FOR LPAREN assign_stmt SEMI expr SEMI expr RPAREN block      { $$ = create_for($3, $5, $7, $9); }
    ;

switch_stmt:
    SWITCH LPAREN expr RPAREN LBRACE case_list RBRACE { $$ = create_switch($3, $6); }
    ;

case_list:
    case_stmt case_list  { $$ = create_seq($1, $2); }
    | default_stmt       { $$ = $1; }
    |                    { $$ = NULL; }
    ;

case_stmt:
    CASE INT_VAL COLON stmt_list { $$ = create_case(create_int_const($2), $4); }
    ;

default_stmt:
    DEFAULT COLON stmt_list { $$ = create_default($3); }
    ;

func_decl:
    type IDENTIFIER LPAREN { 
        DataType t = TYPE_UNKNOWN;
        if(strcmp($1, "int")==0) t = TYPE_INT;
        else if(strcmp($1, "float")==0) t = TYPE_FLOAT;
        else if(strcmp($1, "bool")==0) t = TYPE_BOOL;
        insert_symbol($2, t, line_num);
        enter_scope(); 
    } param_list RPAREN block { 
        // Note: param_list shifted to $5 and block to $7 due to mid-rule action
        $$ = create_function($1, $2, $5, $7); 
        free($2); 
        exit_scope();
    }
    ;

param_list:
    param COMMA param_list { $$ = create_seq($1, $3); }
    | param                { $$ = $1; }
    |                      { $$ = NULL; }
    ;

param:
    type IDENTIFIER { 
        DataType t = TYPE_UNKNOWN;
        if(strcmp($1, "int")==0) t = TYPE_INT;
        else if(strcmp($1, "float")==0) t = TYPE_FLOAT;
        else if(strcmp($1, "bool")==0) t = TYPE_BOOL;
        insert_symbol($2, t, line_num);
        $$ = create_var_decl($1, $2); 
        free($2); 
    }
    ;

func_call:
    IDENTIFIER LPAREN arg_list RPAREN { 
        Symbol* sym = lookup_symbol($1);
        if (!sym) {
            fprintf(stderr, "Semantic Error at line %d: Function '%s' not declared\n", line_num, $1);
        }
        $$ = create_function_call($1, $3); 
        free($1); 
    }
    ;

arg_list:
    expr COMMA arg_list { $$ = create_seq($1, $3); }
    | expr              { $$ = $1; }
    |                   { $$ = NULL; }
    ;

expr:
    expr PLUS expr          { $$ = create_binop("+", $1, $3); }
    | expr MINUS expr       { $$ = create_binop("-", $1, $3); }
    | expr MULT expr        { $$ = create_binop("*", $1, $3); }
    | expr DIV expr         { $$ = create_binop("/", $1, $3); }
    | expr MOD expr         { $$ = create_binop("%", $1, $3); }
    
    | expr EQ expr          { $$ = create_binop("==", $1, $3); }
    | expr NEQ expr         { $$ = create_binop("!=", $1, $3); }
    | expr LT expr          { $$ = create_binop("<", $1, $3); }
    | expr GT expr          { $$ = create_binop(">", $1, $3); }
    | expr LE expr          { $$ = create_binop("<=", $1, $3); }
    | expr GE expr          { $$ = create_binop(">=", $1, $3); }
    
    | expr AND expr         { $$ = create_binop("&&", $1, $3); }
    | expr OR expr          { $$ = create_binop("||", $1, $3); }
    
    | NOT expr              { $$ = create_unary("!", $2); }
    | MINUS expr %prec NOT  { $$ = create_unary("-", $2); }
    
    | expr INC              { $$ = create_unary("++", $1); }
    | expr DEC              { $$ = create_unary("--", $1); }
    
    | LPAREN expr RPAREN    { $$ = $2; }
    
    | IDENTIFIER            { 
        Symbol* sym = lookup_symbol($1);
        if (!sym) {
            fprintf(stderr, "Semantic Error at line %d: Variable '%s' not declared or out of scope\n", line_num, $1);
        }
        $$ = create_identifier($1); free($1); 
    }
    | IDENTIFIER LBRACKET expr RBRACKET { 
        Symbol* sym = lookup_symbol($1);
        if (!sym) {
            fprintf(stderr, "Semantic Error at line %d: Array '%s' not declared or out of scope\n", line_num, $1);
        }
        $$ = create_array_access($1, $3); free($1); 
    }
    
    | INT_VAL               { $$ = create_int_const($1); }
    | FLOAT_VAL             { $$ = create_float_const($1); }
    | TRUE_CONST            { $$ = create_bool_const(1); }
    | FALSE_CONST           { $$ = create_bool_const(0); }
    | func_call             { $$ = $1; }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Syntax Error at line %d: %s (near '%s')\n", line_num, s, yytext);
}