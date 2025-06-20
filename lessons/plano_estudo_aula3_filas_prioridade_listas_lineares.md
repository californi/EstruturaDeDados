### Aula 3: Filas de Prioridade e Listas Lineares

**Duração Estimada:** 90 minutos

**Objetivos de Aprendizagem:**

Ao final desta aula, você será capaz de:

*   Compreender o conceito e o funcionamento de uma Fila de Prioridade.
*   Conhecer as operações básicas de uma Fila de Prioridade: `insert`, `extractMin/Max`, `peekMin/Max`.
*   Implementar uma Fila de Prioridade utilizando arrays (heap binário).
*   Analisar a complexidade de tempo das operações de Fila de Prioridade.
*   Compreender o conceito de Listas Lineares e suas variações.
*   Implementar Listas Lineares utilizando alocação sequencial (arrays) e alocação ligada (listas encadeadas).
*   Analisar a complexidade de tempo das operações em diferentes tipos de Listas Lineares.
*   Reconhecer aplicações práticas de Filas de Prioridade e Listas Lineares.

---

#### 1. Filas de Prioridade (40 minutos)

**1.1. O que é uma Fila de Prioridade?**

Uma Fila de Prioridade é uma estrutura de dados abstrata que, ao contrário das filas FIFO ou pilhas LIFO, organiza seus elementos com base em uma prioridade associada a cada um. O elemento com a maior (ou menor, dependendo da implementação) prioridade é sempre o primeiro a ser removido. Se dois elementos tiverem a mesma prioridade, sua ordem de remoção pode ser definida por FIFO ou LIFO, ou ser arbitrária.

**Analogias:**

*   **Pronto-Socorro:** Pacientes são atendidos não pela ordem de chegada, mas pela gravidade de seu estado (prioridade).
*   **Escalonador de Processos em SO:** Processos com maior prioridade de execução são alocados CPU antes de processos de menor prioridade.

**1.2. Operações Básicas:**

*   **`insert(elemento, prioridade)`:** Adiciona um elemento à fila com uma prioridade específica.
*   **`extractMin()`** (ou `extractMax()`): Remove e retorna o elemento com a menor (ou maior) prioridade da fila.
*   **`peekMin()`** (ou `peekMax()`): Retorna o elemento com a menor (ou maior) prioridade sem removê-lo.
*   **`isEmpty()`:** Verifica se a fila de prioridade está vazia.
*   **`size()`:** Retorna o número de elementos na fila de prioridade.

**1.3. Implementação com Heap Binário:**

A forma mais eficiente e comum de implementar uma Fila de Prioridade é utilizando um Heap Binário. Um heap binário é uma árvore binária completa que satisfaz a propriedade de heap: para um heap de mínimo, o valor de cada nó é menor ou igual ao valor de seus filhos. Para um heap de máximo, o valor de cada nó é maior ou igual ao valor de seus filhos. Heaps podem ser eficientemente representados por arrays.

**Vantagens:**
*   Operações de inserção e extração eficientes (logarítmicas).
*   Representação compacta em array.

**Desvantagens:**
*   Acesso a elementos que não são o mínimo/máximo é ineficiente.

**Exemplo de Código (Python - Heap Binário - `heapq`):**

Python possui um módulo `heapq` que implementa o algoritmo de heap binário de mínimo. Para simular um heap de máximo, podemos armazenar tuplas `(-prioridade, elemento)`.

