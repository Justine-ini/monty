#include "monty.h"

/**
 * mul - muls the top and the second element of the stack
 * @head: pointer to head
 * @counter: current line number
 * Return: void function
 */
void mul(stack_t **head, unsigned int counter)
{
	stack_t *temp;
	int even;

	if (!head || !(*head) || !(*head)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", counter);
		free_stack();
		exit(EXIT_FAILURE);
	}
	temp = *head;

	even = temp->n * temp->next->n;
	pop(head, counter);
	pop(head, counter);
	insert_node(head, even);
}


/**
 * mod - mods the top and the second element of the stack
 * @head: pointer to head
 * @counter: current line number
 * Return: void function
 */
void mod(stack_t **head, unsigned int counter)
{
	stack_t *temp;
	int even;

	if (!head || !(*head) || !(*head)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", counter);
		free_stack();
		exit(EXIT_FAILURE);
	}
	temp = *head;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", counter);
		free_stack();
		exit(EXIT_FAILURE);
	}
	even = temp->next->n % temp->n;
	pop(head, counter);
	pop(head, counter);
	insert_node(head, even);
}
