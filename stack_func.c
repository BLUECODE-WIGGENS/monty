#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: double pointer to head of stack
 * @line_number: counts the number line of the file
 *
 *Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
stack_t *head_node;

head_node = *stack;
if (head_node == NULL)
{
fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
free_struct(*stack);
exit(EXIT_FAILURE);
}
printf("%d\n", head_node->n);
}

/**
 * pop - removes the top element of the stack
 * @stack: double pointer to head of the stack
 * @line_number: number line.
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
stack_t *head_node;

head_node = *stack;
if (head_node == NULL)
{
fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
free_struct(*stack);
exit(EXIT_FAILURE);
}

if ((*stack)->next)
(*stack)->next->prev = NULL;
*stack = (*stack)->next;

free(head_node);
}

/**
 * swap - swaps the top two elements of the stack.
 * @stack: double pointer to head of stack
 * @line_number: number line
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
stack_t *temporary_node;

temporary_node = *stack;
if (!stack || !*stack || !((*stack)->next))
{
fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
free_struct(*stack);
exit(EXIT_FAILURE);
}
*stack = (*stack)->next;
(*stack)->prev = NULL;
if ((*stack)->next)
((*stack)->next)->prev = temporary_node;
temporary_node = (*stack)->next;
(*stack)->next = temporary_node;
temporary_node->prev = *stack;
}

/**
 * add - adds the top two elements of the stack.
 * @stack:  double head pointer
 * @line_number: line number
 *
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
stack_t *new_node;

new_node = *stack;
if (!stack || !*stack || !((*stack)->next))
{
fprintf(stderr, "L%d: can't add, stack too short", line_number);
free_struct(*stack);
exit(EXIT_FAILURE);
}

*stack = (*stack)->next;
(*stack)->n += new_node->n;
(*stack)->prev = NULL;
free(new_node);
}

/**
 * nop - doesn't do anything
 * @stack: double head pointer
 * @line_number: line number
 *
 * Return: void
 */
void nop(stack_t **stack, unsigned int line_number)
{
(void)stack;
(void)line_number;
}
