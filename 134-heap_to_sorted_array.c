#include "binary_trees.h"

/**
 * tree_size - computes the combined heights of a binary tree
 * @tree: pointer to the main node of the tree to compute the height
 *
 * Return: Height or 0 if tree is NULL
 */
size_t tree_size(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (!tree)
		return (0);

	if (tree->left)
		left_height = tree_size(tree->left) + 1;

	if (tree->right)
		right_height = tree_size(tree->right) + 1;

	return (left_height + right_height);
}

/**
 * heap_to_sorted_array - transforms a Binary Max Heap
 * into an ordered array of integers
 * @heap: a pointer to the main node of the heap to transform
 * @size: a pointer to save the length of the array
 *
 * Return: the created array
 *         NULL if there's an error
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int index = 0, *arr = NULL;

	if (!heap || !size)
		return (NULL);

	*size = 1 + tree_size(heap);

	arr = malloc((*size) * sizeof(int));

	if (!arr)
		return (NULL);

	while (heap)
		arr[index] = heap_extract(&heap), index++;

	return (arr);
}
