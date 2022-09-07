#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * push - add a node(value) at the top of the stack
 * @top: current top of the stack
 * @line_number: the current line in the monty file
 * Return: Nothing
 */

void push(stack_t **top, unsigned int line_number)
{
	stack_t *node;

	if (!top)
		return;

	node = malloc(sizeof(*node));

	if (!node)
	{
		free(node);
		node = NULL;
		return;
	}

	node->n = line_number;
	node->next = NULL;
	node->prev = NULL;

	if (!(*top))
	{
		*top = node;
		return;
	}

	node->next = *top;
	*top = node;
}


/**
 * pall - print all nodes(value) in the stack
 * @top: top of the stack
 * @line_number: the current line in the monty file
 * Return: Nothing
 */


void pall(stack_t **top, unsigned int line_number)
{
	stack_t *curr;

	(void)line_number;

	if (!top)
		return;

	curr = *top;

	while (curr)
	{
		printf("%d\n", (curr)->n);
		curr = curr->next;
	}

	free_stack(top);
}


/**
 * free_stack - frees all nodes(value) from memory
 * @top : top of the stack;
 * Return: Nothing
 */

void free_stack(stack_t **top)
{
	if (!top)
		return;

	while (*top)
	{
		stack_t *next = (*top)->next;

		free(*top);
		*top = next;
	}

	if (*top != NULL)
		*top = NULL;
}
