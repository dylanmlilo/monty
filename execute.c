#include <stdio.h>
#include "monty.h"

/**
 * execute - function that executes the opcode
 *
 * @stack: top of the stack
 * @counter: the line counter
 * @file: the poiner to monty file
 * @content: the line content
 *
 * Return: nothing
 */

int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop},
		{"sub", op_sub},
		{"div", op_div},
		{"mul", op_mul},
		{"mod", op_mod},
		{NULL, NULL}
	};

	unsigned int i = 0;
	char *opc;

	opc = strtok(content, " \n\t");

	if (opc && opc[0] == '#')
	{
		return (0);
	}

	bus.arg = strtok(NULL, " \n\t");

	while (opst[i].opcode && opc)
	{
		if (strcmp(opc, opst[i].opcode) == 0)
		{opst[i].op(stack, counter);
			return (0);
		}
		i++;
	}
	if (opc && opst[i].opcode == NULL)
	{ 
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, opc);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
