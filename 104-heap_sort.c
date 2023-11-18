#include "sort.h"


/**
 * siftDown - sifts down the elemnts
 *
 * @array: array to sort
 * @size: size of the array
 * @start: start of the array / subarray
 * @end: end of the array / subarray
 *
 */
void siftDown(int *array, size_t start, size_t end, size_t size)
{
	size_t first, swap, child;
	int tmp;

	for (first = start; (first * 2) + 1 <= end; first = swap)
	{
		child = (first * 2) + 1;
		swap = first;
		if (array[swap] < array[child])
			swap = child;
		if (child + 1 <= end && array[child + 1] > array[swap])
			swap = child + 1;
		if (swap == first)
			return;
		tmp = array[first], array[first] = array[swap], array[swap] = tmp;
		print_array(array, size);
	}
}

/**
 * heap_sort - sorts array of size n in heap sort way
 *
 * @array: array to sort
 * @size: size of the array
 *
 */
void heap_sort(int *array, size_t size)
{
	size_t end;
	int tmp, head;

	if (!array || size <= 1)
		return;
	for (head = (size - 1) / 2; head >= 0; head--)
		siftDown(array, head, size - 1, size);

	for (end = size - 1; end > 0; end--)
	{
		tmp = array[end], array[end] = array[0], array[0] = tmp;
		print_array(array, size);
		siftDown(array, 0, end - 1, size);
	}
}
