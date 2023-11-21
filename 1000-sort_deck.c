#include "deck.h"

int compare_cards(const card_t *card1, const card_t *card2);
void swap_nodes(deck_node_t **deck, deck_node_t *node1, deck_node_t *node2);

/**
 * sort_deck - functions that sorts card
 * @deck:- double pointer to the deck
 * Return:- Always 0
 */

void sort_deck(deck_node_t **deck)
{
	deck_node_t *inner;
	deck_node_t *curr_nod, *min_node;
	card_t *min_card;

	if (*deck == NULL || (*deck)->next == NULL)
		return;

	for (curr_nod = *deck; curr_nod->next != NULL; curr_nod = curr_nod->next)
	{
		min_node = curr_nod;
		min_card = (card_t *)min_node->card;


		for (inner = curr_nod->next; inner != NULL; inner = inner->next)
		{
			card_t *current_card = (card_t *)inner->card;

			if (compare_cards(current_card, min_card) < 0)
			{
				min_node = inner;
				min_card = current_card;
			}
		}

		if (min_node != curr_nod)
			swap_nodes(deck, curr_nod, min_node);
	}

}

/**
 * compare_cards - function that compares card
 * @card1:- card one
 * @card2:- card two
 * Return:- Always 0
 */

int compare_cards(const card_t *card1, const card_t *card2)
{
	int f;
	const char *values[] = {"Ace", "2", "3", "4", "5", "6", "7", "8",
		"9", "10", "Jack", "Queen", "King"};

	if (card1->kind < card2->kind)
	{
		return (-1);
	}

	else if (card1->kind > card2->kind)
	{
		return (1);
	}
	else
	{

		for (f = 0; f < 13; f++)
		{
			if (card1->value == values[f])
				return (-1);
			else if (card2->value == values[f])
				return (1);
		}

		return (0);
	}
}

/**
 * swap_nodes - function that swapps nodes
 * @deck:- double pointer to the deck
 * @node1:- node one
 * @node2:- node two
 * Return:- Always 0
 */

void swap_nodes(deck_node_t **deck, deck_node_t *node1, deck_node_t *node2)
{
	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		*deck = node2;

	if (node2->next != NULL)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}
