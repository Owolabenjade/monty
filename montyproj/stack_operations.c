#include "monty.h"

/**
 *push - Pushes an element to the stack.
 *@stack: A pointer to the top of the stack.
 *@line_number: The line number of the opcode.
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = line_number;  /*Assign the value to the node*/
	new_node->next = *stack;
	new_node->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 *pall - Prints all values on the stack.
 *@stack: A pointer to the top of the stack.
 *@line_number: The line number of the opcode.
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 *pop - Removes the top element of the stack.
 *@stack: A pointer to the top of the stack.
 *@line_number: The line number of the opcode.
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 *swap - Swaps the top two elements of the stack.
 *@stack: A pointer to the top of the stack.
 *@line_number: The line number of the opcode.
*/
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 *add - Adds the top two elements of the stack.
 *@stack: A pointer to the top of the stack.
 *@line_number: The line number of the opcode.
*/
void add(stack_t **stack, unsigned int line_number)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->n + (*stack)->next->n;
	pop(stack, line_number);
	(*stack)->n = result;
}

/**
 *nop - Doesn't do anything.
 *@stack: A pointer to the top of the stack.
 *@line_number: The line number of the opcode.
*/
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
