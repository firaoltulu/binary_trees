#include "binary_trees.h"

size_t function_one(const binary_tree_t *tree);
int function_two(const binary_tree_t *tree);
avl_t *function_three(avl_t **tree, avl_t *parent,
                      avl_t **new, int value);
avl_t *avl_insert(avl_t **tree, int value);

/**
 * function_one - This Function Measures the height of a binary tree.
 * @tree: binary_tree_t pointer that points to the
 * root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */
size_t function_one(const binary_tree_t *tree)
{
    if (tree != NULL)
    {
        size_t one = 0, two = 0;

        one = tree->left ? 1 + binary_tree_height(tree->left) : 1;
        two = tree->right ? 1 + binary_tree_height(tree->right) : 1;
        return ((one > two) ? one : two);
    }
    return (0);
}

/**
 * function_two - Measures the balance factor of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the function_two factor.
 *
 * Return: If tree is NULL, return 0, else return function_two factor.
 */
int function_two(const binary_tree_t *tree)
{
    return (tree != NULL ? function_one(tree->left) - function_one(tree->right) : 0);
}

/**
 * function_three - This Function Inserts a value into an AVL tree recursively.
 * @tree: avl_t double pointer to the root node of the AVL tree to insert into.
 * @parent:avl_t pointer that points to the parent node of the current working node.
 * @new: avl_t double pointer to store the new node.
 * @value: The value to insert into the AVL tree.
 *
 * Return: A pointer to the new root after insertion, or NULL on failure.
 */
avl_t *function_three(avl_t **tree, avl_t *parent,
                      avl_t **new, int value)
{
    int one;

    if (*tree == NULL)
    {
        return (*new = binary_tree_node(parent, value));
    }
    else
    {
        if ((*tree)->n > value)
        {
            (*tree)->left = function_three(&(*tree)->left, *tree, new, value);
            if ((*tree)->left == NULL)
                return (NULL);
        }
        else if ((*tree)->n < value)
        {
            (*tree)->right = function_three(&(*tree)->right, *tree, new, value);
            if ((*tree)->right == NULL)
                return (NULL);
        }
        else
            return (*tree);

        one = function_two(*tree);
        if (one > 1 && (*tree)->left->n > value)
            *tree = binary_tree_rotate_right(*tree);
        else if (one < -1 && (*tree)->right->n < value)
            *tree = binary_tree_rotate_left(*tree);
        else if (one > 1 && (*tree)->left->n < value)
        {
            (*tree)->left = binary_tree_rotate_left((*tree)->left);
            *tree = binary_tree_rotate_right(*tree);
        }
        else if (one < -1 && (*tree)->right->n > value)
        {
            (*tree)->right = binary_tree_rotate_right((*tree)->right);
            *tree = binary_tree_rotate_left(*tree);
        }

        return (*tree);
    }
}

/**
 * avl_insert - Inserts a value into an AVL tree.
 * @tree: A double pointer to the root node of the AVL tree to insert into.
 * @value: The value to insert into the AVL tree.
 *
 * Return: A pointer to the inserted node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    avl_t *one = NULL;

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
        function_three(tree, *tree, &one, value);
        return (one);
    }
}
