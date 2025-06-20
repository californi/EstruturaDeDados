# Plano de Estudo: Estruturas de Dados e Algoritmos

## Módulo 1: Estruturas de Dados Elementares

### Aula 1: Pilhas (Stacks)

**Duração Estimada:** 90 minutos

**Objetivos de Aprendizagem:**

Ao final desta aula, você será capaz de:

*   Compreender o conceito de Pilha (Stack) como uma estrutura de dados linear.
*   Identificar as características de uma Pilha: LIFO (Last In, First Out).
*   Conhecer as operações básicas de Pilha: `push`, `pop`, `peek` (ou `top`), `isEmpty` e `size`.
*   Implementar uma Pilha utilizando arrays (alocação sequencial) e listas encadeadas (alocação ligada).
*   Analisar a complexidade de tempo das operações de Pilha.
*   Reconhecer aplicações práticas de Pilhas em algoritmos e sistemas.

---

#### 1. Introdução ao Conceito de Pilha (15 minutos)

**1.1. O que é uma Pilha?**

Uma pilha é uma estrutura de dados abstrata que opera com base no princípio LIFO (Last In, First Out), o que significa que o último elemento adicionado é o primeiro a ser removido. Pense em uma pilha de pratos: você sempre adiciona um prato no topo e remove o prato que está no topo. Não é possível remover um prato do meio ou da base sem antes remover os que estão acima dele.

**1.2. Analogias e Exemplos do Dia a Dia:**

*   **Pilha de Pratos:** Como mencionado, é o exemplo clássico. O último prato colocado é o primeiro a ser retirado.
*   **Pilha de Livros:** Similar aos pratos.
*   **Desfazer/Refazer em Editores de Texto:** Cada ação é adicionada à pilha de 'desfazer' e a última ação é a primeira a ser desfeita.
*   **Navegação em Navegadores Web:** O histórico de páginas visitadas funciona como uma pilha; a página mais recentemente visitada é a primeira a ser acessada ao usar o botão 'voltar'.

**1.3. Características Principais:**

*   **LIFO (Last In, First Out):** O último elemento inserido é o primeiro a ser removido.
*   **Acesso Restrito:** Apenas o elemento do topo da pilha é acessível para adição ou remoção.

---

#### 2. Operações Básicas de Pilha (20 minutos)

As pilhas possuem um conjunto bem definido de operações que permitem a manipulação de seus elementos. São elas:

*   **`push(elemento)`:** Adiciona um `elemento` ao topo da pilha. Se a pilha estiver cheia (no caso de uma implementação com tamanho fixo), pode ocorrer um erro de "Stack Overflow".
*   **`pop()`:** Remove e retorna o elemento do topo da pilha. Se a pilha estiver vazia, pode ocorrer um erro de "Stack Underflow".
*   **`peek()`** ou **`top()`:** Retorna o elemento do topo da pilha sem removê-lo. Útil para verificar o próximo elemento a ser processado.
*   **`isEmpty()`:** Verifica se a pilha está vazia. Retorna `true` se estiver vazia, `false` caso contrário.
*   **`size()`:** Retorna o número de elementos atualmente na pilha.

---

#### 3. Implementação de Pilhas (30 minutos)

Uma pilha pode ser implementada de diversas maneiras, sendo as mais comuns utilizando arrays (alocação sequencial) ou listas encadeadas (alocação ligada).

**3.1. Implementação com Array (Alocação Sequencial):**

Nesta abordagem, a pilha é representada por um array e um ponteiro (ou índice) que indica a posição do topo da pilha. Quando um elemento é adicionado (`push`), o ponteiro é incrementado e o elemento é inserido na nova posição. Quando um elemento é removido (`pop`), o elemento na posição do ponteiro é retornado e o ponteiro é decrementado.

**Vantagens:**
*   Acesso rápido aos elementos (acesso direto por índice).
*   Uso eficiente da memória para um número fixo de elementos.

**Desvantagens:**
*   Tamanho fixo: a pilha precisa ter um tamanho máximo predefinido. Se esse limite for excedido, ocorre um "Stack Overflow".
*   Redimensionamento pode ser custoso se a pilha precisar crescer além de sua capacidade inicial.

**Exemplo de Código (Python - Array/Lista Dinâmica):**

