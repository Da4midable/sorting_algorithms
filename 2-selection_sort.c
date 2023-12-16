#include "sort.h"

void swap(int *x_val, int *y_val)
{
	int buffer;

	buffer = *x_val;
	*x_val = *y_val;
	*y_val = buffer;
}

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
