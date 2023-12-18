#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Double pointer to the head of the doubly linked list
 * @node: Pointer to the node to swap with its next node
 */
void swap_nodes(listint_t **list, listint_t *node)
{
	listint_t *tmp = node->next;

	if (node->prev)
		node->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = node->prev;
	node->next = tmp->next;
	if (tmp->next)
		tmp->next->prev = node;
	tmp->next = node;
	node->prev = tmp;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 * @list: Double pointer to the head of the doubly linked list
 */

void cocktail_sort_list(listint_t **list)
{
	char swapped = 1;
	listint_t *node = *list;

	if (!list || !*list || !(*list)->next)
		return;

	while (swapped)
	{
		swapped = 0;
		while (node && node->next)
		{
			if (node->n > node->next->n)
			{
				swap_nodes(list, node);
				print_list((const listint_t *)*list);
				swapped = 1;
			}
			else
				node = node->next;
		}
		if (!swapped)
			break;
		swapped = 0;
		while (node && node->prev)
		{
			if (node->prev->n > node->n)
			{
				swap_nodes(list, node->prev);
				print_list((const listint_t *)*list);
				swapped = 1;
			}
			else
				node = node->prev;
		}
	}
}
