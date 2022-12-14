#include "monty.h"

/**
 * stackd - sets the format of data to a stack (LIFO)
 * @stack: pointer to the last element of the data structure
 * @line_number: line_number inside the byte code file
 *
 * Return: void
 */
void stackd(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	bag.on_off = 1;
}

/**
 * queue - sets the format of data to a queue (FIFO)
 * @stack: pointer to the last element of the data structure
 * @line_number: line_number inside the bytecode file
 *
 * Return: void
 *
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	bag.on_off = 0;
}
