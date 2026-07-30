#include "ast.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

ASTNode* create_node(NodeType type) {
    ASTNode* node = (ASTNode*)calloc(1, sizeof(ASTNode));
    if (!node) {
        fprintf(stderr, "Fatal Error: Out of memory!\n");
        exit(1);
    }
    node->type = type;
    return node;
}

ASTNode* create_seq(ASTNode* stmt1, ASTNode* stmt2) {
    if (stmt1 == NULL) return stmt2;
    if (stmt2 == NULL) return stmt1;
    ASTNode* node = create_node(NODE_SEQ);
    node->left = stmt1;
    node->right = stmt2;
    return node;
}

ASTNode* create_int_const(int val) {
    ASTNode* node = create_node(NODE_INT_CONST);
    node->data.int_val = val;
    return node;
}

ASTNode* create_float_const(float val) {
    ASTNode* node = create_node(NODE_FLOAT_CONST);
    node->data.float_val = val;
    return node;
}

ASTNode* create_bool_const(bool val) {
    ASTNode* node = create_node(NODE_BOOL_CONST);
    node->data.bool_val = val;
    return node;
}

ASTNode* create_identifier(char* name) {
    ASTNode* node = create_node(NODE_IDENTIFIER);
    node->data.identifier.name = strdup(name);
    node->data.identifier.index = NULL;
    return node;
}

ASTNode* create_binop(char* op, ASTNode* left, ASTNode* right) {
    ASTNode* node = create_node(NODE_BINOP);
    node->data.str_val = strdup(op);
    node->left = left;
    node->right = right;
    return node;
}

ASTNode* create_unary(char* op, ASTNode* operand) {
    ASTNode* node = create_node(NODE_UNARY);
    node->data.str_val = strdup(op);
    node->left = operand;
    return node;
}

ASTNode* create_var_decl(char* type, char* name) {
    ASTNode* node = create_node(NODE_VAR_DECL);
    node->data.var_decl.type_name = strdup(type);
    node->data.var_decl.name = strdup(name);
    node->data.var_decl.size = NULL;
    return node;
}

ASTNode* create_array_decl(char* type, char* name, ASTNode* size) {
    ASTNode* node = create_node(NODE_ARRAY_DECL);
    node->data.var_decl.type_name = strdup(type);
    node->data.var_decl.name = strdup(name);
    node->data.var_decl.size = size;
    return node;
}

ASTNode* create_array_access(char* name, ASTNode* index) {
    ASTNode* node = create_node(NODE_ARRAY_ACCESS);
    node->data.identifier.name = strdup(name);
    node->data.identifier.index = index;
    return node;
}

ASTNode* create_assign(ASTNode* target, ASTNode* expr) {
    ASTNode* node = create_node(NODE_ASSIGN);
    node->left = target;
    node->right = expr;
    return node;
}

ASTNode* create_if(ASTNode* cond, ASTNode* body) {
    ASTNode* node = create_node(NODE_IF);
    node->data.if_stmt.condition = cond;
    node->data.if_stmt.if_body = body;
    node->data.if_stmt.else_body = NULL;
    return node;
}

ASTNode* create_if_else(ASTNode* cond, ASTNode* if_body, ASTNode* else_body) {
    ASTNode* node = create_node(NODE_IF_ELSE);
    node->data.if_stmt.condition = cond;
    node->data.if_stmt.if_body = if_body;
    node->data.if_stmt.else_body = else_body;
    return node;
}

ASTNode* create_while(ASTNode* cond, ASTNode* body) {
    ASTNode* node = create_node(NODE_WHILE);
    node->data.loop_stmt.condition = cond;
    node->data.loop_stmt.body = body;
    return node;
}

ASTNode* create_do_while(ASTNode* cond, ASTNode* body) {
    ASTNode* node = create_node(NODE_DO_WHILE);
    node->data.loop_stmt.condition = cond;
    node->data.loop_stmt.body = body;
    return node;
}

ASTNode* create_for(ASTNode* init, ASTNode* cond, ASTNode* inc, ASTNode* body) {
    ASTNode* node = create_node(NODE_FOR);
    node->data.for_stmt.init = init;
    node->data.for_stmt.condition = cond;
    node->data.for_stmt.increment = inc;
    node->data.for_stmt.body = body;
    return node;
}

ASTNode* create_switch(ASTNode* expr, ASTNode* cases) {
    ASTNode* node = create_node(NODE_SWITCH);
    node->data.switch_stmt.expr = expr;
    node->data.switch_stmt.cases = cases;
    return node;
}

ASTNode* create_case(ASTNode* val, ASTNode* body) {
    ASTNode* node = create_node(NODE_CASE);
    node->data.case_stmt.value = val;
    node->data.case_stmt.body = body;
    return node;
}

ASTNode* create_default(ASTNode* body) {
    ASTNode* node = create_node(NODE_DEFAULT);
    node->data.case_stmt.value = NULL;
    node->data.case_stmt.body = body;
    return node;
}

ASTNode* create_function(char* return_type, char* name, ASTNode* params, ASTNode* body) {
    ASTNode* node = create_node(NODE_FUNC_DECL);
    node->data.func_decl.return_type = strdup(return_type);
    node->data.func_decl.name = strdup(name);
    node->data.func_decl.params = params;
    node->data.func_decl.body = body;
    return node;
}

ASTNode* create_function_call(char* name, ASTNode* args) {
    ASTNode* node = create_node(NODE_FUNC_CALL);
    node->data.func_call.name = strdup(name);
    node->data.func_call.args = args;
    return node;
}

ASTNode* create_return(ASTNode* expr) {
    ASTNode* node = create_node(NODE_RETURN);
    node->left = expr;
    return node;
}

ASTNode* create_print(ASTNode* expr) {
    ASTNode* node = create_node(NODE_PRINT);
    node->left = expr;
    return node;
}