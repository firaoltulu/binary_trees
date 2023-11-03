#include "binary_trees.h"

/**
 * array_to_bst - This Function builds a Binary Search Tree from an array.
 * @array: int pointer to the first element of the array to be converted.
 * @size: number of element in the array.
 * Return: pointer to the root node of the created BST, or NULL on failure.
 */

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *one;
	size_t two;

	if (array == NULL)
	{
		return (NULL);
	}
	else
	{
		one = NULL;
		for (two = 0; two < size; two++)
		{
			bst_insert(&one, array[two]);
		}
		return (one);
	}
}
