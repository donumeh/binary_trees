#include "binary_trees.h"

/**
 * binary_tree_is_root - checks if a given node is a root
 * @node: the node to check
 *
 * Return: 1 if node is root, 0 if otherwise
 */

int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	if (!node->parent)
		return (1);
	return (0);
}
