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

extern char **line;

char *_strcpy(char *dest, char *src);
size_t letters_f(const char *file);
int _strlen(char *s);
char **str_splt(char *ch, const char d[]);
void free_p(char **a);
void free_c(char *s);
int _strcmp(char *s1, char *s2);
void delete_letter(char *s, const char d[]);
void free_s(stack_t **s);
void delete_dnodeint_at_index(stack_t **head, unsigned int index);

void next_main1(char *code);
void next_main2(char *code, instruction_t instructions[7]);
void next_main3(char **line, instruction_t instructions[7]);

void error_m(void);
void error(char *msg, int c_line, char **current_line, stack_t *s);
void error_i(int c_line, stack_t *s);

void add(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);

#endif
