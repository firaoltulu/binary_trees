#include "binary_trees.h"

/**
 * binary_tree_preorder - This Function goes through a binary tree using pre-order traversal.
 * @tree: binary_tree_t pointer to the root node of the tree to traverse.
 * @func: binary_tree_t pointer to a function to call for each node.
 * Returns: Nothing(Void).
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree && func)
    {
        func(tree->n);
        binary_tree_preorder(tree->left, func);
        binary_tree_preorder(tree->right, func);
    }
}