```python
import heapq

class PriorityQueueHeap:
    def __init__(self):
        self._queue = []
        self._counter = 0 # Para garantir ordem de inserção em caso de prioridades iguais

    def insert(self, item, priority):
        # heapq é um min-heap. Para simular max-heap, use -priority.
        # Adicionamos um contador para garantir estabilidade (FIFO para prioridades iguais)
        heapq.heappush(self._queue, (priority, self._counter, item))
        self._counter += 1

    def extract_min(self):
        if self.is_empty():
            raise IndexError("Fila de Prioridade vazia: não é possível remover elementos.")
        return heapq.heappop(self._queue)[2] # Retorna apenas o item

    def peek_min(self):
        if self.is_empty():
            raise IndexError("Fila de Prioridade vazia: não há elementos para visualizar.")
        return self._queue[0][2]

    def is_empty(self):
        return not self._queue

    def size(self):
        return len(self._queue)

# Exemplo de uso (heap de mínimo):
print("\n--- Testando PriorityQueueHeap (Min-Heap) ---")
pq_min = PriorityQueueHeap()
pq_min.insert("Tarefa Baixa", 3)
pq_min.insert("Tarefa Urgente", 1)
pq_min.insert("Tarefa Média", 2)
pq_min.insert("Tarefa Urgente 2", 1) # Mesma prioridade, ordem de inserção importa

print(f"Tamanho da fila: {pq_min.size()}") # Saída: 4
print(f"Próximo a ser processado: {pq_min.peek_min()}") # Saída: Tarefa Urgente
print(f"Processando: {pq_min.extract_min()}") # Saída: Tarefa Urgente
print(f"Processando: {pq_min.extract_min()}") # Saída: Tarefa Urgente 2
print(f"Processando: {pq_min.extract_min()}") # Saída: Tarefa Média
print(f"Fila de Prioridade vazia? {pq_min.is_empty()}") # Saída: False

```

**1.4. Análise de Complexidade (Heap Binário):**

| Operação     | Complexidade |
| :----------- | :----------- |
| `insert`     | O(log n)     |
| `extractMin` | O(log n)     |
| `peekMin`    | O(1)         |
| `isEmpty`    | O(1)         |
| `size`       | O(1)         |

---

#### 2. Listas Lineares (40 minutos)

Listas lineares são coleções de elementos organizados sequencialmente. Elas são uma das estruturas de dados mais fundamentais e podem ser implementadas de diversas formas.

**2.1. Alocação Sequencial (Arrays/Listas Dinâmicas):**

Nesta abordagem, os elementos são armazenados em posições de memória contíguas. Em muitas linguagens, arrays são de tamanho fixo, mas listas dinâmicas (como `list` em Python ou `ArrayList` em Java) oferecem redimensionamento automático.

**Vantagens:**
*   Acesso direto a qualquer elemento por índice (O(1)).
*   Uso eficiente da memória para armazenamento contíguo.

**Desvantagens:**
*   Inserção/remoção no meio da lista pode ser custosa (O(n)), pois exige o deslocamento de elementos.
*   Redimensionamento pode ser custoso (O(n)) para listas dinâmicas.

**Exemplo de Código (Python - Lista Dinâmica):**

```python
print("\n--- Testando Lista Dinâmica (Python list) ---")
my_list = [10, 20, 30, 40, 50]
print(f"Lista original: {my_list}")
print(f"Acesso ao índice 2: {my_list[2]} (O(1))") # Saída: 30

my_list.insert(2, 25) # Inserção no meio O(n)
print(f"Lista após insert(2, 25): {my_list}") # Saída: [10, 20, 25, 30, 40, 50]

my_list.pop(3) # Remoção no meio O(n)
print(f"Lista após pop(3): {my_list}") # Saída: [10, 20, 25, 40, 50]

my_list.append(60) # Inserção no final O(1) amortizado
print(f"Lista após append(60): {my_list}") # Saída: [10, 20, 25, 40, 50, 60]

my_list.pop() # Remoção no final O(1)
print(f"Lista após pop(): {my_list}") # Saída: [10, 20, 25, 40, 50]

```

**2.2. Alocação Ligada (Listas Encadeadas):**

Em uma lista encadeada, os elementos não são armazenados em posições de memória contíguas. Cada elemento (nó) contém o dado e um ponteiro para o próximo nó na sequência. Existem várias variações:

