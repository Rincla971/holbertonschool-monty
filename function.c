#include "monty.h"

/**
 * __push - fonction pour empiler un élément
 * @token: chaîne de caractères représentant l'élément à empiler
 * @stack: pointeur vers le sommet de la pile
 * @line_number: numéro de la ligne dans le fichier Monty
 */
void __push(char *token, stack_t **stack, unsigned int line_number)
{
	stack_t *newNode = NULL; // Nouveau nœud pour stocker la valeur
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
		if (isdigit(token[i]) == 0) // Vérifie si chaque caractère est un chiffre
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			error = 1;
			return;
		}
	}

	newNode = malloc(sizeof(stack_t)); // Alloue de la mémoire pour le nouveau nœud
	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		error = 1;
		return;
	}
	newNode->n = atoi(token); // Convertit la chaîne de caractères en entier et l'assigne au nouveau nœud
	newNode->next = NULL;
	newNode->prev = NULL;

	if (*stack)
	{
		(*stack)->prev = newNode; // Ajuste les pointeurs pour ajouter le nouveau nœud au sommet
		newNode->next = *stack;
	}
	*stack = newNode; // Met à jour le sommet de la pile avec le nouveau nœud
}

/**
 * __pall - fonction pour afficher tous les éléments de la pile
 * @stack: pointeur vers le sommet de la pile
 * @line_number: numéro de la ligne dans le fichier Monty (non utilisé ici)
 */
void __pall(stack_t **stack, unsigned int line_number)
{
	(void) (line_number); // Cette variable n'est pas utilisée dans cette fonction
	stack_t *h = *stack; // Un pointeur temporaire pour parcourir la pile

	while (h != NULL)
	{
		printf("%d\n", h->n); // Affiche la valeur de chaque nœud de la pile
		h = h->next; // Passe au nœud suivant
	}
}

/**
 * __nop - fonction pour une opération nulle (ne fait rien)
 * @stack: pointeur vers le sommet de la pile (non utilisé ici)
 * @line_number: numéro de la ligne dans le fichier Monty (non utilisé ici)
 */
void __nop(stack_t **stack, unsigned int line_number)
{
	(void) **stack; // Opération nulle, aucune action effectuée sur la pile
	(void) line_number; // Ces paramètres ne sont pas utilisés
}

/**
 * __pint - fonction pour afficher la valeur du sommet de la pile
 * @stack: pointeur vers le sommet de la pile
 * @line_number: numéro de la ligne dans le fichier Monty
 */
void __pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		error = 1;
		return;
	}
	printf("%d\n", (*stack)->n); // Affiche la valeur du sommet de la pile
}

/**
 * __pop - fonction pour retirer l'élément en haut de la pile
 * @stack: pointeur vers le sommet de la pile
 * @line_number: numéro de la ligne dans le fichier Monty
 */
void __pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack; // Garde une référence au sommet de la pile

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		error = 1;
		return;
	}

	*stack = (*stack)->next; // Déplace le pointeur vers le nœud suivant (nouveau sommet)

	if (*stack)
		(*stack)->prev = NULL; // Met à jour le lien vers le nœud précédent

	free(tmp); // Libère la mémoire de l'ancien sommet de la pile
}


