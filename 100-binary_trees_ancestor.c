#include "binary_trees.h"

/**
 * binary_tree_ancestor - check code
 * @node1: binary_tree_t node
 * @node2: binary_tree_t node
 * Return: binary_tree_t node
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *node1
, const binary_tree_t *node2)
{
	binary_tree_t *father = node1->parent;
	binary_tree_t *mother = node2->parent;

	if (!node1 || !node1)
		return (NULL);
	if (node1 == node2)
		return ((binary_tree_t *)node1);
	if (node1 == mother || !mother)
		return (binary_trees_ancestor(node1, mother));
	if (node2 == father || !father)
		return (binary_trees_ancestor(father, node2));
	return (binary_trees_ancestor(father, mother));
}
