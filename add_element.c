#include "monty.h"

/**
 * add_element_stack - Function that adds a new element to a stack
 *
 * @head: Pointer to the head of the stack
 * @n: Value that the element will hold
 */
void add_element_stack(stack_t **head, int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;

	if (*head == NULL)
		(*head)->prev = new_node;

	new_node = *head;
	*head = new_node;
}

/**
 * add_element_queue - Adds a new element to the end of a queue
 *
 * @head: Pointer to the head of the queue
 * @n: Value that the element will hold
 */
void add_element_queue(stack_t **head, int n)
{
	(void) head;
	(void) n;
}
