#include "monty.h"

char **line = NULL;

/**
 * next_main1 - helper main
 * @code: the code
 *
 * Return: Nothing
 */

void next_main1(char *code)
{

	instruction_t instructions[7] = {
		{"push", push},
		{"pall", pall},
		{"pop", pop},
		{"pint", pint},
		{"nop", nop},
		{"swap", swap},
		{"add", add}
	};
	next_main2(code, instructions);
}
/**
 * next_main2 - continuation of next function
 * @code: the contain of opcode file
 * @instructions: instructions in opcode
 *
 * Return: Nothing
 */
void next_main2(char *code, instruction_t instructions[7])
{
	const char d[] = "\n";

	if (code[0] == '\0')
	{
		free_c(code);
		error("unknown instruction", 1, NULL, NULL);
	}
	line = str_splt(code, d);
	free_c(code);
	if (line == NULL)
		error_m();

	next_main3(line, instructions);
	free_p(line);
}

/**
 * next_main3 - main
 * @line: the line
 * @instructions: instructions
 *
 * Return: Nothing
 */
void next_main3(char **line, instruction_t instructions[7])
{

	int i = 0, in = 0;
	char **current_code = NULL;
	size_t j = 0;
	stack_t *stack = NULL;

	while (line[i] != NULL)
	{
		if (line[i][0] == '\0')
		{
			i++;
			continue;
		}
		in = 0;
		delete_letter(line[i], " ");
		current_code = str_splt(line[i], " ");
		for (j = 0; j < 8; j++)
		{
			if (_strcmp(current_code[0], instructions[j].opcode) == 0)
			{
				in = 1;
				free_p(current_code);
				instructions[j].f((&stack), (i + 1));
				break;
			}

		}
		if (in == 0)
		{
			free_p(current_code);
			error_i(i + 1, (stack));
		}
		i++;
	}
	free_s(&stack);
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
		error_m();
	r = read(fd, code, nb);
	if (r > 0)
	{
		code[r - 1] = '\0';
	}
	close(fd);
	next_main1(code);
	return (0);

}
