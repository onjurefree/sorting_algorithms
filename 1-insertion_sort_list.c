#include "sort.h"


/**
 * insertion_sort_list - function that sorts doubly linked list
 * using insertion sort
 * @list:- double pointer to the doubly linked list
 * Return:- Always 0
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp = NULL, *current = NULL, *before = NULL;

	if (list != NULL && *list != NULL && ((*list)->next) != NULL)
	{
		temp = (*list)->next;

		while (temp != NULL)
		{
			current = temp;
			before = temp->prev;

			while (before != NULL && current->n < before->n)
			{
				before->next = current->next;
				current->prev = before->prev;

				if (current->next)
					current->next->prev = before;
				if (before->prev)
					before->prev->next = current;

				current->next = before;
				before->prev = current;
				if (before == *list)
					*list = current;

				print_list(*list);

				before = current->prev;
			}

			temp = temp->next;
		}
	}
}
