#include "../ast/ast.h"



/*
    Dead code elimination

    Removes empty nodes
*/


ASTNode* remove_dead_code(ASTNode *node)
{

    if(node==NULL)
        return NULL;



    node->left =
        remove_dead_code(node->left);



    node->right =
        remove_dead_code(node->right);



    node->third =
        remove_dead_code(node->third);



    node->next =
        remove_dead_code(node->next);





    /*
        Remove empty blocks
    */


    if(node->type == NODE_BLOCK &&
       node->left == NULL)
    {

        return NULL;

    }



    return node;

}git add .
git commit -m "new commit"
