#include "sort.h"

void swapping_ele(listint_t **list, listint_t *a, listint_t *b);

/**
 * cocktail_sort_list - function for sorting using cocktail sort
 * @list:- pointer to the list to sort
 * Return:- Always 0
 */

void cocktail_sort_list(listint_t **list)
{
	int s = 1;
	listint_t *ft;

	if (list == NULL || (*list) == NULL || !(*list)->next)
		return;

	ft = *list;

	while (s)
	{
		s = 0;
		while (ft->next)
		{
			if (ft->n > ft->next->n)
			{
				swapping_ele(list, ft, ft->next);
				print_list(*list);
				s = 1;
				
				continue;
			}

			ft = ft->next;
		}
		if (!s)
			break;
		s = 0;
		while (ft->prev)
		{
			if (ft->n < ft->prev->n)
			{
				swapping_ele(list, ft->prev, ft);
				print_list(*list);
				s = 1;

				continue;
			}

			ft = ft->prev;
		}
	}
}

/**
 * swapping_ele - function that swaps elements
 * @list:- double pointer to the list
 * @a:- element one
 * @b:- element two
 * Return:- Always 0
 */

void swapping_ele(listint_t **list, listint_t *a, listint_t *b)
{
	if ((a->prev) == NULL)
		*list = b;
	else
	{
		a->prev->next = b;
	}

	b->prev = a->prev;

	if (b->next)
	{
		b->next->prev = a;
	}

	a->prev = b;
	a->next = b->next;
	b->next = a;
}
