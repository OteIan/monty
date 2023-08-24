#include "monty.h"

/**
 * f_mod - Functions that divides the top two elements of the stack
 *
 * @head: Double pointer to the head of the stack
 * @line_number: Line no. where the instruction is located in the input source
*/
void f_mod(stack_t **head, unsigned int line_number)
{
    stack_t *current = *head;
    stack_t *counter = *head;
    int remainder = 0, count = 0;

    while (counter != NULL)
    {
        counter = counter->next;
        count++;
    }

    if (count < 2 && current->n == 0)
    {
        if (count < 2)
            fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
        else if (current->n == 0)
            fprintf(stderr, "L%d: division by zero\n", line_number);
        free(bus.content);
        fclose(bus.file);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    remainder = current->next->n % current->n;
    current->next->n = remainder;
    *head = current->next;
    free(current);
}