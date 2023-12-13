#include "monty.h"

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
		error(":can't add, stack too short");
		error("\n");
		exit(EXIT_FAILURE);
	}
	while (head->next != NULL)
		head = head->next;
	head->prev->n += head->n;
	pop(stk, line_number);
	return;
}

void nop(stack_t **stk, unsigned int line_number)
{
	(void)stk, (void)line_number;
}


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
		error(":can't sub, stack too short");
		error("\n");
		exit(EXIT_FAILURE);
	}
	while (head->next != NULL)
		head = head->next;
	head->prev->n -= head->n;
	pop(stk, line_number);
	return;
}

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
		error(":can't div, stack too short");
		error("\n");
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
		exit(EXIT_FAILURE);
	}
	head->prev->n = head->prev->n / head->n;
	pop(stk, line_number);
	return;
}

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
		error(":can't mul, stack too short");
		error("\n");
		exit(EXIT_FAILURE);
	}
	while (head->next != NULL)
		head = head->next;
	head->prev->n = head->prev->n * head->n;
	pop(stk, line_number);
	return;
}
