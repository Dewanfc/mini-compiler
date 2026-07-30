#ifndef SYMTAB_H
#define SYMTAB_H

typedef enum { TYPE_INT, TYPE_FLOAT, TYPE_BOOL, TYPE_UNKNOWN } DataType;

typedef struct Symbol {
    char *name;
    DataType type;
    int scope_level;
    struct Symbol *next;
} Symbol;

void enter_scope();
void exit_scope();
int insert_symbol(char *name, DataType type, int line_num);
Symbol* lookup_symbol(char *name);
void check_type(DataType expected, DataType actual, int line_num);

#endif