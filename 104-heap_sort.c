#include "sort.h"
/**
 * check_tree - swiftdown check
 * @array: pointer to array
 * @size: size of the pointer
 * @n_size: original size of the array
 * @i: index as a root of the tree
 *
**/
void check_tree(int *array, size_t n_size, size_t size, size_t i)
{

	int n, bran_1, bran_2;
	size_t br1, br2;

	br1 = i * 2 + 1;
	br2 = br1 + 1;
	bran_1 = array[br1];
	bran_2 = array[br2];
	if (((br1 < size) && (br2 < size) &&
		(bran_1 >= bran_2 && bran_1 > array[i]))
		|| ((br1 == size - 1) && bran_1 > array[i]))
	{
		n = array[i];
		array[i] = bran_1;
		array[br1] = n;
		print_array(array, n_size);
	}
	else if ((br1 < size) && (br2 < size) &&
		(bran_2 > bran_1 && bran_2 > array[i]))
	{
		n = array[i];
		array[i] = bran_2;
		array[br2] = n;
		print_array(array, n_size);
	}
	if (br1 < size - 1)
		check_tree(array, n_size, size, br1);
	if (br2 < size - 1)
		check_tree(array, n_size, size, br2);
}
/**
 * heap_sort - sorts an array of integers in ascending order using the Heap
 *             sort algorithm
 * @array: pointer to array
 * @size: size of the pointer
 */
void heap_sort(int *array, size_t size)
{
	size_t i, n_size = size;
	int n;

	if (array == NULL)
		return;
	for (i = 0; i < size / 2 ; i++)
	{
		check_tree(array, n_size, size, size / 2 - 1 - i);
	}
	for (i = 0; i < n_size - 1; i++)
	{
		n = array[0];
		array[0] = array[size - 1 - i];
		array[size - 1 - i] = n;
		print_array(array, n_size);
		check_tree(array, n_size, size - i - 1, 0);
	}

}
