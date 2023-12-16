#include "sort.h"

/**
 * swap - Swaps the values of two integers.
 * @x_val: Pointer to the first integer.
 * @y_val: Pointer to the second integer.
 *
 * Description: This function swaps the values of two integers.
 */



void swap(int *x_val, int *y_val)
{
	int buffer;

	buffer = *x_val;
	*x_val = *y_val;
	*y_val = buffer;
}

/**
 * selection_sort - Sorts an array of integers using Selection Sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 *
 * Description: Function sorts an array of integers in ascending order using
 * the Selection Sort algorithm. It iteratively finds the minimum element in
 * the unsorted part of the array and swaps it with the first unsorted element.
 * The process is repeated until the entire array is sorted.
 */

void selection_sort(int *array, size_t size)
{
	size_t i, min_idx, j;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
			{
				min_idx = j;
			}
		}

		if (min_idx != i)
		{
			swap(&array[min_idx], &array[i]);
			print_array(array, size);
		}
	}
}
