#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdarg.h>
#include <ctype.h>
#include <sys/types.h>
#include <string.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct op_instr - opcode
 * @opcode: opcode
 * @arg: arg
 * Description: op code
 */

typedef struct op_instr
{
char *cont;
FILE *file;
char *arg;
int lifo;
unsigned int line_number;
} instr_t;

extern instr_t inst;
void push(stack_t **head, unsigned int i);
void pall(stack_t **head, unsigned int i);
void pint(stack_t **head, unsigned int i);
void pop(stack_t **head, unsigned int i);
void swap(stack_t **head, unsigned int i);
void add(stack_t **head, unsigned int i);
void nop(stack_t **head, unsigned int i);
void free_stack(stack_t *head);
void run_op(stack_t **head, char *line, unsigned int line_number);
instruction_t *get_op_func(const char *opcode);
char *my_strdup(const char *str);

#endif
