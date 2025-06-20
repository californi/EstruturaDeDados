### Aula 6: Árvores AVL e Árvores Rubro-Negras

**Duração Estimada:** 90 minutos

**Objetivos de Aprendizagem:**

Ao final desta aula, você será capaz de:

*   Compreender a necessidade de árvores de busca balanceadas para garantir eficiência nas operações.
*   Entender o conceito de balanceamento em árvores AVL e as regras de rotação (simples e duplas).
*   Implementar as operações de inserção e remoção em árvores AVL, mantendo o balanceamento.
*   Compreender as propriedades das Árvores Rubro-Negras e as regras de coloração e rotação.
*   Analisar a complexidade de tempo das operações em árvores AVL e Rubro-Negras.
*   Reconhecer as aplicações e a importância dessas estruturas em sistemas reais.

---

#### 1. A Necessidade de Árvores Balanceadas (10 minutos)

Nas aulas anteriores, estudamos as Árvores Binárias de Busca (ABBs). Embora eficientes no caso médio (O(log n)), as ABBs podem degenerar para uma estrutura semelhante a uma lista encadeada no pior caso (O(n)), perdendo a eficiência de busca. Isso ocorre quando os elementos são inseridos em ordem estritamente crescente ou decrescente, resultando em uma árvore desbalanceada.

Para garantir que as operações de busca, inserção e remoção mantenham uma complexidade logarítmica (O(log n)) mesmo no pior caso, foram desenvolvidas árvores de busca auto-balanceadas. As mais conhecidas são as Árvores AVL e as Árvores Rubro-Negras.

---

#### 2. Árvores AVL (40 minutos)

**2.1. O que é uma Árvore AVL?**

Uma Árvore AVL (Adelson-Velsky e Landis) é uma Árvore Binária de Busca auto-balanceada. Ela mantém a propriedade de que, para qualquer nó na árvore, a diferença entre as alturas de suas subárvores esquerda e direita (fator de balanceamento) nunca é maior que 1 (ou -1). Se essa propriedade for violada após uma inserção ou remoção, a árvore é rebalanceada através de operações de rotação.

**Fator de Balanceamento (FB):** `altura(subárvore_direita) - altura(subárvore_esquerda)`

*   `FB = 0`: Subárvores têm a mesma altura.
*   `FB = 1`: Subárvore direita é 1 nível mais alta.
*   `FB = -1`: Subárvore esquerda é 1 nível mais alta.
*   `|FB| > 1`: Árvore desbalanceada, requer rotação.

**2.2. Operações de Rotação:**

As rotações são operações que reorganizam os nós da árvore para restaurar o balanceamento, mantendo a propriedade de ABB. Existem quatro tipos básicos de rotações:

*   **Rotação Simples à Direita (LL Case):** Ocorre quando um nó está desbalanceado para a esquerda e seu filho esquerdo também está desbalanceado para a esquerda.

    ```
        Z                       Y
       / \                     / \
      Y   T4                  X   Z
     / \                     / \ / \
    X   T3                  T1 T2 T3 T4
   / \
  T1 T2
    ```

*   **Rotação Simples à Esquerda (RR Case):** Ocorre quando um nó está desbalanceado para a direita e seu filho direito também está desbalanceado para a direita.

    ```
        Z                       Y
       / \                     / \
      T1  Y                   Z   X
         / \                 / \ / \
        T2  X               T1 T2 T3 T4
           / \
          T3 T4
    ```

*   **Rotação Dupla Esquerda-Direita (LR Case):** Ocorre quando um nó está desbalanceado para a esquerda e seu filho esquerdo está desbalanceado para a direita. Envolve uma rotação simples à esquerda no filho esquerdo, seguida de uma rotação simples à direita na raiz original.

    ```
        Z                       Z                       X
       / \                     / \                     / \
      Y   T4                  X   T4                  Y   Z
     / \                     / \                     / \ / \
    T1  X                   Y   T3                  T1 T2 T3 T4
       / \                 / \
      T2 T3               T1 T2
    ```

*   **Rotação Dupla Direita-Esquerda (RL Case):** Ocorre quando um nó está desbalanceado para a direita e seu filho direito está desbalanceado para a esquerda. Envolve uma rotação simples à direita no filho direito, seguida de uma rotação simples à esquerda na raiz original.

    ```
        Z                       Z                       X
       / \                     / \                     / \
      T1  Y                   T1  X                   Z   Y
         / \                     / \                 / \ / \
        X   T4                  T2  Y               T1 T2 T3 T4
       / \                         / \
      T2 T3                       T3 T4
    ```

