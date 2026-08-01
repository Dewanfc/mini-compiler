#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"
#include "ast.h"

#define TABLE_SIZE 100

Symbol* sym_table[TABLE_SIZE];
int current_scope = 0;

unsigned int hash(char *str) {
    unsigned int hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; 
    return hash % TABLE_SIZE;
}

void enter_scope() { current_scope++; }

void exit_scope() {
    // Correctly removes symbols that match the current_scope to catch Scope Violations
    for (int i = 0; i < TABLE_SIZE; i++) {
        Symbol* curr = sym_table[i];
        Symbol* prev = NULL;
        while (curr != NULL) {
            if (curr->scope_level == current_scope) {
                Symbol* temp = curr;
                if (prev == NULL) {
                    sym_table[i] = curr->next;
                    curr = sym_table[i];
                } else {
                    prev->next = curr->next;
                    curr = prev->next;
                }
                free(temp->name);
                free(temp);
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
    }
    current_scope--;
}

int insert_symbol(char *name, DataType type, int line_num) {
    Symbol* existing = lookup_symbol(name);
    // Only throw a redeclaration error if it's declared in the EXACT same scope
    if (existing != NULL && existing->scope_level == current_scope) {
        fprintf(stderr, "Semantic Error at line %d: Redeclaration of variable '%s'\n", line_num, name);
        return 0;
    }
    unsigned int index = hash(name);
    Symbol* new_sym = (Symbol*)malloc(sizeof(Symbol));
    new_sym->name = strdup(name);
    new_sym->type = type;
    new_sym->scope_level = current_scope;
    
    // Insert at the head of the list (handles shadowing automatically)
    new_sym->next = sym_table[index];
    sym_table[index] = new_sym;
    return 1;
}

Symbol* lookup_symbol(char *name) {
    unsigned int index = hash(name);
    Symbol* sym = sym_table[index];
    while (sym != NULL) {
        if (strcmp(sym->name, name) == 0) return sym;
        sym = sym->next;
    }
    return NULL;
}

void check_type(DataType expected, DataType actual, int line_num) {
    if (expected != TYPE_UNKNOWN && actual != TYPE_UNKNOWN && expected != actual) {
        fprintf(stderr, "Semantic Error at line %d: Cannot assign incompatible types\n", line_num);
    }
}

DataType get_type(ASTNode* node) {
    if (!node) return TYPE_UNKNOWN;
    if (node->type == NODE_INT_CONST) return TYPE_INT;
    if (node->type == NODE_FLOAT_CONST) return TYPE_FLOAT;
    if (node->type == NODE_BOOL_CONST) return TYPE_BOOL;
    
    if (node->type == NODE_IDENTIFIER || node->type == NODE_ARRAY_ACCESS) {
        Symbol* sym = lookup_symbol(node->data.identifier.name);
        return sym ? sym->type : TYPE_UNKNOWN;
    }
    if (node->type == NODE_BINOP) {
        return get_type(node->left); // Infers type from the left operand
    }
    if (node->type == NODE_UNARY) {
        return get_type(node->left);
    }
    if (node->type == NODE_FUNC_CALL) {
        Symbol* sym = lookup_symbol(node->data.func_call.name);
        return sym ? sym->type : TYPE_UNKNOWN;
    }
    return TYPE_UNKNOWN;
}