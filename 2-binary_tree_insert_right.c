#include "binary_trees.h"

/**
 * binary_tree_insert_right - check code
 * @p: binary_tree_t
 * @n: int
 * Return: new tree node
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *p, int n)
{
	binary_tree_t *new = malloc(sizeof(binary_tree_t));
	
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->parent = p;
	new->left = NULL;
	new->right = NULL;
	p->right = new;
	return (new);
}
