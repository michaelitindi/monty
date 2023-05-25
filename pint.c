#include "monty.h"

/**
 * pint - prints value at the top of the stack
 * @pointer: head
 * @i: line number
 * Return: void
 */


void pint(stack_t **head, unsigned int i)
{
if (!*head)
{
fprintf(stderr, "L%u: can't pint, stack empty\n", i);
exit(EXIT_FAILURE);
}
printf("%d\n", (*head)->n);
}
