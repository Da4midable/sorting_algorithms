#include "sort.h"

/**
 * swap - Swap the values of two integers.
 * @x_val: Pointer to the first integer.
 * @y_val: Pointer to the second integer.
 */
void swap(int *x_val, int *y_val)
{
	int buffer;

	buffer = *x_val;
	*x_val = *y_val;
	*y_val = buffer;
}

/**
 * bubble_sort - Sort an array of integers using the Bubble Sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	bool swapped;

	for (i = 0; i < size - 1; i++)
	{
		swapped = false;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				swapped = true;
				print_array(array, size);
			}
		}

		if (swapped == false)
			break;
	}
}
