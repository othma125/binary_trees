#include "binary_trees.h"

/**
 * binary_tree_is_heap - Determines if a given
 * binary tree is a Max Binary Heap.
 * @tree: Pointer to the root node of the tree
 *  under evaluation.
 *
 * Description:
 * A Max Binary Heap is a specialized tree-based
 *  data structure that satisfies
 * the heap property. For a particular node I,
 * the values of its children are
 * always less than or equal to the value of I.
 *
 * Return:
 * - 1 if the tree is a valid Max Binary Heap.
 * - 0 if the tree is NULL or does not satisfy the Max Binary Heap property.
 */

int binary_tree_is_heap(const binary_tree_t *tree)
{
	return (tree ? btih_helper(tree) : 0);
}

/**
 * btih_helper - Recursively checks if a binary tree
 * is a valid Max Binary Heap.
 * @tree: Pointer to the current node of the tree under evaluation.
 *
 * Description:
 * A Max Binary Heap is a tree-based structure where for any given node I,
 * the values of its children are always less than or equal to the value of I.
 * This helper function uses a recursive approach to determine if the tree
 * maintains the properties of a Max Binary Heap.
 *
 * Return:
 * - 1 if the subtree rooted at the current node is a
 * valid Max Binary Heap or if the tree is NULL.
 * - 0 if the subtree rooted at the current node does
 * not satisfy the Max Binary Heap property.
 */
int btih_helper(const binary_tree_t *tree)
{
	int is_left_valid, is_right_valid;
	int is_current_node_valid;

	if (tree == NULL)
		return (1);

	if (!binary_tree_is_complete(tree))
		return (0);

	is_current_node_valid = 1;

	if (tree->left && tree->left->n > tree->n)
		is_current_node_valid = 0;

	if (tree->right && tree->right->n > tree->n)
		is_current_node_valid = 0;

	is_left_valid = btih_helper(tree->left);
	is_right_valid = btih_helper(tree->right);

	return (is_current_node_valid && is_left_valid && is_right_valid);
}

/**
 * binary_tree_is_complete - Determines if a given binary tree is complete.
 * @tree: Pointer to the root node of the tree under evaluation.
 *
 * Description:
 * A complete binary tree is a binary tree in which every
 * level, except possibly the last,
 * is completely filled, and all nodes are as far left as
 * possible. This function evaluates
 * the tree to ascertain if it adheres to the properties
 * of a complete binary tree.
 *
 * Return:
 * - 1 if the tree is complete.
 * - 0 if the tree is not complete or if the tree is NULL.
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	return (tree ? btic_helper(tree, 0, binary_tree_size(tree)) : 0);
}

/**
 * btic_helper - Recursively evaluates if a given
 * binary tree is complete.
 * @tree: Pointer to the current node of the tree under evaluation.
 * @index: Index of the current node, used to
 * determine its position in a complete tree.
 * @size: Total number of nodes in the tree.
 *
 * Description:
 * A complete binary tree is one where every level, except possibly the last,
 * is completely filled, and all nodes are as left as possible.
 * This helper function
 * uses a recursive approach, leveraging the index of
 * each node to determine if the tree
 * maintains the properties of a complete binary tree.
 *
 * Return:
 * - 1 if the subtree rooted at the current node is complete.
 * - 0 if the subtree rooted at the current node is not complete or
 * if the tree is NULL.
 */

int btic_helper(const binary_tree_t *tree, size_t index, size_t size)
{
	size_t left_child_index, right_child_index;
	int is_left_complete, is_right_complete;

	if (tree == NULL)
		return (1);

	if (index >= size)
		return (0);

	left_child_index = 2 * index + 1;
	right_child_index = 2 * index + 2;

	is_left_complete = btic_helper(tree->left, left_child_index, size);
	is_right_complete = btic_helper(tree->right, right_child_index, size);

	return (is_left_complete && is_right_complete);
}

/**
 * binary_tree_size - Computes the total number of nodes in a binary tree.
 * @tree: Pointer to the root node of the tree whose
 * size is to be determined.
 *
 * Description:
 * This function recursively traverses the binary tree,
 * counting the number of nodes
 * in both the left and right subtrees, and then adds 1 for the current node.
 * The cumulative count represents the size of the tree.
 *
 * Return:
 * - Total number of nodes in the tree.
 * - 0 if the tree is NULL.
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left_size, right_size;

	if (!tree)
		return (0);

	left_size = binary_tree_size(tree->left);
	right_size = binary_tree_size(tree->right);

	return (left_size + right_size + 1);
}
