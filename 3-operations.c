#include "monty.h"

/**
 * add - add the top two elements of the stack
 * @stack: pointer to the last element of stack
 * @line_number: line number in the byte code
 *
 * Description: the sum is stored in the second top element and the top
 *		element is removed making the stack shorter.
 *
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	int a, b;
	stack_t *new = *stack;

	if (*stack == NULL)
	{
		dprintf(2, "L%d: can't add, stack too short\n", line_number);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->prev == NULL)
	{
		dprintf(2, "L%d: can't add, stack too short\n", line_number);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	a = new->n;
	b = new->prev->n;

	new->prev->n = a + b;
	*stack = new->prev;
	free(new);
}

/**
 * nop - this opcode doesn't do anything
 * @stack: pointer to the last element of the stack
 * @line_number: line number in the byte code
 *
 * Return: void
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

/**
 * sub - subtract the top element from the second top element of the stack
 * @stack: pointer to the last element of stack
 * @line_number: line number in the byte code
 *
 * Description: the difference is stored in the second top element and the top
 * element is removed making the stack shorter.
 *
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int a, b;
	stack_t *new = *stack;

	if (*stack == NULL)
	{
		dprintf(2, "L%d: can't sub, stack too short\n", line_number);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->prev == NULL)
	{
		dprintf(2, "L%d: can't sub, stack too short\n", line_number);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	a = new->n;
	b = new->prev->n;

	new->prev->n = b - a;
	*stack = new->prev;
	free(new);
}

/**
 * divide - divides the second top element of the stack by the top element
 * @stack: pointer to the last element of stack
 * @line_number: line number in the byte code
 *
 * Description: the dividend is stored in the second top element and the top
 * element is removed making the stack shorter.
 * Exit if division by 0 is imminent
 *
 * Return: void
 */
void divide(stack_t **stack, unsigned int line_number)
{
	int a, b;
	stack_t *new = *stack;

	if (*stack == NULL)
	{
		dprintf(2, "L%d: can't div, stack too short\n", line_number);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->prev == NULL)
	{
		dprintf(2, "L%d: can't div, stack too short\n", line_number);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	a = new->n;
	if (a == 0)
	{
		dprintf(2, "L%d: division by zero\n", line_number);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	b = new->prev->n;

	new->prev->n = b / a;
	*stack = new->prev;
	free(new);
}

/**
 * mul - multipy the second elements of the stack by the top element
 * @stack: pointer to the last element of stack
 * @line_number: line number in the byte code
 *
 * Description: the product is stored in the second top element and the top
 * element is removed making the stack shorter.
 *
 * Return: void
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int a, b;
	stack_t *new = *stack;

	if (*stack == NULL)
	{
		dprintf(2, "L%d: can't mul, stack too short\n", line_number);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->prev == NULL)
	{
		dprintf(2, "L%d: can't mul, stack too short\n", line_number);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	a = new->n;
	b = new->prev->n;

	new->prev->n = a * b;
	*stack = new->prev;
	free(new);
}
