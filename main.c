#include <stdio.h>
#include "monty.h"


instr_t inst = {NULL, NULL, NULL, 0, 1};
/**
 * main - interpreter
 * @argc: no of arguments
 * @argv: file location
 * Return: void
 */
#define MAX_LINE_LENGTH 1000

int main(int argc, char *argv[])
{
char line[MAX_LINE_LENGTH];
  unsigned int line_number = 0;
  stack_t *head = NULL;
  FILE *file;
if (argc != 2) {
        fprintf(stderr, "Usage: ./program_name file\n");
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", argv[1]);
        return 1;
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        line_number++;

        if (line[strlen(line) - 1] == '\n')
            line[strlen(line) - 1] = '\0';


     run_op(&head, line, line_number, file);
    }

    fclose(file);
    free_stack(head);

    return (0);
}
