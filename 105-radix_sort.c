#include "sort.h"
/**
 * radix_sort - sorts an array of integers is ascending order
 *              implementing Radix Sort algorithm
 * @array: pointer to array
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int *new_array;
	int i, max, a = 1;
	int j = size;

	if (array == NULL || size < 2)
		return;

	max = max_value(array, size);

	new_array = malloc(sizeof(int) * size);
	while (max / a > 0)
	{
		int abb[20] = {0};

		i = 0;

		while (i < j)
		{
			abb[(array[i] / a) % 10]++;
			i++;
		}

		if (abb != NULL)
		{
			for (i = 1; i < 10; i++)
				abb[i] += abb[i - 1];

			for (i = j - 1; i >= 0; i--)
			{
				new_array[abb[(array[i] / a) % 10] - 1] = array[i];
				abb[(array[i] / a) % 10]--;
			}

			for (i = 0; i < j; i++)
				array[i] = new_array[i];
		}
		a *= 10;
		print_array(array, size);
	}
	free(new_array);
}

/**
 * max_value - gets max value from array
 * @array: pointer to array
 * @size: size of the array
 * Return: max value from array
 */
int max_value(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}
