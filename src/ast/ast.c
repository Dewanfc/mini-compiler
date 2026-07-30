#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ast.h"


ASTNode* create_node(NodeType type)
{
    ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));

    if(node == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }


    node->type = type;

    node->name = NULL;

    node->int_val = 0;
    node->float_val = 0.0;


    node->left = NULL;
    node->right = NULL;
    node->third = NULL;

    node->next = NULL;


    return node;
}



ASTNode* create_identifier(char *name)
{
    ASTNode *node = create_node(NODE_IDENTIFIER);

    node->name = strdup(name);

    return node;
}



ASTNode* create_int_const(int value)
{
    ASTNode *node = create_node(NODE_INT_CONST);

    node->int_val = value;

    return node;
}



ASTNode* create_float_const(float value)
{
    ASTNode *node = create_node(NODE_FLOAT_CONST);

    node->float_val = value;

    return node;
}



ASTNode* create_binop(char *op,
                      ASTNode *left,
                      ASTNode *right)
{
    ASTNode *node = create_node(NODE_BINOP);


    node->name = strdup(op);

    node->left = left;

    node->right = right;


    return node;
}