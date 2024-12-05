#include "monty.h"

void freestacks(stack_t **top)
{
	stack_t *tmp;

	if (!top || !*top)
		return;
	while((*top)->prev)
	{
		(*top) = (*top)->prev;
	}
	while((*top)->next)
	{
		tmp = ((*top)->next);
		free(*top);
		*top = tmp;
	}
	free(*top);
}