#include "binary_trees.h"

/**
 * bst_delete - check code
 * @root: bst_t node
 * @node: bst_t node
 * Return: bst_t node
 */
bst_t *bst_delete(bst_t **root, bst_t *node)
{
	bst_t *temp;

	if (!node->left && !node->right)
	{
		if (node == *root)
			return (free(node), NULL);
		if (node->parent->left == node)
			node->parent->left = NULL;
		else
			node->parent->right = NULL;
		return (free(node), *root);
	}
	if (!node->left)
	{
		if (node == *root)
			return (root = &node->right, (*root)->parent = NULL, free(node), *root);
		if (node->parent->left == node)
			node->parent->left = node->right;
		else
			node->parent->right = node->right;
		return (node->right->parent = node->parent, free(node), *root);
	}
	if (!node->right)
	{
		if (node == *root)
		{
			root = &node->left, (*root)->parent = NULL, free(node);
			return (*root);
		}
		if (node->parent->left == node)
			node->parent->left = node->left;
		else
			node->parent->right = node->left;
		node->left->parent = node->parent;
		return (free(node), *root);
	}
	temp = node->right;
	while (temp->left)
		temp = temp->left;
	return (node->n = temp->n, bst_delete(root, temp));
}

/**
 * remove_recursive - check code
 * @root: bst_t node
 * @node: bst_t node
 * @value: integer
 * Return: bst_t node
 */
bst_t *remove_recursive(bst_t **root, bst_t *node, int value)
{
	if (!node)
		return (NULL);
	if (node->n == value)
		return (bst_delete(root, node));
	if (node->n > value)
		return (remove_recursive(root, node->left, value));
	return (remove_recursive(root, node->right, value));
}
/**
 * bst_remove - check code
 * @root: bst_t node
 * @value: integer
 * Return: bst_t node
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (remove_recursive(&root, root, value));
}
