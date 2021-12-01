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
size_t args_len = 0, cloop;
char array_size[128] = "", *arguments = array_size;

arguments = strtok(NULL, SEPERATORS);

if (arguments == NULL)
{
dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
free_struct(*stack);
exit(EXIT_FAILURE);
}

args_len = strlen(arguments);
for (cloop = 0; cloop < args_len; cloop++)
if (!isdigit(arguments[cloop]) && arguments[0] != "-")
{
dprintf(STDERR_FILENO, "L%u: usage: push interger\n", line_number);
free_struct(*stack);
exit(EXIT_FAILURE);
}
if (stack_environ == 's')
add_newNode(stack, atoi(arguments));

if (stack_environ == 'q')
add_queueNode(stack, atoi(arguments));
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
