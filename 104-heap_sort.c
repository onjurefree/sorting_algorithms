#include "sort.h"

void shifting_down(int *array, size_t st, size_t ed, size_t size);
void swapping(int *a, int *b);

/**
 * heap_sort - function that sorts array using heap sort
 * @array:- pointer to the array
 * @size:- size of the array
 * Return:- Always 0
 */

void heap_sort(int *array, size_t size)
{
	int k;
	int h;

	if (!array || size < 2)
		return;

	for (k = (size - 1) / 2; k >= 0; k--)
	{
		shifting_down(array, k, size - 1, size);
	}

	for (h = size - 1; h > 0; h--)
	{
		swapping(&array[0], &array[h]);
		shifting_down(array, 0, h - 1, size);
		print_array(array, size);
	}
}

/**
 * shifting_down - function that shifts the elements
 * @array:- pointer to the array
 * @st:- start os the array
 * @ed:- end of the array
 * @size:- size of the array
 * Return:- Always 0
 */

void shifting_down(int *array, size_t st, size_t ed, size_t size)
{
	size_t chd;
	size_t swapping_id;
	size_t rt = st;

	while ((2 * rt + 1) <= ed)
	{
		chd = 2 * rt + 1;
		swapping_id = rt;

		if (array[swapping_id] < array[chd])
			swapping_id = chd;

		if (chd + 1 <= ed && array[swapping_id] < array[chd + 1])
			swapping_id = chd + 1;

		if (swapping_id == rt)
			return;

		swapping(&array[rt], &array[swapping_id]);
		print_array(array, size);
		rt = swapping_id;
	}
}

/**
 * swapping - function that swaps elements
 * @a:- first element
 * @b:- second element
 * Return:- Always 0
 */

void swapping(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
