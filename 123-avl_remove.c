#include "binary_trees.h"

/**
 * bal - Measures the balance factor of an AVL tree.
 *
 * @tree: Pointer to the root node of the AVL tree to measure.
 *
 * Return: The balance factor of the AVL tree.
 *         0 if tree is NULL.
 */
void bal(avl_t **tree)
{
	int bval;

	if (!tree || !(*tree))
		return;
	if (!(*tree)->left && !(*tree)->right)
		return;
	bal(&(*tree)->left), bal(&(*tree)->right);
	bval = binary_tree_balance((const binary_tree_t *)*tree);
	if (bval > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (bval < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * successor - Finds the minimum value in the right subtree of a node.
 *
 * @node: Pointer to the node to check.
 *
 * Return: Pointer to the node containing the minimum value.
 *         NULL if node is NULL or if node has no right child.
 */
int successor(bst_t *node)
{
	int left = 0;

	if (node)
	{
		left = successor(node->left);
		return ((left == 0) ? node->n : left);
	}

	return (0);
}
/**
 * remove_type - Removes a node from an AVL tree depending on its children.
 *
 * @root: Pointer to the node to remove.
 *
 * Return: 0 if the node has no children, 1 if it has one child,
 * 2 if it has two children.
 */
int remove_type(bst_t *root)
{
	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if (!root->left || !root->right)
	{
		bst_t *child = root->left ? root->left : root->right;

		if (root->parent->right == root)
			root->parent->right = child;
		else
			root->parent->left = child;
		child->parent = root->parent;
		free(root);
		return (0);
	}
	else
	{
		root->n = successor(root->right);
		return (root->n);
	}
}
/**
 * bst_remove - Removes a node from a Binary Search Tree.
 *
 * @root: Pointer to the root node of the BST to remove from.
 * @value: The value of the node to remove.
 *
 * Return: Pointer to the root node of the BST after removal.
 *         NULL if root is NULL or if the value is not found in the tree.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (!root)
		return (NULL);

	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n && remove_type(root) != 0)
		bst_remove(root->right, remove_type(root));
	else
		return (NULL);

	return (root);
}

/**
 * avl_remove - Removes a node from an AVL tree.
 *
 * @root: Pointer to the root node of the AVL tree to remove from.
 * @value: The value of the node to remove.
 *
 * Return: Pointer to the root node of the AVL tree after removal.
 *         NULL if root is NULL or if the value is not found in the tree.
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_a = bst_remove((bst_t *)root, value);

	if (!root_a)
		return (NULL);
	bal(&root_a);
	return (root_a);
}
