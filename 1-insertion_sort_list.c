#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insert;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		insert = current;
		current = current->next;

		while (insert->prev != NULL && insert->n < insert->prev->n)
		{
			if (insert->next != NULL)
				insert->next->prev = insert->prev;

			insert->prev->next = insert->next;
			insert->next = insert->prev;
			insert->prev = insert->next->prev;
			insert->next->prev = insert;

			if (insert->prev != NULL)
				insert->prev->next = insert;
			else
				*list = insert;

			print_list(*list);
		}
	}
}
