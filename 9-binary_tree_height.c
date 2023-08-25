#include "binary_trees.h"

/**
 * binary_tree_depth - check code
 * @node: binary_tree_t node
 * Return: an integer
 */
size_t binary_tree_depth(const binary_tree_t *node)
{
	size_t depth = 0;

	if (!node)
		return (0);
	while (node->parent)
	{
		depth++;
		node = node->parent;
	}
	return (depth);
}
