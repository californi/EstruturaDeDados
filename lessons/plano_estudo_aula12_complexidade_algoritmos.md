### Aula 12: Complexidade de Algoritmos: Classes de Funções e Notação Assintótica, Resolução de Recorrências

**Duração Estimada:** 90 minutos

**Objetivos de Aprendizagem:**

Ao final desta aula, você será capaz de:

*   Compreender a importância da análise de complexidade de algoritmos para avaliar sua eficiência.
*   Dominar o conceito de Notação Assintótica (Big O, Big Omega, Big Theta) para descrever o comportamento de algoritmos em relação ao tamanho da entrada.
*   Identificar as classes de funções mais comuns (constante, logarítmica, linear, n log n, quadrática, cúbica, exponencial) e seus impactos no desempenho.
*   Analisar a complexidade de tempo e espaço de algoritmos simples.
*   Resolver relações de recorrência para algoritmos recursivos usando o Método da Substituição, o Método da Árvore de Recorrência e o Teorema Mestre.
*   Reconhecer a importância da complexidade no projeto e escolha de algoritmos para problemas do mundo real.

---

#### 1. Introdução à Análise de Complexidade (15 minutos)

**1.1. Por que Analisar Algoritmos?**

Quando resolvemos um problema computacional, geralmente existem várias maneiras de abordá-lo. A análise de algoritmos nos permite comparar diferentes soluções e escolher a mais eficiente. Eficiência pode significar:

*   **Tempo de Execução:** Quanto tempo o algoritmo leva para ser executado em função do tamanho da entrada.
*   **Espaço de Memória:** Quanta memória o algoritmo consome em função do tamanho da entrada.

Nosso foco principal será a complexidade de tempo, pois ela é frequentemente o fator mais crítico para o desempenho de um algoritmo.

**1.2. Medindo a Eficiência:**

Não podemos medir a eficiência em segundos, pois isso depende de fatores como:

*   Velocidade do processador.
*   Linguagem de programação e compilador/interpretador.
*   Carga do sistema.
*   Qualidade do código.

Em vez disso, medimos a eficiência em termos do número de operações elementares que o algoritmo executa, em função do tamanho da entrada (`n`). Isso nos dá uma medida independente de hardware e software.

---

#### 2. Notação Assintótica (40 minutos)

A notação assintótica é uma forma de descrever o comportamento limite de uma função à medida que o tamanho da entrada (`n`) cresce para o infinito. Ela nos permite classificar algoritmos com base em sua taxa de crescimento, ignorando constantes e termos de ordem inferior.

**2.1. Notação Big O (O - Ordem de Crescimento Superior):**

*   **Definição:** `f(n) = O(g(n))` se existem constantes positivas `c` e `n0` tais que `0 <= f(n) <= c * g(n)` para todo `n >= n0`.
*   **Significado:** `g(n)` é um limite superior para `f(n)`. O algoritmo nunca será *pior* do que `g(n)` (assintoticamente).
*   **Exemplo:** Se um algoritmo tem complexidade `3n^2 + 2n + 5`, dizemos que ele é `O(n^2)`. Ignoramos `3`, `2n` e `5` porque `n^2` domina o crescimento para grandes `n`.

**2.2. Notação Big Omega (Ω - Ordem de Crescimento Inferior):**

*   **Definição:** `f(n) = Ω(g(n))` se existem constantes positivas `c` e `n0` tais que `0 <= c * g(n) <= f(n)` para todo `n >= n0`.
*   **Significado:** `g(n)` é um limite inferior para `f(n)`. O algoritmo nunca será *melhor* do que `g(n)` (assintoticamente).
*   **Exemplo:** Um algoritmo de busca linear é `Ω(1)` no melhor caso (primeiro elemento) e `Ω(n)` no pior caso (último elemento ou não encontrado).

**2.3. Notação Big Theta (Θ - Ordem de Crescimento Exata):**

*   **Definição:** `f(n) = Θ(g(n))` se existem constantes positivas `c1`, `c2` e `n0` tais que `0 <= c1 * g(n) <= f(n) <= c2 * g(n)` para todo `n >= n0`.
*   **Significado:** `g(n)` é um limite superior e inferior para `f(n)`. O algoritmo tem um comportamento de crescimento *exatamente* como `g(n)`.
*   **Exemplo:** O Merge Sort tem complexidade `Θ(n log n)` tanto no melhor, médio quanto no pior caso.

**2.4. Classes de Funções Comuns (e suas Complexidades):**

