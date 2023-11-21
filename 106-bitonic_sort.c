#include "sort.h"

static void swapp(int *array, size_t s, size_t y);
static void bitonic_sequnce_recursive(int *array, size_t size, int direction);
static void bitonic_merge(int *array, size_t size, int direction);
static void print_seq(int *array, size_t ll, size_t ul, int bond, size_t size);

/**
 * print_seq - function that prints the sequence
 * @ll:- lower limit
 * @array:- pointer to the array
 * @ul:- upper limit
 * @size:- size of the array
 * @bond:- merge direction
 * Return:- Always 0
 */

static void print_seq(int *array, size_t ll, size_t ul, int bond, size_t size)
{
	size_t i;
	char *dir = bond ? "UP" : "DOWN";

	printf("Merging [%ld/%ld] (%s):\n", ul - ll + 1, size, dir);

	for (i = ll; i < ul; i++)
	{
		printf("%d", array[i]);
		if (i != ul)
			printf(", ");
	}

	printf("\n");

}

/**
 * bitonic_merge - function for merging the halfs
 * @array:- pointer to array
 * @size:- size of the array
 * @direction:- direction of merge
 * Return:- Always 0
 */

static void bitonic_merge(int *array, size_t size, int direction)
{
	if (size > 1)
	{
		size_t j;
		size_t s = size / 2;

		print_seq(array, 0, size - 1, direction, size);

		for (j = 0; j < s; j++)
		{
			if ((array[j] > array[j + s]) == direction)
			{
				swapp(array, j, j + s);

				printf("%d, %d\n", array[j], array[j + s]);

			}
		}

		bitonic_merge(array, s, direction);
		bitonic_merge(array + s, s, direction);
	}
}

/**
 * bitonic_sequnce_recursive - function for making the sequence
 * @array:- pointer to the array
 * @size:- size of the array
 * @direction:- reirection of the sequence
 * Return:- Always 0
 */

static void bitonic_sequnce_recursive(int *array, size_t size, int direction)
{
	if (size > 1)
	{
		size_t s = size / 2;

		bitonic_sequnce_recursive(array, s, 1);
		bitonic_sequnce_recursive(array + s, s, 0);

		bitonic_merge(array, size, direction);
	}
}

/**
 * bitonic_sort - fonction for sorting using bitinic sort
 * @array:- array to sort
 * @size:- size of the array
 * Return:- Always 0
 */

void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
	{
		return;
	}

	bitonic_sequnce_recursive(array, size, 1);
}

/**
 * swapp - function for swapping the elements
 * @array:- pointer to the array
 * @s:- first element
 * @y:- second element
 * Return:- Always 0
 */

static void swapp(int *array, size_t s, size_t y)
{
	int tmp = array[s];

	array[s] = array[y];
	array[y] = tmp;
}