**2.3. Implementação (Conceitual):**

A implementação de árvores AVL envolve a manutenção do fator de balanceamento de cada nó e a aplicação das rotações apropriadas após cada inserção ou remoção. Isso geralmente é feito de forma recursiva, subindo pela árvore após a operação.

**Exemplo de Código (Python - Estrutura Básica de Nó AVL e Rotações):**

```python
class AVLNode:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
        self.height = 1 # Altura do nó

# Funções auxiliares para altura e fator de balanceamento
def get_height(node):
    if not node:
        return 0
    return node.height

def get_balance(node):
    if not node:
        return 0
    return get_height(node.right) - get_height(node.left)

# Funções de rotação
def right_rotate(y):
    x = y.left
    T2 = x.right

    # Realiza a rotação
    x.right = y
    y.left = T2

    # Atualiza alturas
    y.height = 1 + max(get_height(y.left), get_height(y.right))
    x.height = 1 + max(get_height(x.left), get_height(x.right))

    return x # Retorna a nova raiz da subárvore rotacionada

def left_rotate(x):
    y = x.right
    T2 = y.left

    # Realiza a rotação
    y.left = x
    x.right = T2

    # Atualiza alturas
    x.height = 1 + max(get_height(x.left), get_height(x.right))
    y.height = 1 + max(get_height(y.left), get_height(y.right))

    return y # Retorna a nova raiz da subárvore rotacionada

# Exemplo de uso (ilustrativo, não é uma implementação completa de AVL):
print("\n--- Exemplo Conceitual de Rotações AVL ---")
# Rotação Simples à Direita (LL Case)
# Árvore original: Z(30) -> Y(20) -> X(10)
#        30 (Z)
#       / 
#      20 (Y)
#     / 
#    10 (X)

node_Z = AVLNode(30)
node_Y = AVLNode(20)
node_X = AVLNode(10)

node_Z.left = node_Y
node_Y.left = node_X

# Atualiza alturas (simulação)
node_X.height = 1
node_Y.height = 1 + max(get_height(node_Y.left), get_height(node_Y.right)) # 1 + 1 = 2
node_Z.height = 1 + max(get_height(node_Z.left), get_height(node_Z.right)) # 1 + 2 = 3

print(f"Antes da rotação (Z): Altura={node_Z.height}, Balance={get_balance(node_Z)}")
new_root_ll = right_rotate(node_Z)
print(f"Após rotação (Y): Altura={new_root_ll.height}, Balance={get_balance(new_root_ll)}")
# A nova raiz é Y (20), com X (10) à esquerda e Z (30) à direita

# Rotação Simples à Esquerda (RR Case)
# Árvore original: X(10) -> Y(20) -> Z(30)
#    10 (X)
#     \
#      20 (Y)
#       \
#        30 (Z)

node_X_rr = AVLNode(10)
node_Y_rr = AVLNode(20)
node_Z_rr = AVLNode(30)

node_X_rr.right = node_Y_rr
node_Y_rr.right = node_Z_rr

# Atualiza alturas (simulação)
node_Z_rr.height = 1
node_Y_rr.height = 1 + max(get_height(node_Y_rr.left), get_height(node_Y_rr.right)) # 1 + 1 = 2
node_X_rr.height = 1 + max(get_height(node_X_rr.left), get_height(node_X_rr.right)) # 1 + 2 = 3

print(f"\nAntes da rotação (X): Altura={node_X_rr.height}, Balance={get_balance(node_X_rr)}")
new_root_rr = left_rotate(node_X_rr)
print(f"Após rotação (Y): Altura={new_root_rr.height}, Balance={get_balance(new_root_rr)}")
# A nova raiz é Y (20), com X (10) à esquerda e Z (30) à direita

```

---

#### 3. Árvores Rubro-Negras (30 minutos)

**3.1. O que é uma Árvore Rubro-Negra?**

Uma Árvore Rubro-Negra (Red-Black Tree) é outra forma de Árvore Binária de Busca auto-balanceada. Ela garante que a altura da árvore seja logarítmica, mantendo um conjunto de cinco propriedades:

