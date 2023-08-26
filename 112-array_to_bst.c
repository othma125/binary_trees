#include "binary_trees.h"

/**
 * array_to_bst - check code
 * @array: integer array
 * @size: integer
 * Return: bst_t node
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i = 0;
	bst_t *tree = NULL;

	if (!array || size == 0)
		return (NULL);
	for (i = 0; i < size; i++)
		bst_insert(&tree, array[i]);
	return (tree);
}
