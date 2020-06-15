#include "sort.h"
/**
 * selection_sort - Entry Point
 * @array: array to sort
 * @size: size of array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int min = 0;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		swap(array, i, min, size);
	}
}

/**
 * swap - function to swap 2 values to an array
 * @array: array to swap
 * @i: first index to swap
 * @high: high value to swap
 * @size: size value to print array when swap values
 */
void swap(int *array, int i, int high, size_t size)
{
	int tmp = array[i];

	array[i] = array[high];
	array[high] = tmp;
	if (array[i] != array[high])
	{
		print_array(array, size);
	}
}
