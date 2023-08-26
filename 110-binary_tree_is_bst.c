
#include <limits.h>
#include "binary_trees.h"

/**
 * is_bst_recursion - check code
 * @node: binary_tree_t node
 * @min: integer
 * @max: integer
 * Return: an integer
 */
int is_bst_recursion(const binary_tree_t *node, int min, int max)
{
	if (!node)
		return (1);
	if (node->n < min || node->n > max)
		return (0);
	return (is_bst_recursion(node->left, min, node->n - 1) &&
		is_bst_recursion(node->right, node->n + 1, max));
}
/**
 * binary_tree_is_bst - check code
 * @node: binary_tree_t node
 * Return: an integer
 */
int binary_tree_is_bst(const binary_tree_t *node)
{
	if (!node)
		return (0);
	return (is_bst_recursion(node, INT_MIN, INT_MAX));
}
