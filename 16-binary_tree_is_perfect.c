#include "binary_trees.h"

void free_linked_list(depth_ls *);
int compare_leaves(depth_ls *);
void add_depth_end(int, depth_ls **);
int is_perfect_tree_function(const binary_tree_t *, int, depth_ls **);
/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: the root of the tree
 *
 * Return: checks if a binary tree is perfect
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	depth_ls *head;
	int is_perfect;

	if (!tree)
		return (1);
	head = NULL;

	is_perfect = is_perfect_tree_function(tree, 0, &head) == 0 ?
			0 : 1;

	if (is_perfect && compare_leaves(head))
	{
		free_linked_list(head);
		return (1);
	}
	free_linked_list(head);
	return (0);
}


/**
 * is_perfect_tree_function - checks if a binary tree is perfect
 * @level: the current depth level
 * @tree: the current root tree
 * @head: the head of linked list to save depth
 *
 * Return: 1 if perfect, else 0
 */

int is_perfect_tree_function(const binary_tree_t *tree, int level,
		depth_ls **head)
{
	if (!tree)
		return (1);

	if (tree->left == NULL && tree->right == NULL)
	{
		add_depth_end(level, head);
		return (1);
	}

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (is_perfect_tree_function(tree->left, level + 1, head) &&
			is_perfect_tree_function(tree->right, level + 1, head));
}

/**
 * add_depth_end - add the depth level at the end of list
 * @level: the depth of leave
 * @head: the head of the list
 *
 * Return: void
 */

void add_depth_end(int level, depth_ls **head)
{
	depth_ls *node = NULL;

	node = malloc(sizeof(depth_ls));
	if (!node)
		return;

	node->depth = level;
	if (*head == NULL)
	{
		node->next = NULL;
		*head = node;
	}
	else
	{
		depth_ls *tmp = *head;

		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = node;
		node->next = NULL;
	}
}

/**
 * compare_leaves - compares all the depth in the nodes
 * @head: the head
 *
 * Return: 1 if same depth, else 0
 */

int compare_leaves(depth_ls *head)
{
	int depth_level;
	depth_ls *temp = head;

	depth_level = temp->depth;
	while (temp)
	{
		if (depth_level != temp->depth)
			return (0);
		temp = temp->next;
	}

	return (1);
}

/**
 * free_linked_list - frees the head of the linked list
 * @head: the head of the list to free
 *
 * Return: void
 */

void free_linked_list(depth_ls *head)
{
	depth_ls *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
