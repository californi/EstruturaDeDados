### Aula 9: Grafos: Representações, Busca em Largura e Busca em Profundidade e suas Aplicações

**Duração Estimada:** 90 minutos

**Objetivos de Aprendizagem:**

Ao final desta aula, você será capaz de:

*   Compreender o conceito de grafos e sua importância na modelagem de problemas do mundo real.
*   Conhecer as diferentes formas de representação de grafos (matriz de adjacência e lista de adjacência).
*   Implementar e aplicar algoritmos de busca em largura (BFS) em grafos.
*   Implementar e aplicar algoritmos de busca em profundidade (DFS) em grafos.
*   Analisar a complexidade de tempo e espaço dos algoritmos de busca em grafos.
*   Identificar diversas aplicações práticas de grafos e seus algoritmos de busca.

---

#### 1. Introdução a Grafos (15 minutos)

**1.1. O que são Grafos?**

Um grafo é uma estrutura de dados não linear que consiste em um conjunto de vértices (ou nós) e um conjunto de arestas (ou arcos) que conectam pares de vértices. Grafos são ferramentas poderosas para modelar relações e interconexões em diversos domínios, desde redes sociais e mapas de estradas até circuitos elétricos e dependências de tarefas.

**1.2. Terminologia Básica:**

*   **Vértice (V):** Uma entidade no grafo (ex: cidade, pessoa, página web).
*   **Aresta (E):** Uma conexão entre dois vértices (ex: estrada entre cidades, amizade, link).
*   **Grafo Não Direcionado:** Arestas não têm direção (se A está conectado a B, B está conectado a A).
*   **Grafo Direcionado (Dígrafo):** Arestas têm direção (se A está conectado a B, não implica que B esteja conectado a A).
*   **Ponderação (Peso):** Um valor associado a uma aresta (ex: distância, custo, tempo).
*   **Caminho:** Uma sequência de vértices conectados por arestas.
*   **Ciclo:** Um caminho que começa e termina no mesmo vértice.
*   **Grafo Conexo:** Em um grafo não direcionado, existe um caminho entre qualquer par de vértices. Em um dígrafo, pode ser fortemente ou fracamente conexo.
*   **Grau de um Vértice:** Número de arestas incidentes a um vértice (em dígrafos, grau de entrada e grau de saída).

**Exemplo:**

Um mapa de cidades onde as cidades são vértices e as estradas são arestas. As estradas podem ter pesos (distância) e ser direcionadas (rua de mão única) ou não direcionadas.

---

#### 2. Representações de Grafos (20 minutos)

A forma como um grafo é armazenado na memória afeta a eficiência dos algoritmos que o manipulam. As duas representações mais comuns são a matriz de adjacência e a lista de adjacência.

**2.1. Matriz de Adjacência:**

Uma matriz quadrada `A[V][V]` onde `V` é o número de vértices. `A[i][j]` é 1 se existe uma aresta do vértice `i` para o vértice `j`, e 0 caso contrário. Para grafos ponderados, `A[i][j]` pode armazenar o peso da aresta.

**Vantagens:**
*   Verificar a existência de uma aresta é O(1).
*   Fácil de implementar.

**Desvantagens:**
*   Consome muito espaço (O(V^2)), especialmente para grafos esparsos (poucas arestas).
*   Iterar sobre os vizinhos de um vértice é O(V).

**Exemplo (Grafo Não Direcionado):**

```
   A B C D
A [0 1 1 0]
B [1 0 0 1]
C [1 0 0 1]
D [0 1 1 0]
```

**2.2. Lista de Adjacência:**

Um array de listas (ou listas encadeadas), onde o índice `i` do array corresponde ao vértice `i`, e a lista em `array[i]` contém todos os vértices adjacentes a `i`.

**Vantagens:**
*   Consome menos espaço para grafos esparsos (O(V + E)).
*   Iterar sobre os vizinhos de um vértice é O(grau do vértice).

**Desvantagens:**
*   Verificar a existência de uma aresta é O(grau do vértice).

**Exemplo de Código (Python - Lista de Adjacência):**

```python
class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.adj = {i: [] for i in range(vertices)} # Dicionário de listas de adjacência

    def add_edge(self, u, v, is_directed=False):
        self.adj[u].append(v)
        if not is_directed:
            self.adj[v].append(u)

# Exemplo de uso:
print("\n--- Testando Representação de Grafo (Lista de Adjacência) ---")
g = Graph(4) # Grafo com 4 vértices (0, 1, 2, 3)
g.add_edge(0, 1)
g.add_edge(0, 2)
g.add_edge(1, 3)
g.add_edge(2, 3)
print(f"Lista de Adjacência: {g.adj}")
# Output: {0: [1, 2], 1: [0, 3], 2: [0, 3], 3: [1, 2]}

```

---

#### 3. Busca em Largura (BFS - Breadth-First Search) (25 minutos)

BFS é um algoritmo para percorrer ou buscar em estruturas de dados de árvore ou grafo. Ele começa na raiz (ou em um nó arbitrário) e explora todos os nós vizinhos no nível atual antes de passar para os nós no próximo nível. Utiliza uma fila (Queue) para gerenciar os vértices a serem visitados.

