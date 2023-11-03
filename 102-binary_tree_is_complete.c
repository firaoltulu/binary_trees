#include "binary_trees.h"

levelorder_queue_t *function_one(binary_tree_t *node);
void function_two(levelorder_queue_t *head);
void function_three(binary_tree_t *node, levelorder_queue_t *head,
                    levelorder_queue_t **tail);
void function_four(levelorder_queue_t **head);

/**
 * function_one - This Function Creates a new levelorder_queue_t node.
 * @node: binary_tree_t pointer that points to The binary tree node
 * for the new node to contain.
 *
 * Return: If an error occurs, NULL. Otherwise, a pointer to the new node.
 */
levelorder_queue_t *function_one(binary_tree_t *node)
{
    levelorder_queue_t *one;

    one = malloc(sizeof(levelorder_queue_t));
    if (one == NULL)
    {
        return (NULL);
    }
    else
    {
        one->node = node;
        one->next = NULL;
        return (one);
    }
}

/**
 * function_two - Thins Function Frees a levelorder_queue_t queue.
 * @head: binary_tree_t pointer to the head of the queue.
 * Return: Nothing(Void).
 */
void function_two(levelorder_queue_t *head)
{
    levelorder_queue_t *one;

    while (head != NULL)
    {
        one = head->next;
        free(head);
        head = one;
    }
}

/**
 * function_three - This function_threees a node to the back of a levelorder_queue_t queue.
 * @node: binary_tree_t pointer that points to The binary tree node to print and function_three.
 * @head: levelorder_queue_t pointer to the head of the queue.
 * @tail: A double pointer to the tail of the queue.
 *
 * Return: Nothing(Void).
 */
void function_three(binary_tree_t *node, levelorder_queue_t *head,
                    levelorder_queue_t **tail)
{
    levelorder_queue_t *new;

    new = function_one(node);
    if (new == NULL)
    {
        function_two(head);
        exit(1);
    }
    (*tail)->next = new;
    *tail = new;
}

/**
 * function_four - This function does the head of a levelorder_queue_t queue.
 * @head: levelorder_queue_t double pointer to the head of the queue.
 * Return: Nothing(Void).
 */
void function_four(levelorder_queue_t **head)
{
    levelorder_queue_t *one;

    one = (*head)->next;
    free(*head);
    *head = one;
}

/**
 * binary_tree_is_complete - This Function Checks if a binary tree is complete.
 * @tree: binary_tree_t pointer to the root node of the tree to traverse.
 *
 * Return: If the tree is NULL or not complete, 0.Otherwise, 1.
 *
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    levelorder_queue_t *one, *two;
    unsigned char three = 0;

    if (tree == NULL)
    {
        return (0);
    }
    else
    {
        one = two = function_one((binary_tree_t *)tree);
        if (one == NULL)
        {
            exit(1);
        }
        else
        {
            while (one != NULL)
            {
                if (one->node->left != NULL)
                {
                    if (three == 1)
                    {
                        function_two(one);
                        return (0);
                    }
                    else
                    {
                        function_three(one->node->left, one, &two);
                    }
                }
                else
                    three = 1;
                if (one->node->right != NULL)
                {
                    if (three == 1)
                    {
                        function_two(one);
                        return (0);
                    }
                    else
                    {
                        function_three(one->node->right, one, &two);
                    }
                }
                else
                    three = 1;
                function_four(&one);
            }
            return (1);
        }
    }
}