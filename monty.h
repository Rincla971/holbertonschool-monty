#ifndef __MONTY__
#define __MONTY__
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

extern int error;

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
extern char *global_token;
void __pop(stack_t **stack, unsigned int line_number);
void __swap(stack_t **stack, unsigned int line_number);
void __push(char *token,stack_t **stack, unsigned int line_number);
void __pall(stack_t **stack,unsigned int line_number);
void __nop(stack_t **stack,unsigned int line_number);
int get_op_func(char *line, stack_t **stack,unsigned int line_number);
void __pint(stack_t **stack,unsigned int line_number);
void free_all(stack_t *stack, char *line, FILE *ptr);
void __pop(stack_t **stack, unsigned int line_number);
void __add(stack_t **stack, unsigned int line_number);
#endif
