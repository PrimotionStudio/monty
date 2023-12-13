#include "main.h"

void push(stack_t **stk, unsigned int line_number)
{
	extern char *STACK_NUM;
	stack_t *head, *new;
	char *line;
	int n;

	if (!STACK_NUM || atoi(STACK_NUM) == 0)
	{
		error("L");	
		line = itoa(line_number, 10);
		error(line);
		error(": usage: push integer");
		error("\n");
		exit(EXIT_FAILURE);
	}
	new = (stack_t *)malloc(sizeof(stack_t));
	if (!new)
	{
		error("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	n = atoi(STACK_NUM);
	new->n = n;
	new->next = NULL;
	if (*stk == NULL)
	{
		new->prev = NULL;
		*stk = new;
		return;
	}
	else
	{
		head = *stk;
		while (head->next)
			head = head->next;

		new->prev = head;
		head->next = new;
	}
}

void pall(stack_t **stk, unsigned int line_number)
{
	(void)line_number;
	if (*stk == NULL)
		return;
	pall(&((*stk)->next), line_number);
	printf("%d\n", (*stk)->n);
}
