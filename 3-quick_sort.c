#include "sort.h"

/**
 * quick_sort - Implementation of Quick List Algorithm
 * transforms given prototype to more confi prototype to
 * work in our_sort function.
 * @array: Data set in array type.
 * @size: Array's size
 *
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	int size_new;

	size_new = (int)size - 1;
	our_sort(array, 0, size_new, size);
}

/**
 * our_sort - Implementation of Quick Sort Algorithm
 * @array: Data set in array type.
 * @size: Array's size
 * @low: Lowest position to compare
 * @high: Pivot position to compare
 *
 * Return: void
 */

void our_sort(int *array, int low, int high, size_t size)
{
	int part_index = 0;

	if (low < high)
	{
		part_index = our_partition(array, low, high, size);

		our_sort(array, low, part_index - 1, size);
		our_sort(array, part_index + 1, high, size);
	}
}

/**
 * our_partition - Swaps the positions compared to the pivot if
 * they are smallest, or moves the pivot.
 * @array: Data set in array type.
 * @size: Array's size
 * @low: Lowest position to compare
 * @high: Pivot position to compare
 *
 * Return: void
 */

int our_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j = 0;

	for (j = low; j <= high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(array, i, j, size);
		}
	}
	swap(array, i + 1, high, size);
	return (i + 1);
}

/**
 * swap - Swaps two positions in an array
 * @array: Data set in array type.
 * @size: Array's size
 * @i: Actual position
 * @high: Pivot position to compare
 *
 * Return: void
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
