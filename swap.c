#include "monty.h"

/**
 * swap - swaps the values of the two first elements
 * @head: pointer
 * @i: line number
 * Return: void
 */

void swap(stack_t **head, unsigned int i)
{
stack_t *value1, *value2;
int temp;


if (*head == NULL || (*head)->next == NULL)
{
fprintf(stderr, "L%u: can't swap, stack too short\n", i);
exit(EXIT_FAILURE);
}
value1 = *head;
value2 = (*head)->next;
temp = value1->n;
value1->n = value2->n;
value2->n = temp;
}
