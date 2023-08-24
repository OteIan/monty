#include "monty.h"

/**
 * f_sub - Functions that subtracts the top two elements of the stack
 *
 * @head: Double pointer to the head of the stack
 * @line_number: Line no. where the instruction is located in the input source
*/
void f_sub(stack_t **head, unsigned int line_number)
{
    stack_t *current = *head;
    stack_t *counter = *head;
    int dif = 0, count = 0;

    while (counter != NULL)
    {
        counter = counter->next;
        count++;
    }

    if (count < 2)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
        free(bus.content);
        fclose(bus.file);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    dif = current->next->n - current->n;
    current->next->n = dif;
    *head = current->next;
    free(current);
}