*   **Listas Simplesmente Encadeadas:** Cada nó aponta apenas para o próximo. Permite travessia em uma única direção.
*   **Listas Circulares:** O último nó aponta para o primeiro, formando um ciclo. Útil para estruturas que precisam de acesso contínuo.
*   **Listas Duplamente Encadeadas:** Cada nó contém um ponteiro para o próximo e um para o anterior. Permite travessia em ambas as direções e remoção mais eficiente.

**Exemplo de Código (Python - Lista Simplesmente Encadeada):**

```python
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class SinglyLinkedList:
    def __init__(self):
        self.head = None

    def append(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            return
        last_node = self.head
        while last_node.next:
            last_node = last_node.next
        last_node.next = new_node

    def prepend(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    def display(self):
        current = self.head
        elements = []
        while current:
            elements.append(current.data)
            current = current.next
        print(elements)

    def find(self, key):
        current = self.head
        while current:
            if current.data == key:
                return True
            current = current.next
        return False

    def delete_node(self, key):
        current = self.head
        if current and current.data == key:
            self.head = current.next
            current = None
            return
        prev = None
        while current and current.data != key:
            prev = current
            current = current.next
        if current is None:
            return # Elemento não encontrado
        prev.next = current.next
        current = None

# Exemplo de uso:
print("\n--- Testando SinglyLinkedList ---")
sll = SinglyLinkedList()
sll.append(1)
sll.append(2)
sll.append(3)
sll.prepend(0)
sll.display() # Saída: [0, 1, 2, 3]
print(f"Encontrou 2? {sll.find(2)}") # Saída: True
sll.delete_node(2)
sll.display() # Saída: [0, 1, 3]
sll.delete_node(0)
sll.display() # Saída: [1, 3]

```

**Exemplo de Código (Python - Lista Duplamente Encadeada):**

```python
class DoublyNode:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def append(self, data):
        new_node = DoublyNode(data)
        if not self.head:
            self.head = new_node
            self.tail = new_node
            return
        self.tail.next = new_node
        new_node.prev = self.tail
        self.tail = new_node

    def prepend(self, data):
        new_node = DoublyNode(data)
        if not self.head:
            self.head = new_node
            self.tail = new_node
            return
        new_node.next = self.head
        self.head.prev = new_node
        self.head = new_node

    def delete_node(self, key):
        current = self.head
        while current:
            if current.data == key:
                if current.prev:
                    current.prev.next = current.next
                else:
                    self.head = current.next
                if current.next:
                    current.next.prev = current.prev
                else:
                    self.tail = current.prev
                return
            current = current.next

    def display_forward(self):
        current = self.head
        elements = []
        while current:
            elements.append(current.data)
            current = current.next
        print(elements)

    def display_backward(self):
        current = self.tail
        elements = []
        while current:
            elements.append(current.data)
            current = current.prev
        print(elements)

# Exemplo de uso:
print("\n--- Testando DoublyLinkedList ---")
dll = DoublyLinkedList()
dll.append("A")
dll.append("B")
dll.prepend("Z")
dll.display_forward() # Saída: [Z, A, B]
dll.display_backward() # Saída: [B, A, Z]
dll.delete_node("A")
dll.display_forward() # Saída: [Z, B]

```

**2.3. Análise de Complexidade (Listas Lineares):**

| Operação     | Array (Lista Dinâmica) | Lista Simplesmente Encadeada | Lista Duplamente Encadeada |
| :----------- | :--------------------- | :--------------------------- | :------------------------- |
| Acesso (por índice) | O(1)                   | O(n)                         | O(n)                       |
| Inserção (início) | O(n)                   | O(1)                         | O(1)                       |
| Inserção (fim) | O(1) (amortizado)      | O(n)                         | O(1)                       |
| Inserção (meio) | O(n)                   | O(n)                         | O(n)                       |
| Remoção (início) | O(n)                   | O(1)                         | O(1)                       |
| Remoção (fim) | O(1)                   | O(n)                         | O(1)                       |
| Remoção (meio) | O(n)                   | O(n)                         | O(n)                       |

