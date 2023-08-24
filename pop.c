#include "monty.h"
/**
 * pop - delete element top of stack
 * @stack: doble pointer to head of d linked list
 * @counter: current line of monty file
 * Return: returns void
 */
void pop(stack_t **stack, unsigned int counter)
{
	stack_t *temp;

	if (!(*stack) || !stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", counter);
		free_stack();
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	if (temp->next)
	{
		temp->next->prev = NULL;
		*stack = temp->next;
	}
	else
		*stack = NULL;
	free(temp);
}
