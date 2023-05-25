#include "monty.h"

/**
 * add - add the values of top two elements
 * @head: pointer
 * @i: line number
 * Return: void
 */

void add(stack_t **head, unsigned int i)
{
stack_t *value1, *value2;

if (*head == NULL || (*head)->next == NULL)
{
fprintf(stderr, "L%u: can't add, stack too short\n", i);
exit(EXIT_FAILURE);
}
value1 = *head;
value2 = (*head)->next;
value2->n += value1->n;
*head = value2;
value2->prev = NULL;
free(value1);
}
