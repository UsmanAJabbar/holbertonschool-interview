#include "sort.h"
#define TEMPSIZE 128

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

	if (start < end)
	{
		mid = (start + end) / 2;
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
	int L[TEMPSIZE] = { 0 }, R[TEMPSIZE] = { 0 };
	int l_len = (mid - start) + 1;
	int r_len = end - mid;
	int i, j, k;

	/* printf("s %d | m %d | end %d\nl_len %d | r_len %d\n", start, mid, end, l_len, r_len); */
	for (i = 0; i < l_len; i++)
		L[i] = array[start + i];
	for (j = 0; j < r_len; j++)
		R[j] = array[mid + 1 + j];

	i = 0, j = 0, k = start;
	while (i < l_len && j < r_len)
		array[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];

	while (i < l_len)
		array[k++] = L[i++];
	while (j < r_len)
		array[k++] = R[j++];

	printf("Merging...\n[left]: ");
	print_array(L, l_len);
	printf("[right]: ");
	print_array(R, r_len);
	printf("[Done]: ");
	print_array((array + start), end - start + 1);
}
