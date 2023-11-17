#include "main.h"
#include "ext.h"
/**
 * push - to add a new element
 * @stack: the stack
 * @line_number: the number of line
 *
 * Return: Nothing
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;

	(void)line_number;
	if (stack == NULL)
		return;
	new = malloc(sizeof(stack_t *));
	if (new == NULL)
		return;
	new->n = atoi(current_line[1]);
	new->prev = NULL;
	new->next = (*stack);
	if ((*stack) != NULL)
		(*stack)->prev = new;
	(*stack) = new;

}
/**
 * pall - to add a new element
 * @stack: the stack
 * @line_number: the number of line
 *
 * Return: Nothing
 */

void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if ((*stack) == NULL)
		return;
	while ((*stack) != NULL)
	{
		printf("%d\n", (*stack)->n);
		(*stack) = (*stack)->next;
	}
}
