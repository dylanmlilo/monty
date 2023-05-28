#include "monty.h"

/**
 * op_div - function that divides the top two elements of the stack
 *
 * @head: top of stack
 * @counter: the line number
 * Return: does not return
 */

void op_div(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	top = *head;
	if (top->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	opc = top->next->n / top->n;
	top->next->n = opc;
	*head = top->next;
	free(top);
}

/**
 * op_mul - function that multiplies the top two elements of the stack
 *
 * @head: top of stack
 * @counter: the line number
 *
 * Return: does not return
 */

void op_mul(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	top = *head;
	opc = top->next->n * top->n;
	top->next->n = opc;
	*head = top->next;
	free(top);
}

/**
 * op_mod - function that computes the division of two elements
 *
 * @head: top of stack
 * @counter: the line number
 *
 * Return: does not return
 */

void op_mod(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	top = *head;
	if (top->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	opc = top->next->n % top->n;
	top->next->n = opc;
	*head = top->next;
	free(top);
}
