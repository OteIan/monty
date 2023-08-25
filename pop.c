#include "monty.h"

/**
 * f_pop - Removes the top element of the stack
 *
 * @head: Double pointer to the head node of the stack
 * @line_number: Line no. where the instruction is located in the input source
 */
void f_pop(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;

	if (current == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	*head = current->next;
	free(current);
}
