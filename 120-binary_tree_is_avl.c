#include "binary_trees.h"
#include "limits.h"

size_t function_one(const binary_tree_t *tree);
int function_two(const binary_tree_t *tree, int lo, int hi);
int binary_tree_is_avl(const binary_tree_t *tree);

/**
 * function_one - This Function Measures the height of a binary tree.
 * @tree: binary_tree_t pointer points to the to the root node of
 * the tree to measure the function_one.
 *
 * Return: If tree is NULL, your function must return 0, else return function_one.
 */
size_t function_one(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t one = 0, two = 0;
		one = tree->left ? 1 + function_one(tree->left) : 1;
		two = tree->right ? 1 + function_one(tree->right) : 1;
		return ((one > two) ? one : two);
	}
	else
	{
		return (0);
	}
}

/**
 * function_two - This Function Checks if a binary tree is a valid AVL tree.
 * @tree: binary_tree_t pointer to the root node of the tree to check.
 * @lo: The value of the smallest node visited thus far.
 * @hi: The value of the largest node visited this far.
 *
 * Return: If the tree is a valid AVL tree, 1, otherwise, 0.
 */
int function_two(const binary_tree_t *tree, int lo, int hi)
{
	size_t one, two, three;

	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
		{
			return (0);
		}
		else
		{
			one = function_one(tree->left);
			two = function_one(tree->right);
			three = one > two ? one - two : two - one;
			if (three > 1)
			{
				return (0);
			}
			else
			{
				return (function_two(tree->left, lo, tree->n - 1) &&
						function_two(tree->right, tree->n + 1, hi));
			}
		}
	}
	return (1);
}

/**
 * binary_tree_is_avl - This Function Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		return (function_two(tree, INT_MIN, INT_MAX));
	}
}
