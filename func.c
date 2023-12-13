#include "monty.h"

/**
 * error - Prints an error message and exits the program
 * @str: The error message to be printed
 */
void error(char *str)
{
	write(STDERR_FILENO, str, strlen(str));
}


/**
 * set_stack_value - Sets a global variable to the specified value
 * @value: The value to set the global variable to
 */
void set_stack_value(char *value)
{
	extern char *STACK_NUM;
	STACK_NUM = value;
}

/**
 * is_cmd_acceptable - Checks if a command is acceptable and returns the
 * corresponding instruction_t structure
 * @cmd: The command to check
 * @line_number: The line number in the Monty bytecode file
 *
 * Return: The corresponding instruction_t structure or a default structure
 *         if the command is not acceptable
 */
instruction_t is_cmd_acceptable(char *cmd, int line_number)
{
	char *line;
	int i;
	instruction_t ins[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{NULL, NULL}
	};

	for (i = 0; ins[i].opcode != NULL; i++)
	{
		if (strcmp(cmd, ins[i].opcode) == 0)
			return (ins[i]);
	}
	/** Couldn't find command */
	error("L");
	line = itoa(line_number, 10);
	error(line);
	error(": unknown instruction ");
	error(cmd);
	error("\n");
	exit(EXIT_FAILURE);
}

/**
 * exec_line - Executes the instructions from a line in the Monty bytecode file
 * @buffer: The buffer containing the line from the bytecode file
 * @line_number: The line number in the Monty bytecode file
 * @stk: A pointer to the head of the stack
 */
void exec_line(char buffer[BUFFER_SIZE], int line_number, stack_t **stk)
{
	char *opcode, *value;
	instruction_t ins;

	opcode = strtok(buffer, " ");

	/** Handle a comment */
	if ((opcode != NULL && opcode[0] == '#') || opcode == NULL)
		return;
	value = strtok(NULL, " ");
	if (value == NULL)
		set_stack_value(NULL);
	else
		set_stack_value(value);
	ins = is_cmd_acceptable(opcode, line_number);
	ins.f(stk, line_number);
}

/**
 * itoa - Converts an integer to a string representation in the specified base
 * @num: The integer to convert
 * @base: The base for the conversion
 *
 * Return: A pointer to the resulting string
 */
char *itoa(int num, int base)
{
	int is_negative = 0, length, temp, start, end, i, rem;
	char *str;

	if (num < 0 && base == 10)
	{
		is_negative = 1;
		num = -num;
	}
	length = (num == 0) ? 1 : 0;
	temp = num;
	while (temp != 0)
	{
		temp /= base;
		length++;
	}
	str = (char *)malloc((length + is_negative + 1) * sizeof(char));
	if (str == NULL)
	{
		error("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	i = 0;
	for (; num != 0; num /= base)
	{
		rem = num % base;
		if (rem > 9)
			str[i++] = (rem - 10) + 'a';
		else
			str[i++] = rem + '0';
	}
	if (is_negative && base == 10)
		str[i++] = '-';
	str[i] = '\0';
	start = 0;
	end = i - 1;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
	return (str);
}
