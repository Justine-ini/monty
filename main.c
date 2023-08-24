#include "monty.h"

stack_t **global_free;

/**
 * main - monty interpreter
 * @argc: number of agruments
 * @argv: name of file in argv[1]
 * Return: return success if interpreter worked
 */

int main(int argc, char *argv[])
{
	FILE *monty_file;
	/*int line = 1;*/
	unsigned int count_lines = 0;
	char *dataptr = NULL, *operator = NULL;
	size_t size = 0;
	stack_t *node = NULL;

	global_free = &node;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		free_stack();
		exit(EXIT_FAILURE);
	}
	monty_file = fopen(argv[1], "r");
	if (monty_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		free_stack();
		exit(EXIT_FAILURE);
	}
	/*while (getline(&dataptr, &size, monty_file) != -1)*/
	while (fgets(dataptr, size, monty_file) != NULL)
	{
		count_lines++;
		operator = strtok(dataptr, DELIMETER);
		if (operator != NULL && operator[0] != '#')
			monty_function(operator, &node, count_lines);
	}
	fclose(monty_file);
	if (dataptr)
		free(dataptr);
	free_stack();
	return (0);
}
