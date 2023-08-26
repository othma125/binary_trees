#include "binary_trees.h"

/**
 * bst_insert - Inserts a new node into a Binary Search Tree.
 *
 * @tree: Pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: Pointer to the created node.
 *         NULL if tree is NULL or if the value already exists in the tree.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node = NULL;

	if (!tree)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	if (value == (*tree)->n)
		return (NULL);

	if (value < (*tree)->n)
	{
		if ((*tree)->left == NULL)
		{
			new_node = binary_tree_node(*tree, value);
			(*tree)->left = new_node;
			return (new_node);
		}
		else
		{
			return (bst_insert(&((*tree)->left), value));
		}
	}
	else
	{
		if ((*tree)->right == NULL)
		{
			new_node = binary_tree_node(*tree, value);
			(*tree)->right = new_node;
			return (new_node);
		}
		else
		{
			return (bst_insert(&((*tree)->right), value));
		}
	}
}
