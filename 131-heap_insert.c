#include "binary_trees.h"

/**
 * heap_insert - Inserts a value into a Max Binary Heap.
 *
 * @root: Pointer to the root node of the Max Binary Heap to insert into.
 * @value: The value to store in the node to be inserted.
 *
 * Return: Pointer to the created node.
 *         NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *current, *new_node, *flip_node;
	int t_size, num_leaves, sub_size, bit_mask, tree_lvl, tmp;

	if (!root)
		return (NULL);
	if (!(*root))
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	current = *root, t_size = binary_tree_size(current), num_leaves = t_size;
	tree_lvl = 0, sub_size = 1;
	while (num_leaves >= sub_size)
		num_leaves -= sub_size, sub_size *= 2, tree_lvl++;
	bit_mask = 1 << (tree_lvl - 1);
	while (bit_mask != 1)
	{
		if (num_leaves & bit_mask)
			current = current->right;
		else
			current = current->left;
		bit_mask >>= 1;
	}
	new_node = binary_tree_node(current, value);
	if (num_leaves & 1)
		current->right = new_node;
	else
		current->left = new_node;
	flip_node = new_node;
	while (flip_node->parent && (flip_node->n > flip_node->parent->n))
	{
		tmp = flip_node->n;
		flip_node->n = flip_node->parent->n;
		flip_node->parent->n = tmp;
		flip_node = flip_node->parent;
	}
	return (flip_node);
}

/**
 * binary_tree_size - Measures the size of a binary tree.
 *
 * @tree: Pointer to the root node of the binary tree to measure.
 *
 * Return: The size of the binary tree.
 *         0 if tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
