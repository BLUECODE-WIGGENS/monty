#include "monty.h"

/**
 * push - pushes an element to the stack.
 * @stack: pointer to pointer to head of the stack
 * @line_number: counts number of lines
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
stack_t *new_node;

new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
free_struct(*stack);
exit(EXIT_FAILURE);
}

new_node->next = *stack;
new_node->prev = NULL;
new_node->n = stack_environ;
if (*stack)
(*stack)->prev = new_node;
*stack = new_node;
}

/**
 * pall - prints all the values on the stack
 * @stack: double pointer to head of the stack
 * @line_number: void
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
stack_t *head_node;

(void) line_number;
head_node = *stack;
while (head_node != NULL)
{
printf("%d\n", head_node->n);
head_node = head_node->next;
}
}
