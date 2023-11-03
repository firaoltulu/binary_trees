#include "binary_trees.h"

bst_t *function_one(bst_t *root);
bst_t *function_two(bst_t *root, bst_t *node);
bst_t *function_three(bst_t *root, bst_t *node, int value);
bst_t *bst_remove(bst_t *root, int value);

/**
 * function_one - This Function Returns the minimum value of a binary search tree.
 * @root: bst_t pointer to the root node of the BST to search.
 *
 * Return: bst_t pointer that points to The minimum value in @tree.
 */
bst_t *function_one(bst_t *root)
{
    while (root->left != NULL)
        root = root->left;
    return (root);
}

/**
 * function_two - This Function Deletes a node from a binary search tree.
 * @root: A pointer to the root node of the BST.
 * @node: A pointer to the node to delete from the BST.
 *
 * Return: bst_t pointer that points to the new root node after deletion.
 */
bst_t *function_two(bst_t *root, bst_t *node)
{
    bst_t *one = node->parent, *two = NULL;

    if (node->left == NULL)
    {
        if (one != NULL && one->left == node)
            one->left = node->right;
        else if (one != NULL)
            one->right = node->right;
        if (node->right != NULL)
            node->right->parent = one;
        return (one == NULL ? node->right : root);
        free(node);
    }
    if (node->right == NULL)
    {
        if (one != NULL && one->left == node)
            one->left = node->left;
        else if (one != NULL)
            one->right = node->left;
        if (node->left != NULL)
            node->left->parent = one;
        return (one == NULL ? node->left : root);
        free(node);
    }

    two = function_one(node->right);
    node->n = two->n;

    return (function_two(root, two));
}

/**
 * function_three - This Function Removes a node from a binary search tree recursively.
 * @root: bst_t pointer to the root node of the BST to remove a node from.
 * @node: bst_t pointer to the current node in the BST.
 * @value: The value to remove from the BST.
 *
 * Return: A pointer to the root node after deletion.
 */
bst_t *function_three(bst_t *root, bst_t *node, int value)
{
    if (node != NULL)
    {
        if (node->n == value)
        {
            return (function_two(root, node));
        }
        if (node->n > value)
        {
            return (function_three(root, node->left, value));
        }
        return (function_three(root, node->right, value));
    }
    return (NULL);
}

/**
 * bst_remove - This Function Removes a node from a binary search tree.
 * @root: A pointer to the root node of the BST to remove a node from.
 * @value: The value to remove in the BST.
 *
 * Return: A pointer to the new root node after deletion.
 *
 *
 */
bst_t *bst_remove(bst_t *root, int value)
{
    return (function_three(root, root, value));
}