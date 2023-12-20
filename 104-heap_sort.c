#include "sort.h"

void swap(int *x, int *y);
void sift_down(int *array, size_t root, size_t size);
void heapify(int *array, size_t size);

/**
 * swap - Swaps two integers in an array.
 * @x: pointer to the first integer to swap.
 * @y: pointer to the second integer to swap.
 */
void swap(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * sift_down - Performs the sift-down operation in the heap sort algorithm
 * @array: Array to be sorted
 * @root: Root index of the subtree
 * @size: Size of the array
 */
void sift_down(int *array, size_t root, size_t size)
{
	size_t largest, left, right;

	largest = root;
	left = 2 * root + 1;
	right = 2 * root + 2;

	if (left < size && array[left] > array[largest])
		largest = left;

	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != root)
	{
		swap(&array[root], &array[largest]);
		print_array(array, size);
		sift_down(array, largest, size);
	}
}

/**
 * heapify - Converts the given array into a max-heap
 * @array: pointer to the integer array to be heapified
 * @size: number of elements in the array
 */
void heapify(int *array, size_t size)
{
	int i;

	for (i = size / 2 - 1; i >= 0; i--)
		sift_down(array, i, size);
}

/**
 * heap_sort - Sorts an array of integers in ascending
 *             order using the heap sort algorithm
 * @array: pointer to the array of integers
 * @size: number of elements in the array
 */
void heap_sort(int *array, size_t size)
{
	int i;
	heapify(array, size);

	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		sift_down(array, 0, i);
	}
}
