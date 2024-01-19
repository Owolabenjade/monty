#include "monty.h"

instruction_t instructions[] = {
		{"push", push},
			{"pall", pall},
				{"pint", pint},
					{"pop", pop},
						{"swap", swap},
							{"add", add},
								{"nop", nop},
									{NULL, NULL}
};

/**
 *  * main - Entry point of the Monty bytecodes interpreter
 *   * @argc: Number of arguments
 *    * @argv: Array of arguments
 *     * Return: EXIT_SUCCESS on success or EXIT_FAILURE on failure
 *      */
int main(int argc, char **argv)
{
		FILE *file;
			char *line = NULL;
				size_t len = 0;
					ssize_t read;
						unsigned int line_number = 0;
							char *opcode;
								stack_t *stack = NULL;

									if (argc != 2)
											{
														fprintf(stderr, "USAGE: monty file\n");
																exit(EXIT_FAILURE);
																	}

										file = fopen(argv[1], "r");
											if (file == NULL)
													{
																fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
																		exit(EXIT_FAILURE);
																			}

												while ((read = getline(&line, &len, file)) != -1)
														{
																	line_number++;
																			opcode = strtok(line, "\n ");
																					if (opcode)
																								{
																												execute_opcode(opcode, &stack, line_number);
																														}
																						}

													free_stack(&stack);
														free(line);
															fclose(file);
																return (EXIT_SUCCESS);
}

/**
 *  * execute_opcode - Executes the function associated with the opcode
 *   * @opcode: The opcode to execute
 *    * @stack: Double pointer to the top of the stack
 *     * @line_number: The line number where the opcode is located
 *      */
void execute_opcode(char *opcode, stack_t **stack, unsigned int line_number)
{
		int i = 0;

			while (instructions[i].opcode)
					{
								if (strcmp(instructions[i].opcode, opcode) == 0)
											{
															instructions[i].f(stack, line_number);
																		return;
																				}
										i++;
											}

				fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
					exit(EXIT_FAILURE);
}

/**
 *  * free_stack - Frees a stack
 *   * @stack: Pointer to the top of the stack
 *    */
void free_stack(stack_t **stack)
{
		stack_t *temp;

			while (*stack)
					{
								temp = (*stack)->next;
										free(*stack);
												*stack = temp;
													}
				}
