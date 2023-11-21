#include "sort.h"

/**
 * bubble_sort - function that sorts arrays using
 * bubble sort algorith
 * @array:- pointer to the array to sort
 * @size:- size of the array
 * Return:- Always 0
 */

void bubble_sort(int *array, size_t size)
{
	size_t k;
	int swap = -1;
	int temp;



	if (size < 2)
		return;

	while (swap != 0)
	{
		swap = 0;

		for (k = 0; k < size - 1; k++)
		{
			if (array[k] > array[k + 1])
			{
				temp = array[k];
				array[k] = array[k + 1];
				array[k + 1] = temp;
				swap++;

				print_array(array, size);
			}
		}

	}
}
