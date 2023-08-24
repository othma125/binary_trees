#include "binary_trees.h"

/**
 * binary_tree_insert_right - check code
 * @p: binary_tree_t
 * @n: int
 * Return: new tree node
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *p, int n)
{
	binary_tree_t *new = binary_tree_node(p, n);
	
	if (new == NULL)
		return (NULL);
	if (p->right != NULL)
	{
		new->right = p->right;
		p->right->parent = new;
	}
	p->right = new;
	return (new);
}
