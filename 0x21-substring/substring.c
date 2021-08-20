#include "substring.h"

/**
 * find_substring - returns the idxes where
 * the words defined in `words` were first found
 * @s: massive string to scan
 * @words: array of words to look for in `@s`
 * @nb_words: len of @words
 * @n: len of the returned array... to be edited in-place
 * Returns: newly malloced array with idx || NULL
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int w_idx, res_idx, found_idx;
	int *resArr = malloc(sizeof(int) * 128);

	w_idx = res_idx = 0;

	if (!s || !words || !n)
		return (NULL);

	for (; w_idx < nb_words; w_idx++) {
		found_idx = str_search(s, words[w_idx]);
		if (found_idx != -1) {
			*n = 2;
			resArr[res_idx++] = found_idx;
		}
	}
	return (resArr);
}

/* Returns the idx where the first occurrence of the word was found in s */
int str_search(char const *str, char const *word)
{
	int s_idx, w_idx;

	for (s_idx = 0; str[s_idx]; s_idx++) {
		for (w_idx = 0; word[w_idx]; w_idx++)
			if (str[s_idx + w_idx] != word[w_idx])
				break;
		if (!(word[w_idx])) /* If the last index is null that means the whole string checked out */
			return (s_idx);
	}
	return (-1);

}

