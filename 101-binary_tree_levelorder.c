#include "binary_trees.h"

int find_height(const binary_tree_t *);
int find_depth(const binary_tree_t *);
void print_levelorder(const binary_tree_t *, int, void (*)(int));
/**
 * binary_tree_levelorder - goes through a binary tree
 * using level-order traversal
 * @tree: the root of the tree
 * @func: the function to print the value
 *
 * Return: void
 */

void binary_tree_levelorder(const binary_tree_t *tree,
		void (*func)(int))
{
	int tree_height, i;

	if (!tree || !func)
		return;

	tree_height = find_height(tree);

	for (i = 0; i < tree_height; i++)
	{
		print_levelorder(tree, i, func);
	}
}


/**
 * find_height - finds the height of a tree
 * @tree: the root to start count
 *
 * Return: int (height)
 */

int find_height(const binary_tree_t *tree)
{
	int left_side, right_side;

	if (!tree)
		return (0);

	left_side = find_height(tree->left);
	right_side = find_height(tree->right);

	if (left_side >= right_side)
		return (left_side + 1);
	else
		return (right_side + 1);
}


/**
 * find_depth - finds the depth of a node
 * @node: the node to search for depth
 *
 * Return: int (depth of node)
 */

int find_depth(const binary_tree_t *node)
{
	int depth_level = 0;

	while (node->parent != NULL)
	{
		depth_level++;
		node = node->parent;
	}

	return (depth_level);
}


/**
 * print_levelorder - prints the node values by level
 * @tree: the root
 * @level: the level to print
 * @func: the function that prints
 *
 * Return: void
 */

void print_levelorder(const binary_tree_t *tree,
		int level, void (*func)(int))
{
	int node_depth;

	if (!tree)
		return;

	print_levelorder(tree->left, level, func);
	print_levelorder(tree->right, level, func);
	node_depth = find_depth(tree);
	if (node_depth == level)
		func(tree->n);
}
