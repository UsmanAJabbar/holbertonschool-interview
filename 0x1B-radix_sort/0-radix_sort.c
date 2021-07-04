#include "sort.h"

/**
 * max_num - Returns the max/max in an array
 * @array: int array as input
 * @len: len
 * Return: Max number || 0
 */
int max_num(int *array, int len)
{
	int max;
	int index;

	if (!array)
		return (INT_MIN);

	for (index = 0; index < len; index++)
		max = (array[index] > max) ? array[index] : max;

	return (max);
}

/**
 * num_at_pos - num at pos
 * @num: num
 * @exponent: exp
 * Return: int
 */
int num_at_pos(int num, int exponent)
{
	return ((num / exponent) % 10);
}

/**
 * digit_counting_sort - the main func
 * @array: array
 * @exponent: exp
 * @len: len
 * Return: None
 */
void digit_counting_sort(int *array, int exponent, int len)
{
	int i;
	int digit;
	int digit_freq[10] = { 0 };
	int *temp = malloc(sizeof(int) * len);
	int index_of_temp;

	/* Get the frequency of digits */
	for (i = 0; i < len; i++)
		digit_freq[num_at_pos(array[i], exponent)]++;

	/* Create a running sum of the array */
	for (i = 1; i < 10; i++)
		digit_freq[i] += digit_freq[i - 1];

	/* Radix Sort */
	for (i = len - 1; i >= 0; i--)
	{
		digit = num_at_pos(array[i], exponent);
		index_of_temp = --digit_freq[digit];
		temp[index_of_temp] = array[i];
	}

	for (i = 0; i < len; i++)
		array[i] = temp[i];

	print_array(array, (size_t)len);
}
/**
 * radix_sort - applies the radix sort
 * algorithm to an array of integers
 * @array: input array with integers exclusively
 * @size: size of the input array
 * Return: None since the array is supposed to be
 * sorted in place
 */
void radix_sort(int *array, size_t size)
{
	int max = max_num(array, (int)size);
	int exp = 1;

	for (; max / exp > 0; exp *= 10)
		digit_counting_sort(array, exp, (int)size);
}
