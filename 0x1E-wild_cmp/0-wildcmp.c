#include "holberton.h"

/**
 * wildcmp - compares two strings with wildcards
 * @s1: first string
 * @s2: second string
 * Return: 0 if they aren't identical, 1 if they are
 */
int wildcmp(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (1);

	/*
	# MASTER PLAN
	# Go through the whole string
	# If *s1 and *s2 are on a wildcard, increment both of them
	# If only s2 has a wildcard
	#	if s2[i + 1] == NULL return true (aka 1)
	#	else:
	#		increment s1 until s2[i + 1] aren't the same
	#		then increment both as usual with an strcmp
	*/
	if (*s1 == '*' && *s2 == '*')
		return wildcmp(s1 + 1, s2 + 1);
	else if (*s2 == '*')
		return wildcmp(s1 + 1, s2);
	else if (*s1 == '*')
		return wildcmp(s1, s2 + 1);
	else if (*s1 == *s2)
		return wildcmp(s1 + 1, s2 + 1);
	else
		return (0);
}
