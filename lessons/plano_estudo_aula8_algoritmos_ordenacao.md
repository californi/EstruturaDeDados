### Aula 8: Algoritmos de Ordenação em Memória Primária e Secundária e suas Complexidades

**Duração Estimada:** 90 minutos

**Objetivos de Aprendizagem:**

Ao final desta aula, você será capaz de:

*   Compreender a importância da ordenação de dados em diversas aplicações computacionais.
*   Conhecer e implementar os principais algoritmos de ordenação em memória primária: Bubble Sort, Selection Sort, Insertion Sort, Insertion Sort, Merge Sort, Quick Sort e Heap Sort.
*   Analisar a complexidade de tempo e espaço de cada algoritmo de ordenação em diferentes cenários (melhor, médio e pior caso).
*   Distinguir entre algoritmos de ordenação estáveis e instáveis, e in-place e out-of-place.
*   Entender os desafios e as abordagens para ordenação de dados em memória secundária (ordenação externa).
*   Reconhecer as aplicações e as trade-offs na escolha do algoritmo de ordenação adequado.

---

#### 1. Introdução à Ordenação (10 minutos)

**1.1. O que é Ordenação?**

Ordenação é o processo de organizar uma coleção de itens em uma sequência específica, baseada em um critério de ordenação (geralmente numérico ou alfabético). A ordenação é uma das operações mais fundamentais e frequentemente realizadas em ciência da computação, sendo um pré-requisito para muitas outras operações eficientes, como busca binária, fusão de dados e processamento de banco de dados.

**1.2. Importância da Ordenação:**

*   **Busca Eficiente:** Dados ordenados permitem o uso de algoritmos de busca mais rápidos (ex: busca binária).
*   **Processamento de Dados:** Facilita a análise, agregação e comparação de dados.
*   **Apresentação:** Melhora a legibilidade e a usabilidade de informações para usuários.
*   **Algoritmos:** Muitos algoritmos funcionam de forma mais eficiente ou dependem de dados ordenados.

**1.3. Terminologia:**

*   **Estabilidade:** Um algoritmo de ordenação é **estável** se ele mantém a ordem relativa de elementos com chaves iguais. Por exemplo, se dois elementos 'A' e 'B' têm o mesmo valor e 'A' aparece antes de 'B' na entrada, 'A' ainda aparecerá antes de 'B' na saída ordenada.
*   **In-place:** Um algoritmo de ordenação é **in-place** se ele requer uma quantidade constante ou muito pequena de espaço de memória auxiliar (O(1) ou O(log n)) além do espaço ocupado pelos dados de entrada. Algoritmos que exigem espaço auxiliar proporcional ao tamanho da entrada (O(n)) são considerados **out-of-place**.

---

#### 2. Algoritmos de Ordenação em Memória Primária (50 minutos)

Estes algoritmos operam sobre dados que cabem inteiramente na memória RAM.

**2.1. Bubble Sort (Ordenação por Bolha):**

Um algoritmo de ordenação simples que repetidamente percorre a lista, compara elementos adjacentes e os troca se estiverem na ordem errada. O processo é repetido até que nenhuma troca seja necessária, indicando que a lista está ordenada. Elementos maiores "borbulham" para o final da lista.

**Complexidade:**
*   **Pior Caso:** O(n^2)
*   **Caso Médio:** O(n^2)
*   **Melhor Caso:** O(n) (se já estiver ordenado e otimizado para parar)
*   **Estável:** Sim
*   **In-place:** Sim

**Exemplo de Código (Python):**

```python
def bubble_sort(arr):
    n = len(arr)
    for i in range(n - 1):
        swapped = False
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
        if not swapped:
            break # Se nenhuma troca ocorreu, a lista está ordenada
    return arr

# Exemplo de uso:
print("\n--- Testando Bubble Sort ---")
arr_bubble = [64, 34, 25, 12, 22, 11, 90]
print(f"Array original: {arr_bubble}")
print(f"Array ordenado: {bubble_sort(arr_bubble)}") # Saída: [11, 12, 22, 25, 34, 64, 90]

```

**2.2. Selection Sort (Ordenação por Seleção):**