| Notação | Nome da Classe | Exemplo de Operação/Algoritmo |
| :------ | :------------- | :---------------------------- |
| O(1)    | Constante      | Acesso a um elemento em array, push/pop em pilha, enqueue/dequeue em fila (lista encadeada) |
| O(log n)| Logarítmica    | Busca binária, operações em árvores balanceadas (AVL, Rubro-Negra) |
| O(n)    | Linear         | Busca linear, travessia de lista encadeada, soma de elementos em array |
| O(n log n)| Linear-Logarítmica | Merge Sort, Quick Sort (caso médio), Heap Sort |
| O(n^2)  | Quadrática     | Bubble Sort, Selection Sort, Insertion Sort (pior caso) |
| O(n^3)  | Cúbica         | Multiplicação de matrizes (algoritmo simples), Floyd-Warshall |
| O(2^n)  | Exponencial    | Problemas de força bruta (ex: Problema do Caixeiro Viajante sem otimização) |
| O(n!)   | Fatorial       | Geração de permutações |

**2.5. Análise de Complexidade de Espaço:**

Similar à complexidade de tempo, a complexidade de espaço mede a quantidade de memória auxiliar que um algoritmo utiliza. É expressa usando a mesma notação assintótica.

*   **Exemplo:** Merge Sort tem complexidade de espaço O(n) devido ao array auxiliar usado na fase de mesclagem. Quick Sort (in-place) tem complexidade de espaço O(log n) devido à pilha de recursão.

---

#### 3. Resolução de Recorrências (25 minutos)

Algoritmos recursivos, especialmente aqueles que seguem o paradigma de Divisão e Conquista, têm seu tempo de execução descrito por relações de recorrência. Resolver uma recorrência significa encontrar uma forma fechada (não recursiva) para a função de tempo de execução, geralmente em termos de notação assintótica.

**3.1. Método da Substituição:**

1.  **Adivinhe a solução:** Baseado em sua experiência ou em padrões comuns.
2.  **Verifique por indução:** Prove que sua adivinhação é correta, usando indução matemática.
3.  **Resolva as constantes:** Encontre os valores das constantes `c` e `n0`.

**Exemplo:** `T(n) = 2T(n/2) + n` (Merge Sort)

*   Adivinhe: `T(n) = O(n log n)`.
*   Prove por indução que `T(n) <= c * n log n`.

**3.2. Método da Árvore de Recorrência:**

1.  Desenhe uma árvore que representa as chamadas recursivas e o custo em cada nível.
2.  Some o custo em cada nível.
3.  Some os custos de todos os níveis para obter o custo total.

**Exemplo:** `T(n) = 2T(n/2) + n`

*   Nível 0: `n`
*   Nível 1: `n/2 + n/2 = n`
*   ... (log n níveis)
*   Custo total: `n * log n`

**3.3. Teorema Mestre:**

O Teorema Mestre fornece uma solução para recorrências da forma `T(n) = aT(n/b) + f(n)`, onde `a >= 1`, `b > 1`, e `f(n)` é uma função assintoticamente positiva. Existem três casos:

*   **Caso 1:** Se `f(n) = O(n^(log_b a - ε))` para alguma constante `ε > 0`, então `T(n) = Θ(n^(log_b a))`.
    *   `log_b a` domina `f(n)`.
*   **Caso 2:** Se `f(n) = Θ(n^(log_b a) * log^k n)` para alguma constante `k >= 0`, então `T(n) = Θ(n^(log_b a) * log^(k+1) n)`.
    *   `f(n)` e `n^(log_b a)` são assintoticamente iguais (ou `f(n)` é um fator logarítmico maior).
*   **Caso 3:** Se `f(n) = Ω(n^(log_b a + ε))` para alguma constante `ε > 0`, e se `a * f(n/b) <= c * f(n)` para alguma constante `c < 1` e `n` suficientemente grande (condição de regularidade), então `T(n) = Θ(f(n))`.
    *   `f(n)` domina `n^(log_b a)`.

**Exemplos de Aplicação do Teorema Mestre:**

*   **Merge Sort:** `T(n) = 2T(n/2) + n`
    *   `a=2, b=2, f(n)=n`. `log_b a = log_2 2 = 1`. `n^(log_b a) = n^1 = n`.
    *   `f(n) = n = Θ(n^1 * log^0 n)`. Corresponde ao **Caso 2** com `k=0`.
    *   Solução: `T(n) = Θ(n log n)`.

