#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"

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
    // In a full implementation, you would remove symbols matching current_scope here.
    current_scope--;
}

int insert_symbol(char *name, DataType type, int line_num) {
    if (lookup_symbol(name) != NULL) {
        fprintf(stderr, "Semantic Error at line %d: Redeclaration of variable '%s'\n", line_num, name);
        return 0;
    }
    unsigned int index = hash(name);
    Symbol* new_sym = (Symbol*)malloc(sizeof(Symbol));
    new_sym->name = strdup(name);
    new_sym->type = type;
    new_sym->scope_level = current_scope;
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