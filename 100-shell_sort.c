#include "sort.h"

/**
 * swap_ints - Swaps two integers
 * @x: Pointer to the first integer to swap
 * @y: Pointer to the second integer to swap
 */
void swap_ints(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * shell_sort - Sorts an array of integers in ascending order using shell sort
 * @array: The array to be sorted
 * @size: The size of the array
 *
 * Description: Uses Knuth sequence algorithm interval
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			for (j = i; j >= gap && array[j - gap] > array[j]; j -= gap)
			{
				swap_ints(&array[j - gap], &array[j]);
			}
		}

		gap = (gap - 1) / 3;

		print_array(array, size);
	}
}
