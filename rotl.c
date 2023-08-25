#include "monty.h"
/**
 * rotl - rotates the stack to the top
 * @head: double pointer to the begining of the list
 * @counter: script line number
 */
void rotl(stack_t **head, unsigned int counter)
{
	stack_t *temp, *top;
	(void) counter;

	if (!head || !(*head) || !(*head)->next)
		return;
	temp = *head;
	top = temp->next;
	top->prev = NULL;

	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *head;

	(*head)->next = NULL;
	(*head)->prev = temp;

	*head = top;
}