```python
class StackArray:
    def __init__(self):
        self.items = []

    def isEmpty(self):
        return self.items == []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        if self.isEmpty():
            raise IndexError("Pilha vazia: não é possível remover elementos.")
        return self.items.pop()

    def peek(self):
        if self.isEmpty():
            raise IndexError("Pilha vazia: não há elementos para visualizar.")
        return self.items[len(self.items)-1]

    def size(self):
        return len(self.items)

# Exemplo de uso:
print("\n--- Testando StackArray ---")
s_array = StackArray()
print(f"Pilha vazia? {s_array.isEmpty()}") # Saída: Pilha vazia? True
s_array.push(10)
s_array.push(20)
s_array.push(30)
print(f"Tamanho da pilha: {s_array.size()}") # Saída: Tamanho da pilha: 3
print(f"Elemento no topo: {s_array.peek()}") # Saída: Elemento no topo: 30
print(f"Removendo: {s_array.pop()}") # Saída: Removendo: 30
print(f"Elemento no topo após pop: {s_array.peek()}") # Saída: Elemento no topo após pop: 20
print(f"Pilha vazia? {s_array.isEmpty()}") # Saída: Pilha vazia? False

```

**3.2. Implementação com Lista Encadeada (Alocação Ligada):**

Nesta abordagem, cada elemento da pilha é um nó em uma lista encadeada. O topo da pilha é o primeiro nó da lista. Adicionar (`push`) um elemento significa criar um novo nó e fazer com que ele aponte para o antigo topo, tornando-se o novo topo. Remover (`pop`) um elemento significa remover o primeiro nó e fazer com que o segundo nó se torne o novo topo.

**Vantagens:**
*   Tamanho dinâmico: a pilha pode crescer ou diminuir conforme a necessidade, limitada apenas pela memória disponível.
*   Inserção e remoção eficientes (O(1)).

**Desvantagens:**
*   Maior consumo de memória por elemento (devido aos ponteiros).
*   Acesso a elementos que não são o topo é mais lento (requer travessia da lista).

**Exemplo de Código (Python - Lista Encadeada):**

```python
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class StackLinkedList:
    def __init__(self):
        self.head = None
        self.count = 0

    def isEmpty(self):
        return self.head is None

    def push(self, item):
        new_node = Node(item)
        new_node.next = self.head
        self.head = new_node
        self.count += 1

    def pop(self):
        if self.isEmpty():
            raise IndexError("Pilha vazia: não é possível remover elementos.")
        popped_item = self.head.data
        self.head = self.head.next
        self.count -= 1
        return popped_item

    def peek(self):
        if self.isEmpty():
            raise IndexError("Pilha vazia: não há elementos para visualizar.")
        return self.head.data

    def size(self):
        return self.count

# Exemplo de uso:
print("\n--- Testando StackLinkedList ---")
s_linked = StackLinkedList()
print(f"Pilha vazia? {s_linked.isEmpty()}") # Saída: Pilha vazia? True
s_linked.push("apple")
s_linked.push("banana")
s_linked.push("cherry")
print(f"Tamanho da pilha: {s_linked.size()}") # Saída: Tamanho da pilha: 3
print(f"Elemento no topo: {s_linked.peek()}") # Saída: Elemento no topo: cherry
print(f"Removendo: {s_linked.pop()}") # Saída: Removendo: cherry
print(f"Elemento no topo após pop: {s_linked.peek()}") # Saída: Elemento no topo após pop: banana
print(f"Pilha vazia? {s_linked.isEmpty()}") # Saída: Pilha vazia? False

```

---

#### 4. Análise de Complexidade (10 minutos)

A complexidade de tempo das operações de pilha é um ponto crucial para entender sua eficiência. Para ambas as implementações (array e lista encadeada), as operações básicas (`push`, `pop`, `peek`, `isEmpty`, `size`) geralmente possuem complexidade de tempo constante, ou seja, O(1).

*   **`push`:** Adicionar um elemento ao topo leva tempo constante, pois envolve apenas a manipulação de um ponteiro/índice e a inserção no final (array dinâmico) ou no início (lista encadeada).
*   **`pop`:** Remover um elemento do topo também leva tempo constante, pela mesma razão.
*   **`peek`:** Acessar o elemento do topo é direto e leva tempo constante.
*   **`isEmpty`:** Verificar se a pilha está vazia é uma verificação simples e leva tempo constante.
*   **`size`:** Retornar o tamanho da pilha (se mantido por um contador) leva tempo constante. Se for necessário percorrer a estrutura para contar, a complexidade seria O(n), mas implementações eficientes mantêm um contador.

**Tabela de Complexidade:**

| Operação | Implementação com Array (Lista Dinâmica) | Implementação com Lista Encadeada |
| :------- | :--------------------------------------- | :-------------------------------- |
| `push`   | O(1) (amortizado para redimensionamento) | O(1)                              |
| `pop`    | O(1)                                     | O(1)                              |
| `peek`   | O(1)                                     | O(1)                              |
| `isEmpty`| O(1)                                     | O(1)                              |
| `size`   | O(1)                                     | O(1)                              |

---

#### 5. Aplicações Práticas (10 minutos)

As pilhas são amplamente utilizadas em diversas áreas da computação devido à sua natureza LIFO. Algumas aplicações notáveis incluem:

