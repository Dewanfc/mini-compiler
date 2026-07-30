#ifndef AST_H
#define AST_H

#include <stdbool.h>

/* ===========================
 * AST Node Types
 * =========================== */
typedef enum {
    NODE_SEQ,               /* Sequence of statements */
    NODE_VAR_DECL,          /* Variable declaration */
    NODE_ARRAY_DECL,        /* Array declaration */
    NODE_ASSIGN,            /* Assignment */
    NODE_INT_CONST,         /* Integer constant */
    NODE_FLOAT_CONST,       /* Float constant */
    NODE_BOOL_CONST,        /* Boolean constant */
    NODE_IDENTIFIER,        /* Variable usage */
    NODE_ARRAY_ACCESS,      /* Array element access */
    NODE_BINOP,             /* Binary Operations */
    NODE_UNARY,             /* Unary Operations */
    NODE_IF,                /* If statement */
    NODE_IF_ELSE,           /* If-Else statement */
    NODE_WHILE,             /* While loop */
    NODE_DO_WHILE,          /* Do-While loop */
    NODE_FOR,               /* For loop */
    NODE_SWITCH,            /* Switch statement */
    NODE_CASE,              /* Case block */
    NODE_DEFAULT,           /* Default block */
    NODE_FUNC_DECL,         /* Function declaration */
    NODE_FUNC_CALL,         /* Function call */
    NODE_RETURN,            /* Return statement */
    NODE_PRINT              /* Print statement */
} NodeType;

/* ===========================
 * AST Node Structure
 * =========================== */
typedef struct ASTNode {
    NodeType type;
    
    struct ASTNode* left;
    struct ASTNode* right;
    struct ASTNode* next;

    union {
        int int_val;
        float float_val;
        bool bool_val;
        char* str_val; 
        
        struct {
            char* type_name; 
            char* name;
            struct ASTNode* size; 
        } var_decl;

        struct {
            char* name;
            struct ASTNode* index; 
        } identifier;

        struct {
            struct ASTNode* condition;
            struct ASTNode* if_body;
            struct ASTNode* else_body;
        } if_stmt;

        struct {
            struct ASTNode* condition;
            struct ASTNode* body;
        } loop_stmt;

        struct {
            struct ASTNode* init;
            struct ASTNode* condition;
            struct ASTNode* increment;
            struct ASTNode* body;
        } for_stmt;

        struct {
            struct ASTNode* expr;
            struct ASTNode* cases;
        } switch_stmt;

        struct {
            struct ASTNode* value;
            struct ASTNode* body;
        } case_stmt;

        struct {
            char* return_type;
            char* name;
            struct ASTNode* params;
            struct ASTNode* body;
        } func_decl;

        struct {
            char* name;
            struct ASTNode* args;
        } func_call;

    } data;
} ASTNode;

/* ===========================
 * Constructor Prototypes
 * =========================== */
ASTNode* create_node(NodeType type);
ASTNode* create_seq(ASTNode* stmt1, ASTNode* stmt2);
ASTNode* create_int_const(int val);
ASTNode* create_float_const(float val);
ASTNode* create_bool_const(bool val);
ASTNode* create_identifier(char* name);
ASTNode* create_binop(char* op, ASTNode* left, ASTNode* right);
ASTNode* create_unary(char* op, ASTNode* operand);
ASTNode* create_var_decl(char* type, char* name);
ASTNode* create_array_decl(char* type, char* name, ASTNode* size);
ASTNode* create_array_access(char* name, ASTNode* index);
ASTNode* create_assign(ASTNode* target, ASTNode* expr);
ASTNode* create_if(ASTNode* cond, ASTNode* body);
ASTNode* create_if_else(ASTNode* cond, ASTNode* if_body, ASTNode* else_body);
ASTNode* create_while(ASTNode* cond, ASTNode* body);
ASTNode* create_do_while(ASTNode* cond, ASTNode* body);
ASTNode* create_for(ASTNode* init, ASTNode* cond, ASTNode* inc, ASTNode* body);
ASTNode* create_switch(ASTNode* expr, ASTNode* cases);
ASTNode* create_case(ASTNode* val, ASTNode* body);
ASTNode* create_default(ASTNode* body);
ASTNode* create_function(char* return_type, char* name, ASTNode* params, ASTNode* body);
ASTNode* create_function_call(char* name, ASTNode* args);
ASTNode* create_return(ASTNode* expr);
ASTNode* create_print(ASTNode* expr);

void free_ast(ASTNode* node);

#endif 