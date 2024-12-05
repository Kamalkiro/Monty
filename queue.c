#include "monty.h"

void _pushi(stack_t **top, unsigned int line_number)
{
	int argi;
	stack_t *new = malloc(sizeof(stack_t)), *tmp;

	if (line_number > 1000000000)
	{
		argi = -1;
		line_number %= 1000000000; 
	}
	else if (line_number > 10000)
	{
		argi = line_number / 10000;
		line_number %= 10000; 
	}
	else
		argi = 0;
	if (argi == -1)
	{
		dprintf(2, "L%d: usage: push integer", line_number);
		exit(EXIT_FAILURE);
	}
	new->n = argi;
	if (!*top)
	{
		*top = new;
		(*top)->next = NULL;
		(*top)->prev = NULL;
	}
	else
	{
		while((*top)->next)
			(*top) = (*top)->next;
		new->prev = (*top);
		new->next = NULL;
		(*top)->next = new;
		(*top) = new;
	}
}
