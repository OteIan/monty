#include "monty.h"

/**
 * f_mul - Functions that multiplies the top two elements of the stack
 *
 * @head: Double pointer to the head of the stack
 * @line_number: Line no. where the instruction is located in the input source
 */
void f_mul(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;
	stack_t *counter = *head;
	int product = 0, count = 0;

	while (counter != NULL)
	{
		counter = counter->next;
		count++;
	}

	if (count < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free(bus.content);
		fclose(bus.file);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	product = current->n + current->next->n;
	current->next->n = product;
	*head = current->next;
	free(current);
}
