#include "sort.h"


/**
 * lomuto - Lomuto partition scheme.
 *
 * @array: array to sort
 * @size: size of the array
 * @start: start of the array / subarray
 * @end: end of the array / subarray
 *
 * Return: the index of pivot point
 */
int lomuto(int *array, size_t size, int start, int end)
{
	int pivot = array[end], i = start, j, tmp;

	for (j = start; j < end; j++)
	{
		if (array[j] < pivot)
		{
			tmp = array[i], array[i] = array[j];
			array[j] = tmp, i++;
			if (array[i - 1] != array[j])
				print_array(array, size);
		}
	}
	tmp = array[i], array[i] = array[end];
	array[end] = tmp;
	if (array[i] != tmp)
		print_array(array, size);
	return (i);
}


/**
 * quick - sorts array of size n in quick sort way
 *
 * @array: array to sort
 * @size: size of the array
 * @start: start of the array / subarray
 * @end: end of the array / subarray
 *
 */
void quick(int *array, size_t size, int start, int end)
{
	int pivot;

	if (start >= end || start < 0)
		return;
	pivot = lomuto(array, size, start, end);
	quick(array, size, start, pivot - 1);
	quick(array, size, pivot + 1, end);

}

/**
 * quick_sort_hoare - sorts array of size n in quick sort way
 *
 * @array: array to sort
 * @size: size of the array
 *
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size <= 1)
		return;
	quick(array, size, 0, size - 1);
}
