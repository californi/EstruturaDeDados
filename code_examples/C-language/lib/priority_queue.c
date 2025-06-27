#include "../include/priority_queue.h"

// ========================================
// IMPLEMENTAÇÃO DA FILA DE PRIORIDADE COM HEAP
// ========================================

void pqueue_init(PriorityQueue* pq) {
    if (pq == NULL) return;
    pq->size = 0;
}

bool pqueue_is_empty(PriorityQueue* pq) {
    if (pq == NULL) return true;
    return pq->size == 0;
}

bool pqueue_is_full(PriorityQueue* pq) {
    if (pq == NULL) return true;
    return pq->size == MAX_SIZE;
}

int pqueue_insert(PriorityQueue* pq, DataType value, int priority) {
    if (pq == NULL) return FAILURE;
    
    if (pqueue_is_full(pq)) {
        print_error(QUEUE_FULL);
        return FAILURE;
    }
    
    // Inserir no final do heap
    pq->heap[pq->size].data = value;
    pq->heap[pq->size].priority = priority;
    pq->size++;
    
    // Restaurar propriedade do heap (subir)
    heapify_up(pq, pq->size - 1);
    
    return SUCCESS;
}

int pqueue_extract_max(PriorityQueue* pq, DataType* value, int* priority) {
    if (pq == NULL || value == NULL || priority == NULL) return FAILURE;
    
    if (pqueue_is_empty(pq)) {
        print_error(QUEUE_EMPTY);
        return FAILURE;
    }
    
    // Salvar o elemento de maior prioridade (raiz)
    *value = pq->heap[0].data;
    *priority = pq->heap[0].priority;
    
    // Mover último elemento para a raiz
    pq->heap[0] = pq->heap[pq->size - 1];
    pq->size--;
    
    // Restaurar propriedade do heap (descer)
    if (pq->size > 0) {
        heapify_down(pq, 0);
    }
    
    return SUCCESS;
}

int pqueue_peek_max(PriorityQueue* pq, DataType* value, int* priority) {
    if (pq == NULL || value == NULL || priority == NULL) return FAILURE;
    
    if (pqueue_is_empty(pq)) {
        print_error(QUEUE_EMPTY);
        return FAILURE;
    }
    
    *value = pq->heap[0].data;
    *priority = pq->heap[0].priority;
    
    return SUCCESS;
}

int pqueue_size(PriorityQueue* pq) {
    if (pq == NULL) return 0;
    return pq->size;
}

void pqueue_print(PriorityQueue* pq) {
    if (pq == NULL) {
        printf("Fila de prioridade inválida!\n");
        return;
    }
    
    if (pqueue_is_empty(pq)) {
        printf("Fila de prioridade vazia!\n");
        return;
    }
    
    printf("Fila de Prioridade (valor:prioridade): ");
    for (int i = 0; i < pq->size; i++) {
        printf("(%d:%d) ", pq->heap[i].data, pq->heap[i].priority);
    }
    printf("\n");
}

void pqueue_clear(PriorityQueue* pq) {
    if (pq == NULL) return;
    pq->size = 0;
}

// ========================================
// FUNÇÕES AUXILIARES DO HEAP
// ========================================

void heapify_up(PriorityQueue* pq, int index) {
    if (pq == NULL || index <= 0) return;
    
    int parent_index = parent(index);
    
    // Se a prioridade do filho é maior que a do pai, trocar
    if (pq->heap[index].priority > pq->heap[parent_index].priority) {
        swap_elements(&pq->heap[index], &pq->heap[parent_index]);
        heapify_up(pq, parent_index);
    }
}

void heapify_down(PriorityQueue* pq, int index) {
    if (pq == NULL || index >= pq->size) return;
    
    int largest = index;
    int left = left_child(index);
    int right = right_child(index);
    
    // Encontrar o maior entre pai, filho esquerdo e filho direito
    if (left < pq->size && pq->heap[left].priority > pq->heap[largest].priority) {
        largest = left;
    }
    
    if (right < pq->size && pq->heap[right].priority > pq->heap[largest].priority) {
        largest = right;
    }
    
    // Se o maior não é o pai, trocar e continuar
    if (largest != index) {
        swap_elements(&pq->heap[index], &pq->heap[largest]);
        heapify_down(pq, largest);
    }
}

void swap_elements(PriorityElement* a, PriorityElement* b) {
    if (a == NULL || b == NULL) return;
    
    PriorityElement temp = *a;
    *a = *b;
    *b = temp;
}

int parent(int index) {
    return (index - 1) / 2;
}

int left_child(int index) {
    return 2 * index + 1;
}

int right_child(int index) {
    return 2 * index + 2;
}

// ========================================
// FUNÇÃO DE DEMONSTRAÇÃO
// ========================================

void demonstrate_priority_queue(void) {
    print_separator("DEMONSTRAÇÃO: FILA DE PRIORIDADE COM HEAP");
    
    PriorityQueue pq;
    pqueue_init(&pq);
    
    printf("1. Fila de prioridade inicializada\n");
    printf("   Vazia? %s\n", pqueue_is_empty(&pq) ? "Sim" : "Não");
    printf("   Tamanho: %d\n", pqueue_size(&pq));
    
    printf("\n2. Inserindo elementos com diferentes prioridades:\n");
    printf("   Inserindo: (10, prioridade 3)\n");
    pqueue_insert(&pq, 10, 3);
    printf("   Inserindo: (20, prioridade 1)\n");
    pqueue_insert(&pq, 20, 1);
    printf("   Inserindo: (30, prioridade 5)\n");
    pqueue_insert(&pq, 30, 5);
    printf("   Inserindo: (40, prioridade 2)\n");
    pqueue_insert(&pq, 40, 2);
    printf("   Inserindo: (50, prioridade 4)\n");
    pqueue_insert(&pq, 50, 4);
    
    printf("\n   ");
    pqueue_print(&pq);
    printf("   Tamanho: %d\n", pqueue_size(&pq));
    
    DataType value;
    int priority;
    printf("\n3. Consultando elemento de maior prioridade\n");
    if (pqueue_peek_max(&pq, &value, &priority) == SUCCESS) {
        printf("   Maior prioridade: valor=%d, prioridade=%d\n", value, priority);
    }
    
    printf("\n4. Removendo elementos por ordem de prioridade:\n");
    while (!pqueue_is_empty(&pq)) {
        if (pqueue_extract_max(&pq, &value, &priority) == SUCCESS) {
            printf("   Removido: valor=%d, prioridade=%d\n", value, priority);
        }
    }
    
    printf("\n   ");
    pqueue_print(&pq);
    printf("   Vazia? %s\n", pqueue_is_empty(&pq) ? "Sim" : "Não");
    
    printf("\n5. Teste com prioridades iguais:\n");
    pqueue_insert(&pq, 100, 2);
    pqueue_insert(&pq, 200, 2);
    pqueue_insert(&pq, 300, 2);
    
    printf("   ");
    pqueue_print(&pq);
    
    printf("   Removendo elementos:\n");
    while (!pqueue_is_empty(&pq)) {
        if (pqueue_extract_max(&pq, &value, &priority) == SUCCESS) {
            printf("   Removido: valor=%d, prioridade=%d\n", value, priority);
        }
    }
}

