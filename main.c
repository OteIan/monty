#include "monty.h"

bus_t bus = {NULL, NULL, NULL, 0};

/**
 * main - main function
 *
 * @argc: argument count
 * @argv: argument vector
*/
int main(int argc, char *argv[])
{
    FILE *file;
    char *content;
    size_t len = 0;
    ssize_t nread = 1;
    stack_t *head = NULL;
    unsigned int count = 0;

    if (argc != 3)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    bus.file = file;
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (nread > 0)
    {
        count++;
        content = NULL;
        nread = getline(&content, &len, file);
        bus.content = content;
        if (nread > 0)
            exec_opcode(content, &head, count, file);
        free(content);
    }
    free_stack(head);
    fclose(file);
    return (0);

}