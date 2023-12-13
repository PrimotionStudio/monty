#include "monty.h"

void mod(stack_t **stk, unsigned int line_number)
{
	stack_t *head = *stk;
	char *line;

	(void)line_number;
	if (head == NULL || head->next == NULL)
	{
		error("L");	
		line = itoa(line_number, 10);
		error(line);
		error(":can't mod, stack too short");
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
	head->prev->n = head->prev->n % head->n;
	pop(stk, line_number);
	return;
}

void pchar(stack_t **stk, unsigned int line_number)
{
	stack_t *head = *stk;
	char *line;

	(void)line_number;
	if (head == NULL)
	{
		error("L");	
		line = itoa(line_number, 10);
		error(line);
		error(":can't pchar, stack empty");
		error("\n");
		exit(EXIT_FAILURE);
	}
	if (head->next == NULL)
	{
		if ((head->n >= 65 && head->n <= 90) || (head->n >= 97 && head->n <= 122))
		{
			printf("%c\n", (char)head->n);
			return;
		}
		else
		{
			error("L");
			line = itoa(line_number, 10);
			error(line);
			error(":can't pchar, value out of range");
			error("\n");
			exit(EXIT_FAILURE);
		}
	}
	while (head->next != NULL)
		head = head->next;

	if ((head->n >= 65 && head->n <= 90) || (head->n >= 97 && head->n <= 122))
		printf("%c\n", (char)head->n);
	else
	{
		error("L");
		line = itoa(line_number, 10);
		error(line);
		error(":can't pchar, value out of range");
		error("\n");
		exit(EXIT_FAILURE);
	}
}

void pstr(stack_t **stk, unsigned int line_number)
{
	stack_t *head = *stk;

	(void)line_number;
	if (head == NULL)
	{
		printf("\n");
		return;
	}
	if (head->next == NULL)
	{
		if ((head->n >= 65 && head->n <= 90) || (head->n >= 97 && head->n <= 122))
			printf("%c\n", (char)head->n);
		return;
	}
	while (head->next != NULL)
		head = head->next;
	while (head->prev != NULL)
	{
		if (head->n > 0 && head->n <= 127)
			printf("%c", (char)head->n);
		else
		{
			printf("\n");
			return;
		}
		head = head->prev;
	}
	printf("\n");
	return;
}

int is_int(const char *str)
{
	if (*str == '\0')
		return (0);
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}


void rotl(stack_t **stk, unsigned int line_number)
{
	stack_t *head = *stk;
	char *line;

	(void)line_number;
	if (head == NULL || head->next == NULL)
	{
		error("L");	
		line = itoa(line_number, 10);
		error(line);
		error(":can't rotl, stack too short");
		error("\n");
		exit(EXIT_FAILURE);
	}
	while (head->next != NULL)
		head = head->next;
	head->next = *stk;
	(*stk)->prev = head;
	head->prev->next = NULL;
	head->prev = NULL;
	*stk = head;
	return;
}
