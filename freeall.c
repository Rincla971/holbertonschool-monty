#include "monty.h"

/**
 * free_all - fonction qui libère toute la mémoire et ferme le fichier
 * @stack: la liste à libérer
 * @line: la ligne lue avec getline à libérer
 * @ptr: le fichier à fermer
 */
void free_all(stack_t *stack, char *line, FILE *ptr)
{
	stack_t *temp = stack; // Crée un pointeur temporaire pour la liste

	// Boucle pour libérer la mémoire de chaque élément de la liste
	while (stack)
	{
		temp = stack;
		stack = stack->next; // Avance dans la liste
		free(temp); // Libère l'élément actuel de la liste
	}

	free(line); // Libère la mémoire allouée pour la ligne lue avec getline
	fclose(ptr); // Ferme le fichier
}
