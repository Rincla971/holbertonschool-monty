#include "monty.h"
/**
 * get_op_func - function
 * @line: name of instruction
 * @stack: liste
 * @line_number: line_number
 * Return: success or failure
 */
int get_op_func(char *line, stack_t **stack, unsigned int line_number)
{

	instruction_t func[] = {
		{"pall", __pall},
		{"nop", __nop},
		{"pint", __pint},
		{"pop", __pop},
		{"add", __add},
		{"swap", __swap},
		{NULL, NULL},
	};
	int i;

	for (i = 0; func[i].opcode != NULL; i++)
	{
		if (strcmp(line, func[i].opcode) == 0)
		{
			func[i].f(stack, line_number);
			return (EXIT_SUCCESS);
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, line);
	error = 1;
	return (EXIT_FAILURE);
}