Divide a lista em duas partes: uma sublista ordenada e uma sublista não ordenada. Em cada iteração, o menor (ou maior) elemento da sublista não ordenada é selecionado e movido para o final da sublista ordenada.

**Complexidade:**
*   **Pior Caso:** O(n^2)
*   **Caso Médio:** O(n^2)
*   **Melhor Caso:** O(n^2)
*   **Estável:** Não (geralmente)
*   **In-place:** Sim

**Exemplo de Código (Python):**

```python
def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        min_idx = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i] # Troca o elemento atual com o menor encontrado
    return arr

# Exemplo de uso:
print("\n--- Testando Selection Sort ---")
arr_selection = [64, 25, 12, 22, 11]
print(f"Array original: {arr_selection}")
print(f"Array ordenado: {selection_sort(arr_selection)}") # Saída: [11, 12, 22, 25, 64]

```

**2.3. Insertion Sort (Ordenação por Inserção):**

Constrói a lista final ordenada um item por vez. Ele itera sobre a lista de entrada, removendo um elemento por vez e inserindo-o na posição correta na parte já ordenada da lista.

**Complexidade:**
*   **Pior Caso:** O(n^2)
*   **Caso Médio:** O(n^2)
*   **Melhor Caso:** O(n) (se já estiver ordenado)
*   **Estável:** Sim
*   **In-place:** Sim

**Exemplo de Código (Python):**

```python
def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
    return arr

# Exemplo de uso:
print("\n--- Testando Insertion Sort ---")
arr_insertion = [12, 11, 13, 5, 6]
print(f"Array original: {arr_insertion}")
print(f"Array ordenado: {insertion_sort(arr_insertion)}") # Saída: [5, 6, 11, 12, 13]

```

**2.4. Merge Sort (Ordenação por Intercalação):**

Um algoritmo de ordenação eficiente baseado na técnica de divisão e conquista. Ele divide recursivamente a lista em duas metades até que cada sublista contenha apenas um elemento (que é considerado ordenado). Em seguida, ele mescla (intercala) as sublistas de volta em ordem.

**Complexidade:**
*   **Pior Caso:** O(n log n)
*   **Caso Médio:** O(n log n)
*   **Melhor Caso:** O(n log n)
*   **Estável:** Sim
*   **In-place:** Não (requer espaço auxiliar O(n))

**Exemplo de Código (Python):**

```python
def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2
        left_half = arr[:mid]
        right_half = arr[mid:]

        merge_sort(left_half)
        merge_sort(right_half)

        i = j = k = 0

        while i < len(left_half) and j < len(right_half):
            if left_half[i] < right_half[j]:
                arr[k] = left_half[i]
                i += 1
            else:
                arr[k] = right_half[j]
                j += 1
            k += 1

        while i < len(left_half):
            arr[k] = left_half[i]
            i += 1
            k += 1

        while j < len(right_half):
            arr[k] = right_half[j]
            j += 1
            k += 1
    return arr

# Exemplo de uso:
print("\n--- Testando Merge Sort ---")
arr_merge = [12, 11, 13, 5, 6, 7]
print(f"Array original: {arr_merge}")
print(f"Array ordenado: {merge_sort(arr_merge)}") # Saída: [5, 6, 7, 11, 12, 13]

```

**2.5. Quick Sort (Ordenação Rápida):**

Também baseado em divisão e conquista. Ele seleciona um elemento como 'pivô' e particiona o array em torno do pivô, de modo que todos os elementos menores que o pivô fiquem antes dele e todos os elementos maiores fiquem depois. O processo é então aplicado recursivamente às sublistas.

**Complexidade:**
*   **Pior Caso:** O(n^2) (ocorre quando o pivô é sempre o menor ou maior elemento)
*   **Caso Médio:** O(n log n)
*   **Melhor Caso:** O(n log n)
*   **Estável:** Não
*   **In-place:** Sim (na maioria das implementações)

**Exemplo de Código (Python):**

