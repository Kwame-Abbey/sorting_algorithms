#include "sort.h"
/**
 * merge - merge function. responsible for merging the array
 * @array: the array that needs sorting
 * @temp: temporary array. facilitates the merging
 * @start: the begining of the array.
 * @middle: middle index of the array
 * @end: the end index of the array.
 */
void merge(int *array, int *temp, int start, int middle, int end)
{
	int i = start, j = middle, k = start, l = middle, flag = 0;

	printf("Merging...\n");
	printf("[left]: ");
	while (k < middle)
	{
		if (flag)
			printf(", ");
		printf("%d", array[k++]);
		flag = 1;
	}
	printf("\n");
	flag = 0;
	printf("[right]: ");
	while (l < end)
	{
		if (flag)
			printf(", ");
		printf("%d", array[l++]);
		flag = 1;
	}
	printf("\n");
	k = start;
	while (k < end)
	{
		if (i < middle && (j >= end || array[i] <= array[j]))
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}
	printf("[Done]: ");
	k = start, flag = 0;
	while (k < end)
	{
		if (flag)
			printf(", ");
		printf("%d", temp[k++]);
		flag = 1;
	}
	printf("\n");
}
/**
 * merge_recursive - responsible for recursive calls.
 * @array: the array passed for sorting
 * @start: the starting index of the array.
 * @end: the end of the array.
 * @temp: temporary array.
 */
void merge_recursive(int *array, int start, int end, int *temp)
{
	int middle = 0;

	if (end - start <= 1)
		return;
	middle = (start + end) / 2;
	merge_recursive(array, start, middle, temp);
	merge_recursive(array, middle, end, temp);
	merge(array, temp, start, middle, end);
}
/**
 * merge_sort - calls the recursive function.
 * @array: array passed for sorting
 * @size: the size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *temp;
	size_t i = 0;

	if (array == NULL || size < 2)
		return;
	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
	{
		exit(EXIT_FAILURE);
	}
	while (i < size)
	{
		temp[i] = array[i];
		i++;
	}
	merge_recursive(array, 0, size, temp);
	i = 0;
	while (i < size)
	{
		array[i] = temp[i];
		i++;
	}
	free(temp);
}
