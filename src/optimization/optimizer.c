#include "ast.h"
#include <stdlib.h>
#include <string.h>

ASTNode* optimize_ast(ASTNode* node) {
    if (!node) return NULL;

    if (node->type == NODE_SEQ || node->type == NODE_ASSIGN || node->type == NODE_RETURN || node->type == NODE_PRINT) {
        node->left = optimize_ast(node->left);
        node->right = optimize_ast(node->right);
    }

    switch (node->type) {
        case NODE_IF:
            node->data.if_stmt.condition = optimize_ast(node->data.if_stmt.condition);
            if (node->data.if_stmt.condition && node->data.if_stmt.condition->type == NODE_BOOL_CONST) {
                if (node->data.if_stmt.condition->data.bool_val == 0) {
                    return NULL;
                } else {
                    return optimize_ast(node->data.if_stmt.if_body);
                }
            }
            node->data.if_stmt.if_body = optimize_ast(node->data.if_stmt.if_body);
            break;

        case NODE_IF_ELSE:
            node->data.if_stmt.condition = optimize_ast(node->data.if_stmt.condition);
            if (node->data.if_stmt.condition && node->data.if_stmt.condition->type == NODE_BOOL_CONST) {
                if (node->data.if_stmt.condition->data.bool_val == 0) {
                    return optimize_ast(node->data.if_stmt.else_body);
                } else {
                    return optimize_ast(node->data.if_stmt.if_body);
                }
            }
            node->data.if_stmt.if_body = optimize_ast(node->data.if_stmt.if_body);
            node->data.if_stmt.else_body = optimize_ast(node->data.if_stmt.else_body);
            break;

        case NODE_WHILE:
        case NODE_DO_WHILE:
            node->data.loop_stmt.condition = optimize_ast(node->data.loop_stmt.condition);
            node->data.loop_stmt.body = optimize_ast(node->data.loop_stmt.body);
            break;

        case NODE_FOR:
            node->data.for_stmt.init = optimize_ast(node->data.for_stmt.init);
            node->data.for_stmt.condition = optimize_ast(node->data.for_stmt.condition);
            node->data.for_stmt.increment = optimize_ast(node->data.for_stmt.increment);
            node->data.for_stmt.body = optimize_ast(node->data.for_stmt.body);
            break;

        case NODE_FUNC_DECL:
            node->data.func_decl.body = optimize_ast(node->data.func_decl.body);
            break;

        case NODE_BINOP: {
            node->left = optimize_ast(node->left);
            node->right = optimize_ast(node->right);

            if (node->left && node->left->type == NODE_INT_CONST &&
                node->right && node->right->type == NODE_INT_CONST) {
                
                int left_val = node->left->data.int_val;
                int right_val = node->right->data.int_val;
                int result = 0;
                char* op = node->data.str_val;

                if (strcmp(op, "+") == 0) result = left_val + right_val;
                else if (strcmp(op, "-") == 0) result = left_val - right_val;
                else if (strcmp(op, "*") == 0) result = left_val * right_val;
                else if (strcmp(op, "/") == 0 && right_val != 0) result = left_val / right_val;
                else if (strcmp(op, "%") == 0 && right_val != 0) result = left_val % right_val;
                else if (strcmp(op, "==") == 0) result = left_val == right_val;
                else if (strcmp(op, "!=") == 0) result = left_val != right_val;
                else if (strcmp(op, "<") == 0) result = left_val < right_val;
                else if (strcmp(op, ">") == 0) result = left_val > right_val;
                else if (strcmp(op, "<=") == 0) result = left_val <= right_val;
                else if (strcmp(op, ">=") == 0) result = left_val >= right_val;
                else return node;

                ASTNode* new_node = create_int_const(result);
                free(node->data.str_val);
                free(node->left);
                free(node->right);
                free(node);
                return new_node;
            }
            break;
        }

        default:
            break;
    }

    return node;
}
