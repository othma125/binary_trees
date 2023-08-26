#include "binary_trees.h"
/**
 * tree_height - Measures the height of a binary tree.
 *
 * @tree: Pointer to the root node of the binary tree to measure.
 *
 * Return: The height of the binary tree.
 *         0 if tree is NULL.
 */
size_t tree_height(const heap_t *tree)
{
	size_t h_left = tree && tree->left ? 1 + tree_height(tree->left) : 0;
	size_t h_right = tree && tree->right ? 1 + tree_height(tree->right) : 0;

	return (h_left > h_right ? h_left : h_right);
}
/**
 * tree_size_h - Measures the sum of heights of a binary tree.
 *
 * @tree: Pointer to the root node of the binary tree to measure.
 *
 * Return: The sum of heights of the binary tree.
 *         0 if tree is NULL.
 */
size_t tree_size_h(const binary_tree_t *tree)
{
	size_t h_left = tree && tree->left ? 1 + tree_size_h(tree->left) : 0;
	size_t h_right = tree && tree->right ? 1 + tree_size_h(tree->right) : 0;

	return (h_left + h_right);
}

/**
 * _preorder - Traverses a binary tree using pre-order traversal.
 *
 * @tree: Pointer to the root node of the tree to traverse.
 * @node: Pointer to the last node in the traversal.
 * @height: The height of the tree.
 *
 * Return: None.
 */
void _preorder(heap_t *tree, heap_t **node, size_t height)
{
	if (!tree)
		return;

	if (!height)
		*node = tree;

	_preorder(tree->left, node, height - 1);
	_preorder(tree->right, node, height - 1);
}

/**
 * heapify - Heapifies a Max Binary Heap.
 *
 * @root: Pointer to the root node of the Max Binary Heap to heapify.
 *
 * Return: None.
 */
void heapify(heap_t *root)
{
	int value;
	heap_t *tmp1, *tmp2;

	if (!root)
		return;

	tmp1 = root;

	while (1)
	{
		if (!tmp1->left)
			break;
		if (!tmp1->right)
			tmp2 = tmp1->left;
		else
		{
			if (tmp1->left->n > tmp1->right->n)
				tmp2 = tmp1->left;
			else
				tmp2 = tmp1->right;
		}
		if (tmp1->n > tmp2->n)
			break;
		value = tmp1->n, tmp1->n = tmp2->n;
		tmp2->n = value, tmp1 = tmp2;
	}
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap.
 *
 * @root: Double pointer to the root node of the Max Binary Heap
 * to extract from.
 *
 * Return: The value stored in the root node.
 *         0 if root is NULL or if the heap is empty.
 */
int heap_extract(heap_t **root)
{
	int value;
	heap_t *heap_r, *node;

	if (!root || !*root)
		return (0);
	heap_r = *root, value = heap_r->n;
	if (!heap_r->left && !heap_r->right)
	{
		*root = NULL, free(heap_r);
		return (value);
	}

	_preorder(heap_r, &node, tree_height(heap_r));

	heap_r->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node), heapify(heap_r), *root = heap_r;
	return (value);
}
