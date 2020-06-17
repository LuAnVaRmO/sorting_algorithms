#include "sort.h"
/**
 * shell_sort - Entry point
 * @array: array to sort
 * @size: size of array
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, temp, j;

	if (!array || !size)
		return;
	gap = get_gap(size);
	while (gap > 0)
	{
		for (i = gap; i < size; i += 1)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > (int)temp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}
		print_array(array, size);
		gap =  (gap - 1) / 3;
	}
}

/**
 * get_gap - get the start gap
 * @size: size of array to look for gap
 * Return: int value of gap
 */
int get_gap(size_t size)
{
	size_t gap;

	gap = 1;
	while (gap < size)
	{
		gap = (gap * 3) + 1;
	}
	gap = (gap - 1) / 3;
	return (gap);
}
