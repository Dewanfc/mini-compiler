#ifndef AST_H
#define AST_H

typedef enum
{
    NODE_PROGRAM,

    NODE_VAR_DECL,
    NODE_ASSIGN,

    NODE_BINOP,

    NODE_IDENTIFIER,
    NODE_INT_CONST,
    NODE_FLOAT_CONST,

    NODE_PRINT,

    NODE_BLOCK,

    NODE_IF,
    NODE_IF_ELSE,

    NODE_WHILE

} NodeType;



typedef struct ASTNode
{
    NodeType type;

    char *name;

    int int_val;
    float float_val;


    struct ASTNode *left;
    struct ASTNode *right;

    // Used for else block in if-else
    struct ASTNode *third;


    // Linked list of statements
    struct ASTNode *next;


} ASTNode;



ASTNode* create_node(NodeType type);

ASTNode* create_identifier(char *name);

ASTNode* create_int_const(int value);

ASTNode* create_float_const(float value);

ASTNode* create_binop(char *op,
                      ASTNode *left,
                      ASTNode *right);



#endif