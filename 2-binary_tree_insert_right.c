#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the
 * right-child of another node
 * @parent: the pointer to the node to insert
 * @value: value to store
 *
 * Return: node
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node, *temp_right;

	node = temp_right = NULL;

	if (parent == NULL)
		return (NULL);

	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);

	node->n = value;
	if (parent->right)
		temp_right = parent->right;
	node->left = NULL;
	node->right = temp_right;
	parent->right = node;
	node->parent = parent;

	if (temp_right)
		temp_right->parent = node;

	return (node);
}
