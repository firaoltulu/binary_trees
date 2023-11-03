#include "binary_trees.h"

/**
 * binary_tree_node - This function that creates a binary tree node.
 *@parent: binary_tree_t is a pointer to the parent node of the node to create.
 *@value: int the value to put in the new node.
 * Return: This function return a pointer to the new node or NULL if no.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *one = malloc(sizeof(binary_tree_t));

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
        return (one);
    }
}