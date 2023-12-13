#include "monty.h"

void push(stack_t **stk, unsigned int line_number)
{
	extern char *STACK_NUM;
	stack_t *head, *new;
	char *line;
	int n;

	if (!STACK_NUM || !is_int(STACK_NUM))
	{
		error("L");	
		line = itoa(line_number, 10);
		error(line);
		error(": usage: push integer");
		error("\n");
		exit(EXIT_FAILURE);
	}
	/**if (!STACK_NUM || atoi(STACK_NUM) == 0)
	  {
	  error("L");	
	  line = itoa(line_number, 10);
	  error(line);
	  error(": usage: push integer");
	  error("\n");
	  exit(EXIT_FAILURE);
	  }*/
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
	stack_t *head = *stk;
	(void)line_number;

	if (head == NULL)
		return;
	pall(&(head->next), line_number);
	printf("%d\n", head->n);
}

void pint(stack_t **stk, unsigned int line_number)
{
	stack_t *head = *stk;
	char *line;

	(void)line_number;
	if (head == NULL)
	{
		error("L");	
		line = itoa(line_number, 10);
		error(line);
		error(": can't pint, stack empty");
		error("\n");
		exit(EXIT_FAILURE);
	}
	if (head->next == NULL)
	{
		printf("%d\n", head->n);
		return;
	}
	while (head->next != NULL)
		head = head->next;
	printf("%d\n", head->n);
	return;
}
void pop(stack_t **stk, unsigned int line_number)
{
	stack_t *head = *stk;
	char *line;

	(void)line_number;
	if (head == NULL)
	{
		error("L");	
		line = itoa(line_number, 10);
		error(line);
		error(": can't pop an stack empty");
		error("\n");
		exit(EXIT_FAILURE);
	}
	if (head->next == NULL)
	{
		free(head);
		*stk = NULL;
		return;
	}
	while (head->next != NULL)
		head = head->next;
	head->prev->next = NULL;
	free(head);
	return;
}

void swap(stack_t **stk, unsigned int line_number)
{
	stack_t *head = *stk;
	char *line;
	int tmp;

	(void)line_number;
	if (head == NULL || head->next == NULL)
	{
		error("L");	
		line = itoa(line_number, 10);
		error(line);
		error(":can't swap, stack too short");
		error("\n");
		exit(EXIT_FAILURE);
	}
	while (head->next != NULL)
		head = head->next;
	tmp = head->n;
	head->n = head->prev->n;
	head->prev->n = tmp;
	return;
}
