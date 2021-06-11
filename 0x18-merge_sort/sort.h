#ifndef _SORT_H
#define _SORT_H

#include <stdio.h>
#include <stdlib.h>

void merge_sort(int *array, size_t size);
void split(int *array, int start, int end);
void merge(int *array, int start, int mid, int end);

void print_array(const int *array, size_t size);

#endif