---

#### 3. Atividade Prática (10 minutos)

**Exercício:** Implemente uma função que receba uma lista simplesmente encadeada e inverta a ordem de seus nós. Você deve fazer isso modificando os ponteiros, sem criar uma nova lista ou copiar os dados para um array auxiliar.

**Dicas:**
1.  Você precisará de três ponteiros: `prev`, `current` e `next_node`.
2.  Itere pela lista, atualizando os ponteiros de cada nó.

**Solução (para referência, não mostre ao aluno antes da tentativa):**

```python
# Reutilizando a classe SinglyLinkedList e Node da seção 2.2

def reverse_singly_linked_list(linked_list):
    prev = None
    current = linked_list.head
    while current:
        next_node = current.next # Salva o próximo nó
        current.next = prev      # Inverte o ponteiro do nó atual
        prev = current           # Move prev para o nó atual
        current = next_node      # Move current para o próximo nó
    linked_list.head = prev # O novo head é o último nó original

# Testes
print("\n--- Testando Inversão de SinglyLinkedList ---")
sll_reverse = SinglyLinkedList()
sll_reverse.append(1)
sll_reverse.append(2)
sll_reverse.append(3)
sll_reverse.append(4)
print("Lista original:")
sll_reverse.display() # Saída: [1, 2, 3, 4]

reverse_singly_linked_list(sll_reverse)
print("Lista invertida:")
sll_reverse.display() # Saída: [4, 3, 2, 1]

sll_empty = SinglyLinkedList()
print("Lista vazia original:")
sll_empty.display() # Saída: []
reverse_singly_linked_list(sll_empty)
print("Lista vazia invertida:")
sll_empty.display() # Saída: []

sll_single = SinglyLinkedList()
sll_single.append(10)
print("Lista com um elemento original:")
sll_single.display() # Saída: [10]
reverse_singly_linked_list(sll_single)
print("Lista com um elemento invertida:")
sll_single.display() # Saída: [10]

```

---

#### 4. Referências e Leitura Complementar

*   **[1] Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009). *Introduction to Algorithms* (3rd ed.). MIT Press.**
    *   Capítulo 6: Heapsort (para Heaps).
    *   Capítulo 10: Estruturas de Dados Básicas (para Listas Encadeadas).

*   **[2] Goodrich, M. T., Tamassia, R., & Goldwasser, M. H. (2014). *Data Structures and Algorithms in Python*. John Wiley & Sons.**
    *   Capítulo 7: Listas Encadeadas.
    *   Capítulo 9: Heaps e Filas de Prioridade.

*   **[3] Sedgewick, R., & Wayne, K. (2011). *Algorithms* (4th ed.). Addison-Wesley Professional.**
    *   Capítulo 2: Sorting (para Heapsort e Heaps).
    *   Capítulo 3: Elementary Data Structures (para Listas Encadeadas).

*   **[4] Livro: Estruturas de Dados e Algoritmos em C++ - Michael T. Goodrich, Roberto Tamassia, David M. Mount.**
    *   Capítulo 7: Listas Encadeadas.
    *   Capítulo 9: Heaps e Filas de Prioridade.

*   **[5] Artigo/Recurso Online:** GeeksforGeeks - Priority Queue (https://www.geeksforgeeks.org/priority-queue-in-python/)
    *   Recurso online sobre Filas de Prioridade.

*   **[6] Artigo/Recurso Online:** GeeksforGeeks - Linked List (https://www.geeksforgeeks.org/data-structures/linked-list/)
    *   Recurso online sobre Listas Encadeadas (simples, duplas, circulares).

---

**Próxima Aula:** Árvores: Terminologia e Representação.



