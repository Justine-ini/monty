#include "monty.h"
/**
 * add - adds the top and the second element of the stack
 * @head: pointer to head
 * @counter: current line number
 * Return: void function
 */
void add(stack_t **head, unsigned int counter)
{
	stack_t *temp;
	int even;

	if (!head || !(*head) || !(*head)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", counter);
		free_stack();
		exit(EXIT_FAILURE);
	}
	temp = *head;

	even = temp->n + temp->next->n;
	pop(head, counter);
	pop(head, counter);
	insert_node(head, even);
}
