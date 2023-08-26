#include "binary_trees.h"

/**
 * array_to_bst_recursion - check code
 * @array: integer array
 * @start: integer
 * @end: integer
 * @parent: bst_t node
 * Return: bst_t node
 */
bst_t *array_to_bst_recursion(int *array, int start, int end, bst_t *parent)
{
	bst_t *new_node;
	int mid;

	if (start > end)
		return (NULL);
	mid = (start + end) / 2;
	new_node = binary_tree_node(parent, array[mid]);
	if (!new_node)
		return (NULL);
	new_node->left = array_to_bst_recursion(array, start, mid - 1, new_node);
	new_node->right = array_to_bst_recursion(array, mid + 1, end, new_node);
	return (new_node);
}
/**
 * array_to_bst - check code
 * @array: integer array
 * @size: integer
 * Return: bst_t node
 */
bst_t *array_to_bst(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);
	return (array_to_bst_recursion(array, 0, size - 1, NULL));
}
