#ifndef _HEADER_
#define _HEADER_

#include <stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern char **current_line;
char *_strcpy(char *dest, char *src);
size_t letters_f(const char *file);
int _strlen(char *s);
char **str_splt(char *ch, const char d[]);
void free_p(char **a);
void free_c(char *s);
int _strcmp(char *s1, char *s2);
void delete_letter(char *s, const char d[]);
void free_s(stack_t *s);

void pint(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);

#endif
