#include "binary_trees.h"

void one_child_node(const binary_tree_t *, size_t *);
/**
 * binary_tree_nodes - counts the node with at least
 * 1 child in a tree
 * @tree: the root of the tree
 *
 * Return: the number of node with at least 1 child
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count = 0;

	if (!tree)
		return (0);

	one_child_node(tree, &count);
	return (count);
}

/**
 * one_child_node - counts the nodes with at least
 * one child
 * @tree: the root of the tree
 * @count: the number of node
 *
 * Return: void
 */

void one_child_node(const binary_tree_t *tree, size_t *count)
{
	if (tree == NULL)
		return;

	one_child_node(tree->left, count);
	one_child_node(tree->right, count);

	if (tree->left || tree->right)
		(*count)++;
}
