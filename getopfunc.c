#include <string.h>
#include "monty.h"

/**
 * get_op_func - get op code function
 * @opcode: opcode
 * Return: op code or null
 */

instruction_t *get_op_func(const char *opcode)
{
  int i;
  instruction_t *instruction;
  instruction_t op_funcs[] = {
        {"push", push},
        {"pall", pall},
        {"pint", pint},
        {"pop", pop},
        {"swap", swap},
        {"add", add},
        {"nop", nop},
        {NULL, NULL}
    };
i = 0;

while (op_funcs[i].opcode != NULL)
    {
        if (strcmp(opcode, op_funcs[i].opcode) == 0)
        {
            instruction = malloc(sizeof(instruction_t));
            if (instruction == NULL)
            {
                fprintf(stderr, "Error: Failed to allocate memory\n");
                exit(EXIT_FAILURE);
            }
            instruction->opcode = my_strdup(op_funcs[i].opcode);
            instruction->f = op_funcs[i].f;
            return (instruction);
        }
        i++;
    }
return (NULL);
}

char *my_strdup(const char *str)
{
    size_t len = strlen(str) + 1;
    char *new_str = malloc(len);
    if (new_str != NULL) {
        memcpy(new_str, str, len);
    }
    return (new_str);
}
