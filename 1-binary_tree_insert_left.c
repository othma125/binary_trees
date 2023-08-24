#include "binary_trees.h"

/**
 * binary_tree_insert_left - check code
 * @p: binary_tree_t
 * @n: int
 * Return: new tree node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *p, int n)
{
	binary_tree_t *new = binary_tree_node(p, n);
	
	if (new == NULL)
		return (NULL);
	if (p->left != NULL)
	{
		new->left = p->left;
		p->left->parent = new;
	}
	p->left = new;
	return (new);
}
