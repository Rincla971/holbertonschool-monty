#include "monty.h"
/**
 * __push - function
 * @token: char
 * @stack: listes
 * @line_number: line number
 */
void __push(char *token, stack_t **stack, unsigned int line_number)
{
	stack_t *newNode = NULL;
	int i;

	if (token == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		error = 1;
		return;

	}
	for (i = 0; token[i] !=  '\0'; i++)
	{
		if (token[i] == '-')
			i++;
		if (isdigit(token[i]) == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			error = 1;
			return;
		}
	}
	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		error = 1;
		return;
	}
	newNode->n = atoi(token);
	newNode->next = NULL;
	newNode->prev = NULL;

	if (*stack)
	{

		(*stack)->prev = newNode;
		newNode->next = *stack;
	}
	*stack = newNode;
}
/**
 * __pall - function
 * @stack: listes
 * @line_number: integers
 */
void __pall(stack_t **stack, unsigned int line_number)
{
	(void) (line_number);
	stack_t *h = *stack;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
/**
 * __nop - function
 * @stack: listes
 * @line_number: integers
 */
void __nop(stack_t **stack, unsigned int line_number)
{
	(void) **stack;
	(void) line_number;
}
/**
 * __pint - function
 * @stack: listes
 * @line_number: integers
 */
void __pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		error = 1;
		return;
	}
	printf("%d\n", (*stack)->n);
}
/**
 * __pop - function
 * @stack: listes
 * @line_number: integers
 */
void __pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		error = 1;
		return;
	}

	*stack = (*stack)->next;

	if (*stack)
		(*stack)->prev = NULL;

	free(tmp);



}
