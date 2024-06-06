#include "binary_trees.h"

int tree_children(const binary_tree_t *, int, const binary_tree_t *);
/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: the root of the tree
 *
 * Return: 1 if the binary tree is full or 0 if not
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	int tree_leave_check_result;
	int array[] = {};

	if (!tree)
		return (1);

	tree_leave_check_result = tree_children(tree, array, tree);
}



/**
 * tree_children - checks if the children are
 * either 2 or 0
 * @tree: gets the node of the tree
 * @array: an array of depths of the leaves
 * @root: the root of the tree
 *
 * Return: 0 if children have at least one child, 1 is they have none
 * or two
 */

int tree_children(const binary_tree_t *tree, int array,
		const binary_tree_t *root)
{
	if (!tree)
		return (1);

	if (tree->left == NULL && tree->right == NULL)
	{
		depth_count(tree, root, array);
		return (1);
	}

	if ((tree->left) && (tree->right))
		return (tree_children(tree->left, array, root) &&
				tree_children(tree->right, array, root));

	return (0);
}

/**
 * depth_count - counts the depth of the node to the root
 * @tree: the current node position
 * @root: the root of the tree
 *
 * Return: the depth
 */

int depth_count(const binary_tree_t *tree, const binary_tree_t *root, int array)
{
	const binary_tree_t *tmp;
	int count;

	tmp = tree;
	count = 0;
	while (tmp->parent != root)
	{
		count++;
		tmp = tmp->parent;
	}
	return (count);
}
