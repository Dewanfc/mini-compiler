#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../ast/ast.h"



int temp_count = 1;

int label_count = 1;





char *new_temp()
{
    char *temp = malloc(20);

    sprintf(temp,"t%d",temp_count++);

    return temp;
}





char *new_label()
{
    char *label = malloc(20);

    sprintf(label,"L%d",label_count++);

    return label;
}







/*
    Constant folding helper
*/


int is_constant(ASTNode *node)
{
    return node &&
    (node->type == NODE_INT_CONST);
}





/*
    Generate TAC
*/


char *generate_tac(ASTNode *node)
{

    if(node == NULL)
        return NULL;



    switch(node->type)
    {



/* =====================
        CONSTANT
   ===================== */


case NODE_INT_CONST:
{

    char *temp=new_temp();

    printf("%s = %d\n",
            temp,
            node->int_val);


    return temp;
}






/* =====================
        VARIABLE
   ===================== */


case NODE_IDENTIFIER:

    return node->name;








/* =====================
        ARRAY ACCESS
   ===================== */


case NODE_ARRAY_ACCESS:
{

    char *index =
        generate_tac(node->left);



    char *temp =
        new_temp();



    printf("%s = %s[%s]\n",
            temp,
            node->name,
            index);



    return temp;
}








/* =====================
        ARRAY ASSIGN
   ===================== */


case NODE_ARRAY_ASSIGN:
{

    char *index =
        generate_tac(node->left);



    char *value =
        generate_tac(node->right);



    printf("%s[%s] = %s\n",
            node->name,
            index,
            value);



    return NULL;
}









/* =====================
        BINARY OP
   ===================== */


case NODE_BINOP:
{

    /*
       Constant folding
    */


    if(is_constant(node->left)
       &&
       is_constant(node->right))
    {

        int result;


        if(strcmp(node->name,"+")==0)

            result =
            node->left->int_val +
            node->right->int_val;


        else if(strcmp(node->name,"-")==0)

            result =
            node->left->int_val -
            node->right->int_val;


        else if(strcmp(node->name,"*")==0)

            result =
            node->left->int_val *
            node->right->int_val;


        else

            result = 0;



        char *temp=new_temp();


        printf("%s = %d\n",
                temp,
                result);



        return temp;
    }



    char *left =
        generate_tac(node->left);


    char *right =
        generate_tac(node->right);



    char *temp =
        new_temp();



    printf("%s = %s %s %s\n",
            temp,
            left,
            node->name,
            right);



    return temp;

}








/* =====================
        UNARY
   ===================== */


case NODE_UNARY:
{

    char *value =
        generate_tac(node->left);



    char *temp =
        new_temp();



    printf("%s = %s%s\n",
            temp,
            node->name,
            value);



    return temp;

}









/* =====================
        ASSIGN
   ===================== */


case NODE_ASSIGN:
{

    char *value =
        generate_tac(node->right);



    printf("%s = %s\n",
            node->left->name,
            value);



    return node->left->name;

}








/* =====================
        PRINT
   ===================== */


case NODE_PRINT:
{

    char *value =
        generate_tac(node->left);



    printf("print %s\n",
            value);



    return NULL;

}









/* =====================
        BLOCK
   ===================== */


case NODE_BLOCK:
{

    ASTNode *current=node->left;


    while(current)
    {

        generate_tac(current);

        current=current->next;
    }


    return NULL;

}








/* =====================
        IF
   ===================== */


case NODE_IF:
{

    char *condition =
        generate_tac(node->left);



    char *label_true =
        new_label();



    char *label_end =
        new_label();



    printf("if %s goto %s\n",
            condition,
            label_true);



    printf("goto %s\n",
            label_end);



    printf("%s:\n",
            label_true);



    generate_tac(node->right);



    printf("%s:\n",
            label_end);



    return NULL;

}








/* =====================
        IF ELSE
   ===================== */


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









/* =====================
        WHILE
   ===================== */


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









/* =====================
        FOR LOOP
   ===================== */


case NODE_FOR:
{

    generate_tac(node->left);



    char *start =
        new_label();



    char *body =
        new_label();



    char *end =
        new_label();



    printf("%s:\n",
            start);



    char *condition =
        generate_tac(node->right);



    printf("if %s goto %s\n",
            condition,
            body);



    printf("goto %s\n",
            end);



    printf("%s:\n",
            body);



    generate_tac(node->next);



    generate_tac(node->third);



    printf("goto %s\n",
            start);



    printf("%s:\n",
            end);



    return NULL;

}









/* =====================
        DO WHILE
   ===================== */


case NODE_DO_WHILE:
{

    char *start =
        new_label();



    printf("%s:\n",
            start);



    generate_tac(node->left);



    char *condition =
        generate_tac(node->right);



    printf("if %s goto %s\n",
            condition,
            start);



    return NULL;

}









/* =====================
        FUNCTIONS
   ===================== */


case NODE_FUNCTION:
{

    printf("FUNCTION %s:\n",
            node->name);



    generate_tac(node->right);



    printf("END FUNCTION\n");



    return NULL;

}






case NODE_FUNCTION_CALL:
{

    printf("call %s\n",
            node->name);



    return node->name;

}








case NODE_RETURN:
{

    char *value =
        generate_tac(node->left);



    printf("return %s\n",
            value);



    return NULL;

}








/* =====================
        ++ / --
   ===================== */


case NODE_INCREMENT:

    printf("%s = %s + 1\n",
            node->left->name,
            node->left->name);

    return NULL;



case NODE_DECREMENT:

    printf("%s = %s - 1\n",
            node->left->name,
            node->left->name);

    return NULL;







default:

    if(node->left)
        generate_tac(node->left);


    if(node->right)
        generate_tac(node->right);


    if(node->next)
        generate_tac(node->next);



    return NULL;

    }

}