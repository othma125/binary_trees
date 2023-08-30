#include "binary_trees.h"

size_t tree_size(const binary_tree_t *tree);

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

/**
 * tree_size - Calculates the total number of nodes in a binary tree.
 *             This function essentially computes the size of the tree.
 * @tree: Pointer to the root node of the tree to measure.
 *
 * Description: The function recursively traverses both left and right
 *              subtrees, counting nodes along the way. The total count
 *              represents the size of the tree.
 *
 * Return: Total number of nodes in the tree, or 0 if tree is NULL.
 */
size_t tree_size(const binary_tree_t *tree)
{
	size_t l_height = 0, r_height = 0;

	if (!tree)
		return (0);

	if (tree->left)
		l_height = tree_size(tree->left) + 1;

	if (tree->right)
		r_height = tree_size(tree->right) + 1;

	return (l_height + r_height);
}
