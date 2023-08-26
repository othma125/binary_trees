#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Rotates the binary tree to the left.
 *
 * @tree: Pointer to the root node of the tree to rotate.
 *
 * Return: Pointer to the new root node of the tree.
 *         NULL if tree is NULL or if tree has no right child.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pvt;

	if (!tree || !tree->right)
		return (NULL);
	pvt = tree->right;
	tree->right = pvt->left;
	if (pvt->left != NULL)
		pvt->left->parent = tree;
	pvt->left = tree;
	pvt->parent = tree->parent;
	tree->parent = pvt;
	return (pvt);
}
