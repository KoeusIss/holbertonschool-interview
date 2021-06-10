#include "sort.h"

/**
 * top_down_merge - Implements top-down merge
 * @array: pointer to the first array
 * @copy: pointer to the second array
 * @size: The first array size
 *
 */
void top_down_merge(int *array, int *copy, size_t size)
{
	size_t half = size / 2;
	int *i = copy;
	int *j = copy + half;

	printf("Merging...\n[left]: "), print_array(copy, half);
	printf("[right]: "), print_array(copy + half, size - half);
	while (i < copy + half || j < copy + size)
		*array++ = i < copy + half && (j >= copy + size || *i <= *j)
			? *i++
			: *j++;
	printf("[Done]: "), print_array(array - size, size);
}

/**
 * top_down_split_merge - applies top down split
 * @array: pointer to the first array
 * @copy: pointer to the second array
 * @size: The size of the first array
 *
 */
void top_down_split_merge(int *array, int *copy, size_t size)
{
	size_t half = size / 2;

	if (size <= 1)
		return;

	top_down_split_merge(copy, array, half);
	top_down_split_merge(copy + half, array + half, size - half);

	top_down_merge(array, copy, size);
}

/**
 * merge_sort - Sorts an array of integers using Merge-sort
 * @array: Pointer to the first element in the array
 * @size: The size of the given array
 *
 */
void merge_sort(int *array, size_t size)
{
	int *copy;
	size_t i;

	copy = malloc(sizeof(*copy) * size);
	if (!copy)
		return;

	for (i = 0; i < size; i++)
		copy[i] = array[i];
	top_down_split_merge(array, copy, size);
	free(copy);
}
