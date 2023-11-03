#include "binary_trees.h"

/**
 * binary_tree_rotate_right - This Function performs a rigth-rotation on a binary tree.
 * @tree: binary_tree_t pointer to binare_tree_t.
 * Return: binary_tree_t pointer to the new root node of the tree once rotated.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *one, *two;

	if (tree == NULL)
	{
		return (NULL);
	}
	else
	{
		if (tree->left)
		{
			two = tree->left->right;
			one = tree->left;
			one->parent = tree->parent;
			one->right = tree;
			tree->parent = one;
			tree->left = two;
			if (two)
				two->parent = tree;
			return (one);
		}
		return (NULL);
	}
}
