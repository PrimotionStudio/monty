#ifndef MAIN
#define MAIN

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1000
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


void error(char *str);
char *itoa(int num, int base);
instruction_t is_cmd_acceptable(char *cmd, int line_number);
void exec_line(char buffer[BUFFER_SIZE], int line_number, stack_t **stk);
void set_stack_value(char *value);
int is_int(const char *str);
void push(stack_t **stk, unsigned int line_number);
void pall(stack_t **stk, unsigned int line_number);
void pint(stack_t **stk, unsigned int line_number);
void pop(stack_t **stk, unsigned int line_number);
void swap(stack_t **stk, unsigned int line_number);
void add(stack_t **stk, unsigned int line_number);
void nop(stack_t **stk, unsigned int line_number);
void sub(stack_t **stk, unsigned int line_number);
void _div(stack_t **stk, unsigned int line_number);
void mul(stack_t **stk, unsigned int line_number);
void mod(stack_t **stk, unsigned int line_number);
void pchar(stack_t **stk, unsigned int line_number);
void pstr(stack_t **stk, unsigned int line_number);
void rotl(stack_t **stk, unsigned int line_number);

#endif
