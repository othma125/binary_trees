#include "binary_trees.h"

/**
 * binary_tree_is_root - check code
 * @node: binary_tree_t node
 * Return: nothing
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	return (node && !node->parent);
}
