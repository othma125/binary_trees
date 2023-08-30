#include "binary_trees.h"

/**
 * binary_tree_is_full - check code
 *
 * @tree: binary_tree_t node
 *
 * Return: an integer
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (!tree)
		return (0);
	if (tree->left)
		left = 1 + binary_tree_is_full(tree->left);
	if (tree->right)
		right = 1 + binary_tree_is_full(tree->right);
	if (left == right)
		return (1);
	return (0);
}
