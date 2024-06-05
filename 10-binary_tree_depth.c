#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node
 * @tree: the root of a tree
 *
 * Return: depth of the node
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	int depth = 0;

	if (tree == NULL)
		return (0);

	while (tree->parent != NULL)
	{
		depth++;
		tree = tree->parent;
	}

	return (depth);
}
