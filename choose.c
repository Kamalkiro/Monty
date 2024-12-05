#include "monty.h"

void (*choose(char *ops))(stack_t **top, unsigned int line_number)
{
	instruction_t ins[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"queue", _nop},
		{"stack", _nop},
		{NULL, NULL},
	};
	int j = 0, x = 0;
	char *turn = _calloc(20);

	while(ops[j] == ' ' && ops[j])
		j++;

	while(ops[j] != ' ' && ops[j])
	{
		turn[x++] = ops[j];
		j++;
	}
	j = 0;
	while (ins[j].opcode)
	{
		if (strcmp(ins[j].opcode, turn) == 0)
		{
			free(turn);
			turn = NULL;
			return(ins[j].f);
		}
		j++;
	}
	if (turn)
	{
		free(turn);
		turn = NULL;
	}
	return NULL;
}