#include "sort.h"
/**
 * insertion_sort_list - Algo for sorting
 * @list: the list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *pointer, *ash, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	ash = (*list)->next;

	while (ash != NULL)
	{
		temp = ash;
		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			pointer = temp->prev;
			if (temp->next != NULL)
				temp->next->prev = pointer;
			if (pointer->prev != NULL)
				pointer->prev->next = temp;
			else
				*list = temp;
			temp->prev = pointer->prev;
			pointer->next = temp->next;
			temp->next = pointer;
			pointer->prev = temp;
			temp = pointer->prev;
			print_list(*list);
		}
		ash = ash->next;
	}
}
