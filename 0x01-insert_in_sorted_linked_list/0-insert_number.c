#include "lists.h"
/**
 * insert_node - inserts a new code
 * in a sorted singly linked list
 * @head: address to the head node
 * @number: number about be be inserted
 */
listint_t *insert_node(listint_t **head, int insert)
{
	listint_t *new = NULL, *cur = (*head), *next = NULL;

	/* NULL CHECK */
	if (!head)
		return (NULL);

	new = malloc(sizeof(listint_t));
	new->n = insert;

	if (!cur->next || insert < 0)
	{
		if (cur->n >= insert)
			new->next = cur, (*head) = new;
		else
			cur->next = new;
		return (new);
	}

	/* Finally, a decent linked list */
	for (next = cur->next; next; cur = cur->next, next = next->next)
		if (cur->n <= insert && next->n >= insert)
			break;

	cur->next = new, new->next = next;
	return (new);
}
