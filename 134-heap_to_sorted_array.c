#include "binary_trees.h"

size_t tree_size(const binary_tree_t *tree);

/**
 * heap_to_sorted_array - Converts a Binary Max Heap into a descendingly
 *                        sorted array of integers.
 * @heap: Pointer to the root node of the heap to be converted.
 * @size: Address where the size of the resulting array will be stored.
 *
 * Description: This function extracts the maximum value from the heap
 *repeatedly, which results in a sorted array
 *in descending order.
 *The size of the array is determined by the total
 *number of nodes
 *in the heap, which is computed using the tree_size function.
 *
 * Return: Pointer to the dynamically allocated sorted array.
 * NULL if the heap is empty or there's a memory allocation failure.
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
