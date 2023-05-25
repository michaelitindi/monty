#include "monty.h"

/**
 * pall - prints values of the stack
 * @head: pointer
 * @i: not used
 * Return: void
 */


void pall(stack_t **head, unsigned int i)
{
stack_t *current;
(void) i;
if (!*head)
{
return;
}
current = *head;
while (current)
{
printf("%d\n", current->n);
current = current->next;
}
}
