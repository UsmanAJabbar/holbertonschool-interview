#include "search_algos.h"

/**
  * advanced_binary - Looks for a specific
  * number in an array, if the number exists
  * this function would return the very first
  * index where @value could be found
  * @array: int input array
  * @size: length of the array
  * @value: value to look for in the array
  * Return: smallest index with @value || NULL
  */
int advanced_binary(int *array, size_t size, int value)
{
	int len = (int)size;

	return helper(array, len, value, 0, len);
}

/**
  * helper - helper function that takes in
  * all the necessary variables from adv binary
  * and returns the appropriate returns
  * @array: int input array
  * @size: length of the array
  * @target: value to look for in the array
  * @start: start index
  * @end: end index
  * Return: index | -1
  */
int helper(int *array, int size, int target, int start, int end)
{
	int mid;

	if (start > end || !array)
		return(-1);

	array_status(array, size, start, end);

	mid = (start + end) / 2;

	if (array[mid] == target)
	{
		while (mid > 0 && array[mid - 1] == target)
			mid -= 1;
		return(mid);
	}

	else if (target > array[mid])
		return helper(array, size, target, mid + 1, end);
	else
		return helper(array, size, target, start, mid - 1);
}

/**
  * array_status - prints out the necessary
  * print statement to showcase the status
  * of the array as we search for the element
  * @array: array
  * @size: len of array
  * @start: start index
  * @end: end index
  * Return: Void
  */
void array_status(int *array, int size, int start, int end)
{
	printf("Searching in array: ");
	for (; start < end; start++)
		printf("%d, ", array[start]);
	printf("%d\n", array[start]);
	return;
}