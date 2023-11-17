#include "sort.h"
/**
 * bubble_sort - Function that illustrates the bubble sort algoritm in arrays.
 * @array: it a pointer to the array of intergers
 * @size: this is the size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int flag;
	size_t temp;

	if (size < 2 || array == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		flag = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				flag = 1;
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
		if (flag == 0)
			return;
	}
}