```python
def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    return quick_sort(left) + middle + quick_sort(right)

# Exemplo de uso:
print("\n--- Testando Quick Sort ---")
arr_quick = [10, 7, 8, 9, 1, 5]
print(f"Array original: {arr_quick}")
print(f"Array ordenado: {quick_sort(arr_quick)}") # Saída: [1, 5, 7, 8, 9, 10]

```

**2.6. Heap Sort (Ordenação por Heap):**

Utiliza a estrutura de dados heap (especificamente um max-heap) para ordenar os elementos. Primeiro, constrói um max-heap a partir do array de entrada. Em seguida, remove repetidamente o elemento máximo (raiz do heap) e o coloca no final do array, reconstruindo o heap com os elementos restantes.

**Complexidade:**
*   **Pior Caso:** O(n log n)
*   **Caso Médio:** O(n log n)
*   **Melhor Caso:** O(n log n)
*   **Estável:** Não
*   **In-place:** Sim

**Exemplo de Código (Python):**

```python
def heapify(arr, n, i):
    largest = i  # Inicializa o maior como raiz
    l = 2 * i + 1  # filho esquerdo
    r = 2 * i + 2  # filho direito

    # Se o filho esquerdo é maior que a raiz
    if l < n and arr[l] > arr[largest]:
        largest = l

    # Se o filho direito é maior que o maior até agora
    if r < n and arr[r] > arr[largest]:
        largest = r

    # Se o maior não é a raiz
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]  # Troca
        heapify(arr, n, largest)  # Chama heapify na heap reduzida

def heap_sort(arr):
    n = len(arr)

    # Constrói um max-heap
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

    # Extrai elementos um por um
    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]  # Troca raiz com o último elemento
        heapify(arr, i, 0)  # Chama heapify na heap reduzida
    return arr

# Exemplo de uso:
print("\n--- Testando Heap Sort ---")
arr_heap = [12, 11, 13, 5, 6, 7]
print(f"Array original: {arr_heap}")
print(f"Array ordenado: {heap_sort(arr_heap)}") # Saída: [5, 6, 7, 11, 12, 13]

```

---

#### 3. Algoritmos de Ordenação em Memória Secundária (Ordenação Externa) (15 minutos)

Quando o volume de dados a ser ordenado é tão grande que não cabe inteiramente na memória primária, precisamos recorrer a algoritmos de ordenação externa. Esses algoritmos minimizam o número de acessos a disco, que são muito mais lentos que os acessos à RAM.

A abordagem geral para ordenação externa envolve duas fases principais:

**3.1. Fase de Criação de Runs (Ordenação Interna):**

1.  O arquivo de entrada é dividido em blocos de tamanho que cabem na memória primária.
2.  Cada bloco é lido na memória, ordenado usando um algoritmo de ordenação interna (como Quick Sort ou Heap Sort), e então gravado de volta no disco como um run (sequência ordenada). O número de runs criados é `N/M`, onde `N` é o tamanho total dos dados e `M` é o tamanho da memória disponível.

**3.2. Fase de Fusão (Merge Phase):**

1.  Os runs criados na fase anterior são mesclados iterativamente. Em cada passo, múltiplos runs são lidos da memória secundária, mesclados na memória primária e o resultado é gravado de volta no disco como um run maior.
2.  Este processo continua até que todos os runs sejam mesclados em um único run ordenado.

**Exemplo: Merge Sort de Múltiplos Caminhos (Multiway Merge Sort):**

É uma extensão do Merge Sort para ordenação externa. Em vez de mesclar apenas dois runs por vez, ele mescla `k` runs simultaneamente, onde `k` é o número de buffers de entrada que podem caber na memória primária. Isso reduz o número de passes de fusão necessários.

**Complexidade da Ordenação Externa:**

A complexidade é medida em termos do número de acessos a disco (I/Os). Para um arquivo de `N` blocos e uma memória de `M` blocos, a ordenação externa geralmente requer `O(N log_M N)` acessos a disco. A fase de criação de runs lê e escreve o arquivo uma vez. A fase de fusão lê e escreve o arquivo `log_k (número de runs)` vezes, onde `k` é o número de runs mesclados por vez.

---

#### 4. Atividade Prática (10 minutos)

