#include "sort.h"

/**
 * swap_left - swap two nodes left right position
 * @list: list
 * Return: NULL
 **/
void swap_left(listint_t *list)
{
	listint_t *tmp, *head;

	while (list->prev != NULL)
	{
		if (list->n < list->prev->n)
		{
			tmp = list->prev->prev;
			list->prev->next = list->next;
			list->next = list->prev;
			list->prev->prev = list;
			list->prev = tmp;
			list->next->next->prev = list->next;
			if (tmp != NULL)
				tmp->next = list;
			head = list;
			while (head->prev != NULL)
				head = head->prev;
			print_list(head);
		}
		else
			list = list->prev;
	}
}

/**
 * swap_right - swap two nodes left right position
 * @l: list
 * Return: Null
 **/
void swap_right(listint_t *l)
{
	listint_t *tmp, *head;

	tmp = l->prev;
	if (tmp != NULL)
	{
		tmp->next = l->next;
		l->next->prev = tmp;
	}
	else
		l->next->prev = NULL;
	l->prev = l->next;
	if (l->next->next != NULL)
	{
		l->next = l->next->next;
		l->prev->next = l;
		l->next->prev = l;
	}
	else
	{
		l->next->next = l;
		l->next = NULL;
	}
	head = l;
	while (head->prev != NULL)
		head = head->prev;
	print_list(head);
	swap_left(l->prev);
}

/**
 * insertion_sort_list - sorts a doubly linked list in ascending order
 * @list: list
 * Return: NULL
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current_node;

	if ((list == NULL) || (*list == NULL) || ((*list)->next == NULL))
		return;
	current_node = *list;
	while (current_node->next != NULL)
	{
		if (current_node->n > current_node->next->n)
		{
			swap_right(current_node);
		}
		else
			current_node = current_node->next;
	}
	while ((*list)->prev != NULL)
		*list = (*list)->prev;
}
