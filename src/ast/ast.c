#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ast.h"



ASTNode* create_node(NodeType type)
{
    ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));


    if(node == NULL)
    {
        fprintf(stderr,"Memory allocation failed\n");
        exit(1);
    }



    node->type = type;


    node->name = NULL;


    node->int_val = 0;

    node->float_val = 0.0;



    node->left = NULL;

    node->right = NULL;

    node->third = NULL;

    node->next = NULL;



    return node;
}





ASTNode* create_identifier(char *name)
{
    ASTNode *node = create_node(NODE_IDENTIFIER);


    node->name = strdup(name);


    return node;
}





ASTNode* create_int_const(int value)
{
    ASTNode *node = create_node(NODE_INT_CONST);


    node->int_val = value;


    return node;
}





ASTNode* create_float_const(float value)
{
    ASTNode *node = create_node(NODE_FLOAT_CONST);


    node->float_val = value;


    return node;
}






/*
    Constant Folding

    Example:

    create_binop("+",
                 create_int_const(10),
                 create_int_const(20))

    becomes:

    create_int_const(30)

*/

ASTNode* create_binop(char *op,
                      ASTNode *left,
                      ASTNode *right)
{

    if(left != NULL &&
       right != NULL &&
       left->type == NODE_INT_CONST &&
       right->type == NODE_INT_CONST)
    {

        int result = 0;



        if(strcmp(op,"+")==0)
        {
            result = left->int_val + right->int_val;
        }


        else if(strcmp(op,"-")==0)
        {
            result = left->int_val - right->int_val;
        }


        else if(strcmp(op,"*")==0)
        {
            result = left->int_val * right->int_val;
        }


        else if(strcmp(op,"/")==0)
        {
            if(right->int_val != 0)
                result = left->int_val / right->int_val;
            else
                return NULL;
        }


        else if(strcmp(op,"%")==0)
        {
            result = left->int_val % right->int_val;
        }


        else if(strcmp(op,"<")==0)
        {
            result = left->int_val < right->int_val;
        }


        else if(strcmp(op,">")==0)
        {
            result = left->int_val > right->int_val;
        }


        else if(strcmp(op,"==")==0)
        {
            result = left->int_val == right->int_val;
        }


        else
        {
            goto normal_node;
        }



        return create_int_const(result);
    }



normal_node:
{
    ASTNode *node = create_node(NODE_BINOP);


    node->name = strdup(op);


    node->left = left;

    node->right = right;


    return node;
}
}







/*
    Unary operator creation

    Examples:

    -x

    !x

*/

ASTNode* create_unary(char *op,
                      ASTNode *child)
{

    /*
        Constant folding for unary operators

        -10  ---> -10

        !0   ---> 1
    */


    if(child != NULL &&
       child->type == NODE_INT_CONST)
    {

        if(strcmp(op,"-")==0)
        {
            return create_int_const(
                -(child->int_val)
            );
        }


        if(strcmp(op,"!")==0)
        {
            return create_int_const(
                !(child->int_val)
            );
        }

    }




    ASTNode *node = create_node(NODE_UNARY);



    node->name = strdup(op);


    node->left = child;



    return node;
}

#include "ast.h"



ASTNode* create_node(NodeType type)
{
    ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));

    node->type = type;

    node->name = NULL;

    node->int_val = 0;

    node->float_val = 0.0;

    node->bool_val = 0;


    node->left = NULL;

    node->right = NULL;

    node->third = NULL;

    node->next = NULL;


    node->array_size = 0;

    node->return_type = NULL;


    return node;
}

ASTNode* create_identifier(char *name)
{
    ASTNode *node = create_node(NODE_IDENTIFIER);

    node->name = strdup(name);

    return node;
}


ASTNode* create_int_const(int value)
{
    ASTNode *node = create_node(NODE_INT_CONST);

    node->int_val = value;

    return node;
}



ASTNode* create_float_const(float value)
{
    ASTNode *node = create_node(NODE_FLOAT_CONST);

    node->float_val = value;

    return node;
}



ASTNode* create_bool_const(int value)
{
    ASTNode *node = create_node(NODE_BOOL_CONST);

    node->bool_val = value;

    return node;
}


/*
    Expressions
*/


ASTNode* create_binop(char *op,
                      ASTNode *left,
                      ASTNode *right)
{

    ASTNode *node = create_node(NODE_BINOP);


    node->name = strdup(op);

    node->left = left;

    node->right = right;


    return node;
}



