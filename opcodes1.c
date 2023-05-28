#include "monty.h"

/**
 * op_push - function that adds a node to the stack
 *
 * @head: top of the stack
 * @counter: line number
 *
 * Return: does not return
 */

void op_push(stack_t **head, unsigned int counter)
{
	int i, n, flag;

	i = flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			i++;
		for (; bus.arg[i] != '\0'; i++)
		{
			if (bus.arg[i] > 57 || bus.arg[i] < 48)
				flag = 1; }
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE); 
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(bus.arg);
	if (bus.lifi == 0)
		add_node(head, n);
}

/**
 * op_pall - function that prints the stack
 *
 * @head: top of the stack stack
 * @counter: is not used
 *
 * Return: does not return
 */

void op_pall(stack_t **head, unsigned int counter)
{
	stack_t *top;
	(void)counter;

	top = *head;
	if (top == NULL)
		return;

	while (top)
	{
		printf("%d\n", top->n);
		top = top->next;
	}
}

/**
 * op_pint - function that prints the top
 *
 * @head: top of stack
 * @counter: the line number
 *
 * Return: does not return
 */

void op_pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * op_pop - function that prints the top of stack
 *
 * @head: top of the stack
 * @counter: the line number
 *
 * Return: does not return
 */

void op_pop(stack_t **head, unsigned int counter)
{
	stack_t *top;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	top = *head;
	*head = top->next;
	free(top);
}

/**
 * op_swap - function that swaps the top two elements of the stack
 * 
 * @head: top of stack
 * @counter: the line number
 *
 * Return: does not return
 */

void op_swap(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	top = *head;
	opc = top->n;
	top->n = top->next->n;
	top->next->n = opc;
}
