#include "sort.h"
/**
 * partition - This function does the partitioning of
 * the array and also calls itself recursively.
 * @array: This is the array that we need to sort
 * @low_index: low index of the array to be sorted.
 * @high_index: high index of the array that needs sorting
 * @size: the size of the array.
 */
void partition(int *array, int low_index, int high_index, int size)
{
	int pivot, i, j, temp, temp2;

	pivot = high_index;
	i = low_index;
	if (low_index < high_index)
	{
		for (j = low_index; j < high_index; j++)
		{
			if (array[j] < array[pivot])
			{
				if (j != i)
				{
					temp = array[j];
					array[j] = array[i];
					array[i] = temp;
					print_array(array, size);
				}
				i++;
			}
		}
		if (i != high_index && array[i] != array[pivot])
		{
			temp2 = array[i];
			array[i] = array[pivot];
			array[pivot] = temp2;
			print_array(array, size);
		}
	partition(array, low_index, (i - 1), size);
	partition(array, (i + 1), high_index, size);
	}
}
/**
 * quick_sort - calls the partition function.
 * @array: array to sort.
 * @size: size of array.
 */
void quick_sort(int *array, size_t size)
{
	partition(array, 0, (size - 1), size);
}
