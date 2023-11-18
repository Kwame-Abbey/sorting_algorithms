#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 *                  order using insertion sort algorithm
 * @list: doubly linked list
 */

void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *current = (*list)->next;

    while (current != NULL)
    {
        listint_t *temp = current->prev;
        
        while (temp != NULL && current->n < temp->n)
        {
            if (current->next != NULL)
                current->next->prev = temp;

            temp->next = current->next;
            current->prev = temp->prev;
            current->next = temp;

            if (temp->prev != NULL)
                temp->prev->next = current;
            else
                *list = current;

            temp->prev = current;

            temp = current->prev;
            print_list(*list);
        }

        current = current->next;
    }
}

