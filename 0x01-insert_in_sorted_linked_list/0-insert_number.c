#include "lists.h"
#define pass (void)0

/**
 * insert_node - inserts a new code
 * in a sorted singly linked list
 * @head: address to the head node
 * @number: number about be be inserted
 */
listint_t *insert_node(listint_t **head, int insert)
{
	listint_t *new = NULL, *cur = *head, *next = NULL;

	// MASTER PLAN
		// * The current plan's to actually use two pointers
		//   to get through the linked list... One's going
		//   to record the current node we're on and the
		//   other's going to record the very next node
		// * With every iteration, check if the inserted
		//   number is bigger than the current, and if it
		//   is, then check if the inserted number is
		//   smaller than the next number, insert!

	/* NULL CHECK */
	if (!*head)
		return (NULL);

	new = malloc(sizeof(listint_t));
	new->n = insert;

	/* If only one node exists */
	if (!cur->next)
	{
		if (cur->n > insert)
			new->next = cur, *head = new;
		else
			cur->next = new;
		return(new);
	}
			
	/* Finally, a decent linked list */
	for (next = cur->next; next->next; cur = cur->next, next = next->next)
		if (cur->n < insert && next->n > insert)
		{
			cur->next = new, new->next = next;
			return (new);
		}

	return (NULL);
}
