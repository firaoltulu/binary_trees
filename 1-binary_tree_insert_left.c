#include "binary_trees.h"

/**
 * binary_tree_insert_left - This function that inserts a node as the left-child.
 *@parent: binary_tree_t pointer to the node to insert the left-child in.
 *@value: the value to store in the new node.
 * Return: pointer to created node, or NULL on failure or if parent is NULL.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
    binary_tree_t *one = NULL;

    if (parent == NULL)
    {
        return (NULL);
    }
    else
    {
        one = malloc(sizeof(binary_tree_t));
        if (one == NULL)
        {
            return (NULL);
        }
        else
        {
            one->n = value;
            one->parent = parent;
            one->left = NULL;
            one->right = NULL;
            if (parent->left == NULL)
                parent->left = one;
            else
            {
                one->left = parent->left;
                parent->left = one;
                one->left->parent = one;
            }
            return (one);
        }
    }
}