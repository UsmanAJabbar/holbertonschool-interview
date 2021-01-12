#include "sandpiles.h"
#include <stdio.h>

static void print_grid_sum(int grid1[3][3], int grid2[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid1[i][j]);
        }

        printf(" %c ", (i == 1 ? '+' : ' '));

        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid2[i][j]);
        }
        printf("\n");
    }
}
static void print_grid(int grid[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}



/**
 * sandpiles_sum - returns a stabilized sandpile
 * @grid1: first 3x3 grid
 * @grid2: second 3x3 grid (to be added to grid1)
 * Return: stabilized grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int rows, columns;

    /* Add up the two grids into grid1 */
    for (columns = 0; columns < 3; columns++)
        for (rows = 0; rows < 3; rows++)
            grid1[columns][rows] = grid1[columns][rows] + grid2[columns][rows];

	print_grid_sum(grid1, grid2);
    stabilized(grid1);
}

void stabilized(int grid[3][3])
{
	int rows, columns, unbalanced = 0;

	for (columns = 0; columns < 3; columns++)
		for (rows = 0; rows < 3; rows++)
			if (grid[columns][rows] > 3)
            {
				grid[columns][rows] -= 4;
                
                /* Overflow check up/down then left/right) */
				if (columns - 1 >= 0)
					grid[columns - 1][rows] += 1;
				if (columns + 1 <= 3)
					grid[columns + 1][rows] += 1;
				if (rows - 1 >= 0)
					grid[columns][rows - 1] += 1;
				if (rows + 1 <= 3)
					grid[columns][rows + 1] += 1;

				unbalanced = 1; /* True, yes it was unbalanced */
            }

	print_grid(grid);
    if (unbalanced == 1)
		stabilized(grid);
}
