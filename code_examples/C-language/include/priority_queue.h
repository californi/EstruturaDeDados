#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "common.h"

// Estrutura para elemento com prioridade
typedef struct {
    DataType data;
    int priority;
} PriorityElement;

// Estrutura da Fila de Prioridade com Heap
typedef struct {
    PriorityElement heap[MAX_SIZE];
    int size;
} PriorityQueue;

// Operações da Fila de Prioridade
void pqueue_init(PriorityQueue* pq);
bool pqueue_is_empty(PriorityQueue* pq);
bool pqueue_is_full(PriorityQueue* pq);
int pqueue_insert(PriorityQueue* pq, DataType value, int priority);
int pqueue_extract_max(PriorityQueue* pq, DataType* value, int* priority);
int pqueue_peek_max(PriorityQueue* pq, DataType* value, int* priority);
int pqueue_size(PriorityQueue* pq);
void pqueue_print(PriorityQueue* pq);
void pqueue_clear(PriorityQueue* pq);

// Funções auxiliares do heap
void heapify_up(PriorityQueue* pq, int index);
void heapify_down(PriorityQueue* pq, int index);
void swap_elements(PriorityElement* a, PriorityElement* b);
int parent(int index);
int left_child(int index);
int right_child(int index);

// Função de demonstração
void demonstrate_priority_queue(void);

#endif // PRIORITY_QUEUE_H

