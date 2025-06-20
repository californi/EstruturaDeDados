### Aula 11: Técnicas de Projetos de Algoritmos: Algoritmos Gulosos, Divisão e Conquista, Programação Dinâmica

**Duração Estimada:** 90 minutos

**Objetivos de Aprendizagem:**

Ao final desta aula, você será capaz de:

*   Compreender os princípios e a filosofia por trás das principais técnicas de projeto de algoritmos.
*   Identificar problemas que podem ser resolvidos por algoritmos gulosos e aplicar a estratégia gulosa.
*   Entender o paradigma de Divisão e Conquista e como aplicá-lo para resolver problemas complexos.
*   Dominar o conceito de Programação Dinâmica, reconhecer suas características e aplicá-la para otimizar soluções.
*   Analisar a complexidade de tempo e espaço de algoritmos projetados usando essas técnicas.
*   Reconhecer as aplicações e as trade-offs de cada técnica.

---

#### 1. Introdução às Técnicas de Projeto de Algoritmos (10 minutos)

Até agora, exploramos diversas estruturas de dados e algoritmos específicos. No entanto, para resolver problemas computacionais complexos de forma eficiente, é crucial entender as **técnicas de projeto de algoritmos**. Estas são abordagens gerais que fornecem um arcabouço para desenvolver algoritmos eficazes. Nesta aula, focaremos em três das mais importantes:

*   **Algoritmos Gulosos (Greedy Algorithms):** Fazem a melhor escolha local na esperança de que essa escolha leve a uma solução ótima global.
*   **Divisão e Conquista (Divide and Conquer):** Quebram um problema grande em subproblemas menores do mesmo tipo, resolvem os subproblemas recursivamente e combinam suas soluções.
*   **Programação Dinâmica (Dynamic Programming):** Resolve problemas otimizados que possuem subproblemas sobrepostos e estrutura ótima, armazenando os resultados de subproblemas para evitar recálculos.

---

#### 2. Algoritmos Gulosos (25 minutos)

**2.1. Conceito:**

Um algoritmo guloso é uma abordagem que, em cada etapa, faz a escolha que parece ser a melhor no momento, ou seja, a escolha localmente ótima. Ele nunca reconsidera suas decisões. Para que um algoritmo guloso funcione corretamente, o problema deve possuir duas propriedades:

*   **Propriedade da Escolha Gulosa (Greedy Choice Property):** Uma solução ótima global pode ser alcançada fazendo uma escolha localmente ótima.
*   **Propriedade da Subestrutura Ótima (Optimal Substructure):** Uma solução ótima para o problema contém soluções ótimas para seus subproblemas.

**2.2. Exemplos e Aplicações:**

*   **Problema da Troca de Moedas:** Dado um conjunto de moedas de diferentes valores, encontrar o menor número de moedas para formar uma quantia. (Funciona para sistemas de moedas canônicos, mas falha para outros).
*   **Problema da Atividade (Activity Selection Problem):** Selecionar o número máximo de atividades que podem ser realizadas por um único recurso, dado que cada atividade tem um tempo de início e fim.
*   **Algoritmo de Dijkstra:** (Já vimos) É um algoritmo guloso para encontrar o caminho mínimo em grafos com pesos não negativos.
*   **Algoritmo de Prim e Kruskal:** Para encontrar a Árvore Geradora Mínima (Minimum Spanning Tree - MST).

**Exemplo de Código (Python - Problema da Troca de Moedas - Guloso):**

```python
def greedy_coin_change(amount, denominations):
    # As denominações devem estar em ordem decrescente
    denominations.sort(reverse=True)
    result = {}
    for coin in denominations:
        while amount >= coin:
            result[coin] = result.get(coin, 0) + 1
            amount -= coin
    return result

# Exemplo de uso:
print("\n--- Testando Algoritmo Guloso (Troca de Moedas) ---")
moedas = [25, 10, 5, 1] # Denominações canônicas
quantia = 67
print(f"Troco para {quantia} com moedas {moedas}: {greedy_coin_change(quantia, moedas)}")
# Saída: {25: 2, 10: 1, 5: 1, 1: 2} (2x25 + 1x10 + 1x5 + 2x1 = 67)

moedas_nao_canonicas = [1, 5, 10, 12, 25]
quantia_nao_canonicas = 29
print(f"Troco para {quantia_nao_canonicas} com moedas {moedas_nao_canonicas}: {greedy_coin_change(quantia_nao_canonicas, moedas_nao_canonicas)}")
# Saída: {25: 1, 10: 0, 12: 0, 5: 0, 1: 4} -> {25: 1, 1: 4} (1x25 + 4x1 = 29) - Ótimo seria 12+12+5 = 29 (3 moedas)
# Este exemplo demonstra que o guloso nem sempre é ótimo para denominações não canônicas.
```

**2.3. Limitações:**

Nem todos os problemas podem ser resolvidos de forma ótima por algoritmos gulosos. É crucial provar que a propriedade da escolha gulosa e a propriedade da subestrutura ótima se aplicam ao problema em questão.

