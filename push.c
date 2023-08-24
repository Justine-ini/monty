#include "monty.h"
/**
 * push - it pushes an element to the stack.
 * @stack: pointer to head
 * @counter: current line number
 * Return: void function
 */
void push(stack_t **stack, unsigned int counter)
{
	int digit;
	char *arguments;

	arguments = strtok(NULL, DELIMETER);

	if (!arguments)
	{
		fprintf(stderr, "L%u: usage: push integer\n", counter);
		exit(EXIT_FAILURE);
	}
	digit = validate_number(arguments, counter);
	if (!insert_node(stack, digit))
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack();
		exit(EXIT_FAILURE);
	}
}

/**
 * insert_node - add node at begining of double linked list
 * @stack: pointer to hed
 * @n: integer
 * Return: number of nodes
 */
stack_t *insert_node(stack_t **stack, const int n)
{
	stack_t *newNode, *temp;

	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
		return (NULL);
	newNode->n = n;
	newNode->prev = NULL;
	temp = *stack;
	if (*stack == NULL)
		newNode->next = NULL;
	else
	{
		newNode->next = temp;
		temp->prev = newNode;
	}
	*stack = newNode;
	return (newNode);
}


