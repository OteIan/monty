#include "monty.h"

/**
 * free_stack - Function that frees a stack
 *
 * @head: Pointer to the head node of the stack
 */
void free_stack(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		if (head != NULL)
			head->prev = NULL;
		free(temp);
	}
}
