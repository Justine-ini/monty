#include "monty.h"
/**
 * monty_function - search monty functions
 * @operator: function to search
 * @node: pointer to head
 * @count_lines: current line number
 * Return: void function
 */
void monty_function(char *operator, stack_t **node, unsigned int count_lines)
{
	size_t i = 0;

	instruction_t valid_com[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", o_div},
		{"mod", mod},
		{"mul", mul},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"nop", nop},
		{NULL, NULL}
	};
	while (valid_com[i].opcode)
	{
		if (strcmp(valid_com[i].opcode, operator) == 0)
		{
			valid_com[i].f(node, count_lines);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", count_lines, operator);
	free_stack();
	exit(EXIT_FAILURE);
}
