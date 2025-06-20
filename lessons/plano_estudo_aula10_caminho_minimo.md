### Aula 10: Problema do Caminho Mínimo em Grafos e suas Variações

**Duração Estimada:** 90 minutos

**Objetivos de Aprendizagem:**

Ao final desta aula, você será capaz de:

*   Compreender o problema do caminho mínimo em grafos e suas diferentes variações.
*   Conhecer e implementar o algoritmo de Dijkstra para grafos com pesos não negativos.
*   Entender o algoritmo de Bellman-Ford para grafos com pesos negativos e detecção de ciclos negativos.
*   Compreender o algoritmo de Floyd-Warshall para encontrar caminhos mínimos entre todos os pares de vértices.
*   Analisar a complexidade de tempo de cada algoritmo.
*   Reconhecer as aplicações práticas desses algoritmos em diversos domínios.

---

#### 1. Introdução ao Problema do Caminho Mínimo (10 minutos)

**1.1. O que é o Problema do Caminho Mínimo?**

O problema do caminho mínimo em um grafo busca encontrar um caminho entre dois vértices (ou entre um vértice e todos os outros, ou entre todos os pares de vértices) de forma que a soma dos pesos das arestas nesse caminho seja a menor possível. Este é um problema fundamental na teoria dos grafos com vastas aplicações.

**1.2. Variações do Problema:**

*   **Fonte Única para Destino Único:** Encontrar o caminho mínimo de um vértice `s` para um vértice `t`.
*   **Fonte Única para Todos os Destinos:** Encontrar o caminho mínimo de um vértice `s` para todos os outros vértices no grafo.
*   **Todos os Pares de Vértices:** Encontrar o caminho mínimo entre cada par de vértices no grafo.

**1.3. Tipos de Grafos:**

*   **Grafos Não Ponderados:** Todos os pesos das arestas são considerados 1. A BFS (Busca em Largura) pode ser usada para encontrar o caminho mínimo neste caso.
*   **Grafos Ponderados com Pesos Não Negativos:** Os pesos das arestas são maiores ou iguais a zero. Algoritmos como Dijkstra são adequados.
*   **Grafos Ponderados com Pesos Negativos:** Alguns pesos de arestas podem ser negativos. Algoritmos como Bellman-Ford são necessários. Cuidado com **ciclos negativos**, que tornam o problema indefinido (o caminho pode ter um peso infinitamente pequeno).

**1.4. Aplicações:**

*   **Sistemas de Navegação (GPS):** Encontrar a rota mais curta ou mais rápida entre dois pontos.
*   **Roteamento de Redes:** Determinar o caminho mais eficiente para pacotes de dados.
*   **Logística e Transporte:** Otimização de rotas de entrega.
*   **Análise de Redes Sociais:** Encontrar o grau de separação entre pessoas.
*   **Bioinformática:** Alinhamento de sequências de DNA.

---

#### 2. Algoritmo de Dijkstra (30 minutos)

O algoritmo de Dijkstra resolve o problema do caminho mínimo de fonte única para grafos com pesos de arestas **não negativos**. É um algoritmo guloso que constrói o caminho mínimo passo a passo.

**2.1. Conceito:**

O algoritmo mantém um conjunto de vértices `S` para os quais o caminho mínimo da fonte já foi determinado. Em cada passo, ele seleciona o vértice `u` fora de `S` que tem a menor estimativa de distância da fonte. Adiciona `u` a `S` e então **relaxa** todas as arestas que saem de `u`.

**Relaxamento de Arestas:** Para uma aresta `(u, v)` com peso `w(u, v)`, se a distância atual para `v` (`d[v]`) for maior que a distância para `u` (`d[u]`) mais o peso da aresta (`d[u] + w(u, v)`), então `d[v]` é atualizada para `d[u] + w(u, v)`.

**2.2. Passos do Algoritmo:**

1.  Inicialize as distâncias: `d[s] = 0` para o vértice fonte `s`, e `d[v] = infinito` para todos os outros vértices `v`.
2.  Crie uma fila de prioridade (min-heap) que armazena pares `(distância, vértice)`, inicialmente contendo `(0, s)`.
3.  Enquanto a fila de prioridade não estiver vazia:
    a.  Extraia o vértice `u` com a menor distância da fila de prioridade.
    b.  Se `u` já foi visitado (ou sua distância extraída é maior que a distância já finalizada), continue.
    c.  Marque `u` como visitado.
    d.  Para cada vizinho `v` de `u`:
        i.  Relaxe a aresta `(u, v)`: se `d[u] + w(u, v) < d[v]`, atualize `d[v]` e insira/atualize `(d[v], v)` na fila de prioridade.

