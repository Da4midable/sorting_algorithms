#include "sort.h"


/**
 * swap_nodes - Swap two nodes in a doubly linked list.
 * @list: Pointer to the head of the list.
 * @a: Pointer to the first node to swap.
 * @b: Pointer to the second node to swap.
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	listint_t *prev_a = a->prev;
	listint_t *next_a = a->next;
	listint_t *prev_b = b->prev;
	listint_t *next_b = b->next;

	(void)(prev_b);

	if (prev_a)
		prev_a->next = b;
	else
		*list = b;

	if (next_a)
		next_a->prev = b;

	b->prev = prev_a;
	b->next = a;
	a->prev = b;
	a->next = next_b;

	if (next_b)
		next_b->prev = a;
}

/**
 * insertion_sort_list - Sort a doubly linked list of integers using
 * the Insertion sort algorithm.
 * @list: Pointer to the head of the list.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *node, *key;
	int n = 0;

	node = *list;

	while (node)
	{
		n++;
		node = node->next;
	}

	node = *list;

	while (node)
	{
		key = node;
		while (key->prev && key->n < key->prev->n)
		{
			swap_nodes(list, key->prev, key);
			print_list(*list);
		}
		node = node->next;
	}
}
