#include "binary_trees.h"

/**
 * binary_tree_insert_right - This Fuction inserts node the right-child of another node.
 *@parent: binary_tree_t pointer to the node to insert the right-child in.
 *@value: the value to store in the new node,
 * Return: return a pointer to the created node, or NULL on failure or if no.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *one = NULL;

	if (parent == NULL)
	{
		return (NULL);
	}
	else
	{
		one = malloc(sizeof(binary_tree_t));
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
			if (parent->right == NULL)
				parent->right = one;
			else
			{
				one->right = parent->right;
				parent->right = one;
				one->right->parent = one;
			}
			return (one);
		}
	}
}
