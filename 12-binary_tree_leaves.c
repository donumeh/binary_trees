#include "binary_trees.h"

void count_leaves(const binary_tree_t *, size_t *);
/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: the root to tree
 *
 * Return: number of leaves
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t count = 0;

	if (tree == NULL)
		return (0);

	count_leaves(tree, &count);

	return (count);
}

/**
 * count_leaves - counts the leaves in a binary tree
 * @tree: the root of the tree
 * @count: the num of leaves in tree
 *
 * Return: num of leaves in tree
 */

void count_leaves(const binary_tree_t *tree, size_t *count)
{
	if (tree == NULL)
		return;
	count_leaves(tree->left, count);
	count_leaves(tree->right, count);

	if (!tree->left && !tree->right)
		(*count)++;
}
