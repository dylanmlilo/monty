#include "monty.h"

/**
 * op_add - function that adds the top two elements of the stack
 *
 * @head: top of stack
 * @counter: line_number
 *
 * Return: does not return
 */

void op_add(stack_t **head, unsigned int counter)
{
	stack_t *top;
	int length, opc;

	length = 0;
	top = *head;

	while (top)
	{
		top = top->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	top = *head;
	opc = top->n + top->next->n;
	top->next->n = opc;
	*head = top->next;
	free(top);
}

/**
 * op_nop - function that does nothind
 *
 * @head: top of stack
 * @counter: line_number
 *
 * Return: does not return
 */

void op_nop(stack_t **head, unsigned int counter)
{
	(void) counter;
	(void) head;
}

/**
 * op_sub - function that sustracts two elements of a stack
 * 
 * @head: top of stack
 * @counter: line_number
 *
 * Return: does not return
 */

void op_sub(stack_t **head, unsigned int counter)
{
	stack_t *opc;
	int ops, nodes;

	nodes = 0;

	opc = *head;
	for (; opc != NULL; nodes++)
	{
		opc = opc->next;
	}
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	opc= *head;
	ops = opc->next->n - opc->n;
	opc->next->n = ops;
	*head = opc->next;
	free(opc);
}
