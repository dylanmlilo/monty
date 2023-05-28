#include "monty.h"

/**
 * free_stack - function that frees a doubly linked list
 * @head: head of the stack
 */

void free_stack(stack_t *head)
{
	stack_t *opc;

	opc = head;
	while (head)
	{
		opc = head->next;
		free(head);
		head = opc;
	}
}
