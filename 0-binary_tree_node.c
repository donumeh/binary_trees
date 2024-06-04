#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 * @parent: the parent of the node
 * @value: the value of the node
 *
 * Return: binary_tree_t node
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);

	node->n = value;

	if (parent != NULL)
		node->parent = parent;
	else
		node->parent = NULL;
	node->left = NULL;
	node->right = NULL;

	return (node);
}