**2.3. Complexidade de Tempo:**

*   **Com array simples (sem fila de prioridade):** O(V^2)
*   **Com fila de prioridade (min-heap binário):** O((V + E) log V) ou O(E log V) se o grafo for conectado.
    *   `V`: número de vértices
    *   `E`: número de arestas

**Exemplo de Código (Python - Dijkstra com `heapq`):**

```python
import heapq

def dijkstra(graph, start_node):
    distances = {node: float(\'inf\') for node in graph} # Inicializa distâncias
    distances[start_node] = 0
    priority_queue = [(0, start_node)] # (distância, vértice)

    while priority_queue:
        current_distance, current_node = heapq.heappop(priority_queue)

        # Se já encontramos um caminho mais curto, ignoramos
        if current_distance > distances[current_node]:
            continue

        for neighbor, weight in graph[current_node].items():
            distance = current_distance + weight

            # Se encontramos um caminho mais curto para o vizinho
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(priority_queue, (distance, neighbor))

    return distances

# Exemplo de uso (grafo como dicionário de dicionários de adjacência):
print("\n--- Testando Algoritmo de Dijkstra ---")
graph_dijkstra = {
    \'A\': {\'B\': 1, \'C\': 4},
    \'B\': {\'A\': 1, \'C\': 2, \'D\': 5},
    \'C\': {\'A\': 4, \'B\': 2, \'D\': 1},
    \'D\': {\'B\': 5, \'C\': 1}
}
start_node_dijkstra = \'A\'
shortest_paths_dijkstra = dijkstra(graph_dijkstra, start_node_dijkstra)
print(f"Caminhos mínimos a partir de {start_node_dijkstra}: {shortest_paths_dijkstra}")
# Saída esperada: {\'A\': 0, \'B\': 1, \'C\': 3, \'D\': 4}
```

---

#### 3. Algoritmo de Bellman-Ford (20 minutos)

O algoritmo de Bellman-Ford resolve o problema do caminho mínimo de fonte única em grafos que podem conter pesos de arestas **negativos**, desde que não haja ciclos negativos alcançáveis a partir da fonte. Ele é mais geral que Dijkstra, mas geralmente mais lento.

**3.1. Conceito:**

Bellman-Ford relaxa todas as arestas do grafo `V-1` vezes. Após `V-1` iterações, se o grafo não contiver ciclos negativos, todas as distâncias de caminho mínimo terão sido encontradas. Uma `V`-ésima iteração é usada para detectar ciclos negativos.

**3.2. Passos do Algoritmo:**

1.  Inicialize as distâncias: `d[s] = 0` para a fonte `s`, e `d[v] = infinito` para todos os outros `v`.
2.  Repita `V-1` vezes:
    a.  Para cada aresta `(u, v)` com peso `w(u, v)` no grafo:
        i.  Relaxe a aresta: se `d[u] + w(u, v) < d[v]`, então `d[v] = d[u] + w(u, v)`.
3.  **Detecção de Ciclos Negativos:** Após `V-1` iterações, faça uma `V`-ésima iteração. Se, durante esta iteração, qualquer distância `d[v]` puder ser ainda mais relaxada (`d[u] + w(u, v) < d[v]`), isso indica a presença de um ciclo negativo alcançável a partir da fonte.

**3.3. Complexidade de Tempo:**

*   O(V * E)

**Exemplo de Código (Python - Bellman-Ford):**

