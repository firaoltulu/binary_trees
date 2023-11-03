#include "binary_trees.h"

/**
 * function_four - This Function create the tree
 * using the half element of the array.
 * @parent: avl_t pointer that points to the
 * parent of the node to create.
 * @array: Integer pointer that points to the
 * sorted array.
 * @begin: position where the array starts.
 * @last: position where the array ends.
 * Return: tree created.
 */
avl_t *function_four(avl_t *parent, int *array, int begin, int last)
{
    avl_t *one;
    binary_tree_t *two;
    int three = 0;

    if (begin <= last)
    {
        three = (begin + last) / 2;
        two = binary_tree_node((binary_tree_t *)parent, array[three]);
        if (two == NULL)
            return (NULL);
        one = (avl_t *)two;
        one->left = function_four(one, array, begin, three - 1);
        one->right = function_four(one, array, three + 1, last);
        return (one);
    }
    return (NULL);
}

/**
 * sorted_array_to_avl - This Function create a alv tree from sorted array.
 * @array: Integer pointer that points to the sorted array.
 * @size: size of the sorted array.
 * Return: alv tree form sorted array.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (array == NULL || size == 0)
    {
        return (NULL);
    }
    else
    {
        return (function_four(NULL, array, 0, ((int)(size)) - 1));
    }
}