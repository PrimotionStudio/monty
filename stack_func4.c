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
