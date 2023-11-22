#include "sort.h"
/**
 * merge_sort - calls the function that deals with the division.
 * @array: array of integers
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
	{
		exit(EXIT_FAILURE);
	}
	merge_sort_recursive(array, temp, 0, (size - 1));
	free(temp);
}
/**
 * merge_sort_recursive - divides the array recursively.
 * @array: the array passed.
 * @temp: temporary array created
 * @left: left most index
 * @right: right most index
 */
void merge_sort_recursive(int *array, int *temp, int left, int right)
{
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2;
		merge_sort_recursive(array, temp, left, mid);
		merge_sort_recursive(array, temp, (mid + 1), right);
		merge(array, temp, left, mid, right);
	}
}
/**
 * merge - performs the merging of the array
 * @array: array to sort
 * @temp: temporary array
 * @left: left most index
 * @mid: middle index
 * @right: right most index
 */
void merge(int *array, int *temp, int left, int mid, int right)
{
	int i = left;
	int j = mid + 1;
	int k = left;
	int x;

	printf("Merging...\n");
	print_left(array, left, mid);
	print_right(array, mid, right);
	while (i <= mid && j <= right)
	{
		if (array[i] <= array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}
	if (i > mid)
	{
		while (j <= right)
		{
			temp[k++] = array[j++];
		}
	}
	else
	{
		while (i <= mid)
		{
			temp[k++] = array[i++];
		}
	}
	printf("[Done]: ");
	for (x = left; x <= right; x++)
	{
		array[x] = temp[x];
		printf("%d", array[x]);
		if (x < right)
			printf(", ");
	}
	printf("\n");
	/*print_done(array, left, right);*/
}
/**
 * print_left_right - focuses on printing
 * @array: the array to retrive the print
 * @left: left most index
 * @mid: middle index
 */
void print_left(int *array, int left, int mid)
{

	int i;

	printf("[Left]: ");
	for (i = left; i <= mid; i++)
	{
		printf("%d", array[i]);
		if (i < mid)
			printf(", ");
	}
	printf("\n");
}
/**
 * print_right - focuses on printing
 * @array: the array to retrive the print
 * @mid: middle index
 * @right: right most index
 */
void print_right(int *array, int mid, int right)
{
	int j;

	printf("[right]: ");
	for (j = mid + 1; j <= right; j++)
	{
		printf("%d", array[j]);
		if (j < right)
			printf(", ");
	}
	printf("\n");
}
