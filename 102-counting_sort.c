#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order using
 *                 the counting sort algorithm
 * @array: array of integers
 * @size: number of elements in array
 */

void counting_sort(int *array, size_t size)
{
	int max, j, *count_array, *input_array;
	size_t i;

	if (array == NULL || size < 2)
		return;
	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	count_array = calloc((max + 1), sizeof(int));
	for (i = 0; i < size; i++)
		count_array[array[i]]++;
	for (j = 1; j < max; j++)
		count_array[j + 1] += count_array[j];

	print_array(count_array, max + 1);

	input_array = malloc(sizeof(int) * size);
	for (i = 0; i < size; i++)
	{
		count_array[array[i]]--;
		input_array[count_array[array[i]]] = array[i];
	}
	for (i = 0; i < size; i++)
		array[i] = input_array[i];
	free(input_array);
	free(count_array);

}
