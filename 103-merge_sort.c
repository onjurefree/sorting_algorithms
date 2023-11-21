#include "sort.h"

void printing_subarray(const char *sid, int *array, int siz);
void merge_all(int *array, int *lft, int lft_sid, int *rght, int rght_sid);
void reculse_merge_sort(int *array, int size);

/**
 * merge_sort - function that sorts array using merge sort
 * @array:- array to sort
 * @size:- size of the array
 * Return:- Always 0
 */

void merge_sort(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return;

	reculse_merge_sort(array, size);
}

/**
 * reculse_merge_sort - function that merges every half
 * @array:- pointer to the array
 * @size:- size of the array
 * Return:- Always 0
 */

void reculse_merge_sort(int *array, int size)
{
	int middle = size / 2;
	int lft_sid = middle;
	int rght_sid = size - middle;

	int *lft = array;
	int *rght = array + lft_sid;

	if (size <= 1)
		return;

	reculse_merge_sort(lft, lft_sid);
	reculse_merge_sort(rght, rght_sid);
	merge_all(array, lft, lft_sid, rght, rght_sid);
}

/**
 * merge_all - function that merges the sorted halfs
 * @lft:- left half
 * @lft_sid:- start of left half
 * @rght:- right half
 * @rght_sid:- start of right half
 * @array:- the array to sort
 * Return:- Always 0
 */

void merge_all(int *array, int *lft, int lft_sid, int *rght, int rght_sid)
{
	int j = 0;
	int m = 0;
	int f = 0;
	int index;
	int *array_tmp = malloc((lft_sid + rght_sid) * sizeof(int));

	printf("Merging...\n");
	printing_subarray("left", lft, lft_sid);
	printing_subarray("right", rght, rght_sid);

	if (!array_tmp)
		exit(EXIT_FAILURE);

	while (j < lft_sid && m < rght_sid)
	{
		if (lft[j] < rght[m])
		{
			array_tmp[f] = lft[j];
			j++;
		}
		else
		{
			array_tmp[f] = rght[m];
			m++;
		}
		f++;
	}

	while (j < lft_sid)
	{
		array_tmp[f] = lft[j];
		j++;
		f++;
	}

	while (m < rght_sid)
	{
		array_tmp[f] = rght[m];
		m++;
		f++;
	}

	for (index = 0; index < (lft_sid + rght_sid); index++)
		array[index] = array_tmp[index];

	free(array_tmp);

	printf("[Done]: ");
	print_array(array, lft_sid + rght_sid);

}

/**
 * printing_subarray - function that prints the sorted halfs
 * @sid:- side to print
 * @siz:- side to print
 * @array:- half of the array
 * Return:- Always 0
 */

void printing_subarray(const char *sid, int *array, int siz)
{
	printf("[%s]: ", sid);
	print_array(array, siz);
}
