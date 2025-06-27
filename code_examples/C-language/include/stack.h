#ifndef STACK_H
#define STACK_H

#include "common.h"

// Estrutura da Pilha com Array
typedef struct {
    DataType data[MAX_SIZE];
    int top;
} StackArray;

// Estrutura da Pilha com Lista Ligada
typedef struct StackNode {
    DataType data;
    struct StackNode* next;
} StackNode;

typedef struct {
    StackNode* top;
    int size;
} StackLinked;

// Operações da Pilha com Array
void stack_array_init(StackArray* stack);
bool stack_array_is_empty(StackArray* stack);
bool stack_array_is_full(StackArray* stack);
int stack_array_push(StackArray* stack, DataType value);
int stack_array_pop(StackArray* stack, DataType* value);
int stack_array_peek(StackArray* stack, DataType* value);
int stack_array_size(StackArray* stack);
void stack_array_print(StackArray* stack);
void stack_array_clear(StackArray* stack);

// Operações da Pilha com Lista Ligada
void stack_linked_init(StackLinked* stack);
bool stack_linked_is_empty(StackLinked* stack);
int stack_linked_push(StackLinked* stack, DataType value);
int stack_linked_pop(StackLinked* stack, DataType* value);
int stack_linked_peek(StackLinked* stack, DataType* value);
int stack_linked_size(StackLinked* stack);
void stack_linked_print(StackLinked* stack);
void stack_linked_clear(StackLinked* stack);

// Funções de demonstração
void demonstrate_stack_array(void);
void demonstrate_stack_linked(void);

#endif // STACK_H

