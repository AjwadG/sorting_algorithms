#include "sort.h"


/**
 * merge - right and left half
 *
 * @arr1: fir copy of array
 * @arr2: second copy of array
 * @start: start of the array / subarray
 * @end: end of the array / subarray
 * @middle: middle of supp arrays
 *
 */
void merge(int *arr1, size_t start, size_t middle, size_t end, int *arr2)
{
	size_t i = start, j = middle, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(&arr2[start], middle - start);
	printf("[right]: ");
	print_array(&arr2[middle], end - middle);
	for (k = i; k < end; k++)
	{
		if (i < middle && (j >= end || arr2[i] <= arr2[j]))
		{
			arr1[k] = arr2[i];
			i++;
		}
		else
		{
			arr1[k] = arr2[j];
			j++;
		}
	}
	printf("[Done]: ");
	print_array(&arr1[start], end - start);
}


/**
 * topDownMerge - sorts array of recursively
 *
 * @arr1: fir copy of array
 * @arr2: second copy of array
 * @start: start of the array / subarray
 * @end: end of the array / subarray
 *
 */
void topDownMerge(int *arr1, size_t start, size_t end, int *arr2)
{
	size_t middle = (end + start) / 2;

	if (end - start <= 1)
		return;

	topDownMerge(arr2, start, middle, arr1);
	topDownMerge(arr2, middle, end, arr1);

	merge(arr1, start, middle, end, arr2);
}

/**
 * merge_sort - sorts array of size n in merge sort way
 *
 * @array: array to sort
 * @size: size of the array
 *
 */
void merge_sort(int *array, size_t size)
{
	int *copy, i;

	if (!array || size <= 1)
		return;

	copy = malloc(sizeof(int) * size);
	if (!copy)
		return;

	for (i = 0; i < (int) size; i++)
		copy[i] = array[i];

	topDownMerge(array, 0, size, copy);
	free(copy);
}
