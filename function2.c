#include "monty.h"
/**
 * __add - function
 * @stack: listes of integers
 * @line_number: line_number
 */
void __add(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		error = 1;
		return;
	}
	(*stack)->next->n += (*stack)->n;
	__pop(stack, line_number);
}

/**
 * __swap - function
 * @stack: listes of intgers
 * @line_number: line number
 */
void __swap(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		error = 1;
		return;
	}

	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;

}
