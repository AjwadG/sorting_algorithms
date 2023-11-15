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

	if (!list || !*list)
		return;

	for (ptr = *list; ptr->next; ptr = ptr->next)
	{
		pt = ptr->next;
		if (pt->n < pt->prev->n)
			ptr = ptr->prev;
		while (pt->prev && pt->n < pt->prev->n)
		{
			curent = pt;
			prev = pt->prev;
			if (curent->next)
				curent->next->prev = prev;
			prev->next = curent->next, curent->next = prev;
			if (prev->prev)
				prev->prev->next = curent;
			else
				*list = curent;
			curent->prev = prev->prev, prev->prev = curent;

			print_list(*list);
		}
	}
}
