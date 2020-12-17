#include "lists.h"

/**
 * insert_node - Inserts a number into a sorted singly linked list
 * @head: pointer to the head of the singly linked list
 * @number: the given integer number
 *
 * Return: A pointer to the new node, NULL otherwise
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *tmp;
	listint_t *cursor = *head;

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);
	new->n = number;
	if (*head == NULL)
	{
		new->next = NULL;
		*head = new;
		return (new);
	}
	if (number < (*head)->n)
	{
		new->next = (*head);
		(*head) = new;
		return (new);
	}
	while (cursor->next && number >= cursor->next->n)
		cursor = cursor->next;
	tmp = cursor->next;
	cursor->next = new;
	new->next = tmp;
	return (new);
}
