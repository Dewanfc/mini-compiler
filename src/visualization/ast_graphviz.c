#include "ast.h"
#include <stdio.h>
#include <stdlib.h>

static int print_graphviz_node(FILE* f, ASTNode* node, int* id_counter) {
    if (!node) return -1;

    int current_id = (*id_counter)++;
    
    switch (node->type) {
        case NODE_SEQ:
            fprintf(f, "  node%d [label=\"SEQ\"];\n", current_id);
            break;
        case NODE_VAR_DECL:
            fprintf(f, "  node%d [label=\"VAR_DECL\\n%s %s\"];\n", current_id, node->data.var_decl.type_name, node->data.var_decl.name);
            break;
        case NODE_ARRAY_DECL:
            fprintf(f, "  node%d [label=\"ARRAY_DECL\\n%s %s\"];\n", current_id, node->data.var_decl.type_name, node->data.var_decl.name);
            if (node->data.var_decl.size) {
                int size_id = print_graphviz_node(f, node->data.var_decl.size, id_counter);
                fprintf(f, "  node%d -> node%d [label=\"size\"];\n", current_id, size_id);
            }
            break;
        case NODE_ASSIGN:
            fprintf(f, "  node%d [label=\"ASSIGN\"];\n", current_id);
            break;
        case NODE_INT_CONST:
            fprintf(f, "  node%d [label=\"INT: %d\"];\n", current_id, node->data.int_val);
            break;
        case NODE_FLOAT_CONST:
            fprintf(f, "  node%d [label=\"FLOAT: %f\"];\n", current_id, node->data.float_val);
            break;
        case NODE_BOOL_CONST:
            fprintf(f, "  node%d [label=\"BOOL: %s\"];\n", current_id, node->data.bool_val ? "true" : "false");
            break;
        case NODE_IDENTIFIER:
            fprintf(f, "  node%d [label=\"ID: %s\"];\n", current_id, node->data.identifier.name);
            break;
        case NODE_ARRAY_ACCESS:
            fprintf(f, "  node%d [label=\"ARRAY_ACCESS\\n%s\"];\n", current_id, node->data.identifier.name);
            if (node->data.identifier.index) {
                int idx_id = print_graphviz_node(f, node->data.identifier.index, id_counter);
                fprintf(f, "  node%d -> node%d [label=\"index\"];\n", current_id, idx_id);
            }
            break;
        case NODE_BINOP:
            fprintf(f, "  node%d [label=\"OP: %s\"];\n", current_id, node->data.str_val);
            break;
        case NODE_UNARY:
            fprintf(f, "  node%d [label=\"UNARY: %s\"];\n", current_id, node->data.str_val);
            break;
        case NODE_IF:
            fprintf(f, "  node%d [label=\"IF\"];\n", current_id);
            if (node->data.if_stmt.condition) {
                int cond_id = print_graphviz_node(f, node->data.if_stmt.condition, id_counter);
                fprintf(f, "  node%d -> node%d [label=\"condition\"];\n", current_id, cond_id);
            }
            if (node->data.if_stmt.if_body) {
                int body_id = print_graphviz_node(f, node->data.if_stmt.if_body, id_counter);
                fprintf(f, "  node%d -> node%d [label=\"then\"];\n", current_id, body_id);
            }
            break;
        case NODE_IF_ELSE:
            fprintf(f, "  node%d [label=\"IF_ELSE\"];\n", current_id);
            if (node->data.if_stmt.condition) {
                int cond_id = print_graphviz_node(f, node->data.if_stmt.condition, id_counter);
                fprintf(f, "  node%d -> node%d [label=\"condition\"];\n", current_id, cond_id);
            }
            if (node->data.if_stmt.if_body) {
                int if_id = print_graphviz_node(f, node->data.if_stmt.if_body, id_counter);
                fprintf(f, "  node%d -> node%d [label=\"then\"];\n", current_id, if_id);
            }
            if (node->data.if_stmt.else_body) {
                int else_id = print_graphviz_node(f, node->data.if_stmt.else_body, id_counter);
                fprintf(f, "  node%d -> node%d [label=\"else\"];\n", current_id, else_id);
            }
            break;
        case NODE_WHILE:
            fprintf(f, "  node%d [label=\"WHILE\"];\n", current_id);
            if (node->data.loop_stmt.condition) {
                int cond_id = print_graphviz_node(f, node->data.loop_stmt.condition, id_counter);
                fprintf(f, "  node%d -> node%d [label=\"condition\"];\n", current_id, cond_id);
            }
            if (node->data.loop_stmt.body) {
                int body_id = print_graphviz_node(f, node->data.loop_stmt.body, id_counter);
                fprintf(f, "  node%d -> node%d [label=\"body\"];\n", current_id, body_id);
            }
            break;
        case NODE_DO_WHILE:
            fprintf(f, "  node%d [label=\"DO_WHILE\"];\n", current_id);
            if (node->data.loop_stmt.body) {
                int body_id = print_graphviz_node(f, node->data.loop_stmt.body, id_counter);
                fprintf(f, "  node%d -> node%d [label=\"body\"];\n", current_id, body_id);
            }
            if (node->data.loop_stmt.condition) {
                int cond_id = print_graphviz_node(f, node->data.loop_stmt.condition, id_counter);
                fprintf(f, "  node%d -> node%d [label=\"condition\"];\n", current_id, cond_id);
            }
            break;
        case NODE_FOR:
            fprintf(f, "  node%d [label=\"FOR\"];\n", current_id);
            if (node->data.for_stmt.init) {
                int init_id = print_graphviz_node(f, node->data.for_stmt.init, id_counter);
                fprintf(f, "  node%d -> node%d [label=\"init\"];\n", current_id, init_id);
            }
            if (node->data.for_stmt.condition) {
                int cond_id = print_graphviz_node(f, node->data.for_stmt.condition, id_counter);
                fprintf(f, "  node%d -> node%d [label=\"condition\"];\n", current_id, cond_id);
            }
            if (node->data.for_stmt.increment) {
                int inc_id = print_graphviz_node(f, node->data.for_stmt.increment, id_counter);
                fprintf(f, "  node%d -> node%d [label=\"increment\"];\n", current_id, inc_id);
            }
            if (node->data.for_stmt.body) {
                int body_id = print_graphviz_node(f, node->data.for_stmt.body, id_counter);
                fprintf(f, "  node%d -> node%d [label=\"body\"];\n", current_id, body_id);
            }
            break;
        case NODE_SWITCH:
            fprintf(f, "  node%d [label=\"SWITCH\"];\n", current_id);
            if (node->data.switch_stmt.expr) {
                int expr_id = print_graphviz_node(f, node->data.switch_stmt.expr, id_counter);
                fprintf(f, "  node%d -> node%d [label=\"expr\"];\n", current_id, expr_id);
            }
            if (node->data.switch_stmt.cases) {
                int cases_id = print_graphviz_node(f, node->data.switch_stmt.cases, id_counter);
                fprintf(f, "  node%d -> node%d [label=\"cases\"];\n", current_id, cases_id);
            }
            break;
        case NODE_CASE:
            fprintf(f, "  node%d [label=\"CASE\"];\n", current_id);
            if (node->data.case_stmt.value) {
                int val_id = print_graphviz_node(f, node->data.case_stmt.value, id_counter);
                fprintf(f, "  node%d -> node%d [label=\"value\"];\n", current_id, val_id);
            }
            if (node->data.case_stmt.body) {
                int body_id = print_graphviz_node(f, node->data.case_stmt.body, id_counter);
                fprintf(f, "  node%d -> node%d [label=\"body\"];\n", current_id, body_id);
            }
            break;
        case NODE_DEFAULT:
            fprintf(f, "  node%d [label=\"DEFAULT\"];\n", current_id);
            if (node->data.case_stmt.body) {
                int body_id = print_graphviz_node(f, node->data.case_stmt.body, id_counter);
                fprintf(f, "  node%d -> node%d [label=\"body\"];\n", current_id, body_id);
            }
            break;
        case NODE_FUNC_DECL:
            fprintf(f, "  node%d [label=\"FUNC_DECL\\n%s %s\"];\n", current_id, node->data.func_decl.return_type, node->data.func_decl.name);
            if (node->data.func_decl.params) {
                int params_id = print_graphviz_node(f, node->data.func_decl.params, id_counter);
                fprintf(f, "  node%d -> node%d [label=\"params\"];\n", current_id, params_id);
            }
            if (node->data.func_decl.body) {
                int body_id = print_graphviz_node(f, node->data.func_decl.body, id_counter);
                fprintf(f, "  node%d -> node%d [label=\"body\"];\n", current_id, body_id);
            }
            break;
        case NODE_FUNC_CALL:
            fprintf(f, "  node%d [label=\"FUNC_CALL\\n%s\"];\n", current_id, node->data.func_call.name);
            if (node->data.func_call.args) {
                int args_id = print_graphviz_node(f, node->data.func_call.args, id_counter);
                fprintf(f, "  node%d -> node%d [label=\"args\"];\n", current_id, args_id);
            }
            break;
        case NODE_RETURN:
            fprintf(f, "  node%d [label=\"RETURN\"];\n", current_id);
            break;
        case NODE_PRINT:
            fprintf(f, "  node%d [label=\"PRINT\"];\n", current_id);
            break;
        default:
            fprintf(f, "  node%d [label=\"UNKNOWN\"];\n", current_id);
            break;
    }

    if (node->type == NODE_SEQ || node->type == NODE_ASSIGN || node->type == NODE_BINOP || node->type == NODE_RETURN || node->type == NODE_PRINT || node->type == NODE_UNARY) {
        if (node->left) {
            int left_id = print_graphviz_node(f, node->left, id_counter);
            fprintf(f, "  node%d -> node%d;\n", current_id, left_id);
        }
        if (node->right) {
            int right_id = print_graphviz_node(f, node->right, id_counter);
            fprintf(f, "  node%d -> node%d;\n", current_id, right_id);
        }
    }

    return current_id;
}

void generate_dot(ASTNode* root, const char* filename) {
    if (!root) return;
    FILE* f = fopen(filename, "w");
    if (!f) {
        fprintf(stderr, "Error opening %s for writing\n", filename);
        return;
    }
    fprintf(f, "digraph AST {\n");
    int id_counter = 0;
    print_graphviz_node(f, root, &id_counter);
    fprintf(f, "}\n");
    fclose(f);
}