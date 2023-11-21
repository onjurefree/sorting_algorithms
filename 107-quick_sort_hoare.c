#include "sort.h"

int hoare_partition(int *array, int low, int high, size_t size);
void quick_sort_hoare_wrapper(int *array, size_t size, int low, int hight);
void swapp(int *array, size_t size,  int *a, int *b);

/**
 * swapp - function that swaps elements
 * @array:- pointer to the array
 * @size:- size of the array
 * @a:- first element
 * @b:- second element
 */

void swapp(int *array, size_t size,  int *a, int *b)
{
	int tmp;

	if (a != b)
	{
		tmp = *a;
		*a = *b;
		*b = tmp;

		print_array(array, size);
	}
}

/**
 * quick_sort_hoare - function for dividing the array
 * @array:- pointer to the array
 * @size:- size of the array
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array && size > 1)
		quick_sort_hoare_wrapper(array, size, 0, size - 1);
}

/**
 * quick_sort_hoare_wrapper - function finding the pivot point
 * @array:- pointer to the array
 * @size:- size of the array
 * @low:- low limit of the sections
 * @high:- higher limit
 */

void quick_sort_hoare_wrapper(int *array, size_t size, int low, int high)
{
	size_t pivot_index;

	if (low < high)
	{
		pivot_index = hoare_partition(array, low, high, size);

		quick_sort_hoare_wrapper(array, size, low,  high - 1);
		quick_sort_hoare_wrapper(array, size, pivot_index, high);
	}
}

/**
 * hoare_partition - function that for perttioning
 * @array:- pointer to the array
 * @low:- low limit
 * @high:- higher limit
 * @size:- size of the array
 * Return:- Always 0
 */

int hoare_partition(int *array, int low, int high, size_t size)
{
	int lw = low - 1;
	int hg = high + 1;
	int pivot = array[high];

	while (1)
	{
	do {
		lw++;
	} while (array[lw] < pivot);

	do {
		hg--;
	} while (array[hg] > pivot);

	if (lw >= hg)
		break;

	swapp(array, size, &array[lw], &array[hg]);
	}
	return (lw);
}
