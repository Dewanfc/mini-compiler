#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

extern FILE* yyin;
extern int yyparse();
extern ASTNode* ast_root;

ASTNode* optimize_ast(ASTNode* node);
char* generate_tac(ASTNode* node);
void generate_dot(ASTNode* root, const char* filename);

int main(int argc, char** argv) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            fprintf(stderr, "Cannot open file %s\n", argv[1]);
            return 1;
        }
    } else {
        yyin = stdin;
    }

    printf("Starting compilation...\n");
    
    if (yyparse() == 0) {
        printf("Syntax Analysis: PASSED\n\n");

        if (ast_root) {
            printf("Optimizing AST...\n");
            ast_root = optimize_ast(ast_root);

            printf("Generating AST visualization...\n");
            generate_dot(ast_root, "ast.dot");
            system("dot -Tpng ast.dot -o ast.png");

            printf("\nGenerating Three Address Code (TAC)...\n");
            generate_tac(ast_root);
        }
    } else {
        printf("Syntax Analysis: FAILED\n");
    }

    if (yyin && yyin != stdin) {
        fclose(yyin);
    }
    
    return 0;
}