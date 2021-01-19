#include "lists.h"

/**
 * is_palindrome - returns whether a list is
 * palindrome
 * @head: head of the ll
 * Return: 0 or 1
 */
int is_palindrome(listint_t **head)
{
	listint_t *s = *head, *d = *head;			/* s = single leap | d = double leap */
	int i = 0, half_arr[4096];
	
	/* This loop searches for the mid */
	/* By the end of the loop, s should */
	/* be pointing to the middle list */
	while (d->next && d->next->next)
	{
		half_arr[i] = s->n;										/* Add each element s goes through */
		i++;													/* Increment so that realloc could use the i */
		/* half_arr = realloc(half_arr, sizeof(int) * (i + 1));	 Add an extra block of memory for the next loop */

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
		{
			free(half_arr);
			return(0);
		}

		s = s->next;
		i--;
	}

	free(half_arr);
	return (1);
}

