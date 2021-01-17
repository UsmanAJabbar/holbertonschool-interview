#include "lists.h"

int is_palindrome(listint_t **head)
{
	listint_t *s = *head, *d = *head;			/* s = single leap | d = double leap */
	int i = 0, *half_arr = malloc(sizeof(int));	/* Use this to dyanmically add items to array */

	/* NULL CHECKS */
	if (!head || !(*head) || !half_arr)
		return(0);

	/* This loop searches for the mid */
	/* By the end of the loop, s should */
	/* be pointing to the middle list */
	while (d->next && d->next->next)
	{
		half_arr[i] = s->n;						/* Add each element s goes through */
		i++;									/* Increment so that realloc could use the i */
		half_arr = realloc(half_arr, i + 1);	/* Add an extra block of memory for the next loop */

		s = s->next;
		d = d->next->next;
	}
	half_arr[i] = s->n;							/* Add the last n in s */

	/* Since i could tell us whether the len of the list is even/odd */
	/* we could take advantage of that and skip the current s if len(ll) */
	/* is an odd */

	/* NOTE: Since i started at 0, the odd/even check looks inversed */
	if (i % 2 == 0)
		s = s->next;

	/* Now that we have the len of s stored in i */
	/* we could decrement i while simulataneously */
	/* move s forward all the way to the end */
	while (s)
	{
		if (s->n != half_arr[i])
			return(0);

		s = s->next;
		i--;
	}

	free(half_arr);
	return (1);
}
