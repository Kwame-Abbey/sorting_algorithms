#include "sort.h"
/**
 * selection_sort - this function implements the selection algorithm
 * @array: the array of intergers to sort
 * @size: the size of the given array
 */
void selection_sort(int *array, size_t size)
{
	size_t temp, i, j, min_index;

	if (size < 2 || array == NULL)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
			{
				min_index = j;
			}
		}
		if (min_index != i)
		{
			temp = array[i];
			array[i] = array[min_index];
			array[min_index] = temp;
			print_array(array, size);
		}
	}
}
