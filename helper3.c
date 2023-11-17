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
