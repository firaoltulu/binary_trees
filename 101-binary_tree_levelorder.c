#include "binary_trees.h"
/**
 * function_one - This Function measures the height of a binary tree.
 *@tree: binary_tree_t pointer to the root node of the tree to measure the height.
 * Return: if tree is NULL, your function must return 0.
 */
size_t function_one(const binary_tree_t *tree)
{
	if (tree)
	{
		int one = 0, two = 0;

		if (tree->right)
			two = 1 + function_one(tree->right);
		if (tree->left)
			one = 1 + function_one(tree->left);
		if (one > two)
			return (one);
		else
			return (two);
	}
	else
	{
		return (0);
	}
}
/**
 * function_two - This Funcion print node, especific level.
 * @tree: binary_tree_t pointer to the root node of the tree to traverse.
 * @func: binary_tree_t pointer to a function to call for each node.
 * @level: level to print.
 * Returns: Nothing(Void).
 */
void function_two(const binary_tree_t *tree, void (*func)(int), int level)
{
	if (tree && func)
	{
		if (level == 1)
			func(tree->n);
		else
		{
			function_two(tree->left, func, level - 1);
			function_two(tree->right, func, level - 1);
		}
	}
}

/**
 * binary_tree_levelorder - This Function goes through a binary tree in level-order traversal.
 * @tree: binary_tree_t pointer to the root node of the tree to traverse.
 * @func: binary_tree_t pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t one = 0, two = 1;

	if (tree && func)
	{
		one = function_one(tree);
		while (two <= one + 1)
		{
			function_two(tree, func, two);
			two++;
		}
	}
}
