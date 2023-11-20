#include "deck.h"


/**
 * get_index - gets index of card
 *
 * @node: head of the linked list
 *
 * Return: index of card
 */
int get_index(deck_node_t *node)
{
	int index = 0;
	const char *card = node->card->value;
	int kinds[4] = {0, 13, 26, 39};

	if (card[0] == 'A')
		index = 1;
	else if (card[0] == 'J')
		index = 11;
	else if (card[0] == 'Q')
		index = 12;
	else if (card[0] == 'K')
		index = 13;
	else
		index = card[0] - '0' + (card[1] == '\0' ? 0 : 9);

	return (index + kinds[node->card->kind]);
}

/**
 * swap - swaps nodes
 *
 * @head: head of the linked list
 * @node1: first node
 * @node2: second node
 *
 */
void swap(deck_node_t **head, deck_node_t *node1, deck_node_t *node2)
{
	if (node2->next)
		node2->next->prev = node1;
	if (node1->prev)
		node1->prev->next = node2;
	else
		*head = node2;
	node1->next = node2->next;
	node2->next = node1;
	node2->prev = node1->prev;
	node1->prev = node2;
}

/**
 * sort_deck - sorts linked deck in cocktail sort way
 *
 * @deck: ahead of linked list
 *
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *pt;
	int swaps;

	if (!deck || !*deck || !(*deck)->next)
		return;

	while (1)
	{
		swaps = 1;
		for (pt = *deck; pt->next; pt = pt->next)
		{
			if (get_index(pt) > get_index(pt->next))
			{
				swap(deck, pt, pt->next);
				pt = pt->prev;
				swaps = 0;
			}
		}
		if (swaps)
			break;
		for (; pt->prev; pt = pt->prev)
		{
			if (get_index(pt) < get_index(pt->prev))
			{
				swap(deck, pt->prev, pt);
				pt = pt->next;
			}
		}
	}
}
