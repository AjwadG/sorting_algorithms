#include "sort.h"


/**
 * bubble_sort - sorts array of size n in pubble sort way
 *
 * @array: array to sort
 * @size: size of the array
 *
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp, swap;

	if (!array || size <= 1)
		return;

	for (i = 0; i < size; i++)
	{
		swap = 0;
		for (j = 1; j < size - i; j++)
		{
			if (array[j] < array[j - 1])
			{
				swap = 1;
				tmp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = tmp;
				print_array(array, size);
			}
		}
		if (!swap)
			break;
	}
}
