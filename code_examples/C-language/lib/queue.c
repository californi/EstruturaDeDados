#include "../include/queue.h"

// ========================================
// IMPLEMENTAÇÃO DA FILA COM ARRAY CIRCULAR
// ========================================

void queue_array_init(QueueArray* queue) {
    if (queue == NULL) return;
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
}

bool queue_array_is_empty(QueueArray* queue) {
    if (queue == NULL) return true;
    return queue->size == 0;
}

bool queue_array_is_full(QueueArray* queue) {
    if (queue == NULL) return true;
    return queue->size == MAX_SIZE;
}

int queue_array_enqueue(QueueArray* queue, DataType value) {
    if (queue == NULL) return FAILURE;
    
    if (queue_array_is_full(queue)) {
        print_error(QUEUE_FULL);
        return FAILURE;
    }
    
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->data[queue->rear] = value;
    queue->size++;
    
    return SUCCESS;
}

int queue_array_dequeue(QueueArray* queue, DataType* value) {
    if (queue == NULL || value == NULL) return FAILURE;
    
    if (queue_array_is_empty(queue)) {
        print_error(QUEUE_EMPTY);
        return FAILURE;
    }
    
    *value = queue->data[queue->front];
    queue->front = (queue->front + 1) % MAX_SIZE;
    queue->size--;
    
    return SUCCESS;
}

int queue_array_front(QueueArray* queue, DataType* value) {
    if (queue == NULL || value == NULL) return FAILURE;
    
    if (queue_array_is_empty(queue)) {
        print_error(QUEUE_EMPTY);
        return FAILURE;
    }
    
    *value = queue->data[queue->front];
    return SUCCESS;
}

int queue_array_size(QueueArray* queue) {
    if (queue == NULL) return 0;
    return queue->size;
}

void queue_array_print(QueueArray* queue) {
    if (queue == NULL) {
        printf("Fila inválida!\n");
        return;
    }
    
    if (queue_array_is_empty(queue)) {
        printf("Fila vazia!\n");
        return;
    }
    
    printf("Fila (frente -> trás): ");
    int current = queue->front;
    for (int i = 0; i < queue->size; i++) {
        printf("%d ", queue->data[current]);
        current = (current + 1) % MAX_SIZE;
    }
    printf("\n");
}

void queue_array_clear(QueueArray* queue) {
    if (queue == NULL) return;
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
}

// ========================================
// IMPLEMENTAÇÃO DA FILA COM LISTA LIGADA
// ========================================

void queue_linked_init(QueueLinked* queue) {
    if (queue == NULL) return;
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
}

bool queue_linked_is_empty(QueueLinked* queue) {
    if (queue == NULL) return true;
    return queue->front == NULL;
}

