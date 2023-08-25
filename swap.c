#include "monty.h"

/**
 * f_swap - Function that swaps the top 2 elements of a stack
 *
 * @head: Double pointer to the head of the stack
 * @line_number: Line no. where the instruction is located in the input source
 */
void f_swap(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;
	stack_t *counter = *head;
	int count = 0, temp = 0;

	while (counter != NULL)
	{
		counter = counter->next;
		count++;
	}

	if (count < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	temp = current->n;
	current->n = current->next->n;
	current->next->n = temp;
}
