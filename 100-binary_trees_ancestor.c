#include "binary_trees.h"

/**
 * binary_tree_depth - This Function measures the depth of a node in a binary tree.
 *@tree: binary_tree_t pointer to the node to measure the depth.
 * Return: if tree is NULL, function must return 0.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		return (1 + binary_tree_depth(tree->parent));
	}
}
/**
 * binary_trees_ancestor - This Function finds the lowest common ancestor of two nodes.
 * @first: binary_tree_t pointer that points to the first node.
 * @second: binary_tree_t pointer that points to the second node.
 * Return: lowest common ancestor
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	size_t one = 0, two = 0;
	const binary_tree_t *three = NULL;

	one = binary_tree_depth(first);
	two = binary_tree_depth(second);
	if (one && two)
	{
		if (one > two)
		{
			three = first;
			first = second;
			second = three;
		}
		while (first)
		{
			three = second;
			while (three)
			{
				if (first == three)
					return ((binary_tree_t *)first);
				three = three->parent;
			}
			first = first->parent;
		}
	}
	else
	{
		return (NULL);
	}
	return (NULL);
}
