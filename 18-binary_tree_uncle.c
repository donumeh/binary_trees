#include "binary_trees.h"

binary_tree_t *tree_sibling(binary_tree_t *);
/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: the node to search
 *
 * Return: uncle of node
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *uncle;

	if (!node || !node->parent || !node->parent->parent)
		return (NULL);

	uncle = tree_sibling(node->parent);
	return (uncle);
}

/**
 * tree_sibling - finds the sibling of a node
 * @node: the node
 *
 * Return: sibling of a node
 */

binary_tree_t *tree_sibling(binary_tree_t *node)
{
	if (node->parent->left != node &&
			node->parent->left)
		return (node->parent->left);

	if (node->parent->right != node &&
			node->parent->right)
		return (node->parent->right);

	return (NULL);
}
