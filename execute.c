#include "monty.h"

/**
 * exec_opcode - This executes the opcode in the line
 *
 * @content: Contains the content of the line
 * @head: Double pointer to the head node of the stack
 * @count: line counter
 * @file: Pointer to the monty file
*/
void exec_opcode(char *content, stack_t **head, unsigned int count, FILE *file)
{
    int i = 0;
    instruction_t op_call[] = {
        {"push", f_push},
        {"pop", f_pall},
        {"pint", f_pint},
        {"pop", f_pop},
        {"swap", f_swap},
        {"add", f_add},
        {"sub", f_sub},
        {"div", f_div},
        {"mul", f_mul},
        {"mod", f_mod},
        {"nop", f_nop},
        {NULL, NULL}
    };
    char *opcode;

    opcode = strtok(content, " \n\t");
    if (opcode[0] == '#')
        return (0);

    bus.arg = strtok(NULL, " \n\t");
    
    while (op_call[i].opcode && opcode)
    {
        if (strcmp(op_call[i].opcode, opcode) == 0)
        {
            op_call[i].f(&head, count);
            return (0);
        }
        i++;
    }

    if (opcode == NULL && op_call[i].opcode == NULL)
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", count, opcode);
        free(content);
        free_stack(head);
        fclose(file);
        exit(EXIT_FAILURE);
    }
    return (1);
}