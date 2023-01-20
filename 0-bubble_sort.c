#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * prints the array after each time you swap two elements
 *
 * @array: array of integers to be sorted
 * @size: number of integers in array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	int temp;
	int swaps = -1;  /* swap counter */

	/* An array does not need to be sorted if its size is less than 2 */
	if (size < 2)
		return;

	/* repeat until swap counter is 0 */
	while (swaps)
	{
		/* reset swap counter to 0 */
		swaps = 0;

		/* look at each adjacent pair */
		for (i = 0; i < size - 1; i++)
		{
			/* if the adjacent elements are not in order */
			if (array[i] > array[i + 1])
			{
				/* swap them */
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;

				/* increment swap counter */
				swaps++;

				/* print the array */
				print_array(array, size);
			}
		}
	}
}
