#include "monty.h"
/**
 * rotr - rotates the stack to the bottom
 * @head: double pointer to the begining of the list
 * @counter: script line number
 */

void rotr(stack_t **head, unsigned int counter)
{
	stack_t *temp;
	(void) counter;

	if (!head || !(*head) || !(*head)->next)
		return;

	temp = *head;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *head;
	temp->prev->next = NULL;
	temp->prev = NULL;

	(*head)->prev = temp;
	(*head) = temp;
}
