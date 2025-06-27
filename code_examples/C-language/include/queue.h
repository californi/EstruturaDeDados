#ifndef QUEUE_H
#define QUEUE_H

#include "common.h"

// Estrutura da Fila com Array Circular
typedef struct {
    DataType data[MAX_SIZE];
    int front;
    int rear;
    int size;
} QueueArray;

// Estrutura da Fila com Lista Ligada
typedef struct QueueNode {
    DataType data;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
    int size;
} QueueLinked;

// Estrutura do Deque (Double-ended Queue)
typedef struct DequeNode {
    DataType data;
    struct DequeNode* next;
    struct DequeNode* prev;
} DequeNode;

typedef struct {
    DequeNode* front;
    DequeNode* rear;
    int size;
} Deque;

// Operações da Fila com Array
void queue_array_init(QueueArray* queue);
bool queue_array_is_empty(QueueArray* queue);
bool queue_array_is_full(QueueArray* queue);
int queue_array_enqueue(QueueArray* queue, DataType value);
int queue_array_dequeue(QueueArray* queue, DataType* value);
int queue_array_front(QueueArray* queue, DataType* value);
int queue_array_size(QueueArray* queue);
void queue_array_print(QueueArray* queue);
void queue_array_clear(QueueArray* queue);

// Operações da Fila com Lista Ligada
void queue_linked_init(QueueLinked* queue);
bool queue_linked_is_empty(QueueLinked* queue);
int queue_linked_enqueue(QueueLinked* queue, DataType value);
int queue_linked_dequeue(QueueLinked* queue, DataType* value);
int queue_linked_front(QueueLinked* queue, DataType* value);
int queue_linked_size(QueueLinked* queue);
void queue_linked_print(QueueLinked* queue);
void queue_linked_clear(QueueLinked* queue);

// Operações do Deque
void deque_init(Deque* deque);
bool deque_is_empty(Deque* deque);
int deque_push_front(Deque* deque, DataType value);
int deque_push_rear(Deque* deque, DataType value);
int deque_pop_front(Deque* deque, DataType* value);
int deque_pop_rear(Deque* deque, DataType* value);
int deque_front(Deque* deque, DataType* value);
int deque_rear(Deque* deque, DataType* value);
int deque_size(Deque* deque);
void deque_print(Deque* deque);
void deque_clear(Deque* deque);

// Funções de demonstração
void demonstrate_queue_array(void);
void demonstrate_queue_linked(void);
void demonstrate_deque(void);

#endif // QUEUE_H