**Funcionamento:**
1.  Comece por um vértice `s`, marque-o como visitado e adicione-o a uma fila.
2.  Enquanto a fila não estiver vazia:
    a.  Remova um vértice `u` da fila.
    b.  Para cada vizinho `v` de `u`:
        i.  Se `v` não foi visitado, marque-o como visitado e adicione-o à fila.

**Aplicações:**
*   Encontrar o caminho mais curto em grafos não ponderados (número mínimo de arestas).
*   Rastreamento de redes sociais (encontrar amigos de amigos).
*   Algoritmo de Kruskal (para Árvore Geradora Mínima).
*   Verificação de conectividade.

**Exemplo de Código (Python - BFS):**

```python
from collections import deque

def bfs(graph, start_node):
    visited = [False] * graph.V
    queue = deque()

    visited[start_node] = True
    queue.append(start_node)

    print(f"\n--- Testando BFS a partir do nó {start_node} ---")
    while queue:
        u = queue.popleft()
        print(u, end=" ")

        for v in graph.adj[u]:
            if not visited[v]:
                visited[v] = True
                queue.append(v)
    print()

# Exemplo de uso:
# g_bfs = Graph(4)
# g_bfs.add_edge(0, 1)
# g_bfs.add_edge(0, 2)
# g_bfs.add_edge(1, 3)
# g_bfs.add_edge(2, 3)
# bfs(g_bfs, 0) # Saída: 0 1 2 3

```

---

#### 4. Busca em Profundidade (DFS - Depth-First Search) (25 minutos)

DFS é outro algoritmo para percorrer ou buscar em estruturas de dados de árvore ou grafo. Ele começa na raiz (ou em um nó arbitrário) e explora o máximo possível ao longo de cada ramo antes de retroceder. Utiliza uma pilha (Stack) ou recursão para gerenciar os vértices a serem visitados.

**Funcionamento (Recursivo):**
1.  Comece por um vértice `u`, marque-o como visitado e processe-o.
2.  Para cada vizinho `v` de `u`:
    a.  Se `v` não foi visitado, chame DFS recursivamente para `v`.

**Aplicações:**
*   Detecção de ciclos em grafos.
*   Ordenação topológica (para dígrafos acíclicos).
*   Encontrar componentes fortemente conectados.
*   Resolução de labirintos.

**Exemplo de Código (Python - DFS):**

```python
def dfs_recursive(graph, start_node, visited):
    visited[start_node] = True
    print(start_node, end=" ")

    for neighbor in graph.adj[start_node]:
        if not visited[neighbor]:
            dfs_recursive(graph, neighbor, visited)

def dfs(graph, start_node):
    visited = [False] * graph.V
    print(f"\n--- Testando DFS a partir do nó {start_node} ---")
    dfs_recursive(graph, start_node, visited)
    print()

# Exemplo de uso:
# g_dfs = Graph(4)
# g_dfs.add_edge(0, 1)
# g_dfs.add_edge(0, 2)
# g_dfs.add_edge(1, 3)
# g_dfs.add_edge(2, 3)
# dfs(g_dfs, 0) # Saída: 0 1 3 2 (ou 0 2 3 1, dependendo da ordem dos vizinhos)

```

---

#### 5. Análise de Complexidade (5 minutos)

**Complexidade de Tempo:**
*   **BFS e DFS (Matriz de Adjacência):** O(V^2)
*   **BFS e DFS (Lista de Adjacência):** O(V + E) (onde V é o número de vértices e E é o número de arestas)

**Complexidade de Espaço:**
*   **BFS:** O(V) (para a fila e o array de visitados)
*   **DFS:** O(V) (para a pilha de recursão/pilha explícita e o array de visitados)

---

#### 6. Atividade Prática (5 minutos)

**Exercício:** Modifique a implementação da BFS para que ela não apenas visite os nós, mas também retorne o caminho mais curto (em número de arestas) de um nó inicial para todos os outros nós no grafo.

**Dicas:**
1.  Mantenha um array `distance` para armazenar a distância de `start_node` para cada nó.
2.  Mantenha um array `parent` para reconstruir o caminho.

---

#### 7. Referências e Leitura Complementar

*   **[1] Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009). *Introduction to Algorithms* (3rd ed.). MIT Press.**
    *   Capítulo 22: Algoritmos Básicos de Grafo.

*   **[2] Goodrich, M. T., Tamassia, R., & Goldwasser, M. H. (2014). *Data Structures and Algorithms in Python*. John Wiley & Sons.**
    *   Capítulo 13: Grafos.

*   **[3] Sedgewick, R., & Wayne, K. (2011). *Algorithms* (4th ed.). Addison-Wesley Professional.**
    *   Capítulo 4: Graphs.

*   **[4] Livro: Estruturas de Dados e Algoritmos em C++ - Michael T. Goodrich, Roberto Tamassia, David M. Mount.**
    *   Capítulo 13: Grafos.

*   **[5] Artigo/Recurso Online:** GeeksforGeeks - Graph and its representations (https://www.geeksforgeeks.org/graph-and-its-representations/)
    *   Recurso online sobre representações de grafos.

*   **[6] Artigo/Recurso Online:** GeeksforGeeks - BFS (https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/)
    *   Recurso online sobre BFS.

*   **[7] Artigo/Recurso Online:** GeeksforGeeks - DFS (https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/)
    *   Recurso online sobre DFS.

---

**Próxima Aula:** Problema do Caminho Mínimo em Grafos e suas Variações.



