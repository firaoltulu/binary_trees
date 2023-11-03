#include "binary_trees.h"

/**
 * array_to_avl - This Function Builds an AVL tree from an array.
 * @array: Integer pointer to the first element of the array to be converted.
 * @size: The number of elements in @array.
 *
 * Return: A pointer to the root node of the created AVL, or NULL upon failure.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	if (array == NULL)
	{
		return (NULL);
	}
	else
	{
		avl_t *three = NULL;
		size_t one, two;

		for (one = 0; one < size; one++)
		{
			for (two = 0; two < one; two++)
			{
				if (array[two] == array[one])
					break;
			}
			if (two == one)
			{
				if (avl_insert(&three, array[one]) == NULL)
					return (NULL);
			}
		}
		return (three);
	}
}
