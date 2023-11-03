#include "binary_trees.h"

/**
 * function_one - This Function Measures function_oneance factor of a AVL.
 * @tree: avl_t double pointer that points to the tree
 * to go through.
 * Return: Nothing(Void).
 */
void function_one(avl_t **tree)
{
    if (tree == NULL || *tree == NULL)
    {
        return;
    }
    if ((*tree)->left == NULL && (*tree)->right == NULL)
    {
        return;
    }
    else
    {
        int one;

        function_one(&(*tree)->left);
        function_one(&(*tree)->right);
        one = binary_tree_balance((const binary_tree_t *)*tree);
        if (one > 1)
            *tree = binary_tree_rotate_right((binary_tree_t *)*tree);
        else if (one < -1)
            *tree = binary_tree_rotate_left((binary_tree_t *)*tree);
    }
}

/**
 * function_two - This Function get the next succussor i mean the
 * min node in the right subtree.
 * @node: bst_t pointer that points to the tree to check.
 * Return: the min value of this tree..
 */
int function_two(bst_t *node)
{
    if (node == NULL)
    {
        return (0);
    }
    else
    {
        int one = 0;

        one = function_two(node->left);
        if (one == 0)
        {
            return (node->n);
        }
        else
        {
            return (one);
        }
    }
}

/**
 *function_three - This function removes a node depending of its children.
 *@root: bst_t pointer that points to node to remove.
 *Return: 0 if it has no children or other value if it has.
 */
int function_three(bst_t *root)
{
    if (!root->left && !root->right)
    {
        if (root->parent->right == root)
            root->parent->right = NULL;
        else
            root->parent->left = NULL;
        free(root);
        return (0);
    }
    else if ((!root->left && root->right) || (!root->right && root->left))
    {
        if (!root->left)
        {
            if (root->parent->right == root)
                root->parent->right = root->right;
            else
                root->parent->left = root->right;
            root->right->parent = root->parent;
        }
        if (!root->right)
        {
            if (root->parent->right == root)
                root->parent->right = root->left;
            else
                root->parent->left = root->left;
            root->left->parent = root->parent;
        }
        free(root);
        return (0);
    }
    else
    {
        int one = 0;

        one = function_two(root->right);
        root->n = one;
        return (one);
    }
}

/**
 * function_four - remove a node from a BST tree
 * @root: root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 */
bst_t *function_four(bst_t *root, int value)
{
    int type = 0;

    if (root == NULL)
    {
        return (NULL);
    }
    else
    {
        if (value < root->n)
            function_four(root->left, value);
        else if (value > root->n)
            function_four(root->right, value);
        else if (value == root->n)
        {
            type = function_three(root);
            if (type != 0)
                function_four(root->right, type);
        }
        else
            return (NULL);
        return (root);
    }
}

/**
 * avl_remove - remove a node from a AVL tree
 * @root: root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 */
avl_t *avl_remove(avl_t *root, int value)
{
    avl_t *one = (avl_t *)function_four((bst_t *)root, value);

    if (one == NULL)
    {
        return (NULL);
    }
    else
    {
        function_one(&one);
        return (one);
    }
}