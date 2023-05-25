#include "monty.h"

/**
 * free_stack - frees stack
 * @head: pointer
 * Return: void
 */


void free_stack(stack_t *head)
{
stack_t *temp;
while (head != NULL)
{
temp = head;
head = head->next;
free(temp);
}
}
