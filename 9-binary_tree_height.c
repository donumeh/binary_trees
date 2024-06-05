#include "binary_trees.h"
#include <stdio.h>

size_t find_height(const binary_tree_t *);

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: the root of the tree
 *
 * Return: size of the height
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	return find_height(tree) - 1;
}




size_t find_height(const binary_tree_t *tree)
{
	int left = 0, right = 0;
	if (tree == NULL)
		return (0);
	
	left = find_height(tree->left);
	right = find_height(tree->right);

	if (left >= right)
		return (left + 1);
	else
		return (right + 1);
}
