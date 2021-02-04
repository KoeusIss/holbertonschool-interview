#include "lists.h"

/**
 * check_cycle - Checks if a linked list had a list
 * @list: the given list
 *
 * Return: O if no cycle, 1 otherwise
 */
int check_cycle(listint_t *list)
{
	listint_t *harry, *turtle;

	turtle = list;
	harry = list->next;
	while (turtle && harry && harry->next)
	{
		turtle = turtle->next;
		harry = harry->next->next;
		if (turtle == harry)
			return (1);
	}
	return (0);
}
