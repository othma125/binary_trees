#include "binary_trees.h"

void sata_helper(avl_t **root, int *array, size_t lo, size_t hi);

/**
 * sorted_array_to_avl - constructs an AVL tree from a sorted list
 * @array: a pointer to the starting element of the array to transform
 * @size: total elements in the array
 *
 * Return: a pointer to the primary node of the generated AVL tree,
 *         or NULL if there's an error
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root_node = NULL;
	size_t mid_point;

	if (!array)
		return (NULL);
	mid_point = (size - 1) / 2;
	root_node = binary_tree_node(NULL, array[mid_point]);

	sata_helper(&root_node, array, -1, mid_point);
	sata_helper(&root_node, array, mid_point, size);

	return (root_node);
}

/**
 * sata_helper - auxiliary function that aids in constructing an
 * AVL tree from a list
 * @root: double pointer to the primary node of the subtree
 * @array: a pointer to the initial element of the array to be transformed
 * @lo: starting index
 * @hi: ending index
 */
void sata_helper(avl_t **root, int *array, size_t lo, size_t hi)
{
	avl_t *new_node = NULL;
	size_t center_idx;

	if (hi - lo > 1)
	{
		center_idx = (hi - lo) / 2 + lo;
		new_node = binary_tree_node(*root, array[center_idx]);
		if (array[center_idx] > (*root)->n)
			(*root)->right = new_node;
		else if (array[center_idx] < (*root)->n)
			(*root)->left = new_node;
		sata_helper(&new_node, array, lo, center_idx);
		sata_helper(&new_node, array, center_idx, hi);
	}
}
