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