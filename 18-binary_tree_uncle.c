#include "binary_trees.h"
	
/**
 * sibling - check code
 * @node: binary_tree_t node
 * Return: binary_tree_t node
 */
binary_tree_t *sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);
	if (node->parent->left == node)
		return (node->parent->right);
	else if (node->parent->right == node)
		return(node->parent->left);
}
/**
 * binary_tree_uncle - check code
 * @node: binary_tree_t node
 * Return: binary_tree_t node
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);
	return (sibling(node->parent));
}
