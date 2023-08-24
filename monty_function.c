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
/*		{"swap", m_swap},
		{"add", m_add},
		{"sub", m_sub},
		{"div", m_div},
		{"mod", m_mod},
		{"mul", m_mul},
		{"pchar", m_pchar},
		{"pstr", m_pstr},
		{"rotl", m_rotl},
		{"rotr", m_rotr},
		{"nop", m_nop},*/
		{NULL, NULL}
	};
	/*
	for (i = 0; valid_com[i].opcode; i++)
	{
		if (strcmp(valid_com[i].opcode, operator) == 0)
		{
			valid_com[i].f(node, count_lines);
			return;
		}
	}*/
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
