#ifndef MONTY_H
#define MONTY_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* MACROS */
#define DELIMETER " \n\t\r"



/* STRUCTURES */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* GLOBAL VARIABLES */
extern stack_t **global_free;

int validate_number(char *arguments, unsigned int counter);
int _isalpha(int c);
int delete_node(stack_t **head, unsigned int index);
void pop(stack_t **stack, unsigned int counter);
void add(stack_t **head, unsigned int counter);
void sub(stack_t **head, unsigned int counter);
void mul(stack_t **head, unsigned int counter);
void o_div(stack_t **head, unsigned int counter);
void mod(stack_t **head, unsigned int counter);
void pchar(stack_t **stack, unsigned int counter);
void pstr(stack_t **head, unsigned int counter);
void rotl(stack_t **head, unsigned int counter);
void rotr(stack_t **head, unsigned int counter);
int read_line(FILE *monty_file);
void monty_function(char *operator, stack_t **node, unsigned int count_lines);
stack_t *insert_node(stack_t **stack, const int n);
void push(stack_t **stack, unsigned int counter);
size_t print_rev(stack_t *h);
void pint(stack_t **node, unsigned int counter);
size_t print(stack_t *h);
void free_stack(void);
void swap(stack_t **stack, unsigned int counter);
void nop(stack_t **head, unsigned int counter);
void pall(stack_t **stack, unsigned int counter);

#endif /* MONTY_H*/
