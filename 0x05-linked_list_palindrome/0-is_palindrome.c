#include "lists.h"

int is_palindrome(listint_t **head)
{
	listint_t *s = *head, *d = *head;
	int i = 0, *half_arr = malloc(sizeof(int));
	
	/* This loop searches for the mid */
	/* By the end of the loop, s should */
	/* be pointing to the middle list */
	while (d->next && d->next->next)
	{
		/* s = s->next;		 Single leaps */
		/* d = d->next->next;  Double leaps */

		printf("'Boutta add %d to half_array[%d]\n", s->n, i);

		half_arr[i] = s->n;						/* Add each element s goes through */
		i++;									/* Increment so that realloc could use the i */
		half_arr = realloc(half_arr, i + 1);	/* Add an extra block of memory for the next loop */

		s = s->next;
		d = d->next->next;
	}

	/* Now that we have the len of s stored in i */
	/* we could decrement i while simulataneously */
	/* move s forward all the way to the end */
	while (s)
	{
		printf("Boutta compare %d with %d\n", s->n, half_arr[i - 1]);
		if (s->n != half_arr[i - 1])
			return(0);

		s = s->next;
		i--;
	}

	free(half_arr);
	return (1);
}
