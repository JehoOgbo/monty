#include "monty.h"

/**
 * push - pushes an element unto the bottom of a linked list
 * @stack: pointer to the last element of the stack
 * @line_number: line number in the byte code
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	int num = bag.holder;

	if (num == -78848)
	{
		dprintf(2, "L%d: usage: push integer\n", line_number);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	current = malloc(sizeof(stack_t));
	if (current == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	current->n = num;
	current->next = NULL;
	if (*stack == NULL)
	{
		current->prev = NULL;
		*stack = current;
		bag.head = current;
		return;
	}
	if (bag.on_off)
	{
		current->prev = *stack;
		(*stack)->next = current;
		*stack = current;
	}
	else
	{
		current->prev = NULL;
		current->next = bag.head;
		bag.head->prev = current;
		bag.head = current;
	}
}

/**
 * pall - prints all elements in the stack from the top
 * @stack: address of last element of stack
 * @line_number: line_number in the bytecode file
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *use;
	(void) line_number;

	use = *stack;
	if (use == NULL)
	{
		return;
	}

	while (use)
	{
		printf("%d\n", use->n);
		use = use->prev;
	}
}
/**
 * pint - prints the value at the top of the stack followed by a new line
 * @stack: address of last element of the stack
 * @line_number: line_number in the bytecode file
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		dprintf(2, "L%d: can't pint, stack empty\n", line_number);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack
 * @stack: address of last element of the stack
 * @line_number: line number in the bytecode file
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *remove;

	if (*stack == NULL)
	{
		dprintf(2, "L%d: can't pop an empty stack\n", line_number);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	remove = *stack;
	*stack = (*stack)->prev;
	free(remove);
}

/**
 * swap - swap the top two elements of the stack
 * @stack: address of last element of the stack
 * @line_number: line number in the bytecode file
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int a, b;

	if (*stack == NULL)
	{
		dprintf(2, "L%d: can't swap, stack too short\n", line_number);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->prev == NULL)
	{
		dprintf(2, "L%d: can't swap, stack too short\n", line_number);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}

	a = (*stack)->n;
	b = (*stack)->prev->n;
	(*stack)->n = b;
	(*stack)->prev->n = a;
}
