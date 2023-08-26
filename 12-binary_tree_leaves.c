#include "binary_trees.h"

/**
 * binary_tree_leaves - check code
 * @tree: binary_tree_t node
 * Return: an integer
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	int leaves = 0;

	if (!tree)
		return (leaves);
	if (!tree->left && !tree->right)
		return (1);
	if (tree->left)
		leaves += binary_tree_leaves(tree->left);
	if (tree->right)
		leaves += binary_tree_leaves(tree->right);
	return (leaves);
}
