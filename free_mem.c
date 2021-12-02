#include "monty.h"

/**
 * free_struct - frees the list.
 * @stack: pointer to a list
 *
 * Return: void
 */
void free_struct(stack_t *stack)
{
stack_t *temporary_node;

if (stack == NULL)
return;

while (stack)
{
temporary_node = stack;
stack = stack->next;
free(temporary_node);
}
stack = NULL;
}
