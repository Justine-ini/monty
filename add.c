#include "monty.h"
/**
 * add - adds the top and the second element of the stack
 * @head: pointer to head
 * @line_count: current line number
 * Return: void function
 */
void add(stack_t **head, unsigned int line_count)
{
	stack_t *temp;
	int valor;

	if (!head || !(*head) || !(*head)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_count);
		free_stack();
		exit(EXIT_FAILURE);
	}
	temp = *head;

	valor = temp->n + temp->next->n;
	pop(head, line_count);
	pop(head, line_count);
	insert_node(head, valor);
}
