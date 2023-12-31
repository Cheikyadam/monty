#include "monty.h"

/**
 * delete_dnodeint_at_index - deleting
 * @head: the list
 * @index: the index of node
 *
 * Return: -1 or 1
 */

void delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	stack_t *p = (*head), *new = NULL;
	unsigned int idx = 1;

	if (head == NULL)
		return;
	if ((*head) == NULL)
		return;
	if (index == 0)
	{
		if ((*head)->next == NULL)
		{
			free((*head));
			(*head) = NULL;
			return;
		}
		new = p;
		(*head) = (*head)->next;
		(*head)->prev = NULL;
		free(new);
		new = NULL;
		return;
	}
	while (p->next != NULL && idx != index)
	{
		p = p->next;
		idx++;
	}
	if (p->next == NULL)
		return;

	new = p->next;
	if (new->next != NULL)
		p->next->prev = p;
	p->next = new->next;
	free(new);
	new = NULL;
}

/**
 * dlistint_len - len
 * @h: the list
 *
 * Return: Number of nodes
 */

size_t dlistint_len(const stack_t *h)
{
	unsigned int size = 0;

	if (h == NULL)
		return (0);
	while (h != NULL)
	{
		size++;
		h = h->next;
	}
	return (size);
}
/**
 * free_s - to free the stack
 * @s: the stack
 *
 * Return: Nothing
 */


void free_s(stack_t **s)
{
	stack_t *current = (*s);

	if (s != NULL)
	{
		if ((*s) != NULL)
		{
			while ((*s) != NULL)
			{
				current = (*s);
				(*s) = (*s)->next;
				free(current);
				current = NULL;

			}
		}
	}
	(*s) = NULL;
}
