#include "binary_trees.h"

/**
 * binary_tree_height - This Function measures the height of a binary tree.
 * @tree: binary_tree_t pointer to the root node of the tree to measure the height.
 * Return: if tree is NULL, your function must return 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    if (tree)
    {
        int one = 0, two = 0;

        if (tree->right)
            two = 1 + binary_tree_height(tree->right);
        if (tree->left)
            one = 1 + binary_tree_height(tree->left);
        if (one > two)
            return (one);
        else
            return (two);
    }
    else
        return (0);
}