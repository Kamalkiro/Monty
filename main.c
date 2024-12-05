#include "monty.h"

int main(int argc, char **argv)
{
	int i = 0, fd, x, argi, flag = 0;
	char *instructions = _calloc(M), *op = NULL, **ops = malloc(M / 4);
	stack_t *stk = NULL;
	void (*fp)(stack_t **, unsigned int);

	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		free(instructions);
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		dprintf(2, "Error: Can't open file <file>\n");
		free(instructions);
		exit(EXIT_FAILURE);
	}
	read(fd, instructions, M);
	op = strtok(instructions, "\n\r");
	while(op)
	{
		ops[i] = op;
		op = strtok(NULL, "\n\r");
		i++;
	}
	for (i = 0; ops[i]; i++)
	{
		if (*ops[i] == '#')
			continue;
		if (strcmp(ops[i], "stack") == 0)
			flag = 0;
		if (strcmp(ops[i], "queue") == 0)
			flag = 1;
		x = i + 1;
		if (flag == 0)
			fp = choose(ops[i]);
		if (flag == 1)
			fp = execute(ops[i]);
		if (!fp)
		{
			dprintf(2, "L<%d>: unknown instruction <%s>\n", x, ops[i]);
			free(instructions);
			freestacks(&stk);
			free(ops);
			exit(EXIT_FAILURE);
		}
		argi = getarg(ops[i]);
		if (argi >= 0)
			x += argi * 10000;
		else
			x += 1000000000;
		fp(&stk, x);
	}
	free(ops);
	free(instructions);
	freestacks(&stk);
	close(fd);
	return 0;
}