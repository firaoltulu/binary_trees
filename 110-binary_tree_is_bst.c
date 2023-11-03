#include "binary_trees.h"
/**
 * function_one - This function find node in a tree.
 * @root: binary_tree_t pointer that points to the root of the tre to evaluate.
 * @node: binary_tree_t pointer that points to the node to find.
 * Return: 1 if exits 0 if no.
 */
int function_one(binary_tree_t *root, binary_tree_t *node)
{

	if (root == NULL)
		return (0);
	if (node == root)
		return (1);
	if (node->n < root->n)
		return (function_one(root->left, node));
	if (node->n > root->n)
		return (function_one(root->right, node));
	return (0);
}
/**
 * function_two - This Function cross the tree checking if each node exist correctly.
 * @root: binary_tree_t pointer that points to the root node of the tree.
 * @node: binary_tree_t pointer that points to the current node to evaluate
 * Return: 1 if is BST0 if no
 */
int function_two(binary_tree_t *root, binary_tree_t *node)
{
	if (root && node)
	{
		int aux = 0;

		aux = function_one(root, node);
		if (node->left)
			aux &= function_two(root, node->left);
		if (node->right)
			aux &= function_two(root, node->right);
		return (aux);
	}
	return (0);
}
/**
 * binary_tree_is_bst - This Function check if ist a correctly bst tree.
 * @tree:binary_tree_t pointer that points to check.
 * Return: 1 if is bst 0 if not.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		return (function_two((binary_tree_t *)tree, (binary_tree_t *)tree));
	}
}
