#include "monty.h"

/**
 * __add - fonction pour additionner les deux premiers éléments de la pile
 * @stack: pointeur vers le sommet de la pile
 * @line_number: numéro de la ligne dans le fichier Monty
 */
void __add(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		error = 1;
		return;
	}
	(*stack)->next->n += (*stack)->n; // Additionne les deux premiers éléments de la pile
	__pop(stack, line_number); // Appelle la fonction __pop pour retirer le premier élément
}

/**
 * __swap - fonction pour échanger les deux premiers éléments de la pile
 * @stack: pointeur vers le sommet de la pile
 * @line_number: numéro de la ligne dans le fichier Monty
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

	tmp = (*stack)->n; // Stocke la valeur du premier élément dans une variable temporaire
	(*stack)->n = (*stack)->next->n; // Échange les valeurs entre les deux premiers éléments de la pile
	(*stack)->next->n = tmp; // Restaure la valeur précédente du premier élément à partir de la variable temporaire
}
