#include "sort.h"
#include <stdio.h>

/**
 * bit_compare - sort the values in a sub-array with respect to
 *                the bitonic sorting algorithm
 * @up: direction of sorting
 * @array: sub-array to sort
 * @size: size of the sub-array
 */
void bit_compare(char up, int *array, size_t size)
{
	size_t i, tmp;
	int swap;

	tmp = size / 2;
	for (i = 0; i < tmp; i++)
	{
		if ((array[i] > array[i + tmp]) == up)
		{
			swap = array[i];
			array[i] = array[i + tmp];
			array[i + tmp] = swap;
		}
	}
}

/**
 * bit_merge - recursive function
 * @up: direction of sorting
 * @array: sub-array to sort
 * @size: size of the sub-array
 */
void bit_merge(char up, int *array, size_t size)
{
	if (size < 2)
		return;
	bit_compare(up, array, size);
	bit_merge(up, array, size / 2);
	bit_merge(up, array + (size / 2), size / 2);
}

/**
 * bit_sort - recursive function
 * @up: direction of sorting
 * @array: sub-array to sort
 * @size: size of the sub-array
 * @t: total size of the original array
 */
void bit_sort(char up, int *array, size_t size, size_t t)
{
	if (size < 2)
		return;
	printf("Merging [%lu/%lu] (%s):\n", size, t, (up == 1) ? "UP" : "DOWN");
	print_array(array, size);
	bit_sort(1, array, size / 2, t);
	bit_sort(0, array + (size / 2), size / 2, t);
	bit_merge(up, array, size);
	printf("Result [%lu/%lu] (%s):\n", size, t, (up == 1) ? "UP" : "DOWN");
	print_array(array, size);

}

/**
 * bitonic_sort - sorts an array of integers in ascending order using
 *                the Bitonic sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	bit_sort(1, array, size, size);
}
