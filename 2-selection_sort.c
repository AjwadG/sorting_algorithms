#include "sort.h"


/**
 * selection_sort - sorts array of size n in selection sort way
 *
 * @array: array to sort
 * @size: size of the array
 *
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, index;
	int tmp, swap;

	if (!array || size <= 1)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swap = 0;
		index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[index] > array[j])
			{
				swap = 1;
				index = j;
			}
		}
		if (swap)
		{
			tmp = array[index];
			array[index] = array[i];
			array[i] = tmp;
			print_array(array, size);
		}
	}
}
