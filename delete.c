#include "main.h"

/**
 * delete_dnodeint_at_index - deleting
 * @head: the list
 * @index: the index of node
 *
 * Return: -1 or 1
 */

int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	stack_t *p = (*head), *new = NULL;
	unsigned int idx = 1;

	if (head == NULL)
		return (-1);
	if ((*head) == NULL)
		return (-1);
	if (index == 0)
	{
		if ((*head)->next == NULL)
		{
			free((*head));
			(*head) = NULL;
			return (1);
		}
		new = p;
		(*head) = (*head)->next;
		(*head)->prev = NULL;
		free(new);
		new = NULL;
		return (1);
	}
	while (p->next != NULL && idx != index)
	{
		p = p->next;
		idx++;
	}
	if (p->next == NULL)
		return (-1);

	new = p->next;
	if (new->next != NULL)
		p->next->prev = p;
	p->next = new->next;
	free(new);
	new = NULL;
	return (1);
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

void free_s(stack_t *s)
{
	unsigned int size = 0, i;

	if (s != NULL)
	{
		size = dlistint_len(s);
		for (i = 0; i < size; i++)
		{
			delete_dnodeint_at_index(&s, i);
		}
	}
}
