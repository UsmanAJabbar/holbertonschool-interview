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

    if (direction != SLIDE_RIGHT && direction != SLIDE_LEFT)
        return(0);

    /**
     * PLAN: Look for a number and record where you found it
     * at, then continue through the for loop and ensure you
     * don't hit the first for loop again
     * 
     * In the second if statement, if we found a number and it
     * isn't the same number we recorded earlier, discard the
     * old number and record the new index and number.
     * 
     * If the same number was found, add them together at the
     * left index where the matching number was found
     * 
     * Then, at the old index reset that index to 0 since we've
     * used it to add it at the initial index location.
     * 
     * By the end of the for loop, we've done all of our
     * additions, simple to cleanup.
     * 
     * Complete the whole loop and then call on the helper
     * function to shift the array left or right
     */
    for(i = 0; i < int_size; i++)
    {
        if(line[i] != 0 && index_found == 9999) {
            index_found = i;
            continue;
        }
        if(line[i] != 0 && index_found != 9999)
        {
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
            arr[i] = (non_zeros[i]) ? non_zeros[i] : 0;

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