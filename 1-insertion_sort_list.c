#include "sort.h"

/**
 * insertion_sort_list - Implementation of Sort List Algorithm
 * @list: Double linked list with data
 *
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *t_prev;

	current = *list;
	if (!current->next)
		return;
	current = current->next;
	t_prev = current->prev;
	
	while (current)
	{
		if ((current->n) < (t_prev->n))
		{
			swap_back(list, t_prev, current);
			current = t_prev->next;
			continue;
		}
		current = current->next;
		t_prev = t_prev->next;
	}
}

/**
 * swap_back - Compares two positions and if [i+1] < [i], swaps
 * them back, and compares againg in reverse direction
 *
 * @list: Double linked list
 * @low: lowest positioned node in the pair
 * @high: highest positioned node in the pair
 *
 * Return: void
 */

void swap_back(listint_t **list, listint_t *low, listint_t *high)
{
	int a = 1;
	int flag = 0;
	listint_t *tmp = NULL;

	while (a)
	{
		if (flag == 1)
		{
			low = low->prev;
			high = high->prev;
		}
		low->next = high->next;
		tmp = low->prev;
		low->prev = high;
		high->prev = tmp;
		if (high->prev != NULL)
			high->prev->next = high;
		high->next = low;
		if (high->prev == NULL)
			*list = high;
		if (low->next != NULL)
			low->next->prev = low;
		tmp = high;
		high = low;
		low = tmp;
		flag = 1;
		print_list(*list);
		if (low->prev == NULL)
		{
			a = 0;
			continue;
		}
		if (low->n > low->prev->n) /*if the loop must stop*/
			a = 0;
	}
}