1.  **Todo nó é vermelho ou preto.**
2.  **A raiz é preta.**
3.  **Todas as folhas (NIL, nós nulos) são pretas.**
4.  **Se um nó é vermelho, então seus filhos são pretos.** (Não pode haver dois nós vermelhos consecutivos no caminho da raiz para uma folha).
5.  **Para cada nó, todos os caminhos simples do nó para folhas descendentes contêm o mesmo número de nós pretos.** (Este é o 


caminho mais importante para o balanceamento).

**3.2. Operações e Rebalanceamento:**

As operações de inserção e remoção em árvores Rubro-Negras são mais complexas que nas ABBs simples, pois envolvem a manutenção das cinco propriedades através de:

*   **Coloração de Nós:** Alterar a cor de nós de vermelho para preto e vice-versa.
*   **Rotações:** As mesmas rotações simples e duplas usadas em árvores AVL, mas aplicadas de forma diferente para manter as propriedades Rubro-Negras.

O rebalanceamento é acionado quando uma inserção ou remoção viola uma das propriedades. Por exemplo, a inserção de um nó vermelho pode criar dois nós vermelhos consecutivos (violando a propriedade 4), exigindo recoloração e/ou rotações.

**3.3. Comparação com AVL:**

| Característica        | Árvore AVL                                 | Árvore Rubro-Negra                               |
| :-------------------- | :----------------------------------------- | :----------------------------------------------- |
| **Balanceamento**     | Mais estritamente balanceada (fator de balanceamento ±1) | Menos estritamente balanceada (altura máxima 2 * log n) |
| **Rotações**          | Mais rotações para manter o balanceamento estrito | Menos rotações, mas com recolorações             |
| **Implementação**     | Mais complexa de implementar               | Mais complexa de implementar (mas mais comum em bibliotecas) |
| **Performance**       | Busca ligeiramente mais rápida             | Inserção/remoção ligeiramente mais rápidas       |
| **Uso Comum**         | Bancos de dados, sistemas de arquivos      | `std::map` e `std::set` em C++, `TreeMap` e `TreeSet` em Java |

---

#### 4. Análise de Complexidade (5 minutos)

Ambas as árvores AVL e Rubro-Negras garantem complexidade de tempo logarítmica para suas operações básicas no pior caso.

**Tabela de Complexidade (Árvores Balanceadas):**

| Operação | Árvore AVL (Pior Caso) | Árvore Rubro-Negra (Pior Caso) |
| :------- | :--------------------- | :----------------------------- |
| `search` | O(log n)               | O(log n)                       |
| `insert` | O(log n)               | O(log n)                       |
| `delete` | O(log n)               | O(log n)                       |

---

#### 5. Aplicações Práticas (5 minutos)

*   **Sistemas de Banco de Dados:** Utilizadas para indexação eficiente de grandes volumes de dados.
*   **Sistemas de Arquivos:** Para organizar e acessar arquivos e diretórios.
*   **Estruturas de Dados Internas em Linguagens de Programação:** Muitas implementações de `mapas` e `conjuntos` (como `std::map` em C++ e `TreeMap` em Java) utilizam árvores Rubro-Negras internamente devido ao seu bom desempenho médio e pior caso.
*   **Roteadores de Rede:** Para armazenar tabelas de roteamento.

---

#### 6. Atividade Prática (10 minutos)

**Exercício:** Dada uma árvore binária de busca (não necessariamente balanceada), explique verbalmente ou em pseudocódigo como você faria para balanceá-la. Pense em uma estratégia que envolva a conversão da árvore para uma lista ordenada e depois a reconstrução da árvore a partir do meio da lista.

**Solução (para referência, não mostre ao aluno antes da tentativa):**