```python
def bellman_ford(graph_edges, start_node):
    # graph_edges é uma lista de tuplas (u, v, weight)
    # vertices é um conjunto de todos os nós
    vertices = set()
    for u, v, w in graph_edges:
        vertices.add(u)
        vertices.add(v)

    distances = {node: float(\'inf\') for node in vertices}
    distances[start_node] = 0

    # Relaxa todas as arestas V-1 vezes
    for _ in range(len(vertices) - 1):
        for u, v, weight in graph_edges:
            if distances[u] != float(\'inf\') and distances[u] + weight < distances[v]:
                distances[v] = distances[u] + weight

    # Verifica ciclos negativos
    for u, v, weight in graph_edges:
        if distances[u] != float(\'inf\') and distances[u] + weight < distances[v]:
            print("Grafo contém ciclo negativo!")
            return None # Indica a presença de ciclo negativo

    return distances

# Exemplo de uso (grafo como lista de arestas):
print("\n--- Testando Algoritmo de Bellman-Ford ---")
edges_bellman = [
    (\'A\', \'B\', 1),
    (\'A\', \'C\', 4),
    (\'B\', \'C\', 2),
    (\'B\', \'D\', 5),
    (\'C\', \'D\', 1)
]
start_node_bellman = \'A\'
shortest_paths_bellman = bellman_ford(edges_bellman, start_node_bellman)
print(f"Caminhos mínimos a partir de {start_node_bellman}: {shortest_paths_bellman}")
# Saída esperada: {\'A\': 0, \'B\': 1, \'C\': 3, \'D\': 4}

# Exemplo com ciclo negativo:
print("\n--- Testando Bellman-Ford com Ciclo Negativo ---")
edges_neg_cycle = [
    (\'A\', \'B\', 1),
    (\'B\', \'C\', -1),
    (\'C\', \'A\', -1)
]
start_node_neg_cycle = \'A\'
shortest_paths_neg_cycle = bellman_ford(edges_neg_cycle, start_node_neg_cycle)
# Saída: Grafo contém ciclo negativo!
```

---

#### 4. Algoritmo de Floyd-Warshall (15 minutos)

O algoritmo de Floyd-Warshall resolve o problema de **todos os pares de caminhos mínimos** em um grafo ponderado (com ou sem pesos negativos, mas sem ciclos negativos). Ele usa uma abordagem de programação dinâmica.

**4.1. Conceito:**

O algoritmo considera todos os vértices `k` como vértices intermediários potenciais em um caminho de `i` para `j`. Ele itera sobre todos os vértices `k` e, para cada `k`, atualiza as distâncias entre todos os pares `(i, j)` se um caminho via `k` for mais curto.

**4.2. Passos do Algoritmo:**

1.  Inicialize uma matriz de distâncias `dist[i][j]` com os pesos das arestas diretas entre `i` e `j`. Se não houver aresta, use infinito. `dist[i][i] = 0`.
2.  Para `k` de 0 a `V-1` (vértice intermediário):
    a.  Para `i` de 0 a `V-1` (vértice de origem):
        i.  Para `j` de 0 a `V-1` (vértice de destino):
            1.  `dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])`
3.  Após todas as iterações, `dist[i][j]` conterá o caminho mínimo de `i` para `j`.
4.  **Detecção de Ciclos Negativos:** Se, após todas as iterações, `dist[i][i]` for negativo para qualquer `i`, então há um ciclo negativo.

**4.3. Complexidade de Tempo:**

*   O(V^3)

**Exemplo de Código (Python - Floyd-Warshall):**

```python
INF = float(\'inf\')

def floyd_warshall(graph_matrix):
    V = len(graph_matrix)
    dist = list(map(lambda i: list(map(lambda j: j, i)), graph_matrix)) # Cria uma cópia da matriz

    # Adiciona todos os vértices um por um ao conjunto de vértices intermediários
    for k in range(V):
        # Escolhe todos os vértices como origem um por um
        for i in range(V):
            # Escolhe todos os vértices como destino para a origem escolhida
            for j in range(V):
                # Se o vértice k está no caminho de i para j, então atualiza o valor
                if dist[i][k] != INF and dist[k][j] != INF:
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

    # Detecção de ciclo negativo
    for i in range(V):
        if dist[i][i] < 0:
            print("Grafo contém ciclo negativo!")
            return None

    return dist

# Exemplo de uso (grafo como matriz de adjacência):
print("\n--- Testando Algoritmo de Floyd-Warshall ---")
graph_fw = [
    [0, 3, INF, 7],
    [8, 0, 2, INF],
    [5, INF, 0, 1],
    [2, INF, INF, 0]
]
shortest_paths_fw = floyd_warshall(graph_fw)
if shortest_paths_fw:
    print("Matriz de distâncias mínimas:")
    for row in shortest_paths_fw:
        print(row)
# Saída esperada (matriz de distâncias mínimas):
# [[0, 3, 5, 6],
#  [7, 0, 2, 3],
#  [5, 8, 0, 1],
#  [2, 5, 7, 0]]
```

