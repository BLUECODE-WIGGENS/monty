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
fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
new_node->next->n *= (*stack)->n;
*stack = (*stack)->next;
free(new_node);
(*stack)->prev = NULL;
}

/**
 * mod - devides the top two elements of the stack.
 * @stack:  double head pointer
 * @line_number: line number
 *
 * Return: void
 */
void mod(stack_t **stack, unsigned int line_number)
{
stack_t *new_node;

new_node = *stack;
if (_len(*stack) < 2 || *stack == NULL)
{
fprintf(stderr, "L%d: can't add, stack too short", line_number);
free_struct(*stack);
exit(EXIT_FAILURE);
}

if (new_node->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", line_number);
free_struct(*stack);
exit(EXIT_FAILURE);
}
new_node->next->n %= (*stack)->n;
*stack = (*stack)->next;
free(new_node);
(*stack)->prev = NULL;
}

/**
 * print_char - prints the char at the top of the stack
 * @stack: double head pointer
 * @line_number: line number 
 *
 * Return: void
 */
void print_char(stack_t **stack, unsigned int line_number)
{
int num;

if (stack == NULL || *stack == NULL)
{
fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
free_struct(*stack);
exit(EXIT_FAILURE);
}
num = (*stack)->n;
if (num < 0 || num > 127)
{
fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
free_struct(*stack);
exit(EXIT_FAILURE);
}
printf("%c\n", num);
}
