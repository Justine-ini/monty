#include "monty.h"
/**
 * pint - prints the value at the top of stack
 * @stack: pointer to the head node pointer of stack
 * @counter: the line number
 * Return: Nothing.
 */
void pint(stack_t **stack, unsigned int counter)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", counter);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	while (temp)
	{
		if (temp->prev == NULL)
			break;
		temp = temp->prev;
	}

	printf("%d\n", temp->n);
}
