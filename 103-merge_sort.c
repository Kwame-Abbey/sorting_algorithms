#include "sort.h"
/**
 * merge_sort - takes in an array and its size and sorts them.
 * @array: array to be sorted.
 * @size: size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size < 2)
	{
		return;
	}

	temp = malloc(size * sizeof(int));
	if (temp == NULL)
	{
		exit(EXIT_FAILURE);
	}
	merge_sort_recursive(array, temp, 0, size);
	free(temp);
}
/**
 * merge_sort_recursive - responsible for doing the recursion
 * @array: the array passed
 * @temp: temporary array
 * @left: index at the far left
 * @right: index at the far right
 */
void merge_sort_recursive(int *array, int *temp, int left, int right)
{
	int mid;

	if ((right - left) > 1)
	{
		mid = left + (right - left) / 2;
		merge_sort_recursive(array, temp, left, mid);
		merge_sort_recursive(array, temp, mid, right);
		merge(array, temp, left, mid, right);
	}
}
/**
 * merge - responsible for the merging
 * @array: the array passed.
 * @temp: pointer to the temporary array
 * @left: the left most index
 * @mid: middle point of the array
 * @right: right most index
 */
void merge(int *array, int *temp, int left, int mid, int right)
{
	int i = left, k = left;
	int j = mid;
	int x;

	printf("Merging...\n");
	printf("[left]: ");
	for (i = left; i < mid; i++)
	{
		printf("%d", array[i]);
		if (i < mid - 1)
			printf(", ");
	}
	printf("\n");
	printf("[right]: ");
	for (i = mid; i < right; i++)
	{
		printf("%d", array[i]);
		if (i < right - 1)
			printf(", ");
	}
	printf("\n");
	while (i < mid && j < right)
	{
		if (array[i] <= array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}
	while (i < mid)
		temp[k++] = array[i++];
	while (j < right)
		temp[k++] = array[j++];
	for (x = left; x < right; x++)
	{
		printf("%d", array[x]);
		if (x < right - 1)
			printf(", ");
	}
	printf("\n");
}
