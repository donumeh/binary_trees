#include "binary_trees.h"

#define ROOT 1
size_t check_height(const binary_tree_t *tree);
/**
 * binary_tree_balance - measures the balance factor of
 * a binary tree
 * @tree: the root node of the tree to measure
 *
 * Return: measure of the balance factor
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	size_t left_side, right_side;

	if (!tree)
		return (0);

	left_side = check_height(tree->left) - ROOT;
	right_side = check_height(tree->right) - ROOT;

	return ((int)(left_side - right_side));
}


/**
 * check_height - checks the height of a root tree
 * @tree: the root of the tree
 *
 * Return: height of the tree
 */

size_t check_height(const binary_tree_t *tree)
{
	size_t left_side = 0, right_side = 0;

	if (!tree)
		return (0);

	left_side = check_height(tree->left);
	right_side = check_height(tree->right);

	if (left_side >= right_side)
		return (left_side + 1);
	else if (right_side > left_side)
		return (right_side + 1);
	return (0);
}
