#include "monty.h"

/**
 * mul - multiplies the second top two elements of the stack
 * @stack: double head pointer of the stack
 * @line_number: line number
 *
 * Return: void
 */

void _mul(stack_t **stack, unsigned int line_number)
{
stack_t *new_node;

new_node = *stack;
if (_len(*stack) < 2 || *stack == NULL)
{
fprintf(stderr, "L%d: can't mul, stack too short", line_number);
exit(EXIT_FAILURE);
}
new_node->next->n *= (*stack)->n;
*stack = (*stack)->next;
free(new_node);
(*stack)->prev = NULL;
}
