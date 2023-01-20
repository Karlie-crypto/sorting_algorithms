#include "sort.h"

/**
 * radix_sort - sorts an array of integers in ascending order using the
 * Radix sort algorithm
 * @array: array of integers
 * @size: size of the array
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	int *output, *count, i, max, exp = 1;

	if (!array || size < 2)
		return;
	/* Find the max value in the array */
	max = array[0];
	for (i = 1; i < (int)size; i++)
		if (array[i] > max)
			max = array[i];
	/* Create an output array and a count array */
	output = malloc(sizeof(int) * size);
	count = malloc(sizeof(int) * 10);
	while (max / exp > 0)
	{
		/* Set all the values in the count array to 0 */
		for (i = 0; i < 10; i++)
			count[i] = 0;
		/* Count the number of times each digit appears in the array */
		for (i = 0; i < (int)size; i++)
			count[(array[i] / exp) % 10]++;
		/* Set the count array to the sum of the previous count */
		for (i = 1; i < 10; i++)
			count[i] += count[i - 1];
		/* Set the output array to the array in reverse order */
		for (i = (int)size - 1; i >= 0; i--)
		{
			output[count[(array[i] / exp) % 10] - 1] = array[i];
			count[(array[i] / exp) % 10]--;
		}
		/* Set the array to the output array */
		for (i = 0; i < (int)size; i++)
			array[i] = output[i];
		/* Print the array */
		print_array(array, size);
		/*  Multiply the exponent by 10 */
		exp *= 10;
	}
	/* Free the output and count arrays */
	free(output);
	free(count);
}
