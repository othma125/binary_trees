#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Determines if a given node
 * is a leaf in a binary tree.
 * @node: Pointer to the node to be checked.
 *
 * Description: A leaf node in a binary tree is a node that has no left or
 *              right child. This function checks if the provided node is a
 *              leaf by ensuring it exists and verifying that neither of its
 *              child pointers are set.
 *
 * Return: 1 if the node is a leaf, 0 otherwise or if the node is NULL.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node)
		return (0);
	if (!node->left && !node->right)
		return (1);
	return (0);
}
