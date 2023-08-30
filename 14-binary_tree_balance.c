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
	size_t left_height = 1, right_height = 1;

	if (!node)
		return (0);
	if (node->left)
		left_height += binary_tree_height(node->left);
	if (node->right)
		right_height += binary_tree_height(node->right);
	if (left_height > right_height)
		return (left_height);
	return (right_height);
}
/**
 * binary_tree_balance - check code
 * @tree: binary_tree_t node
 * Return: an integer
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t left = 0, right = 0;

	if (!tree)
		return (0);
	if (tree->left)
		left = binary_tree_height(tree->left);
	if (tree->right)
		right = binary_tree_height(tree->right);
	return ((int)left - (int)right);
}
