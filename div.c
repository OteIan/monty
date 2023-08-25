#include "monty.h"

/**
 * f_div - Functions that divides the top two elements of the stack
 *
 * @head: Double pointer to the head of the stack
 * @line_number: Line no. where the instruction is located in the input source
 */
void f_div(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;
	stack_t *counter = *head;
	int div = 0, count = 0;

	while (counter != NULL)
	{
		counter = counter->next;
		count++;
	}

	if (count < 2 && current->n == 0)
	{
		if (count < 2)
			fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		else if (current->n == 0)
			fprintf(stderr, "L%d: division by zero\n", line_number);
		free(bus.content);
		fclose(bus.file);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	div = current->next->n / current->n;
	current->next->n = div;
	*head = current->next;
	free(current);
}
