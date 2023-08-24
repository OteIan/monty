#include "monty.h"

/**
 * execute - This executes the opcode in the line
 * 
 * @content: Contains the content of the line
 * @head: Double pointer to the head node of the stack
 * @count: line counter
 * @file: Pointer to the monty file
*/
void execute(char *content, stack_t **head, unsigned int count, FILE *file)
{
    int i = 0;
    instruction_t ops[] = {
        {"push", f_push},
        {"pop", f_pall},
        {NULL, NULL}
    };
    char *opcode;
    
    opcode = strtok(content, " \n\t");

    while (ops[i].opcode && opcode)
    {
        if (strcmp(ops[i].opcode, opcode) == 0)
        {
            ops[i].f(&head, count);
            return (0);
        }
        i++;
    }

}