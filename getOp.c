#include "monty.h"

/**
 * get_op_func - fonction pour obtenir et exécuter la fonction associée à une instruction
 * @line: nom de l'instruction
 * @stack: pointeur vers le sommet de la pile
 * @line_number: numéro de la ligne dans le fichier Monty
 * Return: succès ou échec de l'exécution
 */
int get_op_func(char *line, stack_t **stack, unsigned int line_number)
{
	// Structure associant les instructions (opcodes) à leurs fonctions correspondantes
	instruction_t func[] = {
		{"pall", __pall},
		{"nop", __nop},
		{"pint", __pint},
		{"pop", __pop},
		{"add", __add},
		{"swap", __swap},
		{NULL, NULL}, // Marqueur de fin de la liste des opcodes/fonctions
	};
	int i;

	// Parcourt la liste des opcodes pour trouver celui correspondant à la ligne donnée
	for (i = 0; func[i].opcode != NULL; i++)
	{
		if (strcmp(line, func[i].opcode) == 0)
		{
			func[i].f(stack, line_number); // Exécute la fonction associée à l'opcode trouvé
			return (EXIT_SUCCESS); // Indique le succès de l'exécution de l'instruction
		}
	}

	// Si l'instruction n'est pas reconnue, affiche un message d'erreur et définit error à 1
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, line);
	error = 1;
	return (EXIT_FAILURE); // Indique l'échec de l'exécution de l'instruction
}
