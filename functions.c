#include "monty.h"

void _push(stack_t **top, unsigned int line_number)
{
	int argi;
	stack_t *new = malloc(sizeof(stack_t));

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
		while((*top)->prev)
			(*top) = (*top)->prev;
		new->next = (*top);
		(*top)->prev = new;
		(*top) = new;
	}
}
void _pall(stack_t **top, unsigned int line_number)
{
	stack_t *tmp = *top;

	if (!*top || !top)
		return;
	else
	{
		while((*top)->prev)
			(*top) = (*top)->prev;
		while((*top))
		{
			printf("%d\n", (*top)->n);
			(*top) = (*top)->next;
		}
	}
	*top = tmp;
}
void _pint(stack_t **top, unsigned int line_number)
{
	stack_t *tmp = *top;
	
	line_number %= 10000;
	if (!top || !*top)
	{
		dprintf(2, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	while ((*top)->prev)
		*top = (*top)->prev;
	printf("%d\n", (*top)->n);
	*top = tmp;
}
void _pop(stack_t **top, unsigned int line_number)
{	
	stack_t *tmp = *top;
	
	line_number %= 10000;
	if (!top || !*top)
	{
		dprintf(2, "L%d: can't pop, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	while ((*top)->prev)
		*top = (*top)->prev;
	if ((*top)->next)
		((*top)->next)->prev = NULL;
	tmp = (*top)->next;
	free(*top);
	*top = tmp;
}
void _swap(stack_t **top, unsigned int line_number)
{	
	stack_t *tmp = *top, *sw;
	
	line_number %= 10000;
	if (!top || !*top)
	{
		dprintf(2, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	while ((*top)->prev)
		*top = (*top)->prev;
	if (!(*top)->next)
	{
		dprintf(2, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sw = (*top)->next;
	(*top)->next = sw->next;
	(*top)->prev = sw;
	if(sw->next)
		(sw->next)->prev = *top;
	sw->next = *top;
	sw->prev = NULL;
	*top = tmp;
}
void _add(stack_t **top, unsigned int line_number)
{	
	stack_t *tmp = *top, *sw;
	
	line_number %= 10000;
	if (!top || !*top)
	{
		dprintf(2, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	while ((*top)->prev)
		*top = (*top)->prev;
	if (!(*top)->next)
	{
		dprintf(2, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	((*top)->next)->n += (*top)->n;
	((*top)->next)->prev = NULL;
	sw = *top;
	*top = (*top)->next;
	free(sw);
	sw = NULL;
}
void _nop(stack_t **top, unsigned int line_number)
{	
	return;
}
void _sub(stack_t **top, unsigned int line_number)
{	
	stack_t *tmp = *top, *sw;
	
	line_number %= 10000;
	if (!top || !*top)
	{
		dprintf(2, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	while ((*top)->prev)
		*top = (*top)->prev;
	if (!(*top)->next)
	{
		dprintf(2, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	((*top)->next)->n -= (*top)->n;
	((*top)->next)->prev = NULL;
	sw = *top;
	*top = (*top)->next;
	free(sw);
	sw = NULL;
}
void _div(stack_t **top, unsigned int line_number)
{	
	stack_t *tmp = *top, *sw;
	
	line_number %= 10000;
	if (!top || !*top)
	{
		dprintf(2, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	while ((*top)->prev)
		*top = (*top)->prev;
	if (!(*top)->next)
	{
		dprintf(2, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*top)->n == 0)
	{
		dprintf(2, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	((*top)->next)->n /= (*top)->n;
	((*top)->next)->prev = NULL;
	sw = *top;
	*top = (*top)->next;
	free(sw);
	sw = NULL;
}
void _mul(stack_t **top, unsigned int line_number)
{	
	stack_t *tmp = *top, *sw;
	
	line_number %= 10000;
	if (!top || !*top)
	{
		dprintf(2, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	while ((*top)->prev)
		*top = (*top)->prev;
	if (!(*top)->next)
	{
		dprintf(2, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	((*top)->next)->n *= (*top)->n;
	((*top)->next)->prev = NULL;
	sw = *top;
	*top = (*top)->next;
	free(sw);
	sw = NULL;
}
void _mod(stack_t **top, unsigned int line_number)
{	
	stack_t *tmp = *top, *sw;
	
	line_number %= 10000;
	if (!top || !*top)
	{
		dprintf(2, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	while ((*top)->prev)
		*top = (*top)->prev;
	if (!(*top)->next)
	{
		dprintf(2, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*top)->n == 0)
	{
		dprintf(2, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	((*top)->next)->n %= (*top)->n;
	((*top)->next)->prev = NULL;
	sw = *top;
	*top = (*top)->next;
	free(sw);
	sw = NULL;
}
void _pchar(stack_t **top, unsigned int line_number)
{	
	stack_t *tmp = *top;
	
	line_number %= 10000;
	if (!top || !*top)
	{
		dprintf(2, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	while ((*top)->prev)
		*top = (*top)->prev;
	if ((*top)->n > 32 && (*top)->n < 126)
		printf("%c\n", (*top)->n);
	else
	{
		dprintf(2, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	*top = tmp;
}
void _pstr(stack_t **top, unsigned int line_number)
{	
	stack_t *tmp = *top;

	if (!*top || !top)
		return;
	else
	{
		while((*top)->prev)
			(*top) = (*top)->prev;
		while((*top))
		{
			if ((*top)->n < 32 || (*top)->n > 126)
			{
				puts("");
				*top = tmp;
				return;
			}
			printf("%c", (*top)->n);
			(*top) = (*top)->next;
		}
	}
	puts("");
	*top = tmp;
}
void _rotl(stack_t **top, unsigned int line_number)
{	
	stack_t *tmp = *top, *sw;
	
	line_number %= 10000;
	if (!top || !*top)
	{
		return;
	}
	while ((*top)->prev)
		*top = (*top)->prev;
	if (!(*top)->next)
	{
		return;
	}
	sw = *top;
	while(sw->next)
		sw = sw->next;
	((*top)->next)->prev = NULL;
	sw->next = *top;
	(*top)->prev = sw;
	(*top)->next = NULL;
	*top = tmp;
}
void _rotr(stack_t **top, unsigned int line_number)
{	
	stack_t *tmp = *top, *sw;
	
	line_number %= 10000;
	if (!top || !*top)
	{
		return;
	}
	while ((*top)->prev)
		*top = (*top)->prev;
	if (!(*top)->next)
	{
		return;
	}
	sw = *top;
	while(sw->next)
		sw = sw->next;
	(sw->prev)->next = NULL;
	sw->next = *top;
	(*top)->prev = sw;
	sw->prev = NULL;
	*top = tmp;
}
