#include "sort.h"


/**
 * swap - swaps nodes
 *
 * @head: head of the linked list
 * @node1: first node
 * @node2: second node
 *
 */
void swap(listint_t **head, listint_t *node1, listint_t *node2)
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
	print_list(*head);
}

/**
 * cocktail_sort_list - sorts linked in cocktail sort way
 *
 * @list: ahead of linked list
 *
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *pt;
	int swaps;

	if (!list || !*list || !(*list)->next)
		return;

	while (1)
	{
		swaps = 1;
		for (pt = *list; pt->next; pt = pt->next)
		{
			if (pt->n > pt->next->n)
			{
				swap(list, pt, pt->next);
				pt = pt->prev;
				swaps = 0;
			}
		}
		if (swaps)
			break;
		for (; pt->prev; pt = pt->prev)
		{
			if (pt->n < pt->prev->n)
			{
				swap(list, pt->prev, pt);
				pt = pt->next;
			}
		}
	}
}