ASTNode* create_unary(char *op,
                      ASTNode *child)
{

    ASTNode *node = create_node(NODE_UNARY);


    node->name = strdup(op);

    node->left = child;


    return node;
}



/*
    Variables
*/


ASTNode* create_var_decl(char *name)
{

    ASTNode *node = create_node(NODE_VAR_DECL);


    node->name = strdup(name);


    return node;
}


ASTNode* create_array_decl(char *name,
                           int size)
{

    ASTNode *node =
        create_node(NODE_ARRAY_DECL);


    node->name = strdup(name);


    node->array_size = size;


    return node;
}


ASTNode* create_array_access(char *name,
                             ASTNode *index)
{

    ASTNode *node =
        create_node(NODE_ARRAY_ACCESS);


    node->name = strdup(name);


    node->left = index;


    return node;
}



ASTNode* create_array_assign(char *name,
                             ASTNode *index,
                             ASTNode *value)
{

    ASTNode *node =
        create_node(NODE_ARRAY_ASSIGN);


    node->name = strdup(name);


    node->left = index;

    node->right = value;


    return node;
}




/*
    Statements
*/


ASTNode* create_assign(ASTNode *left,
                       ASTNode *right)
{

    ASTNode *node =
        create_node(NODE_ASSIGN);


    node->left = left;

    node->right = right;


    return node;
}


ASTNode* create_print(ASTNode *expr)
{

    ASTNode *node =
        create_node(NODE_PRINT);


    node->left = expr;


    return node;
}


ASTNode* create_if(ASTNode *condition,
                   ASTNode *body)
{

    ASTNode *node =
        create_node(NODE_IF);


    node->left = condition;

    node->right = body;


    return node;
}


ASTNode* create_if_else(ASTNode *condition,
                        ASTNode *true_body,
                        ASTNode *false_body)
{

    ASTNode *node =
        create_node(NODE_IF_ELSE);


    node->left = condition;

    node->right = true_body;

    node->third = false_body;


    return node;
}

ASTNode* create_while(ASTNode *condition,
                      ASTNode *body)
{

    ASTNode *node =
        create_node(NODE_WHILE);


    node->left = condition;

    node->right = body;


    return node;
}


ASTNode* create_for(ASTNode *init,
                    ASTNode *condition,
                    ASTNode *update,
                    ASTNode *body)
{

    ASTNode *node =
        create_node(NODE_FOR);


    node->left = init;

    node->right = condition;

    node->third = update;

    node->next = body;


    return node;
}


ASTNode* create_do_while(ASTNode *body,
                         ASTNode *condition)
{

    ASTNode *node =
        create_node(NODE_DO_WHILE);


    node->left = body;

    node->right = condition;


    return node;
}









/*
    Functions
*/


ASTNode* create_function(char *name,
                         char *return_type,
                         ASTNode *params,
                         ASTNode *body)
{

    ASTNode *node =
        create_node(NODE_FUNCTION);


    node->name = strdup(name);


    node->return_type = strdup(return_type);


    node->left = params;

    node->right = body;


    return node;
}




ASTNode* create_function_call(char *name,
                              ASTNode *arguments)
{

    ASTNode *node =
        create_node(NODE_FUNCTION_CALL);


    node->name = strdup(name);


    node->left = arguments;


    return node;
}







ASTNode* create_return(ASTNode *value)
{

    ASTNode *node =
        create_node(NODE_RETURN);


    node->left = value;


    return node;
}


/*
    Switch
*/


ASTNode* create_switch(ASTNode *expr,
                       ASTNode *cases)
{

    ASTNode *node =
        create_node(NODE_SWITCH);


    node->left = expr;

    node->right = cases;


    return node;
}








ASTNode* create_case(ASTNode *value,
                     ASTNode *body)
{

    ASTNode *node =
        create_node(NODE_CASE);


    node->left = value;

    node->right = body;


    return node;
}




ASTNode* create_default(ASTNode *body)
{

    ASTNode *node =
        create_node(NODE_DEFAULT);


    node->left = body;


    return node;
}









/*
    Increment / Decrement
*/


ASTNode* create_increment(ASTNode *id)
{

    ASTNode *node =
        create_node(NODE_INCREMENT);


    node->left = id;


    return node;
}


ASTNode* create_decrement(ASTNode *id)
{

    ASTNode *node =
        create_node(NODE_DECREMENT);


    node->left = id;


    return node;
}

