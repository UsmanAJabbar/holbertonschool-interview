#include "regex.h"


int regex_match(char const *str, char const *pattern)
{
	/* '.' matches one single character 
	 * '*' matches either 0 or no character at all
	 */
	/* Check if S1 or S2 is over */
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
