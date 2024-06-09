#include "binary_trees.h"

int find_depth(const binary_tree_t *);
const binary_tree_t *find_ancestor(const binary_tree_t *,
		const binary_tree_t *);
/**
 * binary_trees_ancestor - finds the lowest common
 * ancestor of two nodes
 * @first: the first node
 * @second: the second node
 *
 * Return: the ancestor
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *ancestor = NULL;
	int first_depth, second_depth;

	if (!first || !second)
		return (NULL);

	first_depth = find_depth(first);
	second_depth = find_depth(second);

	if (first_depth == second_depth)
	{
		ancestor = find_ancestor(first, second);
		if (ancestor)
			return ((binary_tree_t *)ancestor);
	}
	else if (first_depth < second_depth)
	{
		while (second_depth != first_depth && second)
		{
			second = second->parent;
			second_depth--;
		}
		ancestor = find_ancestor(first, second);
		if (ancestor)
			return ((binary_tree_t *)ancestor);
	}
	else if (second_depth < first_depth)
	{
		while (first_depth != second_depth && first)
		{
			first = first->parent;
			first_depth--;
		}
		ancestor = find_ancestor(first, second);
		if (ancestor)
			return ((binary_tree_t *)ancestor);
	}

	return (NULL);
}

/**
 * find_depth - the depth level of the node
 * from the root node
 * @node: the node to look for
 *
 * Return: int (depth level)
 */

int find_depth(const binary_tree_t *node)
{
	int depth_level = 0;
	const binary_tree_t *temp = node;

	while (temp->parent != NULL)
	{
		depth_level++;
		temp = temp->parent;
	}

	return (depth_level);
}

/**
 * find_ancestor - finds the ancestor of the two nodes
 * @first: the first node
 * @second: the second node
 *
 * Return: ancestor
 */

const binary_tree_t *find_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	while (first && second)
	{
		if (first == second)
			return (first);
		first = first->parent;
		second = second->parent;
	}

	return (NULL);
}
