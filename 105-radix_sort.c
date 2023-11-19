#include "sort.h"

/**
 * get_digit - gets dgit
 *
 * @n: number
 * @l: lenght wanted
 *
 * Return: only one digit
 */
int get_digit(int n, int l)
{
	int i, upper = 1, lower;

	for (i = 0; i < l; i++)
		upper *= 10;
	lower = upper / 10;
	return ((n % upper) / lower);
}

/**
 * get_d - gets the biggest value
 *
 * @array: array to sort
 * @size: size of the array
 *
 * Return: the lenght of the biggest number
 */
int get_d(int *array, size_t size)
{
	int n = array[size - 1], l;

	while (size-- > 0)
	{
		if (n < array[size])
			n = array[size];
	}
	for (l = 0; n; l++)
		n /= 10;
	return (l);
}


/**
 * radix_sort - sorts linked in radix sort way
 *
 * @array: array to sort
 * @size: size of the array
 *
 */
void radix_sort(int *array, size_t size)
{
	int d, *copy, *count, i, j;

	if (!array || size <= 1)
		return;
	copy = malloc(sizeof(int) * size);
	if (!copy)
		return;
	count = malloc(sizeof(int) * 10);
	if (!count)
	{
		free(copy);
		return;
	}
	d = get_d(array, size);
	for (i = 1; i < d + 1; i++)
	{
		for (j = 0; j < 10; j++)
			count[j] = 0;
		for (j = 0; j < (int) size; j++)
			count[get_digit(array[j], i)]++;
		for (j = 1; j < 10; j++)
			count[j] += count[j - 1];
		for (j = size - 1; j >= 0; j--)
			copy[count[get_digit(array[j], i)]-- - 1] = array[j];
		for (j = 0; j < (int) size; j++)
			array[j] = copy[j];
		print_array(array, size);
	}
	free(copy);
	free(count);
}
