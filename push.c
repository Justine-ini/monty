#include "monty.h"
/**
 * push - Pushes an element onto the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the file
 * @file: Pointer to the input file
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *line = NULL;
	FILE *file = fopen("myfile.m", "r");
	char *arg = strtok(line, " \t\n");
	stack_t *new_node;

	if (fgets(line, sizeof(line), file) == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(line);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	if (arg == NULL || (!isdigit(arg[0]) && arg[0] != '-'))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(line);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(line);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi(arg);
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
	free(line);
}
