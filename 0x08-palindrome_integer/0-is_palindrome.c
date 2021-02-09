#include "palindrome.h"

/**
 * is_palindrome - checks if a passed number
 * is a palindrome
 * @n: input number
 * Return: 0 if not a palindrome | 1 if it is.
 */
int is_palindrome(unsigned long n)
{
	unsigned long rev_n = 0, temp_n = n, last_digit;

	/* PLAN: */
	/* Since we don't have the len, we can't find what's the */
	/* len of (n) without O(2n). To aid this, we could simply */
	/* reduce the steps by simply reversing the number from */
	/* beginning to end and then check the final with n */

	/* temp_n = 1221 */

	/* rev_n will store the result of reversing n */
	/* temp_n would act as a buffer so we don't has to mess with n */

	while (temp_n)
	{
		last_digit = temp_n % 10;
		rev_n = (rev_n * 10) + last_digit;
		temp_n = temp_n / 10;
	}

	return(rev_n == n);
}
