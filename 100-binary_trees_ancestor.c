#include "binary_trees.h"

/**
 * binary_tree_depth - check code
 *
 * @tree: binary_tree_t node
 *
 * Return: integer
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return (tree ? 1 + binary_tree_depth(tree->parent) : 0);
}
/**
 * binary_tree_ancestor - check code
 * @node1: binary_tree_t node
 * @node2: binary_tree_t node
 * Return: binary_tree_t node
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *node1, const binary_tree_t *node2)
{
	size_t depth1, depth2;

	if (!node1 || !node1)
		return (NULL);
	depth1 = binary_tree_depth(node1);
	depth2 = binary_tree_depth(node2);
	if (depth1 > depth2)
	{
		while (depth1 != depth2)
		{
			node1 = node1->parent;
			depth1--;
		}
	}
	else if (depth2 > depth1)
	{
		while (depth2 != depth1)
		{
			node2 = node2->parent;
			depth2--;
		}
	}
	while (node1 && node2)
	{
		if (node1 == node2)
			return ((binary_tree_t *)node1);
		node1 = node1->parent;
		node2 = node2->parent;
	}
	return ((binary_tree_t *)node1);
}
