#include "holberton.h"

/**
 * wildcmp - compares two strings with wildcards
 * @s1: first string
 * @s2: second string
 * Return: 0 if they aren't identical, 1 if they are
 */
int wildcmp(char *s1, char *s2)
{
	/* Check if S1 or S2 is over */
	if (*s1 == '\0' || *s2 == '\0')
	{
		if (*s1 == '\0' && *s2 == '*' && *(s2 + 1) == '\0')
			return (1);
		return (*s1 == '\0' && *s2 == '\0');
	}

	if (*s2 == '*')
		return (wildcmp(s1, s2 + 1) || wildcmp(s1 + 1, s2));

	if (*s1 != *s2)
		return (0);

	return (wildcmp(s1 + 1, s2 + 1));
}
