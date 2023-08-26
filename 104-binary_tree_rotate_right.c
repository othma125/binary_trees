#include "binary_trees.h"

/**
 * binary_tree_is_complete - check code
 * @tree: binary_tree_t node
 * Return: a binary_tree_t node
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *left_node, *tmp;

	if (!tree || !tree->left)
		return (NULL);
	left_node = tree->left;
	tmp = left_node->right;
	left_node->right = tree;
	tree->left = tmp;
	if (tmp)
		tmp->parent = tree;
	tmp = tree->parent;
	tree->parent = left_node;
	left_node->parent = tmp;
	if (tmp)
	{
		if (tmp->left == tree)
			tmp->left = left_node;
		else
			tmp->right = left_node;
	}
	return (left_node);
}
