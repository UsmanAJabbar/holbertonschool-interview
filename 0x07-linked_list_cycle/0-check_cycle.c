#include "lists.h"

/**
 * check_cycle - check cycle is a function that checks
 * whether a linked list is in a loop or not.
 * @list: beginning of the linked list
 * Return: 0 if no loop | 1 if loop detected
 */
int check_cycle(listint_t *list) {
	listint_t *s_leap, *d_leap;

	if (!list)
		return(0);

	for (s_leap = list, d_leap = list->next; d_leap && d_leap->next; s_leap = s_leap->next, d_leap = d_leap->next->next)
		if (s_leap == d_leap)
			return(1);

	return(0);
}
