#include "binary_trees.h"

/**
 * binary_tree_is_leaf - check code
 * @node: binary_tree_t
 * Return: nothing
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node)
		return (0);
	if (!node->left && !node->right)
		return (1);
	return (0);
}
