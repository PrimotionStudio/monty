#include "main.h"

void push(stack_t **stk, unsigned int line_number)
{
	extern char *STACK_NUM;
	stack_t *head, *new;
	char *line;
	int n;

	printf("ABOUT TO PUSH\n");
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
		printf("Added %d to stack\n", (*stk)->n);
		printf("DONE PUSHED\n");
		return;
	}
	else
	{
		head = *stk;
		while (head->next)
			head = head->next;

		new->prev = head;
		head->next = new;
		printf("Added %d to stack\n", (*stk)->n);
		printf("DONE PUSHED\n");
	}
}

void pall(stack_t **stk, unsigned int line_number)
{
	stack_t *head = *stk;

	printf("ABOUT TO PALL\n");
	(void)line_number;
	if (!head)
		return;
	if (head->next == NULL)
	{
		printf("%d\n", head->n);
		return;
	}
	/** Trasverse forward first */
	while (head->next)
		head = head->next;
	printf("Top of stack %d\n", head->n);
	/** Trasverse backwards now */
	while (head->prev)
	{
		printf("%d\n", head->n);
		head = head->prev;
	}
	printf("DONE PALL\n");
}