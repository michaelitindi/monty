#include "monty.h"

/**
 * run_op - runs op codes
 * @head: pointer
 * Return: void
 */
void run_op(stack_t **head, char *line,  unsigned int line_number)
{
char *opcode, *arg;
instruction_t *op_func;
 opcode = strtok(line, " \t\n");
    if (opcode == NULL || opcode[0] == '#')
    {
        return;
    }
    if (strcmp(opcode, "push") == 0)
    {
        arg = strtok(NULL, " \t\n");
        if (arg == NULL || !isdigit(*arg))
        {
            fprintf(stderr, "L%u: usage: push integer\n", line_number);
            free_stack(*head);
            fclose(inst.file);
            exit(EXIT_FAILURE);
        }
    }

    op_func = get_op_func(opcode);
    if (op_func == NULL)
    {
        fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
        free_stack(*head);
        fclose(inst.file);
        exit(EXIT_FAILURE);
    }
    op_func->f(head, line_number);
}
