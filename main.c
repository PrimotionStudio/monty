#include "main.h"

char *STACK_NUM;

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
	return 0;
}