#include "monty.h"


/**
 * pop - removes top element of the stack
 * @head: pointer
 * @i: line number
 * Return: void
 */


void pop(stack_t **head, unsigned int i)
{
stack_t *current;
if (!*head)
{
fprintf(stderr, "L%u: can't pop an empty stack\n", i);
exit(EXIT_FAILURE);
}
current = *head;
*head = (*head)->next;
if (*head)
{
(*head)->prev = NULL;
}
free(current);
}
