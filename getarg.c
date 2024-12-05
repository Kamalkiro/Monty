#include "monty.h"

int getarg(char *instro)
{
	int ret = 0, i = 0;
	char *argi = _calloc(6);

	while (instro[i] == ' ' && instro[i])
		i++;
	while (instro[i] != ' ' && instro[i])
		i++;
	i++;
	while (instro[i] != ' ' && instro[i])
		argi[ret++] = instro[i++];
	if (!*argi || *argi < 48 || *argi > 57)
	{
		free(argi);
		return -1000;
	}
	else
		ret = atoi(argi);
	free(argi);
	return ret;
}