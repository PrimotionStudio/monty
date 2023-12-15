#include "monty.h"

/**
 * free_stk - Frees the memory allocated for a stack
 * @stk: A pointer to the head of the stack
 */
void free_stk(stack_t **stk)
{
	stack_t *cur = (*stk)->next;
	stack_t *tmp;

	if (*stk != NULL && (*stk)->prev != NULL)
	{
		while ((*stk)->prev != NULL)
		{
			tmp = (*stk)->prev;
			(*stk)->prev = NULL;
			(*stk)->next = NULL;
			free(*stk);
			*stk = tmp;
		}
	}

	while (cur != NULL && cur->next != NULL)
	{
		tmp = cur->next;
		cur->prev = NULL;
		cur->next = NULL;
		free(cur);
		cur = tmp;
	}
}

/**
 * rotr - Rotates the stack to the bottom
 * @stk: A pointer to the head of the stack
 * @line_number: The line number in the Monty bytecode file
 */
void rotr(stack_t **stk, unsigned int line_number)
{
	stack_t *head = *stk, *tmp = (*stk)->next;

	(void)line_number;
	if (head == NULL || head->next == NULL)
		return;
	while (head->next != NULL)
		head = head->next;
	(*stk)->next->prev = NULL;
	head->next = *stk;
	(*stk)->next = NULL;
	(*stk)->prev = head;
	*stk = tmp;
	return;
}