---

#### 3. Divisão e Conquista (25 minutos)

**3.1. Conceito:**

Divisão e Conquista é um paradigma de projeto de algoritmos que envolve três etapas principais:

1.  **Dividir (Divide):** O problema é dividido em dois ou mais subproblemas menores e independentes do mesmo tipo do problema original.
2.  **Conquistar (Conquer):** Os subproblemas são resolvidos recursivamente. Se o subproblema for pequeno o suficiente, ele é resolvido diretamente (caso base).
3.  **Combinar (Combine):** As soluções dos subproblemas são combinadas para formar a solução do problema original.

**3.2. Exemplos e Aplicações:**

*   **Merge Sort:** (Já vimos) Divide o array em duas metades, ordena cada metade recursivamente e depois mescla as duas metades ordenadas.
*   **Quick Sort:** (Já vimos) Particiona o array em torno de um pivô e ordena recursivamente as duas partições.
*   **Busca Binária:** Divide o espaço de busca pela metade em cada etapa.
*   **Multiplicação de Matrizes (Strassen):** Um algoritmo mais eficiente que a multiplicação de matrizes padrão, usando divisão e conquista.
*   **Problema da Torre de Hanói:** Um problema clássico que pode ser resolvido recursivamente usando divisão e conquista.

**Exemplo de Código (Python - Busca Binária):**

```python
def binary_search(arr, target):
    left, right = 0, len(arr) - 1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return mid # Elemento encontrado
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1 # Elemento não encontrado

# Exemplo de uso:
print("\n--- Testando Divisão e Conquista (Busca Binária) ---")
lista_ordenada = [1, 5, 7, 10, 12, 15, 20, 22]
alvo1 = 12
alvo2 = 9

indice1 = binary_search(lista_ordenada, alvo1)
indice2 = binary_search(lista_ordenada, alvo2)

print(f"O elemento {alvo1} está no índice: {indice1}") # Saída: 4
print(f"O elemento {alvo2} está no índice: {indice2}") # Saída: -1
```

**3.3. Análise de Complexidade:**

A complexidade de algoritmos de divisão e conquista é frequentemente analisada usando relações de recorrência. O Teorema Mestre é uma ferramenta poderosa para resolver muitas dessas recorrências.

---

#### 4. Programação Dinâmica (25 minutos)

**4.1. Conceito:**

Programação Dinâmica é uma técnica usada para resolver problemas de otimização que possuem duas características principais:

*   **Subproblemas Sobrepostos (Overlapping Subproblems):** O problema pode ser dividido em subproblemas menores que são resolvidos repetidamente. A programação dinâmica resolve cada subproblema apenas uma vez e armazena suas soluções.
*   **Subestrutura Ótima (Optimal Substructure):** Uma solução ótima para o problema pode ser construída a partir de soluções ótimas de seus subproblemas.

Ao contrário de Divisão e Conquista, onde os subproblemas são independentes, na Programação Dinâmica, os subproblemas se sobrepõem. Existem duas abordagens para a programação dinâmica:

*   **Top-Down (Memorização):** Resolve o problema recursivamente, mas armazena os resultados dos subproblemas em uma tabela (cache) para evitar recálculos. Se um subproblema já foi resolvido, seu resultado é recuperado da tabela.
*   **Bottom-Up (Tabulação):** Resolve os subproblemas menores primeiro e constrói a solução para problemas maiores a partir deles, preenchendo uma tabela de forma iterativa.

**4.2. Exemplos e Aplicações:**

*   **Sequência de Fibonacci:** Calcular o n-ésimo número de Fibonacci de forma eficiente.
*   **Problema da Mochila (Knapsack Problem):** Escolher itens para maximizar o valor total sem exceder a capacidade da mochila.
*   **Caminho Mínimo em Grafos (Bellman-Ford, Floyd-Warshall):** (Já vimos) Podem ser vistos como aplicações de programação dinâmica.
*   **Problema da Subsequência Comum Mais Longa (Longest Common Subsequence - LCS):** Encontrar a subsequência mais longa que é comum a duas sequências.
*   **Problema da Multiplicação de Cadeia de Matrizes:** Encontrar a ordem ótima para multiplicar uma cadeia de matrizes para minimizar o número de operações.

**Exemplo de Código (Python - Fibonacci com Programação Dinâmica - Bottom-Up):**

```python
def fibonacci_dp(n):
    if n <= 0:
        return 0
    elif n == 1:
        return 1
    
    dp = [0] * (n + 1)
    dp[1] = 1
    
    for i in range(2, n + 1):
        dp[i] = dp[i-1] + dp[i-2]
    
    return dp[n]

# Exemplo de uso:
print("\n--- Testando Programação Dinâmica (Fibonacci) ---")
n_fib = 10
print(f"O {n_fib}-ésimo número de Fibonacci é: {fibonacci_dp(n_fib)}") # Saída: 55

# Comparação com recursivo simples (para n pequeno, pois é muito ineficiente para n grande)
def fibonacci_recursive_simple(n):
    if n <= 0:
        return 0
    elif n == 1:
        return 1
    else:
        return fibonacci_recursive_simple(n-1) + fibonacci_recursive_simple(n-2)

# print(f"O {n_fib}-ésimo número de Fibonacci (recursivo simples) é: {fibonacci_recursive_simple(n_fib)}")
```

