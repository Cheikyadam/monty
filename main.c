#include "main.h"

char **current_line = NULL;


instruction_t instructions[7] = {
	{"push", push},
	{"pall", pall},
	{"pop", pop},
	{"pint", pint},
	{"nop", nop},
	{"swap", swap},
	{"add", add}
};
/**
 * next_main - continuation of next function
 * @code: the contain of opcode file
 *
 * Return: Nothing
 */
void next_main(char *code)
{
	char **line = NULL;
	int i = 0;
	stack_t *stack = NULL;
	char **current_code = NULL;
	size_t j = 0;

	line = str_splt(code, "\n");
	while (line[i] != NULL)
	{
		delete_letter(line[i], " ");
		current_code = str_splt(line[i], " ");
		current_line = current_code;
		for (j = 0; j < 8; j++)
		{
			if (_strcmp(current_code[0], instructions[j].opcode) == 0)
			{
				instructions[j].f(&stack, (i + 1));
				break;
			}

		}

		i++;
	}
	free_s(stack);
	free_p(current_code);
	free_p(line);


}
/**
 * main - the main function
 * @argc: number of args
 * @argv: the arguments
 *
 * Return: 0
 */

int main(int argc, char **argv)
{
	size_t nb = 0, r;
	int fd;
	char *code = NULL;

	if (argc != 2)
	{
		write(STDERR_FILENO, "USAGE: monty file\n",
				_strlen("USAGE: monty file\n"));
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(STDERR_FILENO, "Error: Can't open file ",
				_strlen("Error: Can't open file "));
		write(STDERR_FILENO, argv[1], _strlen(argv[1]));
		write(STDERR_FILENO, "\n", 1);
		exit(EXIT_FAILURE);
	}
	nb = letters_f(argv[1]);
	code = malloc(nb + 1);
	if (code == NULL)
	{
		write(STDERR_FILENO, "Error: malloc failed\n",
				_strlen("Error: malloc failed\n"));
		exit(EXIT_FAILURE);
	}
	r = read(fd, code, nb);
	if (r > 0)
	{
		code[r - 1] = '\0';
	}
	close(fd);
	next_main(code);
	free_c(code);
	return (0);

}
