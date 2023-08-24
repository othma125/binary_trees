#include "binary_trees.h"

/**
 * binary_tree_inorder - check code
 * @tree: binary_tree_t
 * @func: function pointer
 * Return: nothing
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;
	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
