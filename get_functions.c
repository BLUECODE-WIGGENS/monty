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

void get_func(char **tokens, char *buffer,
stack_t **stack, unsigned int line_number, FILE *fd)
{
	int i = 0;
	char *check = tokens[1];
	instruction_t op_codes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{NULL, NULL}
	};

	if (strcmp(tokens[0], "push") == 0)
	{
		if (!tokens[1] || isdigit(*check) == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free(tokens);
			free(buffer);
			free_struct(*stack);
			fclose(fd);
			exit(EXIT_FAILURE);
		}
	}
	if (tokens[1])
		stack_environ = atoi(tokens[1]);
	while (op_codes[i].opcode != NULL)
	{
		if (strcmp(op_codes[i].opcode, tokens[0]) == 0)
			op_codes[i].f(stack, line_number);
		i++;
	}
}
