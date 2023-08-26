#include "binary_trees.h"

/**
 * binary_tree_is_complete - check code
 * @tree: binary_tree_t node
 * Return: a binary_tree_t node
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);
{
	if (!tree)
		return (NULL);
	if (tree->left)
	{
		tree->left->parent = tree->parent;
		tree->parent = tree->left;
		tree->left = tree->left->right;
		tree->parent->right = tree;
		return (tree->parent);
	}
	return (tree);

}
