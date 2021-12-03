#include "monty.h"

/**
 * rotl_stack - rotates the stack to the bottom.
 * @stack: double pointer head of stack.
 * @line_number: line number.
 *
 * Return: void.
 */
void rotl_stack(stack_t **stack, unsigned int line_number)
{
stack_t *new_node, *node_at_end;

(void)line_number;
if (*stack == NULL || (*stack)->next == NULL)
return;

node_at_end = *stack;
while (node_at_end->next != NULL)
node_at_end = node_at_end->next;

new_node = *stack;
*stack = (*stack)->next;
(*stack)->prev = NULL;
new_node->next = NULL;
new_node->prev = node_at_end;
node_at_end->next = new_node;
}

/**
 * rotr_stack - rotates the stack to the bottom.
 * @stack: double pointer head of stack.
 * @line_number: line number.
 *
 * Return: void.
 */
void rotr_stack(stack_t **stack, unsigned int line_number)
{
stack_t *new_node, *node_at_end;

(void)line_number;
if (*stack == NULL || (*stack)->next == NULL)
return;

node_at_end = *stack;
while (node_at_end->next != NULL)
node_at_end = node_at_end->next;

new_node = *stack;
*stack = node_at_end;
(*stack)->prev->next = NULL;
new_node->prev = NULL;
(*stack)->next = new_node;
new_node->prev = *stack;
}
