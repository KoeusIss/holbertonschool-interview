#include "lists.h"

/**
 * find_listint_loop - Finds the loop in a linked list
 * @head: Pointer to the head of the linked list
 *
 * Return: The address of the loop node, NULL otherwise
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *turtle = head;
	listint_t *harry = head;

	if (!head)
		return (NULL);

	while (harry && harry->next)
	{
		turtle = turtle->next;
		harry = harry->next->next;
		if (turtle == harry)
		{
			turtle = head;
			while (turtle != harry)
			{
				turtle = turtle->next;
				harry = harry->next;
			}
			return (harry);
		}
	}
	return (NULL);
}
