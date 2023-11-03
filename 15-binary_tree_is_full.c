#include "binary_trees.h"

/**
 * binary_tree_is_full - This Function checks if a binary tree is full.
 * @tree: binary_tree_t pointer to the root node of the tree to check.
 * Return: If tree is NULL, your function must return 0.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
    if (tree == NULL)
    {
        return (0);
    }
    else
    {
        if (tree->left != NULL && tree->right != NULL)
        {
            return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
        }
        if (tree->left == NULL && tree->right == NULL)
        {
            return (1);
        }
        else
        {
            return (0);
        }
    }
}