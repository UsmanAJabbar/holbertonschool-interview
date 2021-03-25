#ifndef _BINARY_TREES_H
#define _BINARY_TREES_H

#include <stdlib.h>
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};
typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s avl_t;

/* Main Task Definitions */
avl_t *sorted_array_to_avl(int *array, size_t size);

/* Helper function definitions */
avl_t *create_node(int value, avl_t *parent);
avl_t *sorted_array_to_avl_helper(int *array, size_t start, size_t end, avl_t *parent);
void binary_tree_print(const binary_tree_t *tree);

#endif