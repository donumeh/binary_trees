#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left child
 * of another node
 * @parent: the parent of the node
 * @value: value to insert
 *
 * Return: node
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node, *temp_left;

	if (parent == NULL)
		return (NULL);

	node = temp_left = NULL;

	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);

	if (parent->left)
		temp_left = parent->left;

	node->parent = parent;
	parent->left = node;
	node->left = temp_left;
	node->n = value;
	node->right = NULL;

	if (temp_left)
		temp_left->parent = node;

	return (node);
}
