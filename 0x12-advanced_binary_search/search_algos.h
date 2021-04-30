#ifndef _SEARCH_ALGOS_H
#define _SEARCH_ALGOS_H

#include <stdlib.h>
#include <stdio.h>

int advanced_binary(int *array, size_t size, int value);
int helper(int *array, int size, int target, int start, int end);
void array_status(int *array, int start, int end);

#endif