#include "monty.h"

/**
 * push - pushes element to the stack
 * @head: pointer to head
 * @i: line number
 * Return: void
 */

void push(stack_t **head, unsigned int i)
{
int x;
stack_t *new_node;
char *arg = inst.arg;
if (!arg)
{
fprintf(stderr, "L%u: usage: push integer\n", i);
exit(EXIT_FAILURE);
}
x = atoi(arg);
new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
new_node->n = x;
new_node->prev = NULL;
new_node->next = *head;

if (*head)
{
(*head)->prev = new_node;
}
*head = new_node;
}
