#ifndef _SORT_H
#define _SORT_H

#include <stdlib.h>
#include <limits.h>
#include <math.h>

void radix_sort(int *array, size_t size);

int max_num(int *array, int size);
void digit_counting_sort(int *array, int position, int size);

void print_array(const int *array, size_t size);

#endif
