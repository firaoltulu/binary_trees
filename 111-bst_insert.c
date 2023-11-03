#include "binary_trees.h"
/**
 * bst_insert - This Function inserts a value in a Binary Search Tree.
 * @tree: bst_t double pointer to the root node of the BST to insert the value.
 * @value: value to store in the node to be inserted.
 * Return: Always 0 (Success).
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *one = NULL;

	if (tree == NULL)
	{
		return (NULL);
	}
	else
	{
		if (*tree == NULL)
		{
			*tree = binary_tree_node(NULL, value);
			return (*tree);
		}
		else
		{
			one = *tree;
			if (value < one->n)
			{
				if (one->left == NULL)
				{
					one->left = binary_tree_node(one, value);
					return (one->left);
				}
				return (bst_insert(&(one->left), value));
			}
			if (value > one->n)
			{
				if (one->right == NULL)
				{
					one->right = binary_tree_node(one, value);
					return (one->right);
				}
				return (bst_insert(&(one->right), value));
			}
			return (NULL);
		}
	}
}
