#include "monty.h"

void error(char *str)
{
	write(STDERR_FILENO, str, strlen(str));
}
void set_stack_value(char *value)
{
	extern char *STACK_NUM;
	STACK_NUM = value;
}
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

void exec_line(char buffer[BUFFER_SIZE], int line_number, stack_t **stk)
{
	char *opcode, *value;
	instruction_t ins;

	opcode = strtok(buffer, " ");

	/** Handle a comment */
	/**if (strcmp(opcode[0], "#"))
	  return;*/
	value = strtok(NULL, " ");
	if (value == NULL)
		set_stack_value(NULL);
	else
		set_stack_value(value);
	ins = is_cmd_acceptable(opcode, line_number);
	ins.f(stk, line_number);
}

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
