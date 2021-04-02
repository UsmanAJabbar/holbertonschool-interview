#include "search.h"


/**
 * linear_skip - searches for a specific
 * value in an express-powered linked list
 * @head: address to the head of the list
 * @value: value to look for in the list
 * Return: Returns address to the node | NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	if (!list || list->n > value)
		return (NULL);
	if (list->n == value)
		return (list);

	if (!list->express || list->n < value && value < list->express->n)
		return linear_skip(list->next, value);
	return linear_skip(list->express, value);
}