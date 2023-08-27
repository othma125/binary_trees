#include "binary_trees.h"
#include <limits.h>

/**
 * binary_tree_height - check code
 * @tree: binary_tree_t node
 *
 * Return: integer
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_left = 0;
	size_t height_right = 0;

	if (!tree)
		return (0);
	height_left = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_right = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (height_left > height_right ? height_left : height_right);
}
/**
 * btia_helper - check code
 * @tree: binary_tree_t node
 * @min: integer
 * @max: integer
 * Return: integer
 */
int btia_helper(const binary_tree_t *tree, int min, int max)
{
	int left, right;

	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	left = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	right = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	if (abs(left - right) > 1)
		return (0);
	return (btia_helper(tree->left, min, tree->n - 1) &&
		btia_helper(tree->right, tree->n + 1, max));
}
/**
 * binary_tree_is_avl - check code
 * @tree: binary_tree_t node
 * Return: integer
 */
int binary_tree_is_avl(const binary_tree_t *tree);
{
	if (!tree)
		return (0);
	return (btia_helper(tree, INT_MIN, INT_MAX));
}
