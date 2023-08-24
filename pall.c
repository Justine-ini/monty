#include "monty.h"
/**
 * pall - print the stack
 * @stack: doble pointer to head of d linked list
 * @counter: current line of monty file
 * Return: returns void
 */
void pall(stack_t **stack, unsigned int counter)
{
	stack_t *temp = *stack;
	(void)counter;

	if (*stack && stack)
	{
		for (; temp != NULL; temp = temp->next)
		{
			printf("%d\n", temp->n);
		}
	}
}
