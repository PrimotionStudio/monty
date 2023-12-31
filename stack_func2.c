#include "monty.h"

/**
 * add - Adds the top two elements of the stack
 * @stk: A pointer to the head of the stack
 * @line_number: The line number in the Monty bytecode file
 */
void add(stack_t **stk, unsigned int line_number)
{
	stack_t *head = *stk;
	char *line;

	(void)line_number;
	if (head == NULL || head->next == NULL)
	{
		error("L");	
		line = itoa(line_number, 10);
		error(line);
		error(": can't add, stack too short");
		error("\n");
		free(line);
		exit(EXIT_FAILURE);
	}
	while (head->next != NULL)
		head = head->next;
	head->prev->n += head->n;
	pop(stk, line_number);
	return;
}

/**
 * nop - Does nothing
 * @stk: A pointer to the head of the stack
 * @line_number: The line number in the Monty bytecode file
 */
void nop(stack_t **stk, unsigned int line_number)
{
	(void)stk, (void)line_number;
}

/**
 * sub - Subtracts the top element of the stack from the second top element
 * @stk: A pointer to the head of the stack
 * @line_number: The line number in the Monty bytecode file
 */
void sub(stack_t **stk, unsigned int line_number)
{
	stack_t *head = *stk;
	char *line;

	(void)line_number;
	if (head == NULL || head->next == NULL)
	{
		error("L");	
		line = itoa(line_number, 10);
		error(line);
		error(": can't sub, stack too short");
		error("\n");
		free(line);
		exit(EXIT_FAILURE);
	}
	while (head->next != NULL)
		head = head->next;
	head->prev->n -= head->n;
	pop(stk, line_number);
	return;
}

/**
 * _div - Divides the second top element of the stack by the top element
 * @stk: A pointer to the head of the stack
 * @line_number: The line number in the Monty bytecode file
 */
void _div(stack_t **stk, unsigned int line_number)
{
	stack_t *head = *stk;
	char *line;

	(void)line_number;
	if (head == NULL || head->next == NULL)
	{
		error("L");	
		line = itoa(line_number, 10);
		error(line);
		error(": can't div, stack too short");
		error("\n");
		free(line);
		exit(EXIT_FAILURE);
	}
	while (head->next != NULL)
		head = head->next;
	if (head->n == 0)
	{
		error("L");	
		line = itoa(line_number, 10);
		error(line);
		error(": division by zero");
		error("\n");
		free(line);
		exit(EXIT_FAILURE);
	}
	head->prev->n = head->prev->n / head->n;
	pop(stk, line_number);
	return;
}

/**
 * mul - Multiplies the second top element of the stack by the top element
 * @stk: A pointer to the head of the stack
 * @line_number: The line number in the Monty bytecode file
 */
void mul(stack_t **stk, unsigned int line_number)
{
	stack_t *head = *stk;
	char *line;

	(void)line_number;
	if (head == NULL || head->next == NULL)
	{
		error("L");	
		line = itoa(line_number, 10);
		error(line);
		error(": can't mul, stack too short");
		error("\n");
		free(line);
		exit(EXIT_FAILURE);
	}
	while (head->next != NULL)
		head = head->next;
	head->prev->n = head->prev->n * head->n;
	pop(stk, line_number);
	return;
}
