#include "sort.h"


/**
 * insertion_sort_list - sorts linked in insertion sort way
 *
 * @list: ahead of linked list
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *ptr, *pt, *curent, *prev;

	if (!list || !*list || !(*list)->next)
		return;

	for (ptr = (*list)->next; ptr; ptr = ptr->next)
	{
		pt = ptr;
		while (pt->prev && pt->n < pt->prev->n)
		{
			curent = pt;
			prev = pt->prev, prev->next = curent->next;

			if (curent->next)
				curent->next->prev = prev;

			curent->next = prev, curent->prev = prev->prev;
			prev->prev = curent;

			if (curent->prev)
				curent->prev->next = curent;
			else
				*list = curent;

			print_list(*list);
		}
	}
}