**Exercício:** Escolha um dos algoritmos de ordenação em memória primária (por exemplo, Insertion Sort ou Merge Sort) e implemente-o em sua linguagem de programação preferida. Teste-o com um array de 1000 números aleatórios e meça o tempo de execução. Compare o tempo de execução com o de outro algoritmo de ordenação que você implementou ou que está disponível na biblioteca padrão da sua linguagem.

**Dicas:**
1.  Use a função `time.time()` (Python) ou similar para medir o tempo.
2.  Gere números aleatórios para criar o array de teste.
3.  Considere a complexidade teórica ao analisar os resultados.

**Solução (para referência, não mostre ao aluno antes da tentativa):**

```python
import random
import time

def insertion_sort_practice(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
    return arr

def merge_sort_practice(arr):
    if len(arr) > 1:
        mid = len(arr) // 2
        left_half = arr[:mid]
        right_half = arr[mid:]

        merge_sort_practice(left_half)
        merge_sort_practice(right_half)

        i = j = k = 0

        while i < len(left_half) and j < len(right_half):
            if left_half[i] < right_half[j]:
                arr[k] = left_half[i]
                i += 1
            else:
                arr[k] = right_half[j]
                j += 1
            k += 1

        while i < len(left_half):
            arr[k] = left_half[i]
            i += 1
            k += 1

        while j < len(right_half):
            arr[k] = right_half[j]
            j += 1
            k += 1
    return arr

# Geração de dados de teste
print("\n--- Atividade Prática: Comparação de Algoritmos de Ordenação ---")
NUM_ELEMENTS = 1000
random_list_1 = [random.randint(0, 10000) for _ in range(NUM_ELEMENTS)]
random_list_2 = list(random_list_1) # Copia para garantir os mesmos dados

# Teste Insertion Sort
start_time = time.time()
insertion_sort_practice(random_list_1)
end_time = time.time()
print(f"Insertion Sort para {NUM_ELEMENTS} elementos: {end_time - start_time:.6f} segundos")

# Teste Merge Sort
start_time = time.time()
merge_sort_practice(random_list_2)
end_time = time.time()
print(f"Merge Sort para {NUM_ELEMENTS} elementos: {end_time - start_time:.6f} segundos")

# Teste com a função sort() do Python (geralmente Timsort, O(n log n))
random_list_3 = list(random_list_1) # Outra cópia
start_time = time.time()
random_list_3.sort()
end_time = time.time()
print(f"Python built-in sort para {NUM_ELEMENTS} elementos: {end_time - start_time:.6f} segundos")

```

---

#### 5. Referências e Leitura Complementar

*   **[1] Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009). *Introduction to Algorithms* (3rd ed.). MIT Press.**
    *   Capítulo 2: Getting Started (para Insertion Sort).
    *   Capítulo 6: Heapsort.
    *   Capítulo 7: Quicksort.
    *   Capítulo 8: Sorting in Linear Time.
    *   Capítulo 16: Greedy Algorithms (para alguns problemas de ordenação).

*   **[2] Goodrich, M. T., Tamassia, R., & Goldwasser, M. H. (2014). *Data Structures and Algorithms in Python*. John Wiley & Sons.**
    *   Capítulo 12: Ordenação e Seleção.

*   **[3] Sedgewick, R., & Wayne, K. (2011). *Algorithms* (4th ed.). Addison-Wesley Professional.**
    *   Capítulo 2: Sorting.

*   **[4] Livro: Estruturas de Dados e Algoritmos em C++ - Michael T. Goodrich, Roberto Tamassia, David M. Mount.**
    *   Capítulo 12: Ordenação e Seleção.

*   **[5] Artigo/Recurso Online:** GeeksforGeeks - Sorting Algorithms (https://www.geeksforgeeks.org/sorting-algorithms/)
    *   Um recurso online abrangente sobre diversos algoritmos de ordenação.

*   **[6] Artigo/Recurso Online:** GeeksforGeeks - External Sorting (https://www.geeksforgeeks.org/external-sorting/)
    *   Recurso online sobre ordenação externa.

---

**Próxima Aula:** Grafos: Representações, Busca em Largura e Busca em Profundidade.



