#include "binary_trees.h"

/**
 * binary_tree_size - check code
 *
 * @tree: binary_tree_t node
 *
 * Return: an integer
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
		return (0);
	size = 0;
	if (tree->left)
		size += binary_tree_size(tree->left);
	if (tree->right)
		size += binary_tree_size(tree->right);
	return (size + 1);
}
