#include "monty.h"

int error = 0; // Variable globale pour suivre les erreurs

/**
 * main - la fonction principale du programme
 * @argv: tableau d'arguments
 * @argc: nombre d'arguments
 * Return: EXIT_FAILURE ou EXIT_SUCCESS
 */
int main(int argc, char **argv)
{
	FILE *ptr;
	char *line = NULL, *token = NULL;
	size_t size = 0;
	stack_t *stack = NULL; // Initialisation de la pile
	unsigned int line_number = 0;

	if (argc != 2) // Vérifie le nombre d'arguments passés au programme
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	ptr = fopen(argv[1], "r"); // Ouvre le fichier spécifié en lecture
	if (ptr == NULL) // Vérifie si l'ouverture du fichier a échoué
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	// Boucle pour lire chaque ligne du fichier et exécuter les instructions Monty
	while (getline(&line, &size, ptr) != -1 && error != 1)
	{
		line_number++; // Incrémente le numéro de ligne

		// Découpe la ligne en tokens (mots)
		token = strtok(line, "\n\t ");
		if (token == NULL || strncmp(token, "#", 1) == 0)
			continue; // Ignore les lignes vides ou les commentaires

		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, "\n\t ");
			__push(token, &stack, line_number); // Appelle la fonction push
		}
		else
			get_op_func(token, &stack, line_number); // Appelle la fonction associée à l'opcode
	}

	free_all(stack, line, ptr); // Libère la mémoire allouée
	if (error == 1)
		exit(EXIT_FAILURE); // Quitte avec un code d'erreur si une erreur a été détectée

	return (EXIT_SUCCESS); // Termine le programme avec succès
}
