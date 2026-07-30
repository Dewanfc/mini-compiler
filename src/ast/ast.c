#include <stdlib.h>
#include <string.h>
#include "ast.h"

ASTNode* create_node(NodeType type) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = type;
    node->name = NULL;
    node->left = NULL;
    node->right = NULL;
    node->next = NULL;
    return node;
}

ASTNode* create_binop(char* op, ASTNode* left, ASTNode* right) {
    ASTNode* node = create_node(NODE_BINOP);
    node->name = strdup(op);
    node->left = left;
    node->right = right;
    return node;
}

ASTNode* create_identifier(char* name) {
    ASTNode* node = create_node(NODE_IDENTIFIER);
    node->name = strdup(name);
    return node;
}

ASTNode* create_int_const(int val) {
    ASTNode* node = create_node(NODE_INT_CONST);
    node->int_val = val;
    return node;
}