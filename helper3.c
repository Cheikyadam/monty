#include "main.h"

/**
 * pop - to add a new element
 * @stack: the stack
 * @line_number: the number of line
 *
 * Return: Nothing
 */

void pop(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if ((*stack) == NULL)
		return;
	delete_dnodeint_at_index(stack, 0);
}

/**
 * swap - to add a new element
 * @stack: the stack
 * @line_number: the number of line
 *
 * Return: Nothing
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int c;

	(void)line_number;
	if ((*stack) == NULL)
		return;
	c = (*stack)->n;
	if ((*stack)->next == NULL)
		return;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = c;
}

/**
 * add - to add a new element
 * @stack: the stack
 * @line_number: the number of line
 *
 * Return: Nothing
 */

void add(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if ((*stack) == NULL)
		return;
	if ((*stack)->next == NULL)
		return;
	(*stack)->n = (*stack)->next->n + (*stack)->n;
}
