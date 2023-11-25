#ifndef SORT_H
#define SORT_H
/** c header files **/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

/* Function prototypes*/
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void partition(int *array, int low_index, int high_index, int size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
int hoare_partition(int *array, int low_index, int high_index, int size);
void hoare_recursion(int *array, int low_index, int high_index, int size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
int max_value(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void bit_compare(char up, int *array, size_t size);
void bit_merge(char up, int *array, size_t size);
void bit_sort(char up, int *array, size_t size, size_t t);
void merge(int *array, int *temp, int start, int middle, int end);
void merge_recursive(int *array, int start, int end, int *temp);
void merge_sort(int *array, size_t size);

#endif
