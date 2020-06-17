#include "sort.h"
/**
 * quick_sort_hoare - Entry Point
 * @array: array to sort
 * @size: size of array
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
	int low, high;

	if (array == NULL)
		return;

	low = 0;
	high = (int)size - 1;

	our_quick_sort(array, low, high, size);
}

/**
 * our_quick_sort - function that implements QuickSort
 * @arr: Array to be sorted
 * @low: Starting index
 * @high: Ending index
 * @size: size of array
 */
void our_quick_sort(int *arr, int low, int high, size_t size)
{
	if (low < high)
	{
		/**
		 * pi is partitioning index, arr[p] is now at right place
		 */

		int pi = hoare_partition(arr, low, high, size);

		/**
		 * Separately sort elements before
		 * partition and after partition
		 */
		our_quick_sort(arr, low, pi, size);
		our_quick_sort(arr, pi + 1, high, size);
	}
}

/**
 * hoare_partition - our partition method hoare
 * @arr: array to sort
 * @low: low value
 * @high: high value
 * @size: total size of array
 * Return: index to sort with recursion in our_quick_sort
 */
int hoare_partition(int *arr, int low, int high, size_t size)
{
	int pivot = arr[high];
	int i = low - 1;
	int j = high + 1;
	int a = 1;

	while (a)
	{
		/**
		 * Find leftmost element greater than
		 * or equal to pivot
		 */
		do {
			i++;
		} while (arr[i] < pivot);

		/**
		 * Find rightmost element smaller than
		 * or equal to pivot
		 */
		do {
			j--;
		} while (arr[j] > pivot);
		/* If two pointers met.*/

		if (i > j)
			return (j);
		swap(arr, i, j, size);
	}
	return (j);
}

/**
 * swap - Swaps two positions in an array
 * @array: Data set in array type.
 * @size: Array's size
 * @low: Actual position
 * @high: Pivot position to compare
 * Return: void
 */
void swap(int *array, int low, int high, size_t size)
{
	int tmp = array[low];

	array[low] = array[high];
	array[high] = tmp;
	if (array[low] != array[high])
	{
		print_array(array, size);
	}
}
