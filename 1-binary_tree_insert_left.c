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

	if (!new || !p)
		return (NULL);
	if (p->left)
	{
		new->left = p->left;
		new->left->parent = new;
	}
	p->left = new;
	return (new);
}
