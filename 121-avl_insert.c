#include "binary_trees.h"

/**
 * r_insert_node - Inserts a new node into an AVL tree.
 *
 * @tree: Pointer to the root node of the AVL tree.
 * @parent: Pointer to the parent node of the AVL tree.
 * @new: Pointer to the left or right child of the parent node.
 * @nval: The value to store in the node to be inserted.
 *
 * Return: Pointer to the new root node of the AVL tree after insertion.
 *         NULL if tree is NULL.
 */
avl_t *r_insert_node(avl_t **tree, avl_t *parent, avl_t **new, int nval)
{
	if (!(*tree))
	{
		*new = binary_tree_node(parent, nval);
		return (*new);
	}

	if (nval < (*tree)->n)
		(*tree)->left = r_insert_node(&((*tree)->left), *tree, new, nval);
	else if (nval > (*tree)->n)
		(*tree)->right = r_insert_node(&((*tree)->right), *tree, new, nval);
	else
		return (*tree);

	if (binary_tree_balance(*tree) > 1)
	{
		if (nval < (*tree)->left->n)
			*tree = binary_tree_rotate_right(*tree);
		else
		{
			(*tree)->left = binary_tree_rotate_left((*tree)->left);
			*tree = binary_tree_rotate_right(*tree);
		}
	}
	else if (binary_tree_balance(*tree) < -1)
	{
		if (nval > (*tree)->right->n)
			*tree = binary_tree_rotate_left(*tree);
		else
		{
			(*tree)->right = binary_tree_rotate_right((*tree)->right);
			*tree = binary_tree_rotate_left(*tree);
		}
	}

	return (*tree);
}

/**
 * avl_insert - Inserts a new node into an AVL tree.
 *
 * @tree: Pointer to the root node of the AVL tree to insert into.
 * @value: The value to store in the node to be inserted.
 *
 * Return: Pointer to the new node inserted into the AVL tree.
 *         NULL if tree is NULL or if the value already exists in the tree.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node;

	if (!(*tree))
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	r_insert_node(tree, *tree, &new_node, value);
	return (new_node);
}
