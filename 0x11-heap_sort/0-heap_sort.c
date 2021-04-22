#include "sort.h"

/**
 * swap - Swap between two element of an array
 * @first: Pointer to the first element
 * @second: Pointer to the second element
 */
void swap(int *first, int *second) {
	int temp = *first;
	*first = *second;
	*second = temp;
}

/**
 * heapify - Finds the largest element among a root
 * @array: Pointer to the given array
 * @size: The size of given array
 * @idx: the given idx
 */
void heapify(int *array, int size, int idx)
{
	int largest = idx;
	int left = 2 * idx + 1;
	int right = 2 * idx + 2;

	if (left < size && array[left] > array[largest])
		largest = left;

	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != idx)
	{
		swap(&array[idx], &array[largest]);
		print_array(array, size);
		heapify(array, size, largest);
	}
}

/**
 * heap_sort - Sorts an array in ascending order
 * @array: Pointer to the given array
 * @size: the size of the given array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	for (i = size / 2 - 1; i >= 0; i--)
	{
		heapify(array, size, i);
	}

	for (i = size - 1; i >= 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, i, 0);
	}
}
