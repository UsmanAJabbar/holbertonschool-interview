#ifndef _SLIDE_LINE_H
#define _SLIDE_LINE_H

#include <stddef.h>
#include <stdio.h>
#define SLIDE_LEFT      'L'
#define SLIDE_RIGHT     'R'

/* Function Definitions */
int slide_line(int *line, size_t size, int direction);
void shift(int *arr, int size, int direction);

#endif