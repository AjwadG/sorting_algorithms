#include "sort.h"


/**
 * hoare - hoare partition scheme.
 *
 * @array: array to sort
 * @size: size of the array
 * @start: start of the array / subarray
 * @end: end of the array / subarray
 *
 * Return: the index of pivot point
 */
int hoare(int *array, size_t size, int start, int end)
{
	int pivot = array[end], i = start - 1, j = end + 1, tmp;

	while (1)
	{
		do
			i++;
		while (array[i] < pivot);
		do
			j--;
		while (array[j] > pivot);
		if (i >= j)
			return (i);
		tmp = array[i], array[i] = array[j];
		array[j] = tmp;
		print_array(array, size);
	}
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
	pivot = hoare(array, size, start, end);
	quick(array, size, start, pivot - 1);
	quick(array, size, pivot, end);

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
