#include "sort.h"

void bitonic_merge(int *array, size_t start, size_t size, int dir);
void bitonic_sort_recursive(int *array, size_t start, size_t size, int dir);

/**
 * bitonic_merge - Merges a bitonic sequence
 * @array: pointer to the array to be sorted
 * @start: Starting index of the sequence
 * @size: number of elements in the sequence
 * @dir: Sorting direction (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, size_t start, size_t size, int dir)
{
	size_t i, k = size / 2;
	int tmp;

	if (size > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", size, size, (dir == 1) ? "UP" : "DOWN");
		print_array(array + start, size);

		for (i = start; i < start + k; i++)
		{
			if ((array[i] > array[i + k]) == dir)
			{
				tmp = array[i];
				array[i] = array[i + k];
				array[i + k] = tmp;
			}
		}

		bitonic_merge(array, start, k, dir);
		bitonic_merge(array, start + k, k, dir);
	}
}

/**
 * bitonic_sort_recursive - Recursively sort a bitonic sequence
 * @array: pointer to the array to be sorted
 * @start: Starting index of the sequence
 * @size: number of elements in the sequence
 * @dir: Sorting direction (1 for ascending, 0 for descending)
 */
void bitonic_sort_recursive(int *array, size_t start, size_t size, int dir)
{
	size_t k = size / 2;

	if (size > 1)
	{
		bitonic_sort_recursive(array, start, k, 1);
		bitonic_sort_recursive(array, start + k, k, 0);

		bitonic_merge(array, start, size, dir);
	}
}

/**
 * bitonic_sort - Sorts an array of integers using the Bitonic sort algorithm
 * @array: ponter to the array to be sorted
 * @size: number of elements in the array
 */
void bitonic_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    bitonic_sort_recursive(array, 0, size, 1);
}