```python
# Reutilizando a classe Node e BinarySearchTree da Aula 5

# Passo 1: Converter a ABB para uma lista ordenada (percurso em-ordem)
def tree_to_sorted_list(node, sorted_list):
    if node:
        tree_to_sorted_list(node.left, sorted_list)
        sorted_list.append(node.key)
        tree_to_sorted_list(node.right, sorted_list)

# Passo 2: Construir uma ABB balanceada a partir da lista ordenada
def sorted_list_to_bst(sorted_list, start, end):
    if start > end:
        return None

    mid = (start + end) // 2
    node = Node(sorted_list[mid])

    node.left = sorted_list_to_bst(sorted_list, start, mid - 1)
    node.right = sorted_list_to_bst(sorted_list, mid + 1, end)

    return node

def balance_bst(bst):
    if not bst.root:
        return

    sorted_nodes = []
    tree_to_sorted_list(bst.root, sorted_nodes)

    bst.root = sorted_list_to_bst(sorted_nodes, 0, len(sorted_nodes) - 1)

# Testes
print("\n--- Testando Balanceamento de ABB ---")
# Criando uma ABB desbalanceada (degenerada)
bst_unbalanced = BinarySearchTree()
bst_unbalanced.insert(10)
bst_unbalanced.insert(20)
bst_unbalanced.insert(30)
bst_unbalanced.insert(40)
bst_unbalanced.insert(50)

print("ABB desbalanceada (percurso em-ordem):")
inorder_traversal(bst_unbalanced.root) # Saída: 10 20 30 40 50
print("\n")

balance_bst(bst_unbalanced)

print("ABB balanceada (percurso em-ordem):")
inorder_traversal(bst_unbalanced.root) # Saída: 10 20 30 40 50
print("\n")

# Para verificar visualmente o balanceamento, você precisaria de uma função de impressão de árvore
# mas conceitualmente, a raiz agora seria 30, com 20 à esquerda e 40 à direita, etc.
# O percurso em-ordem permanece o mesmo, mas a estrutura interna muda.

```

**Explicação da Solução:**

1.  **Converter para Lista Ordenada (`tree_to_sorted_list`):**
    *   Realizamos um percurso **em-ordem** na ABB. Como uma das propriedades do percurso em-ordem em uma ABB é que ele visita os nós em ordem crescente, podemos simplesmente adicionar os valores dos nós a uma lista Python vazia durante esse percurso.
    *   Isso nos dá uma lista linear de todos os elementos da árvore, já ordenados.

2.  **Construir ABB Balanceada a partir da Lista (`sorted_list_to_bst`):**
    *   Esta é uma função recursiva que recebe a lista ordenada e os índices de início e fim da sublista a ser processada.
    *   O elemento do meio da lista (ou sublista) é sempre escolhido como a raiz da subárvore atual. Isso garante que, em cada nível, aproximadamente metade dos elementos restantes irá para a subárvore esquerda e a outra metade para a subárvore direita, resultando em uma árvore balanceada.
    *   A função então chama a si mesma recursivamente para construir a subárvore esquerda (com os elementos à esquerda do meio) e a subárvore direita (com os elementos à direita do meio).

3.  **Função `balance_bst`:**
    *   Esta função orquestra o processo, chamando `tree_to_sorted_list` para obter a lista ordenada e, em seguida, `sorted_list_to_bst` para reconstruir a árvore balanceada a partir dessa lista, atualizando a raiz da ABB original.

Essa abordagem é eficaz para balancear uma ABB, transformando um problema potencialmente O(n) (no caso degenerado) em um problema O(n) para a conversão para lista e O(n) para a reconstrução, resultando em uma complexidade total de O(n) para o balanceamento, o que é eficiente para a maioria dos casos.

---

#### 7. Referências e Leitura Complementar

*   **[1] Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009). *Introduction to Algorithms* (3rd ed.). MIT Press.**
    *   Capítulo 13: Árvores Rubro-Negras.
    *   Capítulo 14: Aumentando Estruturas de Dados (inclui árvores AVL).

*   **[2] Goodrich, M. T., Tamassia, R., & Goldwasser, M. H. (2014). *Data Structures and Algorithms in Python*. John Wiley & Sons.**
    *   Capítulo 11: Árvores de Busca (inclui árvores AVL e Rubro-Negras).

*   **[3] Sedgewick, R., & Wayne, K. (2011). *Algorithms* (4th ed.). Addison-Wesley Professional.**
    *   Capítulo 3: Elementary Data Structures (seção sobre Árvores de Busca Balanceadas).

*   **[4] Livro: Estruturas de Dados e Algoritmos em C++ - Michael T. Goodrich, Roberto Tamassia, David M. Mount.**
    *   Capítulo 11: Árvores de Busca (inclui árvores AVL e Rubro-Negras).

*   **[5] Artigo/Recurso Online:** GeeksforGeeks - AVL Tree (https://www.geeksforgeeks.org/avl-tree-set-1-insertion/)
    *   Recurso online abrangente sobre Árvores AVL.

*   **[6] Artigo/Recurso Online:** GeeksforGeeks - Red-Black Tree (https://www.geeksforgeeks.org/red-black-tree-set-1-introduction-and-properties/)
    *   Recurso online abrangente sobre Árvores Rubro-Negras.

---

**Próxima Aula:** Estruturas de Dados em Memória Secundária: Organização de Arquivos e Indexação.



