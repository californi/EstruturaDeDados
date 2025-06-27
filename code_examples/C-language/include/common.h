#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Definições de constantes
#define MAX_SIZE 100
#define SUCCESS 1
#define FAILURE 0
#define EMPTY -1

// Tipos de dados comuns
typedef int DataType;
typedef enum {
    STACK_EMPTY = -1,
    STACK_FULL = -2,
    QUEUE_EMPTY = -3,
    QUEUE_FULL = -4,
    LIST_EMPTY = -5,
    LIST_FULL = -6,
    INVALID_POSITION = -7,
    MEMORY_ERROR = -8
} ErrorCode;

// Funções utilitárias
void print_error(ErrorCode error);
void print_separator(const char* title);
void pause_execution(void);

#endif // COMMON_H