**4.3. Comparação com Guloso e Divisão e Conquista:**

| Característica         | Guloso                      | Divisão e Conquista         | Programação Dinâmica        |
| :--------------------- | :-------------------------- | :-------------------------- | :-------------------------- |
| **Escolha**            | Melhor localmente           | Divide em subproblemas      | Resolve subproblemas sobrepostos |
| **Subproblemas**       | Não sobrepostos             | Independentes               | Sobrepostos                 |
| **Subestrutura Ótima** | Sim                         | Sim                         | Sim                         |
| **Reuso de Soluções**  | Não                         | Não                         | Sim (memorização/tabulação) |
| **Aplicações**         | Otimização local            | Problemas recursivos        | Problemas de otimização com subproblemas sobrepostos |

---

#### 5. Atividade Prática (5 minutos)

**Exercício:** Implemente a função para calcular o n-ésimo número de Fibonacci usando a abordagem de Programação Dinâmica (Bottom-Up/Tabulação). Compare o desempenho com uma implementação recursiva simples (sem memorização) para um valor de `n` relativamente grande (ex: `n=30` ou `n=40`).

**Solução (para referência, não mostre ao aluno antes da tentativa):**

```python
import time

def fibonacci_dp_practice(n):
    if n <= 0:
        return 0
    elif n == 1:
        return 1
    
    dp = [0] * (n + 1)
    dp[1] = 1
    
    for i in range(2, n + 1):
        dp[i] = dp[i-1] + dp[i-2]
    
    return dp[n]

def fibonacci_recursive_simple_practice(n):
    if n <= 0:
        return 0
    elif n == 1:
        return 1
    else:
        return fibonacci_recursive_simple_practice(n-1) + fibonacci_recursive_simple_practice(n-2)

print("\n--- Atividade Prática: Comparação Fibonacci DP vs Recursivo ---")
n_test = 35 # Um valor que mostra a diferença de desempenho

start_time = time.time()
result_dp = fibonacci_dp_practice(n_test)
end_time = time.time()
print(f"Fibonacci DP para n={n_test}: {result_dp} (Tempo: {end_time - start_time:.6f} segundos)")

start_time = time.time()
result_recursive = fibonacci_recursive_simple_practice(n_test)
end_time = time.time()
print(f"Fibonacci Recursivo Simples para n={n_test}: {result_recursive} (Tempo: {end_time - start_time:.6f} segundos)")

```

---

#### 6. Referências e Leitura Complementar

*   **[1] Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009). *Introduction to Algorithms* (3rd ed.). MIT Press.**
    *   Capítulo 15: Programação Dinâmica.
    *   Capítulo 16: Algoritmos Gulosos.
    *   Capítulo 2: Getting Started (para Divisão e Conquista - Merge Sort).

*   **[2] Goodrich, M. T., Tamassia, R., & Goldwasser, M. H. (2014). *Data Structures and Algorithms in Python*. John Wiley & Sons.**
    *   Capítulo 13: Algoritmos de Grafos (inclui alguns exemplos de guloso e DP).
    *   Capítulo 15: Algoritmos de Programação Dinâmica.

*   **[3] Sedgewick, R., & Wayne, K. (2011). *Algorithms* (4th ed.). Addison-Wesley Professional.**
    *   Capítulo 2: Sorting (para Divisão e Conquista - Merge Sort, Quick Sort).
    *   Capítulo 4: Graphs (para Guloso - Dijkstra, Prim, Kruskal).
    *   Capítulo 5: Strings (para Programação Dinâmica - LCS).

*   **[4] Livro: Estruturas de Dados e Algoritmos em C++ - Michael T. Goodrich, Roberto Tamassia, David M. Mount.**
    *   Capítulo 15: Algoritmos de Programação Dinâmica.
    *   Capítulo 16: Algoritmos Gulosos.

*   **[5] Artigo/Recurso Online:** GeeksforGeeks - Greedy Algorithms (https://www.geeksforgeeks.org/greedy-algorithms/)
    *   Recurso online sobre algoritmos gulosos.

*   **[6] Artigo/Recurso Online:** GeeksforGeeks - Divide and Conquer (https://www.geeksforgeeks.org/divide-and-conquer-algorithm-introduction/)
    *   Recurso online sobre divisão e conquista.

*   **[7] Artigo/Recurso Online:** GeeksforGeeks - Dynamic Programming (https://www.geeksforgeeks.org/dynamic-programming/)
    *   Recurso online sobre programação dinâmica.

---

**Próxima Aula:** Complexidade de Algoritmos: Classes de Funções e Notação Assintótica, Resolução de Recorrências.



