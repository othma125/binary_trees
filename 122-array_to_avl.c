#include "binary_trees.h"

/**
 * binary_tree_is_avl - check code
 * @array: integer array
 * @size: integer
 * Return: integer
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t i = 0;
	avl_t *tree = NULL;

	if (!array || size == 0)
		return (NULL);
	for (i = 0; i < size; i++)
		avl_insert(&tree, array[i]);
	return (tree);
}
