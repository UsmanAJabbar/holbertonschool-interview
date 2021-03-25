#include "binary_trees.h"

avl_t *create_node(int value, avl_t *parent)
{
	avl_t *node = malloc(sizeof(avl_t));

	if (!node)
		return (NULL);
	
	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *sorted_avl;

	if (!array || size == 0)
		return (NULL);

	sorted_avl = sorted_array_to_avl_helper(array, 0, size - 1, NULL);

	return (sorted_avl);
}

avl_t *sorted_array_to_avl_helper(int *array, size_t start, size_t end, avl_t *parent)
{
	size_t mid;
	avl_t *node;

	if ((int)start > (int)end)
		return (NULL);

	mid = (start + end) / 2;
	node = create_node(array[mid], parent);
	node->left = sorted_array_to_avl_helper(array, start, mid - 1, node);
	node->right = sorted_array_to_avl_helper(array, mid + 1, end, node);

	return node;
}