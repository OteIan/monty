#include "monty.h"

/**
 * f_pall - Prints all the values of the stack, starting from the top
 *
 * @stack: Double pointer to the head node of the stack
 * @line_number: Line no. where the instruction is located in the input source
*/
void f_pall(stack_t **head, __attribute__((unused))unsigned int line_number)
{
    stack_t *current = *head;

    if (current == NULL)
        return (0);

    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}