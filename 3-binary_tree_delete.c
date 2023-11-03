#include "binary_trees.h"

/**
 * binary_tree_delete - This function that deletes an entire binary tree.
 * @tree: binary_tree_t pointer to the root node of the tree to delete.
 * Returns: Nothing(Void).
 */
void binary_tree_delete(binary_tree_t *tree)
{
    if (tree)
    {
        binary_tree_delete(tree->right);
        binary_tree_delete(tree->left);
        free(tree);
    }
}
