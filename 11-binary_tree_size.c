#include "binary_trees.h"

void tree_size(const binary_tree_t *, size_t *);

/**
 * binary_tree_size - measure the size of a binary tree
 * @tree: the node to check
 *
 * Return: size of the tree
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree == NULL)
		return (0);

	tree_size(tree, &size);
	return (size);
}


/**
 * tree_size - checks the size of the tree
 * @tree: the tree
 * @size: the size of the node being updated
 *
 * Return: void
 */

void tree_size(const binary_tree_t *tree, size_t *size)
{
	if (tree == NULL)
		return;
	tree_size(tree->left, size);
	tree_size(tree->right, size);
	(*size)++;
}
