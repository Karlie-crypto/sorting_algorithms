#include "sort.h"

/**
 *swap_nodes - swap current and next node positon
 *@list: cuarrent position of a linked list
 *
 *Return: Nothing it's a void functions
 */
void swap_nodes(listint_t **list)
{
	listint_t *cpy_list, *cmp_node, *save_node;

	cpy_list = *list;
	cmp_node = cpy_list->next;
	save_node = cpy_list->prev;
	cpy_list->next = cmp_node->next;
	cpy_list->prev = cmp_node;
	if (cmp_node->next != NULL)
		cmp_node->next->prev = cpy_list;
	cmp_node->next = cpy_list;
	cmp_node->prev = save_node;
	if (save_node != NULL)
		save_node->next = cmp_node;
}
/**
 *cocktail_sort_list - sort double linked list with cocktail sort
 *@list: double linked list to sort
 *
 *Return: Nothing, it's a void function
 */
void cocktail_sort_list(listint_t **list)
{
	int swap, v_act, v_nxt;
	listint_t *cpy_list;

	cpy_list = *list;
	swap = 0;
	do {
		while (cpy_list->next != NULL)
		{
			v_act = cpy_list->n;
			v_nxt = cpy_list->next->n;
			if (v_act > v_nxt)
			{
				swap_nodes(&cpy_list);
				swap = 1;
				print_list(*list);
			}
			else
				cpy_list = cpy_list->next;
		}
		if (swap == 0)
			break;
		swap = 0;
		while (cpy_list->prev != NULL)
		{
			v_act = cpy_list->n;
			v_nxt = cpy_list->prev->n;
			if (v_act < v_nxt)
			{
				swap_nodes(&(cpy_list->prev));
				swap = 1;
				if (cpy_list->prev == NULL)
					*list = cpy_list;
				print_list(*list);
			}
			else
				cpy_list = cpy_list->prev;
		}
	} while (swap == 1);
}
