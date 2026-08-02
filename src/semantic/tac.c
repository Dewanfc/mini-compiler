#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int temp_count = 1;
static int label_count = 1;

char* new_temp() {
    char* temp = (char*)malloc(16);
    sprintf(temp, "t%d", temp_count++);
    return temp;
}


char* new_label() {
    char* label = (char*)malloc(16);
    sprintf(label, "L%d", label_count++);
    return label;
}

char* generate_tac(ASTNode* node) {
    if (!node) return NULL;

    switch (node->type) {
        case NODE_SEQ:
            generate_tac(node->left);
            generate_tac(node->right);
            return NULL;

        case NODE_INT_CONST: {
            char* temp = new_temp();
            printf("%s = %d\n", temp, node->data.int_val);
            return temp;
        }

        case NODE_FLOAT_CONST: {
            char* temp = new_temp();
            printf("%s = %f\n", temp, node->data.float_val);
            return temp;
        }

        case NODE_BOOL_CONST: {
            char* temp = new_temp();
            printf("%s = %s\n", temp, node->data.bool_val ? "true" : "false");
            return temp;
        }

        case NODE_IDENTIFIER:
            return strdup(node->data.identifier.name);

        case NODE_BINOP: {
            char* left = generate_tac(node->left);
            char* right = generate_tac(node->right);
            char* temp = new_temp();
            printf("%s = %s %s %s\n", temp, left, node->data.str_val, right);
            free(left);
            free(right);
            return temp;
        }

        case NODE_UNARY: {
            char* operand = generate_tac(node->left);
            char* temp = new_temp();
            printf("%s = %s%s\n", temp, node->data.str_val, operand);
            free(operand);
            return temp;
        }

        case NODE_ASSIGN: {
            char* expr = generate_tac(node->right);
            if (node->left->type == NODE_IDENTIFIER) {
                printf("%s = %s\n", node->left->data.identifier.name, expr);
            } else if (node->left->type == NODE_ARRAY_ACCESS) {
                char* index = generate_tac(node->left->data.identifier.index);
                printf("%s[%s] = %s\n", node->left->data.identifier.name, index, expr);
                free(index);
            }
            free(expr);
            return NULL;
        }

        case NODE_IF: {
            char* cond = generate_tac(node->data.if_stmt.condition);
            char* L1 = new_label();
            char* L2 = new_label();
            printf("t_cond = %s\n", cond);
            printf("if t_cond goto %s\n", L1);
            printf("goto %s\n", L2);
            printf("%s:\n", L1);
            generate_tac(node->data.if_stmt.if_body);
            printf("%s:\n", L2);
            free(cond);
            free(L1);
            free(L2);
            return NULL;
        }

        case NODE_IF_ELSE: {
            char* cond = generate_tac(node->data.if_stmt.condition);
            char* L1 = new_label();
            char* L2 = new_label();
            char* L3 = new_label();
            printf("t_cond = %s\n", cond);
            printf("if t_cond goto %s\n", L1);
            printf("goto %s\n", L2);
            printf("%s:\n", L1);
            generate_tac(node->data.if_stmt.if_body);
            printf("goto %s\n", L3);
            printf("%s:\n", L2);
            generate_tac(node->data.if_stmt.else_body);
            printf("%s:\n", L3);
            free(cond);
            free(L1);
            free(L2);
            free(L3);
            return NULL;
        }

        case NODE_WHILE: {
            char* L1 = new_label();
            char* L2 = new_label();
            printf("%s:\n", L1);
            char* cond = generate_tac(node->data.loop_stmt.condition);
            printf("t_cond = %s\n", cond);
            printf("if_false t_cond goto %s\n", L2);
            generate_tac(node->data.loop_stmt.body);
            printf("goto %s\n", L1);
            printf("%s:\n", L2);
            free(cond);
            free(L1);
            free(L2);
            return NULL;
        }

        case NODE_FOR: {
            generate_tac(node->data.for_stmt.init);
            char* L1 = new_label();
            char* L2 = new_label();
            printf("%s:\n", L1);
            char* cond = generate_tac(node->data.for_stmt.condition);
            printf("t_cond = %s\n", cond);
            printf("if_false t_cond goto %s\n", L2);
            generate_tac(node->data.for_stmt.body);
            generate_tac(node->data.for_stmt.increment);
            printf("goto %s\n", L1);
            printf("%s:\n", L2);
            free(cond);
            free(L1);
            free(L2);
            return NULL;
        }

        case NODE_DO_WHILE: {
            char* L1 = new_label();
            printf("%s:\n", L1);
            generate_tac(node->data.loop_stmt.body);
            char* cond = generate_tac(node->data.loop_stmt.condition);
            printf("t_cond = %s\n", cond);
            printf("if t_cond goto %s\n", L1);
            free(cond);
            free(L1);
            return NULL;
        }

        case NODE_PRINT: {
            char* expr = generate_tac(node->left);
            printf("print %s\n", expr);
            free(expr);
            return NULL;
        }

        case NODE_FUNC_DECL: {
            printf("%s:\n", node->data.func_decl.name);
            generate_tac(node->data.func_decl.body);
            return NULL;
        }

        case NODE_FUNC_CALL: {
            ASTNode* arg = node->data.func_call.args;
            while (arg != NULL) {
                if (arg->type == NODE_SEQ) {
                    char* p = generate_tac(arg->left);
                    printf("param %s\n", p);
                    free(p);
                    arg = arg->right;
                } else {
                    char* p = generate_tac(arg);
                    printf("param %s\n", p);
                    free(p);
                    break;
                }
            }
            char* temp = new_temp();
            printf("%s = call %s\n", temp, node->data.func_call.name);
            return temp;
        }

        case NODE_RETURN: {
            char* expr = generate_tac(node->left);
            printf("return %s\n", expr);
            free(expr);
            return NULL;
        }

        case NODE_ARRAY_ACCESS: {
            char* index = generate_tac(node->data.identifier.index);
            char* temp = new_temp();
            printf("%s = %s[%s]\n", temp, node->data.identifier.name, index);
            free(index);
            return temp;
        }

        case NODE_ARRAY_DECL:
        case NODE_VAR_DECL:
            return NULL;
        case NODE_SWITCH: {
            char* expr = generate_tac(node->data.switch_stmt.expr);
            printf("t_switch = %s\n", expr);
            generate_tac(node->data.switch_stmt.cases);
            free(expr);
            return NULL;
        }

        case NODE_CASE: {
            char* val = generate_tac(node->data.case_stmt.value);
            char* next_case = new_label();
            printf("if t_switch != %s goto %s\n", val, next_case);
            generate_tac(node->data.case_stmt.body);
            printf("%s:\n", next_case);
            free(val);
            return NULL;
        }

        case NODE_DEFAULT: {
            printf("default:\n");
            generate_tac(node->data.case_stmt.body);
            return NULL;
        }

        default:
            return NULL;
    }
}