*   **Gerenciamento de Chamadas de Função (Call Stack):** Em programação, quando uma função chama outra, o endereço de retorno e as variáveis locais da função chamadora são empilhados. Quando a função chamada termina, esses dados são desempilhados, permitindo que a execução retorne ao ponto correto.
*   **Avaliação de Expressões (Notação Polonesa Reversa - RPN):** Pilhas são usadas para converter expressões infixas (ex: `A + B`) para pós-fixas (ex: `AB+`) e para avaliá-las.
*   **Verificação de Balanceamento de Parênteses/Chaves:** Para verificar se parênteses, colchetes e chaves em uma expressão estão corretamente balanceados.
*   **Algoritmos de Backtracking:** Em problemas que envolvem a exploração de múltiplos caminhos (como labirintos ou quebra-cabeças), a pilha pode ser usada para armazenar os estados visitados e permitir o retorno a um estado anterior quando um caminho não leva à solução.
*   **Desfazer/Refazer Operações:** Já mencionado, é uma aplicação direta do conceito LIFO.

---

#### 6. Atividade Prática (15 minutos)

**Exercício:** Implemente uma função em Python que utilize uma pilha para verificar se uma string de entrada possui parênteses, colchetes e chaves balanceados. Por exemplo:

*   `"([]{})"` -> Balanceado
*   `"([)]"` -> Não Balanceado
*   `"((()))"` -> Balanceado

**Dicas:**
1.  Crie uma pilha vazia.
2.  Percorra a string caractere por caractere.
3.  Se for um caractere de abertura (`(`, `[`, `{`), empilhe-o.
4.  Se for um caractere de fechamento (`)`, `]`, `}`):
    *   Verifique se a pilha está vazia. Se estiver, não está balanceado.
    *   Desempilhe o elemento do topo e verifique se ele corresponde ao caractere de fechamento atual.
5.  Ao final da string, se a pilha estiver vazia, a expressão está balanceada.

**Solução (para referência, não mostre ao aluno antes da tentativa):**

```python
def is_balanced(expression):
    stack = StackArray() # Ou StackLinkedList()
    mapping = {')': '(', ']': '[', '}': '{'}
    open_brackets = set(mapping.values())

    for char in expression:
        if char in open_brackets:
            stack.push(char)
        elif char in mapping:
            if stack.isEmpty() or stack.pop() != mapping[char]:
                return False
    return stack.isEmpty()

# Testes
print("\n--- Testando Balanceamento de Parênteses ---")
print(f"'([]{{}})' é balanceado? {is_balanced('([]{})')}") # Saída: True
print(f"'([)]' é balanceado? {is_balanced('([)]')}")     # Saída: False
print(f"'((()))' é balanceado? {is_balanced('((()))')}")   # Saída: True
print(f"'{{[()}}' é balanceado? {is_balanced('{[()}}')}")   # Saída: False
print(f"'{{}}[]()' é balanceado? {is_balanced('{}[]()')}")   # Saída: True
print(f"'(' é balanceado? {is_balanced('(')}")         # Saída: False
print(f"')' é balanceado? {is_balanced(')')}")         # Saída: False

```

---

#### 7. Referências e Leitura Complementar

Para aprofundar seus conhecimentos sobre Pilhas e estruturas de dados em geral, recomendo as seguintes obras:

*   **[1] Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009). *Introduction to Algorithms* (3rd ed.). MIT Press.**
    *   Capítulo 10: Estruturas de Dados Básicas (seção sobre Pilhas e Filas).
    *   Considerado a 'bíblia' dos algoritmos, oferece uma abordagem rigorosa e detalhada.

*   **[2] Goodrich, M. T., Tamassia, R., & Goldwasser, M. H. (2014). *Data Structures and Algorithms in Python*. John Wiley & Sons.**
    *   Capítulo 6: Stacks, Queues, and Deques.
    *   Excelente para quem busca implementações e exemplos em Python.

*   **[3] Sedgewick, R., & Wayne, K. (2011). *Algorithms* (4th ed.). Addison-Wesley Professional.**
    *   Capítulo 1: Fundamentals (seção sobre Stacks and Queues).
    *   Abordagem mais prática e focada em aplicações, com exemplos em Java (conceitos são transferíveis).

*   **[4] Livro: Estruturas de Dados e Algoritmos em C++ - Michael T. Goodrich, Roberto Tamassia, David M. Mount.**
    *   Capítulo 6: Pilhas, Filas e Deques.
    *   Embora em C++, os conceitos são universais e a explicação é muito clara.

*   **[5] Artigo/Recurso Online:** GeeksforGeeks - Stack Data Structure (https://www.geeksforgeeks.org/stack-data-structure/)
    *   Um recurso online popular com explicações claras, exemplos de código em várias linguagens e problemas práticos.

---

**Próxima Aula:** Filas (Queues) e Deques.



