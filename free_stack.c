#include "monty.h"
/**
 * free_stack - function for free all nodes
 */
void free_stack(void)
{
	stack_t *current_node;
	stack_t *temp = NULL;

	current_node = *global_free;

	for (; current_node != NULL; )
	{
		temp = current_node->next;
		free(current_node);
		current_node = temp;
	}
}
