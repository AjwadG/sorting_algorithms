#include "sort.h"


/**
 * knuth - kntuh sequence
 *
 * @array: array to sort
 * @size: size of the array
 * @gap: start of the array / subarray
 *
 * Return: the index of pivot point
 */
void knuth(int *array, size_t size, size_t gap)
{
	size_t i, j;
	int tmp;

	for (; gap > 0; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			for (j = i; j > gap - 1; j -= gap)
			{
				if (array[j - gap] < tmp)
					break;
				array[j] = array[j - gap];
			}
			array[j] = tmp;
		}
		print_array(array, size);
	}
}


/**
 * shell_sort - sorts array of size n in shell sort way
 *
 * @array: array to sort
 * @size: size of the array
 *
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1;

	if (!array || size <= 1)
		return;

	while (gap < size)
		gap = gap * 3 + 1;

	knuth(array, size, (gap - 1) / 3);
}
