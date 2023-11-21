#include "sort.h"
/**
 * quick_sort_hoare - Quick sort algorith implementing the Hoare partition
 * @array: The array that needs to be sorted.
 * @size: The size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	hoare_recursion(array, 0, (size - 1), size);
}
/**
 * hoare_partition - partition algorith used.
 * @array: the array used.
 * @low_index: low-bound
 * @high_index: high-bound
 * @size: size of the array
 * Return: interger
 */
int hoare_partition(int *array, int low_index, int high_index, int size)
{
	int pivot, i, j, temp1;

	pivot = array[high_index];
	i = low_index;
	j = high_index;

	for (i = low_index, j = high_index; 1; i++, j--)
	{
		while (array[i] < pivot)
		{
			i++;
		}
		while (array[j] > pivot && high_index > 0)
		{
			j--;
		}
		if (i >= j)
		{
			return (i);
		}
			temp1 = array[j];
			array[j] = array[i];
			array[i] = temp1;
			print_array(array, size);
	}
}
/**
 * hoare_recursion - function responsible for the recursion
 * @array: the array to sort
 * @low_index: low bound
 * @high_index: high bound
 * @size: size of array
 */
void hoare_recursion(int *array, int low_index, int high_index, int size)
{
	int pivot_index;

	if (low_index < high_index)
	{
		pivot_index = hoare_partition(array, low_index, high_index, size);

		hoare_recursion(array, low_index, (pivot_index - 1), size);
		hoare_recursion(array, (pivot_index), high_index, size);
	}
}
