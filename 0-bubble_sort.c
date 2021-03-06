#include "sort.h"
/**
 * bubble_sort - Entry point
 * @array: array to sort
 * @size: size of the array
 * Return: sorted list
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, k, s_temp;

	s_temp = size;
	for (i = 0; i < s_temp; s_temp--)
	{
		k = i;
		for (j = k + 1; j < s_temp; j++, k++)
		{
			if (array[k] > array[j])
			{
				swap(array, k, j, size);
			}
		}
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
