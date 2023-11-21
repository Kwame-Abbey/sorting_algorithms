#include "sort.h"

/**
* swap_nodes - swaps two nodes in a doubly linked list
		* @list: pointer to the list head
* @a: first node to swap
* @b: second node to swap
*/
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	listint_t *a_prev = a->prev, *b_next = b->next;

	if (a_prev)
		a_prev->next = b;
	else
		*list = b;

	if (b_next)
		b_next->prev = a;

	a->next = b_next;
	b->prev = a_prev;
	b->next = a;
	a->prev = b;

	print_list(*list);
}

/**
* cocktail_sort_list - sorts a doubly linked list using the
*                      cocktail Sort algorithm
* @list: pointer to the list head
*/
void cocktail_sort_list(listint_t **list)
{
	int swapped = 0;
	listint_t *current = *list;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		swapped = 0;

		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				current = current->prev ? current->prev : *list;
				swapped = 1;
			} else
			{
				current = current->next;
			}
		}

		if (!swapped)
			break;

		swapped = 0;
		while (current->prev != NULL)
		{
			if (current->prev->n > current->n)
			{
				swap_nodes(list, current->prev, current);
				current = current->next ? current->next : NULL;
				swapped = 1;
			} else
			{
				current = current->prev;
			}
		}
	} while (swapped);
}

