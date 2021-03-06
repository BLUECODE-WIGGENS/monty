#include "monty.h"

/**
 * _len - counts length of doubly linked list
 * @stack: head node
 *
 * Return: length
 */
size_t _len(const stack_t *stack)
{
size_t len = 0;

while (stack)
{
stack = stack->next;
len++;
}
return (len);
}

/**
 * push - pushes an element to the stack.
 * @stack: pointer to pointer to head of the stack
 * @line_number: counts number of lines
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_struct(*stack);
		exit(EXIT_FAILURE);
	}
	new->next = *stack;
	new->prev = NULL;
	new->n = stack_environ;
	if (*stack)
		(*stack)->prev = new;
	*stack = new;
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

/**
 * sub - subtracts the top two elements of the stack.
 * @stack:  double head pointer
 * @line_number: line number
 *
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
stack_t *new_node;

new_node = *stack;
if (_len(*stack) < 2 || *stack == NULL)
{
fprintf(stderr, "L%d: can't add, stack too short", line_number);
free_struct(*stack);
exit(EXIT_FAILURE);
}
new_node->next->n -= (*stack)->n;
*stack = (*stack)->next;
free(new_node);
(*stack)->prev = NULL;
}

/**
 * _div - devides the top two elements of the stack.
 * @stack:  double head pointer
 * @line_number: line number
 *
 * Return: void
 */
void _div(stack_t **stack, unsigned int line_number)
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
new_node->next->n /= (*stack)->n;
*stack = (*stack)->next;
free(new_node);
(*stack)->prev = NULL;
}
