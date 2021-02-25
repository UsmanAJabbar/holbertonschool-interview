#include "slide_line.h"
#include <stdio.h>

/*
 * slide_line - aims to replicate
 * the 2048 game in C.
 * @line: contains arrays
 * @size: len(line)
 * @direction: left/right
 * Return: 0 on fail | 1 on success
 */
int slide_line(int *line, size_t size, int direction)
{
    int i, index_found = 9999, int_size = (int)size;

    if (!line || size < 2)
        return(0);

    for(i = 0; i < int_size; i++)
    {
        if(line[i] != 0 && index_found == 9999) {
            index_found = i;
            continue;
        }
        if(line[i] != 0 && index_found != 9999)
        {
            /* 2 0 0 4 0 2 2 */
            if(line[i] != line[index_found]) {
                index_found = i;
                continue;
            }
            if(line[i] == line[index_found]) {
                line[i] = line[i] + line[index_found];
                line[index_found] = 0;
                continue;
            }
        }
    }
    shift(line, int_size, direction);
    return(1);
}

/**
 * shift - shifts the array left/right
 * @arr: array
 * @size: len(array)
 * @direction: left/right
 * Return: None
 */
void shift(int *arr, int size, int direction)
{
    int i, j;                               /* i for the for loop */
    int non_zeros[4096];
    int len_zeros, len_nums;


    for(i = 0, j = 0; i < size; i++)
        if(arr[i] != 0)
            non_zeros[j] = arr[i], j++;     /* Read all non-0s into non-zeros */

    if(direction == SLIDE_LEFT)
        for(i = 0; i < size; i++)
        {
            if(non_zeros[i])
                arr[i] = non_zeros[i];
            else
                arr[i] = 0;
        }
    if(direction == SLIDE_RIGHT)
    {
        len_nums = j;
        len_zeros = size - len_nums;

        /* Copy number of zeros */
        for(i = 0; i < len_zeros; i++)
            arr[i] = 0;
        /* Copy the number of non zeros */
        for(i = len_zeros; i < size; i++, j++)
            arr[i] = non_zeros[i - len_zeros];
    }
}