#include "binary_trees.h"

/**
 * binary_tree_rotate_left -  This Function performs a left-rotation on a binary tree.
 * @tree: binary_tree_t pointer to binare_tree_t.
 * Return: binary_tree_t pointer to the new root node of the tree once rotated.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
    binary_tree_t *aux, *temp;

    if (tree == NULL)
    {
        return (NULL);
    }
    else
    {
        if (tree->right)
        {
            temp = tree->right->left;
            aux = tree->right;
            aux->parent = tree->parent;
            aux->left = tree;
            tree->parent = aux;
            tree->right = temp;
            if (temp)
                temp->parent = tree;
            return (aux);
        }
        return (NULL);
    }
}