#include "binary_trees.h"
/**
 * bst_search - This function find node in a tree.
 * @tree: bst_t pointer that points to the root of the tre to evaluate.
 * @value: node to find.
 * Return: bst_t pointer that points 1 if exits 0 if no.
 */
bst_t *bst_search(const bst_t *tree, int value)
{

	if (tree == NULL)
		return (NULL);
	if (value == tree->n)
		return ((bst_t *)tree);
	if (value < tree->n)
		return (bst_search(tree->left, value));
	else
		return (bst_search(tree->right, value));
	return (NULL);
}
