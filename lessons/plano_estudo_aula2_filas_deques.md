### Aula 2: Filas (Queues) e Deques (Double-Ended Queues)

**Duração Estimada:** 90 minutos

**Objetivos de Aprendizagem:**

Ao final desta aula, você será capaz de:

*   Compreender o conceito de Fila (Queue) como uma estrutura de dados linear.
*   Identificar as características de uma Fila: FIFO (First In, First Out).
*   Conhecer as operações básicas de Fila: `enqueue`, `dequeue`, `peek` (ou `front`), `isEmpty` e `size`.
*   Implementar uma Fila utilizando arrays (alocação sequencial) e listas encadeadas (alocação ligada).
*   Analisar a complexidade de tempo das operações de Fila.
*   Compreender o conceito de Deque (Double-Ended Queue) e suas operações.
*   Reconhecer aplicações práticas de Filas e Deques em algoritmos e sistemas.

---

#### 1. Introdução ao Conceito de Fila (15 minutos)

**1.1. O que é uma Fila?**

Uma fila é uma estrutura de dados linear que segue o princípio FIFO (First In, First Out), o que significa que o primeiro elemento adicionado é o primeiro a ser removido. Pense em uma fila de banco ou de supermercado: a primeira pessoa a entrar na fila é a primeira a ser atendida.

**1.2. Analogias e Exemplos do Dia a Dia:**

*   **Fila de Banco/Supermercado:** O exemplo mais intuitivo. Quem chega primeiro, é atendido primeiro.
*   **Impressora:** Documentos enviados para impressão formam uma fila. O primeiro documento enviado é o primeiro a ser impresso.
*   **Chamadas de Suporte:** Chamadas telefônicas para um serviço de suporte são geralmente processadas em ordem de chegada.
*   **Buffers de Rede:** Pacotes de dados em uma rede são armazenados em filas antes de serem processados.

**1.3. Características Principais:**

*   **FIFO (First In, First Out):** O primeiro elemento inserido é o primeiro a ser removido.
*   **Acesso Restrito:** Elementos são adicionados em uma extremidade (geralmente chamada de `rear` ou `back`) e removidos da outra extremidade (geralmente chamada de `front`).

---

#### 2. Operações Básicas de Fila (20 minutos)

As filas possuem um conjunto de operações que permitem a manipulação de seus elementos:

*   **`enqueue(elemento)`:** Adiciona um `elemento` ao final da fila. Se a fila estiver cheia (em implementações com tamanho fixo), pode ocorrer um erro de "Queue Overflow".
*   **`dequeue()`:** Remove e retorna o elemento do início da fila. Se a fila estiver vazia, pode ocorrer um erro de "Queue Underflow".
*   **`peek()`** ou **`front()`:** Retorna o elemento do início da fila sem removê-lo. Útil para verificar o próximo elemento a ser processado.
*   **`isEmpty()`:** Verifica se a fila está vazia. Retorna `true` se estiver vazia, `false` caso contrário.
*   **`size()`:** Retorna o número de elementos atualmente na fila.

---

#### 3. Implementação de Filas (30 minutos)

Assim como as pilhas, as filas podem ser implementadas utilizando arrays ou listas encadeadas.

**3.1. Implementação com Array (Alocação Sequencial):**

Uma fila pode ser implementada com um array, mas isso requer um cuidado especial com o gerenciamento dos índices `front` e `rear`. Uma abordagem comum é usar um array circular para evitar o deslocamento de elementos a cada `dequeue`.

**Vantagens:**
*   Acesso rápido aos elementos.
*   Uso eficiente da memória para um número fixo de elementos.

**Desvantagens:**
*   Tamanho fixo: a fila precisa ter um tamanho máximo predefinido.
*   Gerenciamento de índices pode ser complexo em arrays não circulares.

**Exemplo de Código (Python - Array/Lista Dinâmica):**

