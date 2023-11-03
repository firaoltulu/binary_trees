#include "binary_trees.h"
/**
 * binary_tree_height - This Function measures the height of a binary tree.
 *@tree: binary_tree_t pointer to the root node of the tree to measure the height.
 * Return: if tree is NULL, your function must return 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		int left = 1, right = 1;

		if (tree->right)
			right += binary_tree_height(tree->right);
		if (tree->left)
			left += binary_tree_height(tree->left);
		if (left > right)
			return (left);
		else
			return (right);
	}
	else
		return (0);
}
/**
 * binary_tree_balance - This Function measures the balance factor of a binary tree.
 *@tree: binary_tree_t pointer to the root node of the tree to measure the balance factor.
 * Return: If tree is NULL, return 0.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
	}
}
