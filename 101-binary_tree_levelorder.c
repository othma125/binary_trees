#include "binary_trees.h"

/**
 * binary_tree_levelorder - traverse a binary tree using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 *
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t lvl = 1, max_lvl;

	if (tree == NULL || func == NULL)
		return;

	max_lvl = binary_tree_height(tree) + 1;

	while (lvl <= max_lvl)
	{
		btlo_helper(tree, func, lvl);
		lvl++;
	}
}

/**
 * btlo_helper - traverse a binary tree using post-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 * @level: the level of the tree to call func upon
 *
 * Return: void
 */
void btlo_helper(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (tree == NULL)
		return;

	if (level == 1)
	{
		func(tree->n);
		return;
	}

	btlo_helper(tree->left, func, level - 1);
	btlo_helper(tree->right, func, level - 1);
}

/**
 * binary_tree_height - calculate the height of a binary tree
 * @tree: pointer to the root node of the tree to calculate the height of
 *
 * Return: the height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l = 0, height_r = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		height_l = 1 + binary_tree_height(tree->left);

	if (tree->right)
		height_r = 1 + binary_tree_height(tree->right);

	return (height_l > height_r ? height_l : height_r);
}
