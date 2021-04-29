#include "search_algos.h"

/**
 * print_array - Prints an array recursibely
 * @array: Pointer to the first element in the array
 * @start: Index of the printing start
 * @size: Size of the array
 */
void print_array(int *array, size_t start, size_t size)
{
	if (start > size)
		return;
	printf("%d", array[start]);
	if (start < size)
		printf(", ");
	print_array(array, start + 1, size);
}

/**
 * advanced_binary - Searches for a value in a sorted array
 * @array: Pointer to the first element of the array to search in
 * @size: Number of element in array
 * @value: The value to search for
 *
 * Return: Index where value is located, otherwise return NULL
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t low = 0;
	size_t high = size - 1;
	size_t mid;

	if (!array)
		return (-1);
	while (low <= high)
	{
		printf("Searching in array: ");
		print_array(array, low, high);
		printf("\n");

		mid = (low + high) / 2;
		if (array[mid] == value && array[mid - 1] != value)
			return (mid);
		else if (array[mid] < value)
			low = mid + 1;
		else
			high = mid;
	}
	return (-1);
}
