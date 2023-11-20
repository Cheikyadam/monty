#include "monty.h"
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
	char **current_line = NULL;
	int number;
	const char d[] = " ";

	current_line = str_splt(line[line_number - 1], d);
	if (stack == NULL || current_line[1] == NULL)
		error("usage: push integer\n", line_number, current_line, (*stack));
	number = atoi(current_line[1]);
	if (number == 0)
	{
		error("usage: push integer\n", line_number, current_line, (*stack));
	}
	free_p(current_line);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		error_m();
	new->n = number;
	new->prev = NULL;
	new->next = (*stack);
	if ((*stack) != NULL)
		(*stack)->prev = new;
	(*stack) = new;
	stack = &(*stack);
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
	stack_t *move = (*stack);

	(void)line_number;
	if ((*stack) == NULL)
		return;
	while ((move) != NULL)
	{
		printf("%d\n", (move)->n);
		(move) = (move)->next;
	}
}

/**
 * nop - to add a new element
 * @stack: the stack
 * @line_number: the number of line
 *
 * Return: Nothing
 */

void nop(stack_t **stack, unsigned int line_number)
{
	char *opc = NULL;

	opc = line[line_number - 1];
	delete_letter(opc, " ");
	if (opc[3] != '\0')
		error_i(line_number, (*stack));
}
/**
 * pint - to add a new element
 * @stack: the stack
 * @line_number: the number of line
 *
 * Return: Nothing
 */

void pint(stack_t **stack, unsigned int line_number)
{

	char *opc = NULL;

	opc = line[line_number - 1];
	delete_letter(opc, " ");
	if (opc[4] != '\0')
		error_i(line_number, (*stack));
	if ((*stack) == NULL)
		return;
	printf("%d\n", (*stack)->n);
}
