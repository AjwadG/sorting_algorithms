#include "sort.h"

/**
 * out_put - prints formated out
 *
 * @a: array
 * @sub: size of the sub array
 * @full: size of the full array
 * @order: assending or de
 * @res: result or merg
 * @start: start of sub array
 */
void out_put(int *a, int start, int sub, int full, int order, int res)
{
	char *s1 = res ? "Result" : "Merging";
	char *s2 = order ? "UP" : "DOWN";

	printf("%s [%d/%d] (%s):\n", s1, sub, full, s2);

	print_array(&a[start], sub);
}
/**
 * merge - merges the tow halfs recrsively
 *
 * @array: array to sort
 * @start: first index
 * @len: size of the array
 * @de: assending or dessednig
 * @size: size of the array
 *
 */
void merge(int *array, size_t start, size_t len, int de, size_t size)
{
	int k = len / 2, tmp;
	size_t i;

	if (len < 2)
		return;
	for (i = start; i < start + k; i++)
	{
		if (de == (array[i] > array[i + k]))
		{
			tmp = array[i], array[i] = array[i + k];
			array[i + k] = tmp;
		}
	}
	merge(array, start, k, de, size);
	merge(array, start + k, k, de, size);

}

/**
 * sort - sorts recrsively
 *
 * @array: array to sort
 * @start: first index
 * @len: size of the array
 * @de: assending or dessednig
 * @size: size of the array
 *
 */
void sort(int *array, size_t start, size_t len, int de, size_t size)
{
	int k = len / 2;

	if (len < 2)
		return;
	out_put(array, start, len, size, de, 0);

	sort(array, start, k, 1, size);

	sort(array, start + k, k, 0, size);

	merge(array, start, len, de, size);

	out_put(array, start, len, size, de, 1);
}
/**
 * bitonic_sort - sorts linked in bitnoic sort way
 *
 * @array: array to sort
 * @size: size of the array
 *
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size <= 1)
		return;
	sort(array, 0, size, 1, size);
}