```python
class QueueArray:
    def __init__(self):
        self.items = []

    def isEmpty(self):
        return self.items == []

    def enqueue(self, item):
        self.items.insert(0, item) # Inserção no início para simular o rear

    def dequeue(self):
        if self.isEmpty():
            raise IndexError("Fila vazia: não é possível remover elementos.")
        return self.items.pop() # Remoção do final para simular o front

    def peek(self):
        if self.isEmpty():
            raise IndexError("Fila vazia: não há elementos para visualizar.")
        return self.items[len(self.items)-1]

    def size(self):
        return len(self.items)

# Exemplo de uso:
print("\n--- Testando QueueArray ---")
q_array = QueueArray()
print(f"Fila vazia? {q_array.isEmpty()}") # Saída: Fila vazia? True
q_array.enqueue("primeiro")
q_array.enqueue("segundo")
q_array.enqueue("terceiro")
print(f"Tamanho da fila: {q_array.size()}") # Saída: Tamanho da fila: 3
print(f"Elemento no front: {q_array.peek()}") # Saída: Elemento no front: primeiro
print(f"Removendo: {q_array.dequeue()}") # Saída: Removendo: primeiro
print(f"Elemento no front após dequeue: {q_array.peek()}") # Saída: Elemento no front após dequeue: segundo
print(f"Fila vazia? {q_array.isEmpty()}") # Saída: Fila vazia? False

```

**Nota:** A implementação acima com `insert(0, item)` e `pop()` para simular uma fila em Python é didática, mas ineficiente para grandes volumes de dados, pois `insert(0, item)` tem complexidade O(n). Uma implementação mais eficiente em Python usaria `collections.deque` ou uma lista encadeada.

**3.2. Implementação com Lista Encadeada (Alocação Ligada):**

Esta é a forma mais comum e eficiente de implementar uma fila. Mantemos ponteiros para o `front` (início) e `rear` (final) da fila. `enqueue` adiciona um nó ao `rear`, e `dequeue` remove um nó do `front`.

**Vantagens:**
*   Tamanho dinâmico: a fila pode crescer ou diminuir conforme a necessidade.
*   Inserção e remoção eficientes (O(1)).

**Desvantagens:**
*   Maior consumo de memória por elemento (devido aos ponteiros).

**Exemplo de Código (Python - Lista Encadeada):**

```python
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class QueueLinkedList:
    def __init__(self):
        self.front = None
        self.rear = None
        self.count = 0

    def isEmpty(self):
        return self.front is None

    def enqueue(self, item):
        new_node = Node(item)
        if self.isEmpty():
            self.front = new_node
        else:
            self.rear.next = new_node
        self.rear = new_node
        self.count += 1

    def dequeue(self):
        if self.isEmpty():
            raise IndexError("Fila vazia: não é possível remover elementos.")
        dequeued_item = self.front.data
        self.front = self.front.next
        if self.front is None: # Se a fila ficou vazia após a remoção
            self.rear = None
        self.count -= 1
        return dequeued_item

    def peek(self):
        if self.isEmpty():
            raise IndexError("Fila vazia: não há elementos para visualizar.")
        return self.front.data

    def size(self):
        return self.count

# Exemplo de uso:
print("\n--- Testando QueueLinkedList ---")
q_linked = QueueLinkedList()
print(f"Fila vazia? {q_linked.isEmpty()}") # Saída: Fila vazia? True
q_linked.enqueue(100)
q_linked.enqueue(200)
q_linked.enqueue(300)
print(f"Tamanho da fila: {q_linked.size()}") # Saída: Tamanho da fila: 3
print(f"Elemento no front: {q_linked.peek()}") # Saída: Elemento no front: 100
print(f"Removendo: {q_linked.dequeue()}") # Saída: Removendo: 100
print(f"Elemento no front após dequeue: {q_linked.peek()}") # Saída: Elemento no front após dequeue: 200
print(f"Fila vazia? {q_linked.isEmpty()}") # Saída: Fila vazia? False

```

---

#### 4. Deques (Double-Ended Queues) (10 minutos)

Um Deque, ou Fila de Duas Pontas, é uma estrutura de dados que generaliza tanto as pilhas quanto as filas. Ele permite a inserção e remoção de elementos em ambas as extremidades (início e fim).

