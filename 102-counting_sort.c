#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order using the
 * Counting sort algorithm.
 *
 * Assume that array will contain only numbers >= 0.
 * You are allowed to use malloc and free.
 * Print your counting array once it is set up.
 * This array is of size k + 1 where k is the largest number in array.
 *
 * @array: pointer to array of integers to sort.
 * @size: size of array.
 *
 * Return: No return.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *output, max = 0, i;

	if (!array || size < 2)
		return;

	/**
	 * Find the maximum value in the array.
	 * Create a count array of size max + 1.
	 * Initialize all values in count array as 0.
	 * Store the count of each element in the count array.
	 * Modify the count array by adding the previous counts.
	 * Output each object from the input sequence followed by decreasing
	 * its count by 1.
	 * Print the sorted array.
	 */

	for (i = 0; i < (int)size; i++)
		if (array[i] > max)
			max = array[i];
	count = malloc(sizeof(int) * (max + 1));
	output = malloc(sizeof(int) * size);
	if (!count || !output)
		return;
	for (i = 0; i <= max; i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);
	for (i = 0; i < (int)size; i++)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = output[i];
	free(count);
	free(output);
}
