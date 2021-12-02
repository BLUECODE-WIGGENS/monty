#include "monty.h"

/**
 * get_instructions - function to call the function to the instruction
 * @tokens: array of tokens
 * @stack: head of the stack
 * @buffer: buffer
 * @line_number: line number
 * @fd: file
 *
 * Return: Void
 */

void get_func(char **stack_arglist, char *size,
stack_t **stack, unsigned int line_number, FILE *fd)
{
	int cloop = 0;
	char *check = stack_arglist[1];
	instruction_t list_func[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{NULL, NULL}
	};

	if (strcmp(stack_arglist[0], "push") == 0)
	{
		if (!stack_arglist[1] || isdigit(*check) == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free(stack_arglist);
			free(size);
			free_struct(*stack);
			fclose(fd);
			exit(EXIT_FAILURE);
		}
	}
	if (stack_arglist[1])
		stack_environ = atoi(stack_arglist[1]);
	while (list_func[cloop].opcode != NULL)
	{
		if (strcmp(list_func[cloop].opcode, stack_arglist[0]) == 0)
			list_func[cloop].f(stack, line_number);
		cloop++;
	}
}
