#ifndef AST_H
#define AST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum
{

    /* Basic nodes */
    NODE_PROGRAM,
    NODE_BLOCK,

    NODE_VAR_DECL,
    NODE_ARRAY_DECL,

    NODE_ASSIGN,
    NODE_ARRAY_ASSIGN,

    NODE_IDENTIFIER,
    NODE_ARRAY_ACCESS,


    /* Constants */
    NODE_INT_CONST,
    NODE_FLOAT_CONST,
    NODE_BOOL_CONST,


    /* Expressions */
    NODE_BINOP,
    NODE_UNARY,


    /* Statements */
    NODE_PRINT,

    NODE_IF,
    NODE_IF_ELSE,

    NODE_WHILE,
    NODE_FOR,
    NODE_DO_WHILE,


    /* Functions */
    NODE_FUNCTION,
    NODE_PARAM_LIST,
    NODE_FUNCTION_CALL,
    NODE_RETURN,


    /* Switch */
    NODE_SWITCH,
    NODE_CASE,
    NODE_DEFAULT,


    /* Increment decrement */
    NODE_INCREMENT,
    NODE_DECREMENT,


    /* Optimization */
    NODE_EMPTY


} NodeType;

typedef struct ASTNode
{

    NodeType type;


    /*
        Stores:
        variable name
        operator symbol
        function name
        array name
    */

    char *name;



    /*
        Constant values
    */

    int int_val;

    float float_val;

    int bool_val;




    /*
        Tree connections
    */


    struct ASTNode *left;

    struct ASTNode *right;

/*
        Third child

        Used for:
        - for loop update
        - if else false branch
        - function parameters
    */

    struct ASTNode *third;



    /*
        Linked list

        Used for:
        - statements
        - parameters
        - arguments
        - cases
    */

     struct ASTNode *next;



    /*
        Array size

        Example:

        int arr[10]

        size = 10
    */

    int array_size;



    /*
        Function information
    */


    char *return_type;


} ASTNode;



/*
    Basic constructors
*/
ASTNode* create_node(NodeType type);



ASTNode* create_identifier(char *name);



ASTNode* create_int_const(int value);



ASTNode* create_float_const(float value);



ASTNode* create_bool_const(int value);



/*
    Expressions
*/

ASTNode* create_binop(char *op,
                      ASTNode *left,
                      ASTNode *right);



ASTNode* create_unary(char *op,
                      ASTNode *child);



/*
    Variables
*/

ASTNode* create_var_decl(char *name);



ASTNode* create_array_decl(char *name,
                           int size);



ASTNode* create_array_access(char *name,
                             ASTNode *index);



ASTNode* create_array_assign(char *name,
                             ASTNode *index,
                             ASTNode *value);



/*
    Statements
*/

ASTNode* create_assign(ASTNode *left,
                       ASTNode *right);



ASTNode* create_print(ASTNode *expr);



ASTNode* create_if(ASTNode *condition,
                   ASTNode *body);



ASTNode* create_if_else(ASTNode *condition,
                        ASTNode *true_body,
                        ASTNode *false_body);



ASTNode* create_while(ASTNode *condition,
                      ASTNode *body);



ASTNode* create_for(ASTNode *init,
                    ASTNode *condition,
                    ASTNode *update,
                    ASTNode *body);



ASTNode* create_do_while(ASTNode *body,
                         ASTNode *condition);



/*
    Functions
*/

ASTNode* create_function(char *name,
                         char *return_type,
                         ASTNode *params,
                         ASTNode *body);



ASTNode* create_function_call(char *name,
                              ASTNode *arguments);



ASTNode* create_return(ASTNode *value);



/*
    Switch case
*/

ASTNode* create_switch(ASTNode *expr,
                       ASTNode *cases);



ASTNode* create_case(ASTNode *value,
                     ASTNode *body);



ASTNode* create_default(ASTNode *body);



/*
    Increment decrement
*/

ASTNode* create_increment(ASTNode *id);



ASTNode* create_decrement(ASTNode *id);



#endif