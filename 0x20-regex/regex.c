#include "regex.h"

/**
 * regex_match - returns true or false whether a string matches
 * a pattern
 * @str: string
 * @pattern: regex pattern
 * Return: 0 | 1
 */
int regex_match(char const *str, char const *pattern)
{
	if (*str == '\0' || *pattern == '\0')
	{
		if (*str == '\0' && *pattern == '*' && *(pattern + 1) == '\0')
			return (1);
		return (*str == '\0' && *pattern == '\0');
	}

	if (*pattern == '*')
		return (regex_match(str, pattern + 1) || regex_match(str + 1, pattern));

	if (*pattern == '.')
		return (regex_match(str + 1, pattern + 1));

	if (*str != *pattern)
		return (0);

	return (regex_match(str + 1, pattern + 1));
}