**Operações Básicas de Deque:**

*   `addFront(elemento)`: Adiciona um elemento ao início do deque.
*   `addRear(elemento)`: Adiciona um elemento ao final do deque.
*   `removeFront()`: Remove e retorna o elemento do início do deque.
*   `removeRear()`: Remove e retorna o elemento do final do deque.
*   `peekFront()`: Retorna o elemento do início sem removê-lo.
*   `peekRear()`: Retorna o elemento do final sem removê-lo.
*   `isEmpty()`: Verifica se o deque está vazio.
*   `size()`: Retorna o número de elementos no deque.

**Implementação de Deques:**

Deques são geralmente implementados usando listas duplamente encadeadas para permitir operações eficientes em ambas as extremidades. Em Python, a classe `collections.deque` oferece uma implementação otimizada de deque.

**Exemplo de Código (Python - `collections.deque`):**

```python
from collections import deque

print("\n--- Testando collections.deque ---")
d = deque()
print(f"Deque vazio? {len(d) == 0}") # Saída: Deque vazio? True
d.appendleft(1) # addFront
d.append(2)    # addRear
d.appendleft(0) # addFront
print(f"Deque: {list(d)}")       # Saída: Deque: [0, 1, 2]
print(f"Removendo do front: {d.popleft()}") # Saída: Removendo do front: 0
print(f"Removendo do rear: {d.pop()}")     # Saída: Removendo do rear: 2
print(f"Deque: {list(d)}")       # Saída: Deque: [1]
print(f"Elemento no front: {d[0]}") # Saída: Elemento no front: 1
print(f"Elemento no rear: {d[-1]}") # Saída: Elemento no rear: 1

```

---

#### 5. Análise de Complexidade (5 minutos)

Para implementações eficientes (como lista encadeada para filas e lista duplamente encadeada para deques), todas as operações básicas (`enqueue`, `dequeue`, `peek`, `addFront`, `addRear`, `removeFront`, `removeRear`, `isEmpty`, `size`) possuem complexidade de tempo constante, O(1).

**Tabela de Complexidade (Filas e Deques):**

| Operação     | Fila (Lista Encadeada) | Deque (Lista Duplamente Encadeada) |
| :----------- | :--------------------- | :--------------------------------- |
| `enqueue`    | O(1)                   | O(1) (addRear)                     |
| `dequeue`    | O(1)                   | O(1) (removeFront)                 |
| `peek`       | O(1)                   | O(1) (peekFront)                   |
| `addFront`   | N/A                    | O(1)                               |
| `addRear`    | N/A                    | O(1)                               |
| `removeFront`| N/A                    | O(1)                               |
| `removeRear` | N/A                    | O(1)                               |
| `isEmpty`    | O(1)                   | O(1)                               |
| `size`       | O(1)                   | O(1)                               |

---

#### 6. Aplicações Práticas (5 minutos)

**Aplicações de Filas:**

*   **Escalonamento de Tarefas:** Sistemas operacionais usam filas para gerenciar processos a serem executados.
*   **Simulações:** Modelagem de sistemas onde eventos ocorrem em ordem de chegada.
*   **Busca em Largura (BFS - Breadth-First Search):** Algoritmo de travessia de grafos que utiliza uma fila para explorar os nós em níveis.
*   **Gerenciamento de Eventos:** Em sistemas baseados em eventos, as filas armazenam eventos a serem processados.

**Aplicações de Deques:**

*   **Implementação de Pilhas e Filas:** Um deque pode ser usado para implementar ambas as estruturas.
*   **Algoritmos de Sliding Window:** Em problemas onde uma "janela" de tamanho fixo se move sobre uma sequência de dados.
*   **Processamento de Histórico:** Manter um histórico de ações onde tanto as ações mais recentes quanto as mais antigas podem ser acessadas e removidas.

---

#### 7. Atividade Prática (5 minutos)

**Exercício:** Implemente uma Fila de Prioridade (usando uma lista Python como base, por simplicidade, embora não seja a forma mais eficiente) onde elementos com maior prioridade são removidos primeiro. Se as prioridades forem iguais, a ordem de chegada deve ser mantida (FIFO).

