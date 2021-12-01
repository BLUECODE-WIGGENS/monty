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
dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
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
dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n");
free_struct(*stack);
exit(EXIT_FAILURE);
}

if ((*stack)->next)
(*stack)->next->prev = NULL;
*stack = (*stack)->next;

free(head_node);
}
