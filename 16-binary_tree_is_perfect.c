#include "binary_trees.h"

/**
 * min_leaf_depth - check code
 *
 * @tree: binary_tree_t node
 *
 * Return: an integer
 */
size_t min_leaf_depth(const binary_tree_t *tree)
{
	if (!tree || (!tree->left && !tree->right))
		return (0);
	if (tree->left)
		return (1 + min_leaf_depth(tree->left));
	return (1 + min_leaf_depth(tree->right));
}
/**
 * binary_tree_is_perfect - check code
 *
 * @node: binary_tree_t node
 * @max_depth: integer
 * @level: integer
 *
 * Return: an integer
 */
int perfect_recursively(const binary_tree_t *node,
						size_t max_depth, size_t level)
{
	if (!node->left && !node->right)
		return (level == max_depth ? 1 : 0);
	if (!node->left || !node->right)
		return (0);
	return (perfect_recursively(node->left, max_depth, level + 1) &&
			perfect_recursively(node->right, max_depth, level + 1));
}
/**
 * binary_tree_is_perfect - check code
 *
 * @tree: binary_tree_t node
 *
 * Return: an integer
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (perfect_recursively(tree, min_leaf_depth(tree), 0));
}