---

#### 5. Atividade Prática (10 minutos)

**Exercício:** Considere o seguinte grafo ponderado (representado como um dicionário de adjacência, onde as chaves são os nós e os valores são dicionários de vizinhos com seus pesos):

```python
grafo_exemplo = {
    \'A\': {\'B\': 6, \'D\': 1},
    \'B\': {\'A\': 6, \'C\': 5, \'D\': 2, \'E\': 2},
    \'C\': {\'B\': 5, \'E\': 5},
    \'D\': {\'A\': 1, \'B\': 2, \'E\': 1},
    \'E\': {\'B\': 2, \'C\': 5, \'D\': 1}
}
```

Utilize o algoritmo de Dijkstra para encontrar o caminho mínimo do nó 'A' para todos os outros nós. Escreva o código e imprima as distâncias resultantes.

**Solução (para referência, não mostre ao aluno antes da tentativa):**

```python
import heapq

def dijkstra_practice(graph, start_node):
    distances = {node: float(\'inf\') for node in graph} # Inicializa distâncias
    distances[start_node] = 0
    priority_queue = [(0, start_node)] # (distância, vértice)

    while priority_queue:
        current_distance, current_node = heapq.heappop(priority_queue)

        if current_distance > distances[current_node]:
            continue

        for neighbor, weight in graph[current_node].items():
            distance = current_distance + weight

            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(priority_queue, (distance, neighbor))

    return distances

print("\n--- Atividade Prática: Dijkstra em Grafo Exemplo ---")
grafo_exemplo = {
    \'A\': {\'B\': 6, \'D\': 1},
    \'B\': {\'A\': 6, \'C\': 5, \'D\': 2, \'E\': 2},
    \'C\': {\'B\': 5, \'E\': 5},
    \'D\': {\'A\': 1, \'B\': 2, \'E\': 1},
    \'E\': {\'B\': 2, \'C\': 5, \'D\': 1}
}

start_node_practice = \'A\'
shortest_paths_practice = dijkstra_practice(grafo_exemplo, start_node_practice)
print(f"Caminhos mínimos a partir de {start_node_practice}: {shortest_paths_practice}")
# Saída esperada: {\'A\': 0, \'B\': 3, \'D\': 1, \'E\': 2, \'C\': 7}
```

---

#### 6. Referências e Leitura Complementar

*   **[1] Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009). *Introduction to Algorithms* (3rd ed.). MIT Press.**
    *   Capítulo 24: Caminhos Mínimos de Fonte Única (Dijkstra, Bellman-Ford).
    *   Capítulo 25: Caminhos Mínimos de Todos os Pares (Floyd-Warshall).

*   **[2] Goodrich, M. T., Tamassia, R., & Goldwasser, M. H. (2014). *Data Structures and Algorithms in Python*. John Wiley & Sons.**
    *   Capítulo 14: Grafos (seções sobre caminhos mínimos).

*   **[3] Sedgewick, R., & Wayne, K. (2011). *Algorithms* (4th ed.). Addison-Wesley Professional.**
    *   Capítulo 4: Graphs (seções sobre caminhos mínimos).

*   **[4] Livro: Estruturas de Dados e Algoritmos em C++ - Michael T. Goodrich, Roberto Tamassia, David M. Mount.**
    *   Capítulo 14: Grafos (seções sobre caminhos mínimos).

*   **[5] Artigo/Recurso Online:** GeeksforGeeks - Dijkstra\'s Algorithm (https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/)
    *   Recurso online sobre o algoritmo de Dijkstra.

*   **[6] Artigo/Recurso Online:** GeeksforGeeks - Bellman-Ford Algorithm (https://www.geeksforgeeks.org/bellman-ford-algorithm-introduction-and-example/)
    *   Recurso online sobre o algoritmo de Bellman-Ford.

*   **[7] Artigo/Recurso Online:** GeeksforGeeks - Floyd Warshall Algorithm (https://www.geeksforgeeks.org/floyd-warshall-algorithm-dp-16/)
    *   Recurso online sobre o algoritmo de Floyd-Warshall.

---

**Próxima Aula:** Técnicas de Projetos de Algoritmos: Algoritmos Gulosos, Divisão e Conquista, Programação Dinâmica.



