#include <stdio.h>
#include <stdlib.h>

#include "ast/ast.h"
#include "symbol_table/symtab.h"

/* Bison/Flex */
extern int yyparse(void);
extern FILE *yyin;
extern int line_num;

/* AST root created by parser.y */
extern ASTNode *root;

/* TAC generator */
extern char *generate_tac(ASTNode *node);

/* Optimizer */
extern ASTNode *remove_dead_code(ASTNode *node);

/* Graphviz */
extern void create_ast_graph(ASTNode *root);

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        yyin = fopen(argv[1], "r");

        if (yyin == NULL)
        {
            fprintf(stderr,
                    "Error: Could not open file '%s'\n",
                    argv[1]);
            return EXIT_FAILURE;
        }
    }

    printf("========== Compiler Started ==========\n");

    /* Initialize Symbol Table */
    enter_scope();

    /* Parse */
    if (yyparse() == 0)
    {
        printf("Syntax Analysis: PASSED\n");

        if (root != NULL)
        {
            /* Optimization */
            root = remove_dead_code(root);

            /* Generate AST Graph */
            create_ast_graph(root);

            printf("Generating Three Address Code (TAC)...\n");

            /* Generate TAC */
            generate_tac(root);
        }
        else
        {
            printf("No AST generated.\n");
        }
    }
    else
    {
        printf("Syntax Analysis: FAILED\n");
    }

    exit_scope();

    if (yyin != NULL)
        fclose(yyin);

    return EXIT_SUCCESS;
}