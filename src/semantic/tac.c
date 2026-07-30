#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../ast/ast.h"


int temp_count = 1;
int label_count = 1;



char *new_temp()
{
    char *temp = (char *)malloc(20);

    sprintf(temp, "t%d", temp_count++);

    return temp;
}



char *new_label()
{
    char *label = (char *)malloc(20);

    sprintf(label, "L%d", label_count++);

    return label;
}





char *generate_tac(ASTNode *node)
{
    if(node == NULL)
        return NULL;



    switch(node->type)
    {


    case NODE_INT_CONST:
    {
        char *temp = new_temp();

        printf("%s = %d\n",
               temp,
               node->int_val);

        return temp;
    }



    case NODE_FLOAT_CONST:
    {
        char *temp = new_temp();

        printf("%s = %f\n",
               temp,
               node->float_val);

        return temp;
    }




    case NODE_IDENTIFIER:
    {
        return node->name;
    }




    case NODE_BINOP:
    {
        char *left =
            generate_tac(node->left);


        char *right =
            generate_tac(node->right);


        char *temp =
            new_temp();



        if(right != NULL)
        {
            printf("%s = %s %s %s\n",
                   temp,
                   left,
                   node->name,
                   right);
        }
        else
        {
            printf("%s = %s %s\n",
                   temp,
                   node->name,
                   left);
        }


        return temp;
    }




    case NODE_ASSIGN:
    {
        char *value =
            generate_tac(node->right);



        printf("%s = %s\n",
               node->left->name,
               value);


        return node->left->name;
    }




    case NODE_PRINT:
    {
        char *value =
            generate_tac(node->left);



        if(value != NULL)
            printf("print %s\n", value);


        return NULL;
    }






    case NODE_BLOCK:
    {
        ASTNode *current = node->left;


        while(current != NULL)
        {
            generate_tac(current);

            current = current->next;
        }


        return NULL;
    }







    case NODE_IF:
    {
        char *condition =
            generate_tac(node->left);


        char *true_label =
            new_label();


        char *end_label =
            new_label();



        printf("if %s goto %s\n",
               condition,
               true_label);


        printf("goto %s\n",
               end_label);



        printf("%s:\n",
               true_label);



        generate_tac(node->right);



        printf("%s:\n",
               end_label);



        return NULL;
    }







    case NODE_IF_ELSE:
    {
        char *condition =
            generate_tac(node->left);



        char *true_label =
            new_label();


        char *false_label =
            new_label();


        char *end_label =
            new_label();





        printf("if %s goto %s\n",
               condition,
               true_label);



        printf("goto %s\n",
               false_label);





        printf("%s:\n",
               true_label);



        generate_tac(node->right);



        printf("goto %s\n",
               end_label);





        printf("%s:\n",
               false_label);



        generate_tac(node->third);





        printf("%s:\n",
               end_label);



        return NULL;
    }








    case NODE_WHILE:
    {
        char *start =
            new_label();


        char *body =
            new_label();


        char *end =
            new_label();





        printf("%s:\n",
               start);



        char *condition =
            generate_tac(node->left);




        printf("if %s goto %s\n",
               condition,
               body);



        printf("goto %s\n",
               end);





        printf("%s:\n",
               body);



        generate_tac(node->right);



        printf("goto %s\n",
               start);



        printf("%s:\n",
               end);



        return NULL;
    }







    default:
    {

        if(node->left)
            generate_tac(node->left);


        if(node->right)
            generate_tac(node->right);


        if(node->third)
            generate_tac(node->third);


        if(node->next)
            generate_tac(node->next);



        return NULL;
    }



    }

}