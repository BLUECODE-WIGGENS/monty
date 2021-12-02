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
	char *args_line = NULL, **arg_list;
	size_t size = 0;
	stack_t *stack = NULL;
	int line_number = 1;

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
		arg_list = argument_block(args_line);
		if (arg_list == NULL)
			continue;
		get_func(arg_list, args_line, &stack, line_number, fd);
		free(arg_list);
	}
	free(args_line);
	free_struct(stack);
	fclose(fd);
	return (0);
}

/**
 *argument_block - function to brake a string into tokens
 *@string: string to be tokenized
 *
 *Return: array of tokens
 */
char **argument_block(char *string)
{

	int cloop = 0;
	char *argument, **stack_arglist, *seperators = SEPERATORS;

	stack_arglist = malloc(sizeof(char *) * 32);
	if (stack_arglist == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	*stack_arglist = NULL;
	argument = strtok(string, seperators);
	while (argument != NULL)
	{
		stack_arglist[cloop] = argument;
		cloop++;
		argument = strtok(NULL, seperators);
	}
	if ((argument == NULL && *stack_arglist == NULL)
	 || *stack_arglist[0] == COMMENT)
	{
		free(stack_arglist);
		free(argument);
		return (NULL);
	}
	stack_arglist[cloop] = NULL;
	return (stack_arglist);
}
