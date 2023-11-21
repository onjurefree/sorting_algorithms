#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: array of integers
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	partition(array, 0, size - 1, size);
}

/**
 * partition - divide and conquer
 * @array: list of integers
 * @bot: first integer
 * @top: last integer
 * @size: length of array
 */
void partition(int *array, int bot, int top, size_t size)
{
	if (bot < top)
	{
		int sorted = sorted_array(array, bot, top, size);

		partition(array, bot, sorted - 1, size);
		partition(array, sorted + 1, top, size);
	}
}

/**
 * sorted_array - divide and conquer
 * @array: list of integers
 * @bot: first integer
 * @top: last integer
 * @size: length of array
 * Return:- Always 0
 */

int sorted_array(int *array, int bot, int top, size_t size)
{
	int swap, new_pivot;
	int pivot = array[top];
	int i = bot, j = bot;

	for (; j < top; j++)
	{
		if (array[j] <= pivot)
		{
			if (i != j)
			{
				swap = array[i];
				array[i] = array[j];
				array[j] = swap;
				print_array(array, size);
			}
			i++;
		}
	}

	if (pivot != array[i])
	{
	new_pivot = array[i];
	array[i] = array[top];
	array[top] = new_pivot;
	print_array(array, size);
	}

	return (i);
}
