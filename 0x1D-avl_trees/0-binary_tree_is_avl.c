#include "binary_trees.h"


/**
 * binary_tree_is_balanced - checks and returns whether
 * a given binary tree is a valid avl tree
 * @tree: tree is a pointer to the root node of the tree to check
 * Return: 1 if valid AVL | 0 if not
 */
int binary_tree_is_balanced(const binary_tree_t *tree)
{
	int height_left, height_right, balance;

	if (!tree)
		return (0);

	if (tree->left && !binary_tree_is_balanced(tree->left))
		return (0);

	if (tree->right && !binary_tree_is_balanced(tree->right))
		return (0);

	height_left = get_bst_height(tree->left);
	height_right = get_bst_height(tree->right);

	balance = height_left - height_right;

	return (balance >= -1 && balance <= 1);
}

/**
 * binary_tree_is_avl - checks and returns whether
 * a given binary tree is a valid avl tree
 * @tree: tree is a pointer to the root node of the tree to check
 * Return: 1 if valid AVL | 0 if not
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	return (
		binary_tree_is_balanced(tree)
		&&
		binary_tree_is_bst(tree, INT_MIN, INT_MAX)
	);
}

/**
 * get_bst_height - returns the height of the BST
 * @tree: BST node as input
 * Return: Height of the BST
 */
int get_bst_height(const binary_tree_t *tree)
{
	int height_left, height_right;

	if (!tree)
		return (0);

	height_left = get_bst_height(tree->left);
	height_right = get_bst_height(tree->right);

	return (MAX(height_left, height_right) + 1);
}

/**
 * binary_tree_is_bst - returns whether a BST is valid
 * @tree: current node
 * @min: min_value
 * @max: max_value
 * Return: True if valid BST | False if not
 */
int binary_tree_is_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (0);

	if (tree->n < min || tree->n > max)
		return (0);

	return (
		(!tree->left || binary_tree_is_bst(tree->left, min, tree->n))
		&&
		(!tree->right || binary_tree_is_bst(tree->right, tree->n, max))
		);
}
