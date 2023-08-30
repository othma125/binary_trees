#include "binary_trees.h"

/**
 * binary_tree_height - check code
 *
 * @node: binary_tree_t node
 *
 * Return: an integer
 */
size_t binary_tree_height(const binary_tree_t *node)
{
	size_t left_height = 0, right_height = 0;

	if (node == NULL)
		return (0);
	if (node->left)
		left_height = 1 + binary_tree_height(node->left);
	if (node->right)
		right_height = 1 + binary_tree_height(node->right);
	if (left_height > right_height)
		return (left_height);
	return (right_height);
}
