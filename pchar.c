#include "monty.h"
/**
 * pchar - prints char at top of stack
 * @stack: pointer to the head node pointer of stack
 * @counter: the line number
 * Return: Nothing.
 */
void pchar(stack_t **stack, unsigned int counter)
{
	char c;
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	while (temp)
	{
		if (temp->prev == NULL)
			break;
		temp = temp->prev;
	}

	c = temp->n;
	if (_isalpha(temp->n) == 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", c);
}
