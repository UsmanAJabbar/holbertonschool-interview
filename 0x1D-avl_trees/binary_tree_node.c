#include "binary_trees.h"


/**
 * binary_tree_node - creates a binary_tree_node
 * @parent_node: address with the parent binary tree node
 * @value: value to insert in the new node
 * Return: NULL || new node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node = malloc(sizeof(binary_tree_t));

	if (node) {
		node->parent = parent;
		node->n = value;
		node->left = node->right = NULL;
	}

	return (node);
}
