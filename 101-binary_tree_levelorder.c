#include "binary_trees.h"


/**
 * binary_tree_levelorder - goes through binary tree using
 * level-order traversal
 * @tree: the root of the tree
 * @func: the function to print the node value
 *
 * Return: void
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t **array;
	int front = 0, rear = 0;

	array = malloc(sizeof(binary_tree_t *));
	if (array == NULL)
		return;

	if (!tree)
		return;

	array[rear++] = (binary_tree_t *)tree;

	while (front < rear)
	{
		binary_tree_t *current = array[front++];

		func(current->n);

		if (current->left)
		{
			array = realloc(array, sizeof(binary_tree_t *) * (rear + 2));
			array[rear++] = current->left;
		}

		if (current->right)
		{
			array = realloc(array, sizeof(binary_tree_t *) * (rear + 2));
			array[rear++] = current->right;
		}
	}

	free(array);
}
