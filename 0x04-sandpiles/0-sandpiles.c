#include <stdio.h>
#include <stdlib.h>

/**
 * is_stable - Checks if the grid is stable
 * @grid: The grid to check
 *
 * Return: 1 if the grid is stable, 0 otherwise
 */
int is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (1);
		}
	}
	return (0);
}

/**
 * somme - Sums two grids
 * @a: the first grid
 * @b: the second grid
 *
 * Return: a grid sum of a and b
 */
void somme(int a[3][3], int b[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			a[i][j] += b[i][j];
		}
	}
}

/**
 * transfer - transfers the grid
 * @grid: the given grid
 *
 */
void transfer(int grid[3][3])
{
	int i, j;
	int result[3][3];

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			result[i][j] = 0;
		}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] >= 4)
			{
				grid[i][j] = grid[i][j] - 4;
				if ((i - 1 >= 0) && (i - 1 < 3))
					result[i - 1][j] += 1;
				if ((j - 1 >= 0) && (j - 1 < 3))
					result[i][j - 1] += 1;
				if ((i + 1 >= 0) && (i + 1 < 3))
					result[i + 1][j] += 1;
				if ((j + 1 >= 0) && (j + 1 < 3))
					result[i][j + 1] += 1;
			}
		}
	}
	somme(grid, result);
}

/**
 * sandpiles_sum - sums sandpiles
 * @grid1: the first grid
 * @grid2: the second grid
 *
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	somme(grid1, grid2);
	while (is_stable(grid1))
	{
		printf("\n");
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (j)
					printf(" ");
				printf("%d", grid1[i][j]);
			}
			printf("\n");
		}
		transfer(grid1);
	}
}
