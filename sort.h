#ifndef _SORT_H
#define _SORT_H

#include <stdlib.h>
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void swap(int *array, int i, int high, size_t size);
int our_partition(int *array, int low, int high, size_t size);
void our_sort(int *array, int low, int high, size_t size);
void quick_sort(int *array, size_t size);
void swap_back(listint_t **list, listint_t *low, listint_t *high);
void shell_sort(int *array, size_t size);
int get_gap(size_t size);

#endif /* _SORT_H */
