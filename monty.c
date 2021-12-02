#include "monty.h"
int stack_environ;

/**
 * main - main function
 * @argc: count of arguments
 * @argv: vector to arguments
 *
 * Return: 0 on success, error on failure
 */

int main(int argc, char **argv)
{
	FILE *fd;
	char *args_line = NULL;
	char **tokens;
	size_t size = 0;
	stack_t *stack = NULL;
	int line_number;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	for (line_number = 1; getline(&args_line, &size, fd) != -1; line_number++)
	{
		tokens = tokenizer(buffer);
		if (tokens == NULL)
			continue;
		get_func(tokens, buffer, &stack, line_number, fd);
		free(tokens);
	}
	free(buffer);
	free_struct(stack);
	fclose(fd);
	return (0);
}
