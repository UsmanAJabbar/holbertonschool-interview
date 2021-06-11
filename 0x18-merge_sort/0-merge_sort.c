#include "sort.h"

/**
  * merge_sort - some doc
  * @array: array
  * @size: size
  * Return: None
  */
void merge_sort(int *array, size_t size)
{
	if (!array || size == 1)
		return;

	split(array, 0, (int)size - 1);
}

/**
  * split - splits the array into half
  * @array: array
  * @start: start
  * @end: end
  * Return: None
  */
void split(int *array, int start, int end)
{
	int mid;

	if (start < end) {
		mid  = (start + end) / 2;
		split(array, start, mid);
		split(array, mid + 1, end);
		merge(array, start, mid, end);
	}
}

/**
  * merge - splits the array into half
  * @array: array
  * @start: start
  * @mid: mid
  * @end: end
  * Return: None
  */
void merge(int *array, int start, int mid, int end)
{
	array[0] = 0;
	array[start] = 0;
	array[mid] = 0;
	array[end] = 0;
	return;
}