#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a Binary Search Tree.
 *
 * @tree: Pointer to the root node of the BST to search.
 * @value: The value to search for in the tree.
 *
 * Return: Pointer to the node containing the value.
 *         NULL if tree is NULL or if no match is found.
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *n = (bst_t *)tree;

	if (!tree)
		return (NULL);

	while (n)
	{
		if (value == n->n)
			return (n);
		if (value < n->n)
			n = n->left;
		else if (value > n->n)
			n = n->right;
	}

	return (NULL);
}