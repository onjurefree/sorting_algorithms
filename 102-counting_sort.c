#include "sort.h"

void value_not(int *array, int size);
int get_maxim(int *array, size_t size);

/**
 * counting_sort - function for sorting array
 * @array:- pointer to the array
 * @size:- size of the array
 * Return:- Always 0
 */

void counting_sort(int *array, size_t size)
{
	size_t k;
	int s, h;
	int *scurrent, *addcurrent, *srting;

	s = get_maxim(array, size);

	if (s == 0)
		return;

	scurrent = malloc(sizeof(int) * (s + 1));
	addcurrent = malloc(sizeof(int) * (s + 1));
	srting = malloc(sizeof(int) * size);

	if (scurrent == NULL || addcurrent == NULL || srting == NULL)
		return;

	value_not(scurrent, (s + 1));

	for (k = 0; k < size; k++)
		scurrent[array[k]] += 1;

	value_not(addcurrent, (s + 1));
	addcurrent[0] = scurrent[0];

	for (h = 1; h < (s + 1); h++)
		addcurrent[h] = scurrent[h] + addcurrent[h - 1];

	print_array(addcurrent, (s + 1));

	value_not(srting, size);

	for (k = 0; k < size; k++)
	{
		addcurrent[array[k]] -= 1;
		srting[addcurrent[array[k]]] = array[k];
	}

	for (k = 0; k < size; k++)
	{
		array[k] = srting[k];
	}

	free(addcurrent);
	free(scurrent);
	free(srting);

}

/**
 * value_not - function for checking if value is 0
 * @array:- pointer to the array
 * @size:- size of the array
 * Return:- Always 0
 */

void value_not(int *array, int size)
{
	int j = 0;

	for (; j < size; j++)
		array[j] = 0;
}

/**
 * get_maxim - function that gets the maxim number
 * @array:- pointer to the array
 * @size:- size of the array
 * Return:- Always 0
 */

int get_maxim(int *array, size_t size)
{
	int largest;
	size_t j = 0;

	if (size < 2)
		return (0);

	largest = array[0];

	for (; j < size; j++)
	{
		if (largest < array[j])
		{
			largest = array[j];
		}
	}

	return (largest);

}
