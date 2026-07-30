#include <stdio.h>
#include "../ast/ast.h"


int node_count = 0;



void generate_graph(ASTNode *node, FILE *file)
{

    if(node == NULL)
        return;



    int current = node_count++;



    fprintf(file,
            "node%d[label=\"",
            current);



    switch(node->type)
    {

        case NODE_PROGRAM:
            fprintf(file,"PROGRAM");
            break;


        case NODE_BLOCK:
            fprintf(file,"BLOCK");
            break;


        case NODE_VAR_DECL:
            fprintf(file,"VAR %s",
                    node->name);
            break;


        case NODE_ARRAY_DECL:
            fprintf(file,
                    "ARRAY %s[%d]",
                    node->name,
                    node->array_size);
            break;


        case NODE_ASSIGN:
            fprintf(file,"ASSIGN");
            break;


        case NODE_BINOP:
            fprintf(file,"%s",
                    node->name);
            break;


        case NODE_INT_CONST:
            fprintf(file,"%d",
                    node->int_val);
            break;


        case NODE_IDENTIFIER:
            fprintf(file,"%s",
                    node->name);
            break;


        case NODE_PRINT:
            fprintf(file,"PRINT");
            break;


        case NODE_IF:
            fprintf(file,"IF");
            break;


        case NODE_WHILE:
            fprintf(file,"WHILE");
            break;


        case NODE_FOR:
            fprintf(file,"FOR");
            break;


        case NODE_FUNCTION:
            fprintf(file,
                    "FUNCTION %s",
                    node->name);
            break;


        case NODE_RETURN:
            fprintf(file,"RETURN");
            break;


        default:
            fprintf(file,"NODE");

    }


    fprintf(file,"\"];\n");




    if(node->left)
    {

        int child=node_count;


        generate_graph(node->left,file);


        fprintf(file,
        "node%d -> node%d;\n",
        current,
        child);

    }



    if(node->right)
    {

        int child=node_count;


        generate_graph(node->right,file);


        fprintf(file,
        "node%d -> node%d;\n",
        current,
        child);

    }



    if(node->third)
    {

        int child=node_count;


        generate_graph(node->third,file);


        fprintf(file,
        "node%d -> node%d;\n",
        current,
        child);

    }


}



void create_ast_graph(ASTNode *root)
{

    FILE *file=fopen("ast.dot","w");


    if(!file)
    {
        printf("Cannot create graph file\n");
        return;
    }



    fprintf(file,
    "digraph AST {\n");



    node_count=0;


    generate_graph(root,file);



    fprintf(file,
    "}\n");



    fclose(file);



    printf("AST graph generated: ast.dot\n");

}