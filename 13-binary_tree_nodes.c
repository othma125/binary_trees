#include "binary_trees.h"

/**
 * binary_tree_nodes - check code
 * @tree: binary_tree_t node
 * Return: an integer
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0;

	if (!tree)
		return (nodes);
	if (tree->left || tree->right)
		nodes += 1;
	if (tree->left)
		nodes += binary_tree_nodes(tree->left);
	if (tree->right)
		nodes += binary_tree_nodes(tree->right);
	return (nodes);
}
