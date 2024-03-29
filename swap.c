#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: double pointer to the head ot the stack
 * @counter: the number of the line in file
 * Return: void
 */
void swap(stack_t **stack, unsigned int counter)
{
	stack_t *temp;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", counter);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	(*stack)->prev = temp;
	(*stack)->next = temp->next;
	temp->prev = NULL;

	if (temp->next)
		temp->next->prev = *stack;
	temp->next = *stack;
	*stack = temp;
}
