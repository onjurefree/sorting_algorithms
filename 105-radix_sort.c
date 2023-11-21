#include "sort.h"

int getting_maxim(int *array, size_t size);
void count_sort(int *array, size_t size, int p);

/**
 * radix_sort - function that sorts ints using redix sort algorith
 * @array:- the array to sort
 * @size:- size of the array
 * Return:- Always 0
 */

void radix_sort(int *array, size_t size)
{
	int p;
	int maxim;

	if (size < 2)
		return;

	maxim = getting_maxim(array, size);

	for (p = 1; (maxim / p) > 0; p *= 10)
	{
		count_sort(array, size, p);
		print_array(array, size);
	}
}

/**
 * count_sort - function that counts sort
 * @array:- array to sort
 * @size:- size of the array
 * @p:- the exponent of least significant digit
 * Return:- Always 0
 */

void count_sort(int *array, size_t size, int p)
{
	int *results = malloc(size * sizeof(int));
	size_t j;
	int f;
	int z;
	size_t k;
	int total[10] = {0};

	if (results == NULL)
		exit(EXIT_FAILURE);


	for (j = 0; j < size; j++)
	{
		total[(array[j] / p) % 10]++;
	}

	for (f = 1; f < 10; f++)
	{
		total[f] += total[f - 1];
	}

	for (z =  (int)size - 1; z >= 0; z--)
	{
		results[total[(array[z] / p) % 10] - 1] = array[z];
		total[(array[z] / p) % 10]--;
	}

	for (k = 0; k < size; k++)
	{
		array[k] = results[k];
	}

	free(results);
}

/**
 * getting_maxim - this function finds the maxim element in the array
 * @array:- the array to search
 * @size:- size of array
 * Return:- Always 0
 */

int getting_maxim(int *array, size_t size)
{
	int h;
	int largest = array[0];

	for (h = 1; h < (int)size; h++)
	{
		if (array[h] > largest)
		{
			largest = array[h];
		}
	}

	return (largest);
}
