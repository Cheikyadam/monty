#include "monty.h"

/**
 * error_m - handle malloc failed error
 *
 * Return: Nothing
 */

void error_m(void)
{
	free_p(line);
	write(STDERR_FILENO, "Error: malloc failed\n",
			_strlen("Error: malloc failed\n"));
	exit(EXIT_FAILURE);
}

/**
 * error_i - errors
 * @c_line: the line
 * @s: the stack
 *
 * Return: Nothing
 */

void error_i(int c_line, stack_t *s)
{
	char **current = str_splt(line[c_line - 1], " ");

	fprintf(stderr, "L%d: unknown instruction %s\n",
			c_line, current[0]);
	free_p(current);
	free_p(line);
	free_s(&s);
	exit(EXIT_FAILURE);
}

/**
 * error - errors
 * @msg: error message
 * @c_line: the line
 * @current_line: the current code
 * @s: the stack
 *
 * Return: Nothing
 */

void error(char *msg, int c_line, char **current_line, stack_t *s)
{
	free_p(current_line);
	free_s(&s);
	free_p(line);
	fprintf(stderr, "L%d: %s", c_line, msg);
	exit(EXIT_FAILURE);
}
