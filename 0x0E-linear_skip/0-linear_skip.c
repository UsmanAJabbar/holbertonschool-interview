#include "search.h"


/**
 * linear_skip - searches for a specific
 * value in an express-powered linked list
 * @head: address to the head of the list
 * @value: value to look for in the list
 * Return: Returns address to the node | NULL
 */
skiplist_t *linear_skip(skiplist_t *head, int value) {
	int flag = 0;

	if (!head)
		return (NULL);

	return linear_skip_helper(head, value, head->index, head->n, flag);
}

skiplist_t *linear_skip_helper(skiplist_t *list, int target, size_t index, int value, int flag)
{
	if (!list || list->n > target)
		return (NULL);
	if (list->n == target)
		return (list);

	printf("Value checked at index [%zu] = [%d]\n", index, value);

	if (list->express && target >= list->express->n)
		return linear_skip_helper(list->express, target, list->express->index, list->express->n, flag);

	if (!flag && list->express)
	{
		printf("Value found between indexes [%zu] and [%zu]\n", list->index, list->express->index);
		flag = 1;
	}
	return linear_skip_helper(list->next, target, list->next->index, list->next->n, flag);
}