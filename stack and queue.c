#include "monty.h"

/**
 * stack_set - sets the format of the data to a stack
 * @stack: head node
 * @line_number: line nmbr
 *
 * Return: Void
 */
void stack_set(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
	stack_environ = 0;
}

/**
 * queue_set - sets the format of the data to a queue
 * @stack: double head node of the stack
 * @line_number: line number
 *
 * Return: Void
 */
void queue_set(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
	stack_environ = 1;
}