**Dicas:**
1.  Cada elemento na fila pode ser uma tupla `(prioridade, item)`.
2.  Ao adicionar, insira o elemento na posição correta para manter a ordem de prioridade.
3.  Ao remover, sempre remova o elemento de maior prioridade.

**Solução (para referência, não mostre ao aluno antes da tentativa):**

```python
class PriorityQueue:
    def __init__(self):
        self.items = []

    def isEmpty(self):
        return len(self.items) == 0

    def enqueue(self, item, priority):
        # Inserir mantendo a ordem de prioridade (maior prioridade = menor número)
        # Se prioridades iguais, mantém a ordem de chegada (FIFO)
        new_element = (priority, item)
        inserted = False
        for i in range(len(self.items)):
            if new_element[0] < self.items[i][0]:
                self.items.insert(i, new_element)
                inserted = True
                break
        if not inserted:
            self.items.append(new_element)

    def dequeue(self):
        if self.isEmpty():
            raise IndexError("Fila de Prioridade vazia: não é possível remover elementos.")
        return self.items.pop(0)[1] # Remove e retorna o item do elemento de maior prioridade

    def peek(self):
        if self.isEmpty():
            raise IndexError("Fila de Prioridade vazia: não há elementos para visualizar.")
        return self.items[0][1]

    def size(self):
        return len(self.items)

# Testes
print("\n--- Testando PriorityQueue ---")
pq = PriorityQueue()
print(f"Fila de Prioridade vazia? {pq.isEmpty()}") # Saída: True
pq.enqueue("Tarefa A", 3)
pq.enqueue("Tarefa B", 1)
pq.enqueue("Tarefa C", 2)
pq.enqueue("Tarefa D", 1) # Mesma prioridade que B, D deve vir depois de B

print(f"Tamanho da fila: {pq.size()}") # Saída: 4
print(f"Próximo a ser processado: {pq.peek()}") # Saída: Tarefa B
print(f"Processando: {pq.dequeue()}") # Saída: Tarefa B
print(f"Processando: {pq.dequeue()}") # Saída: Tarefa D
print(f"Processando: {pq.dequeue()}") # Saída: Tarefa C
print(f"Processando: {pq.dequeue()}") # Saída: Tarefa A
print(f"Fila de Prioridade vazia? {pq.isEmpty()}") # Saída: True

```

---

#### 8. Referências e Leitura Complementar

As referências para Filas e Deques são as mesmas das Pilhas, pois são estruturas de dados elementares frequentemente abordadas em conjunto:

*   **[1] Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009). *Introduction to Algorithms* (3rd ed.). MIT Press.**
    *   Capítulo 10: Estruturas de Dados Básicas (seção sobre Pilhas e Filas).

*   **[2] Goodrich, M. T., Tamassia, R., & Goldwasser, M. H. (2014). *Data Structures and Algorithms in Python*. John Wiley & Sons.**
    *   Capítulo 6: Stacks, Queues, and Deques.

*   **[3] Sedgewick, R., & Wayne, K. (2011). *Algorithms* (4th ed.). Addison-Wesley Professional.**
    *   Capítulo 1: Fundamentals (seção sobre Stacks and Queues).

*   **[4] Livro: Estruturas de Dados e Algoritmos em C++ - Michael T. Goodrich, Roberto Tamassia, David M. Mount.**
    *   Capítulo 6: Pilhas, Filas e Deques.

*   **[5] Artigo/Recurso Online:** GeeksforGeeks - Queue Data Structure (https://www.geeksforgeeks.org/queue-data-structure/)
    *   Um recurso online popular com explicações claras, exemplos de código em várias linguagens e problemas práticos.

*   **[6] Artigo/Recurso Online:** GeeksforGeeks - Deque (Double-ended Queue) in Python (https://www.geeksforgeeks.org/deque-in-python-set-1-introduction-and-basic-operations/)
    *   Recurso específico sobre Deques em Python.

---

**Próxima Aula:** Filas de Prioridade e Listas Lineares.



