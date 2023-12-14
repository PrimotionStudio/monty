#include "monty.h"

char *STACK_NUM;
void free_stack(stack_t *stack);

/**
 * main - Entry point for the Monty bytecode interpreter
 * @argc: Number of command-line arguments
 * @argv: Array of strings containing the command-line arguments
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char const *argv[])
{
	FILE *fp;
	char buffer[BUFFER_SIZE];
	int line_number = 0;
	stack_t *stk = NULL;

	if (argc != 2)
	{
		error("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen((char *)argv[1], "r");
	if (!fp)
	{
		error("Error: Can't open file ");
		error((char *)argv[1]);
		error("\n");
		exit(EXIT_FAILURE);
	}

	while (fgets(buffer, BUFFER_SIZE, fp))
	{
		buffer[strcspn(buffer, "\n")] = '\0';
		++line_number;
		exec_line(buffer, line_number, &stk);
	}
	fclose(fp);
	/* free_stk(&stk); */
	return 0;
}
