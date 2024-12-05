#include "monty.h"

char *_calloc(int n)
{
	char *ret = malloc(n);
	int i = 0;

	while (i < n)
	{
		ret[i] = '\0';
		i++;
	}
	return ret;
}