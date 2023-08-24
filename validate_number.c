#include "monty.h"
/**
 * validate_number - check if string is a number
 * @arguments: param to push
 * @counter: current line number
 * Return: number
 */
int validate_number(char *arguments, unsigned int counter)
{
	int digit;

	digit = atoi(arguments);
	if (digit == 0 && strcmp(arguments, "0") != 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", counter);
		free_stack();
		exit(EXIT_FAILURE);
	}
	return (digit);
}
