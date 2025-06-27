# Aula 2: Filas (Queues) e Deques

## Objetivos de Aprendizagem

Ao final desta aula, você será capaz de:
- Compreender o conceito e funcionamento de filas e deques
- Implementar filas usando arrays circulares e listas ligadas em C
- Implementar deques (filas de dupla extremidade)
- Analisar a complexidade das operações
- Identificar aplicações práticas de filas e deques
- Resolver problemas usando essas estruturas

## 1. Introdução às Filas

### O que é uma Fila?

Uma **fila** (queue) é uma estrutura de dados linear que segue o princípio **FIFO** (First In, First Out - Primeiro a Entrar, Primeiro a Sair). É como uma fila de pessoas: quem chega primeiro é atendido primeiro.

### Características Principais

- **Inserção**: Sempre no final da fila (rear/back)
- **Remoção**: Sempre do início da fila (front)
- **Acesso**: Limitado às extremidades
- **Ordem**: Mantém a ordem de chegada dos elementos

### Terminologia

- **Enqueue**: Inserir um elemento no final da fila
- **Dequeue**: Remover um elemento do início da fila
- **Front**: Primeiro elemento da fila
- **Rear**: Último elemento da fila

## 2. Operações Básicas de Filas

### Operações Fundamentais

1. **Enqueue**: Inserir elemento no final
2. **Dequeue**: Remover elemento do início
3. **Front**: Consultar o primeiro elemento
4. **IsEmpty**: Verificar se a fila está vazia
5. **Size**: Obter o número de elementos

### Operações Auxiliares

- **IsFull**: Verificar se a fila está cheia (array)
- **Clear**: Remover todos os elementos
- **Print**: Exibir todos os elementos

## 3. Implementações de Filas em C

### 3.1 Implementação com Array Circular

```c
typedef struct {
    DataType data[MAX_SIZE];
    int front;
    int rear;
    int size;
} QueueArray;

// Por que circular?
// - Evita desperdício de espaço
// - Reutiliza posições liberadas
// - Operações O(1) eficientes
```

**Vantagens do Array Circular:**
- Uso eficiente do espaço
- Operações O(1)
- Implementação relativamente simples

**Desvantagens:**
- Tamanho fixo
- Complexidade adicional para gerenciar índices

### 3.2 Implementação com Lista Ligada

```c
typedef struct QueueNode {
    DataType data;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
    int size;
} QueueLinked;
```

**Vantagens da Lista Ligada:**
- Tamanho dinâmico
- Não há limite de elementos
- Uso eficiente de memória

**Desvantagens:**
- Overhead de ponteiros
- Possível fragmentação de memória

## 4. Introdução aos Deques

### O que é um Deque?

Um **deque** (double-ended queue) é uma estrutura que permite inserção e remoção em ambas as extremidades. Combina características de pilhas e filas.

### Operações do Deque

1. **Push Front**: Inserir no início
2. **Push Rear**: Inserir no final
3. **Pop Front**: Remover do início
4. **Pop Rear**: Remover do final
5. **Front**: Consultar primeiro elemento
6. **Rear**: Consultar último elemento

### Implementação com Lista Duplamente Ligada

```c
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
```

## 5. Análise de Complexidade

### Complexidade Temporal

| Operação | Array Circular | Lista Ligada | Deque |
|----------|----------------|--------------|-------|
| Enqueue/Push | O(1) | O(1) | O(1) |
| Dequeue/Pop | O(1) | O(1) | O(1) |
| Front/Rear | O(1) | O(1) | O(1) |
| IsEmpty | O(1) | O(1) | O(1) |
| Size | O(1) | O(1) | O(1) |

### Complexidade Espacial

- **Array Circular**: O(n) - tamanho fixo
- **Lista Ligada**: O(n) - tamanho atual
- **Deque**: O(n) - tamanho atual + overhead de ponteiros duplos

## 6. Aplicações Práticas

### 6.1 Filas

#### Sistemas Operacionais
```c
// Escalonamento de processos
// Fila de processos prontos para execução
QueueLinked ready_queue;
queue_linked_init(&ready_queue);

// Adicionar processo à fila
queue_linked_enqueue(&ready_queue, process_id);

// Executar próximo processo
int next_process;
queue_linked_dequeue(&ready_queue, &next_process);
```

#### Sistemas de Impressão
- Fila de documentos para impressão
- Ordem de chegada determina ordem de impressão

#### Algoritmos de Busca
- Busca em Largura (BFS) em grafos
- Exploração nível por nível

#### Simulações
- Filas de atendimento em bancos
- Tráfego de rede
- Sistemas de call center

### 6.2 Deques

#### Algoritmos de Janela Deslizante
```c
// Encontrar máximo em janela de tamanho k
void sliding_window_maximum(int arr[], int n, int k) {
    Deque dq;
    deque_init(&dq);
    
    // Processar primeira janela
    for (int i = 0; i < k; i++) {
        // Remove elementos menores que o atual
        while (!deque_is_empty(&dq)) {
            int rear_val;
            deque_rear(&dq, &rear_val);
            if (arr[rear_val] >= arr[i]) break;
            deque_pop_rear(&dq, &rear_val);
        }
        deque_push_rear(&dq, i);
    }
    
    // Processar janelas restantes
    for (int i = k; i < n; i++) {
        int front_val;
        deque_front(&dq, &front_val);
        printf("Máximo da janela: %d\n", arr[front_val]);
        
        // Remove elementos fora da janela
        while (!deque_is_empty(&dq)) {
            deque_front(&dq, &front_val);
            if (front_val <= i - k) {
                deque_pop_front(&dq, &front_val);
            } else break;
        }
        
        // Adiciona elemento atual
        while (!deque_is_empty(&dq)) {
            int rear_val;
            deque_rear(&dq, &rear_val);
            if (arr[rear_val] >= arr[i]) break;
            deque_pop_rear(&dq, &rear_val);
        }
        deque_push_rear(&dq, i);
    }
}
```