int queue_linked_enqueue(QueueLinked* queue, DataType value) {
    if (queue == NULL) return FAILURE;
    
    QueueNode* new_node = (QueueNode*)malloc(sizeof(QueueNode));
    if (new_node == NULL) {
        print_error(MEMORY_ERROR);
        return FAILURE;
    }
    
    new_node->data = value;
    new_node->next = NULL;
    
    if (queue_linked_is_empty(queue)) {
        queue->front = new_node;
        queue->rear = new_node;
    } else {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
    
    queue->size++;
    return SUCCESS;
}

int queue_linked_dequeue(QueueLinked* queue, DataType* value) {
    if (queue == NULL || value == NULL) return FAILURE;
    
    if (queue_linked_is_empty(queue)) {
        print_error(QUEUE_EMPTY);
        return FAILURE;
    }
    
    QueueNode* temp = queue->front;
    *value = temp->data;
    queue->front = temp->next;
    
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    
    free(temp);
    queue->size--;
    
    return SUCCESS;
}

int queue_linked_front(QueueLinked* queue, DataType* value) {
    if (queue == NULL || value == NULL) return FAILURE;
    
    if (queue_linked_is_empty(queue)) {
        print_error(QUEUE_EMPTY);
        return FAILURE;
    }
    
    *value = queue->front->data;
    return SUCCESS;
}

int queue_linked_size(QueueLinked* queue) {
    if (queue == NULL) return 0;
    return queue->size;
}

void queue_linked_print(QueueLinked* queue) {
    if (queue == NULL) {
        printf("Fila inválida!\n");
        return;
    }
    
    if (queue_linked_is_empty(queue)) {
        printf("Fila vazia!\n");
        return;
    }
    
    printf("Fila (frente -> trás): ");
    QueueNode* current = queue->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void queue_linked_clear(QueueLinked* queue) {
    if (queue == NULL) return;
    
    DataType temp;
    while (!queue_linked_is_empty(queue)) {
        queue_linked_dequeue(queue, &temp);
    }
}

// ========================================
// IMPLEMENTAÇÃO DO DEQUE
// ========================================

void deque_init(Deque* deque) {
    if (deque == NULL) return;
    deque->front = NULL;
    deque->rear = NULL;
    deque->size = 0;
}

bool deque_is_empty(Deque* deque) {
    if (deque == NULL) return true;
    return deque->front == NULL;
}

int deque_push_front(Deque* deque, DataType value) {
    if (deque == NULL) return FAILURE;
    
    DequeNode* new_node = (DequeNode*)malloc(sizeof(DequeNode));
    if (new_node == NULL) {
        print_error(MEMORY_ERROR);
        return FAILURE;
    }
    
    new_node->data = value;
    new_node->next = deque->front;
    new_node->prev = NULL;
    
    if (deque_is_empty(deque)) {
        deque->front = new_node;
        deque->rear = new_node;
    } else {
        deque->front->prev = new_node;
        deque->front = new_node;
    }
    
    deque->size++;
    return SUCCESS;
}

int deque_push_rear(Deque* deque, DataType value) {
    if (deque == NULL) return FAILURE;
    
    DequeNode* new_node = (DequeNode*)malloc(sizeof(DequeNode));
    if (new_node == NULL) {
        print_error(MEMORY_ERROR);
        return FAILURE;
    }
    
    new_node->data = value;
    new_node->next = NULL;
    new_node->prev = deque->rear;
    
    if (deque_is_empty(deque)) {
        deque->front = new_node;
        deque->rear = new_node;
    } else {
        deque->rear->next = new_node;
        deque->rear = new_node;
    }
    
    deque->size++;
    return SUCCESS;
}

int deque_pop_front(Deque* deque, DataType* value) {
    if (deque == NULL || value == NULL) return FAILURE;
    
    if (deque_is_empty(deque)) {
        print_error(QUEUE_EMPTY);
        return FAILURE;
    }
    
    DequeNode* temp = deque->front;
    *value = temp->data;
    deque->front = temp->next;
    
    if (deque->front == NULL) {
        deque->rear = NULL;
    } else {
        deque->front->prev = NULL;
    }
    
    free(temp);
    deque->size--;
    
    return SUCCESS;
}

int deque_pop_rear(Deque* deque, DataType* value) {
    if (deque == NULL || value == NULL) return FAILURE;
    
    if (deque_is_empty(deque)) {
        print_error(QUEUE_EMPTY);
        return FAILURE;
    }
    
    DequeNode* temp = deque->rear;
    *value = temp->data;
    deque->rear = temp->prev;
    
    if (deque->rear == NULL) {
        deque->front = NULL;
    } else {
        deque->rear->next = NULL;
    }
    
    free(temp);
    deque->size--;
    
    return SUCCESS;
}

int deque_front(Deque* deque, DataType* value) {
    if (deque == NULL || value == NULL) return FAILURE;
    
    if (deque_is_empty(deque)) {
        print_error(QUEUE_EMPTY);
        return FAILURE;
    }
    
    *value = deque->front->data;
    return SUCCESS;
}

int deque_rear(Deque* deque, DataType* value) {
    if (deque == NULL || value == NULL) return FAILURE;
    
    if (deque_is_empty(deque)) {
        print_error(QUEUE_EMPTY);
        return FAILURE;
    }
    
    *value = deque->rear->data;
    return SUCCESS;
}

int deque_size(Deque* deque) {
    if (deque == NULL) return 0;
    return deque->size;
}

void deque_print(Deque* deque) {
    if (deque == NULL) {
        printf("Deque inválido!\n");
        return;
    }
    
    if (deque_is_empty(deque)) {
        printf("Deque vazio!\n");
        return;
    }
    
    printf("Deque (frente -> trás): ");
    DequeNode* current = deque->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void deque_clear(Deque* deque) {
    if (deque == NULL) return;
    
    DataType temp;
    while (!deque_is_empty(deque)) {
        deque_pop_front(deque, &temp);
    }
}

// ========================================
// FUNÇÕES DE DEMONSTRAÇÃO
// ========================================

void demonstrate_queue_array(void) {
    print_separator("DEMONSTRAÇÃO: FILA COM ARRAY CIRCULAR");
    
    QueueArray queue;
    queue_array_init(&queue);
    
    printf("1. Fila inicializada\n");
    printf("   Vazia? %s\n", queue_array_is_empty(&queue) ? "Sim" : "Não");
    printf("   Tamanho: %d\n", queue_array_size(&queue));
    
    printf("\n2. Inserindo elementos: 10, 20, 30, 40, 50\n");
    queue_array_enqueue(&queue, 10);
    queue_array_enqueue(&queue, 20);
    queue_array_enqueue(&queue, 30);
    queue_array_enqueue(&queue, 40);
    queue_array_enqueue(&queue, 50);
    
    printf("   ");
    queue_array_print(&queue);
    printf("   Tamanho: %d\n", queue_array_size(&queue));
    
    DataType value;
    printf("\n3. Consultando a frente\n");
    if (queue_array_front(&queue, &value) == SUCCESS) {
        printf("   Frente: %d\n", value);
    }
    
    printf("\n4. Removendo 2 elementos\n");
    if (queue_array_dequeue(&queue, &value) == SUCCESS) {
        printf("   Removido: %d\n", value);
    }
    if (queue_array_dequeue(&queue, &value) == SUCCESS) {
        printf("   Removido: %d\n", value);
    }
    
    printf("   ");
    queue_array_print(&queue);
    printf("   Tamanho: %d\n", queue_array_size(&queue));
    
    printf("\n5. Inserindo mais elementos: 60, 70\n");
    queue_array_enqueue(&queue, 60);
    queue_array_enqueue(&queue, 70);
    
    printf("   ");
    queue_array_print(&queue);
    printf("   Tamanho: %d\n", queue_array_size(&queue));
}

void demonstrate_queue_linked(void) {
    print_separator("DEMONSTRAÇÃO: FILA COM LISTA LIGADA");
    
    QueueLinked queue;
    queue_linked_init(&queue);
    
    printf("1. Fila inicializada\n");
    printf("   Vazia? %s\n", queue_linked_is_empty(&queue) ? "Sim" : "Não");
    printf("   Tamanho: %d\n", queue_linked_size(&queue));
    
    printf("\n2. Inserindo elementos: 100, 200, 300, 400, 500\n");
    queue_linked_enqueue(&queue, 100);
    queue_linked_enqueue(&queue, 200);
    queue_linked_enqueue(&queue, 300);
    queue_linked_enqueue(&queue, 400);
    queue_linked_enqueue(&queue, 500);
    
    printf("   ");
    queue_linked_print(&queue);
    printf("   Tamanho: %d\n", queue_linked_size(&queue));
    
    DataType value;
    printf("\n3. Consultando a frente\n");
    if (queue_linked_front(&queue, &value) == SUCCESS) {
        printf("   Frente: %d\n", value);
    }
    
    printf("\n4. Removendo 3 elementos\n");
    for (int i = 0; i < 3; i++) {
        if (queue_linked_dequeue(&queue, &value) == SUCCESS) {
            printf("   Removido: %d\n", value);
        }
    }
    
    printf("   ");
    queue_linked_print(&queue);
    printf("   Tamanho: %d\n", queue_linked_size(&queue));
    
    printf("\n5. Limpando a fila\n");
    queue_linked_clear(&queue);
    printf("   ");
    queue_linked_print(&queue);
    printf("   Vazia? %s\n", queue_linked_is_empty(&queue) ? "Sim" : "Não");
}

void demonstrate_deque(void) {
    print_separator("DEMONSTRAÇÃO: DEQUE (FILA DUPLA)");
    
    Deque deque;
    deque_init(&deque);
    
    printf("1. Deque inicializado\n");
    printf("   Vazio? %s\n", deque_is_empty(&deque) ? "Sim" : "Não");
    printf("   Tamanho: %d\n", deque_size(&deque));
    
    printf("\n2. Inserindo na frente: 20, 10\n");
    deque_push_front(&deque, 20);
    deque_push_front(&deque, 10);
    
    printf("   ");
    deque_print(&deque);
    
    printf("\n3. Inserindo no final: 30, 40\n");
    deque_push_rear(&deque, 30);
    deque_push_rear(&deque, 40);
    
    printf("   ");
    deque_print(&deque);
    printf("   Tamanho: %d\n", deque_size(&deque));
    
    DataType value;
    printf("\n4. Consultando extremos\n");
    if (deque_front(&deque, &value) == SUCCESS) {
        printf("   Frente: %d\n", value);
    }
    if (deque_rear(&deque, &value) == SUCCESS) {
        printf("   Trás: %d\n", value);
    }
    
    printf("\n5. Removendo da frente e do final\n");
    if (deque_pop_front(&deque, &value) == SUCCESS) {
        printf("   Removido da frente: %d\n", value);
    }
    if (deque_pop_rear(&deque, &value) == SUCCESS) {
        printf("   Removido do final: %d\n", value);
    }
    
    printf("   ");
    deque_print(&deque);
    printf("   Tamanho: %d\n", deque_size(&deque));
    
    printf("\n6. Limpando o deque\n");
    deque_clear(&deque);
    printf("   ");
    deque_print(&deque);
    printf("   Vazio? %s\n", deque_is_empty(&deque) ? "Sim" : "Não");
}

