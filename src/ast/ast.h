#ifndef AST_H
#define AST_H

typedef enum {
    NODE_VAR_DECL, NODE_ASSIGN, NODE_BINOP, NODE_IDENTIFIER, 
    NODE_INT_CONST, NODE_FLOAT_CONST, NODE_BOOL_CONST, 
    NODE_IF, NODE_WHILE, NODE_PRINT, NODE_BLOCK
} NodeType;

typedef struct ASTNode {
    NodeType type;
    char *name;             // For identifiers and operators
    int int_val;            // For int constants
    float float_val;        // For float constants
    int bool_val;           // For boolean constants
    
    struct ASTNode *left;   // Left child (or condition)
    struct ASTNode *right;  // Right child (or body/else)
    struct ASTNode *next;   // For lists of statements
} ASTNode;

ASTNode* create_node(NodeType type);
ASTNode* create_binop(char* op, ASTNode* left, ASTNode* right);
ASTNode* create_identifier(char* name);
ASTNode* create_int_const(int val);

#endif