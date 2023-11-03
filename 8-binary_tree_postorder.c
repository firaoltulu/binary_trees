#include "binary_trees.h"

/**
 * binary_tree_postorder - This Function goes through a binary tree using post-order.
 * @tree: binary_tree_t pointer to the root node of the tree to traverse.
 * @func: binary_tree_t pointer to a function to call for each node.
 * Return: Nothing(Void).
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
