#include "binary_trees.h"
/**
 * nodes_counter - check code
 * @tree: binary_tree_t node
 * Return: an integer
 */
size_t nodes_counter(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + nodes_counter(tree->left) +
		nodes_counter(tree->right));
}
/**
 * complete_recursively - check code
 * @node: binary_tree_t node
 * @index: integer
 * @nodes_count: integer
 * Return: an integer
 */
int complete_recursively(const binary_tree_t *node,
size_t index, size_t nodes_count)
{
	if (!node)
		return (1);
	if (index >= nodes_count)
		return (0);
	return (complete_recursively(node->left, 2 * index + 1, nodes_count) &&
		complete_recursively(node->right, 2 * index + 2, nodes_count));
}
/**
 * binary_tree_is_complete - check code
 * @tree: binary_tree_t node
 * Return: an integer
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (!tree)
		return (1);
	return (complete_recursively(tree, 0, nodes_counter(tree)));
}