#### Outras Aplicações de Deques
- Histórico de navegação (frente/trás)
- Implementação de outras estruturas
- Algoritmos de otimização
- Processamento de palíndromos

## 7. Atividade Prática

### Exercício 1: Demonstração Básica
```bash
gcc -o queue_demo code_examples/aula2_filas_deques/queue_demo.c lib/queue.c lib/common.c -I include
./queue_demo
```

### Exercício 2: Simulação de Fila de Banco
Implemente uma simulação onde clientes chegam aleatoriamente e são atendidos em ordem.

### Exercício 3: Verificador de Palíndromo
Use um deque para verificar se uma string é um palíndromo.

### Exercício 4: Buffer Circular
Implemente um buffer circular para comunicação entre processos.

## 8. Problemas Comuns e Soluções

### 8.1 Array Circular - Gerenciamento de Índices

```c
// Problema: Como detectar fila cheia vs. vazia?
// Solução 1: Manter contador de tamanho
typedef struct {
    DataType data[MAX_SIZE];
    int front, rear, size;
} QueueArray;

// Solução 2: Deixar uma posição vazia
bool is_full_alternative(QueueArray* q) {
    return (q->rear + 1) % MAX_SIZE == q->front;
}
```

### 8.2 Memory Leaks em Listas Ligadas

```c
// Sempre liberar memória ao remover nós
int queue_linked_dequeue(QueueLinked* queue, DataType* value) {
    if (queue_linked_is_empty(queue)) return FAILURE;
    
    QueueNode* temp = queue->front;
    *value = temp->data;
    queue->front = temp->next;
    
    free(temp); // IMPORTANTE: liberar memória
    
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    queue->size--;
    return SUCCESS;
}
```

### 8.3 Deque - Gerenciamento de Ponteiros Duplos

```c
// Cuidado ao atualizar ponteiros prev e next
int deque_push_front(Deque* deque, DataType value) {
    DequeNode* new_node = malloc(sizeof(DequeNode));
    if (!new_node) return FAILURE;
    
    new_node->data = value;
    new_node->next = deque->front;
    new_node->prev = NULL;
    
    if (deque_is_empty(deque)) {
        deque->front = deque->rear = new_node;
    } else {
        deque->front->prev = new_node; // Atualizar prev do antigo front
        deque->front = new_node;
    }
    
    deque->size++;
    return SUCCESS;
}
```

## 9. Comparação entre Estruturas

| Estrutura | Inserção | Remoção | Flexibilidade | Uso de Memória |
|-----------|----------|---------|---------------|----------------|
| **Pilha** | Topo | Topo | Baixa | Eficiente |
| **Fila** | Final | Início | Média | Eficiente |
| **Deque** | Ambas extremidades | Ambas extremidades | Alta | Overhead adicional |

## 10. Otimizações e Variações

### 10.1 Fila de Prioridade
- Elementos têm prioridades
- Remoção por ordem de prioridade
- Implementação com heap (próxima aula)

### 10.2 Fila Circular com Redimensionamento
- Array que cresce dinamicamente
- Combina vantagens de array e lista

### 10.3 Deque com Array
- Implementação mais eficiente em memória
- Complexidade adicional para redimensionamento

## 11. Referências e Leitura Complementar

### Livros Recomendados
1. **"Introduction to Algorithms"** - CLRS, Capítulo 10
2. **"Data Structures and Algorithm Analysis in C"** - Mark Allen Weiss
3. **"The Art of Computer Programming, Volume 1"** - Donald Knuth

### Recursos Online
- [Queue Data Structure - GeeksforGeeks](https://www.geeksforgeeks.org/queue-data-structure/)
- [Deque Data Structure - GeeksforGeeks](https://www.geeksforgeeks.org/deque-set-1-introduction-applications/)
- [Circular Queue - Programiz](https://www.programiz.com/dsa/circular-queue)

### Implementações de Referência
- STL C++: `std::queue`, `std::deque`
- Java: `Queue`, `Deque`, `ArrayDeque`
- Python: `collections.deque`

## Resumo da Aula

Nesta aula, você aprendeu:
- ✅ Conceito fundamental de filas (FIFO)
- ✅ Implementação com arrays circulares e listas ligadas
- ✅ Conceito e implementação de deques
- ✅ Análise de complexidade das operações
- ✅ Aplicações práticas importantes
- ✅ Problemas comuns e suas soluções

**Próxima aula**: Filas de Prioridade e Listas Lineares - estruturas mais avançadas e suas aplicações.

---

**Tempo estimado de estudo**: 90 minutos  
**Dificuldade**: Iniciante a Intermediário  
**Pré-requisitos**: Aula 1 (Pilhas), conhecimentos de ponteiros e alocação dinâmica