*   **Busca Binária:** `T(n) = T(n/2) + 1`
    *   `a=1, b=2, f(n)=1`. `log_b a = log_2 1 = 0`. `n^(log_b a) = n^0 = 1`.
    *   `f(n) = 1 = Θ(n^0 * log^0 n)`. Corresponde ao **Caso 2** com `k=0`.
    *   Solução: `T(n) = Θ(log n)`.

---

#### 4. Atividade Prática (5 minutos)

**Exercício:** Analise a complexidade de tempo do seguinte trecho de código em termos de Notação Big O:

```python
def exemplo_complexidade(n):
    count = 0
    for i in range(n):
        for j in range(n):
            count += 1
    for k in range(n):
        count += 1
    return count
```

**Solução (para referência, não mostre ao aluno antes da tentativa):**

```python
def exemplo_complexidade_solucao(n):
    count = 0
    # O primeiro loop aninhado executa n * n = n^2 operações.
    for i in range(n):
        for j in range(n):
            count += 1
    # O segundo loop executa n operações.
    for k in range(n):
        count += 1
    return count

# A complexidade total é a soma das complexidades das partes: O(n^2) + O(n).
# Como n^2 domina n para grandes valores de n, a complexidade final é O(n^2).
print("\n--- Atividade Prática: Análise de Complexidade de Código ---")
print("A complexidade de tempo da função `exemplo_complexidade(n)` é O(n^2).")
```

**Exercício 2:** Use o Teorema Mestre para resolver a seguinte recorrência: `T(n) = 3T(n/4) + n^2`.

**Solução (para referência, não mostre ao aluno antes da tentativa):**

```python
# Recorrência: T(n) = 3T(n/4) + n^2
# Comparando com T(n) = aT(n/b) + f(n):
# a = 3
# b = 4
# f(n) = n^2

# 1. Calcule log_b a:
# log_4 3 ≈ 0.792

# 2. Compare f(n) com n^(log_b a):
# n^(log_4 3) ≈ n^0.792
# f(n) = n^2

# Como n^2 é assintoticamente maior que n^0.792 (n^2 = Ω(n^0.792 + ε) para ε = 1.208),
# estamos no Caso 3 do Teorema Mestre.

# 3. Verifique a condição de regularidade para o Caso 3:
# a * f(n/b) <= c * f(n) para alguma constante c < 1
# 3 * (n/4)^2 <= c * n^2
# 3 * (n^2 / 16) <= c * n^2
# (3/16) * n^2 <= c * n^2
# Como 3/16 (0.1875) é menor que 1, podemos escolher c = 3/16 (ou qualquer valor entre 3/16 e 1).
# A condição de regularidade é satisfeita.

# 4. Conclusão pelo Teorema Mestre (Caso 3):
# T(n) = Θ(f(n))
# T(n) = Θ(n^2)

print("\n--- Atividade Prática: Resolução de Recorrência (Teorema Mestre) ---")
print("Para a recorrência T(n) = 3T(n/4) + n^2, a solução é T(n) = Θ(n^2) pelo Teorema Mestre (Caso 3).")
```

---

#### 5. Referências e Leitura Complementar

*   **[1] Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009). *Introduction to Algorithms* (3rd ed.). MIT Press.**
    *   Capítulo 3: Crescimento de Funções.
    *   Capítulo 4: Recorrências.

*   **[2] Goodrich, M. T., Tamassia, R., & Goldwasser, M. H. (2014). *Data Structures and Algorithms in Python*. John Wiley & Sons.**
    *   Capítulo 4: Análise de Algoritmos.

*   **[3] Sedgewick, R., & Wayne, K. (2011). *Algorithms* (4th ed.). Addison-Wesley Professional.**
    *   Capítulo 1: Fundamentals (seção sobre Análise de Algoritmos).

*   **[4] Livro: Estruturas de Dados e Algoritmos em C++ - Michael T. Goodrich, Roberto Tamassia, David M. Mount.**
    *   Capítulo 4: Análise de Algoritmos.

*   **[5] Artigo/Recurso Online:** GeeksforGeeks - Asymptotic Notations (https://www.geeksforgeeks.org/asymptotic-notations-and-their-properties/)
    *   Recurso online sobre notações assintóticas.

*   **[6] Artigo/Recurso Online:** GeeksforGeeks - Master Theorem (https://www.geeksforgeeks.org/master-theorem-for-divide-and-conquer-recurrences/)
    *   Recurso online sobre o Teorema Mestre.

---

**Próxima Aula:** Revisão e Entrega do Plano de Estudo Completo.



