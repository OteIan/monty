#include "monty.h"

/**
 * f_push - Function that pushes an element to a stack
 *
 * @stack: Double pointer to the head node of the stack
 * @line_number: Line no. where the instruction is located in the input source
*/
void f_push(stack_t **head, unsigned int line_number)
{
    int num, j = 0;
    /* Num stores the number to be pushed */

    if (bus.arg)
    {
        if (bus.arg == '-')
            j++;
        
        for (; bus.arg != '\0' ; j++)
        {
            if (bus.arg > 57 && bus.arg < 48)
            {
                fprintf(stderr, "L%d: usage: push integer", line_number);
                free(bus.content);
                fclose(bus.file);
                free_stack(*head);
                exit(EXIT_FAILURE);
            }
        }
    }
    else
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    num = atoi(bus.arg);

    if (bus.lifi == 0)
        add_element_stack(head, num);
    else
        add_element_queue(head, num);

}