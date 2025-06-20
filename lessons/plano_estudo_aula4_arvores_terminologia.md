### Aula 4: Árvores: Terminologia e Representação

**Duração Estimada:** 90 minutos

**Objetivos de Aprendizagem:**

Ao final desta aula, você será capaz de:

*   Compreender o conceito fundamental de uma Árvore como uma estrutura de dados não linear.
*   Dominar a terminologia essencial associada a árvores (nó, raiz, filho, pai, irmão, folha, grau, nível, altura, profundidade, caminho, subárvore).
*   Distinguir entre diferentes tipos de árvores (árvore geral, árvore binária, árvore binária completa, árvore binária cheia, árvore binária estritamente binária).
*   Conhecer as principais formas de representação de árvores na memória (listas de adjacência, representação de filhos).
*   Analisar a complexidade de espaço das diferentes representações.
*   Reconhecer aplicações práticas de árvores em computação.

---

#### 1. Introdução ao Conceito de Árvore (15 minutos)

**1.1. O que é uma Árvore?**

Ao contrário das estruturas de dados lineares que estudamos (pilhas, filas, listas), uma árvore é uma estrutura de dados não linear e hierárquica. Ela é composta por um conjunto de nós interligados, onde cada nó pode ter zero ou mais nós 


descendentes (filhos). A estrutura se assemelha a uma árvore genealógica ou a um sistema de arquivos de um computador.

**1.2. Analogias e Exemplos do Dia a Dia:**

*   **Árvore Genealógica:** Representa relações de parentesco de forma hierárquica.
*   **Sistema de Arquivos (Pastas e Arquivos):** Diretórios contêm subdiretórios e arquivos, formando uma estrutura em árvore.
*   **Estrutura de Documentos XML/HTML:** Elementos aninhados formam uma árvore de nós.
*   **Organogramas de Empresas:** Representam a hierarquia de cargos e departamentos.

**1.3. Características Principais:**

*   **Não Linear:** Os elementos não são armazenados sequencialmente.
*   **Hierárquica:** Existe uma relação de pai-filho entre os nós.
*   **Nó Raiz:** Existe um único nó no topo da árvore, sem pai.
*   **Nós Folha:** Nós que não possuem filhos.

---

#### 2. Terminologia Essencial de Árvores (25 minutos)

Para discutir árvores de forma precisa, é fundamental conhecer a terminologia:

*   **Nó (Node):** Um elemento na árvore que contém um valor e pode ter ligações para outros nós.
*   **Raiz (Root):** O nó superior da árvore. É o único nó que não possui pai.
*   **Filho (Child):** Um nó diretamente conectado a outro nó em um nível abaixo. Um nó pode ter um ou mais filhos.
*   **Pai (Parent):** O nó diretamente conectado a outro nó em um nível acima. Cada nó (exceto a raiz) tem exatamente um pai.
*   **Irmão (Sibling):** Nós que compartilham o mesmo pai.
*   **Folha (Leaf Node)::** Um nó que não possui filhos. Também chamado de nó terminal ou externo.
*   **Nó Interno (Internal Node):** Um nó que possui pelo menos um filho.
*   **Aresta (Edge):** A ligação entre dois nós (pai e filho).
*   **Caminho (Path):** Uma sequência de nós e arestas do nó de origem ao nó de destino.
*   **Comprimento do Caminho:** O número de arestas em um caminho.
*   **Ancestral (Ancestor):** Qualquer nó no caminho da raiz até um nó específico (excluindo o próprio nó).
*   **Descendente (Descendant):** Qualquer nó no caminho de um nó específico até uma folha (excluindo o próprio nó).
*   **Subárvore (Subtree):** Uma parte de uma árvore que é, por si só, uma árvore. Qualquer nó em uma árvore pode ser considerado a raiz de uma subárvore.
*   **Grau de um Nó (Degree of a Node):** O número de filhos de um nó.
*   **Grau de uma Árvore (Degree of a Tree):** O grau máximo entre todos os nós da árvore.
*   **Nível (Level):** A profundidade de um nó na árvore. A raiz está no nível 0 (ou 1, dependendo da convenção). O nível de um nó é o número de arestas no caminho da raiz até ele.
*   **Altura (Height):** A altura de um nó é o número de arestas no caminho mais longo de um nó até uma folha descendente. A altura de uma árvore é a altura de sua raiz.
*   **Profundidade (Depth):** A profundidade de um nó é o número de arestas no caminho da raiz até o nó. É o mesmo que o nível do nó.

---

#### 3. Tipos de Árvores (20 minutos)

Existem vários tipos de árvores, cada um com características e usos específicos:

*   **Árvore Geral (General Tree):** Uma árvore onde cada nó pode ter um número ilimitado de filhos.

*   **Árvore Binária (Binary Tree):** Uma árvore onde cada nó pode ter no máximo dois filhos, geralmente chamados de filho esquerdo e filho direito.

    *   **Árvore Binária Completa (Complete Binary Tree):** Uma árvore binária onde todos os níveis, exceto possivelmente o último, estão completamente preenchidos, e todos os nós no último nível estão o mais à esquerda possível. Heaps são exemplos de árvores binárias completas.

    *   **Árvore Binária Cheia (Full Binary Tree ou Strict Binary Tree):** Uma árvore binária onde cada nó tem zero ou dois filhos. Nenhum nó tem apenas um filho.

    *   **Árvore Binária Perfeita (Perfect Binary Tree):** Uma árvore binária que é tanto cheia quanto completa. Todos os nós internos têm dois filhos e todas as folhas estão no mesmo nível.

    *   **Árvore Binária Degenerada (Degenerate Binary Tree ou Skewed Tree):** Uma árvore onde cada nó pai tem apenas um filho. Essencialmente, comporta-se como uma lista encadeada.

---

#### 4. Representação de Árvores (20 minutos)

Árvores podem ser representadas na memória de várias maneiras. As mais comuns para árvores binárias são:

**4.1. Representação com Ponteiros (Nós e Referências):**

Esta é a forma mais intuitiva e flexível. Cada nó é um objeto que contém o valor do dado e referências (ponteiros) para seus filhos. Para árvores binárias, cada nó teria referências para o filho esquerdo e o filho direito.

**Vantagens:**
*   Flexível para árvores de tamanho e forma variáveis.
*   Inserção e remoção de nós são eficientes.

**Desvantagens:**
*   Maior consumo de memória devido aos ponteiros.
*   Acesso a um nó específico pode exigir travessia desde a raiz.

**Exemplo de Código (Python - Nó de Árvore Binária):**

```python
class TreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

# Exemplo de criação de uma árvore simples:
print("\n--- Exemplo de Criação de Árvore Simples ---")
root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.left.left = TreeNode(4)
root.left.right = TreeNode(5)

# Para visualizar a estrutura (apenas para demonstração, não é parte da classe TreeNode)
# print(f"Raiz: {root.data}")
# print(f"Filho esquerdo da raiz: {root.left.data}")
# print(f"Filho direito da raiz: {root.right.data}")
# print(f"Filho esquerdo de {root.left.data}: {root.left.left.data}")
# print(f"Filho direito de {root.left.data}: {root.left.right.data}")

```

**4.2. Representação com Array (para Árvores Binárias Completas):**

Árvores binárias completas podem ser eficientemente representadas usando um array. Se um nó está no índice `i` do array:

*   Seu filho esquerdo está no índice `2*i + 1`.
*   Seu filho direito está no índice `2*i + 2`.
*   Seu pai está no índice `(i-1) // 2`.

**Vantagens:**
*   Uso eficiente da memória (não há sobrecarga de ponteiros).
*   Acesso rápido a pais e filhos por cálculo de índice.

**Desvantagens:**
*   Ineficiente para árvores que não são completas (muitos espaços vazios no array).
*   Inserção e remoção podem ser complexas se a árvore não for mantida completa.

**Exemplo de Código (Conceitual - Array):**

```python
# Representação de uma árvore binária completa em array
# Ex: [A, B, C, D, E, F, G]
# A (0)
#  |- B (1)
#  |- C (2)
#     |- D (3)
#     |- E (4)
#     |- F (5)
#     |- G (6)

print("\n--- Exemplo de Representação de Árvore Binária Completa em Array ---")
tree_array = ['A', 'B', 'C', 'D', 'E', 'F', 'G']

# Exemplo de cálculos de índices:
root_index = 0
print(f"Raiz: {tree_array[root_index]}")

node_B_index = 1
print(f"Nó B (índice {node_B_index}): {tree_array[node_B_index]}")
print(f"  Filho esquerdo de B (índice {2*node_B_index + 1}): {tree_array[2*node_B_index + 1]}")
print(f"  Filho direito de B (índice {2*node_B_index + 2}): {tree_array[2*node_B_index + 2]}")

node_D_index = 3
print(f"Nó D (índice {node_D_index}): {tree_array[node_D_index]}")
print(f"  Pai de D (índice {(node_D_index-1)//2}): {tree_array[(node_D_index-1)//2]}")

```

---

#### 5. Atividade Prática (10 minutos)

**Exercício:** Dada a seguinte representação de uma árvore binária usando a classe `TreeNode`:

```python
class TreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

# Construa a seguinte árvore:
#       1
#      / \
#     2   3
#    / \
#   4   5

root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.left.left = TreeNode(4)
root.left.right = TreeNode(5)
```

Após construir a árvore, escreva uma função que calcule a altura da árvore. A altura de uma árvore vazia é -1, e a altura de uma árvore com apenas um nó (raiz) é 0.

**Solução (para referência, não mostre ao aluno antes da tentativa):**

```python
class TreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def calculate_height(node):
    # Caso base: árvore vazia
    if node is None:
        return -1

    # Altura da subárvore esquerda
    left_height = calculate_height(node.left)
    # Altura da subárvore direita
    right_height = calculate_height(node.right)

    # A altura do nó atual é 1 + o máximo entre as alturas das subárvores
    return 1 + max(left_height, right_height)

# Construindo a árvore do exercício:
print("\n--- Testando Cálculo de Altura da Árvore ---")
#       1
#      / \
#     2   3
#    / \
#   4   5

root_ex = TreeNode(1)
root_ex.left = TreeNode(2)
root_ex.right = TreeNode(3)
root_ex.left.left = TreeNode(4)
root_ex.left.right = TreeNode(5)

print(f"Altura da árvore: {calculate_height(root_ex)}") # Saída esperada: 2

# Teste com árvore de um único nó
root_single = TreeNode(10)
print(f"Altura da árvore de um único nó: {calculate_height(root_single)}") # Saída esperada: 0

# Teste com árvore vazia
root_empty = None
print(f"Altura da árvore vazia: {calculate_height(root_empty)}") # Saída esperada: -1

```

---

#### 6. Referências e Leitura Complementar

*   **[1] Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009). *Introduction to Algorithms* (3rd ed.). MIT Press.**
    *   Capítulo 10: Estruturas de Dados Básicas (seção sobre Árvores).

*   **[2] Goodrich, M. T., Tamassia, R., & Goldwasser, M. H. (2014). *Data Structures and Algorithms in Python*. John Wiley & Sons.**
    *   Capítulo 8: Árvores.

*   **[3] Sedgewick, R., & Wayne, K. (2011). *Algorithms* (4th ed.). Addison-Wesley Professional.**
    *   Capítulo 3: Elementary Data Structures (seção sobre Árvores).

*   **[4] Livro: Estruturas de Dados e Algoritmos em C++ - Michael T. Goodrich, Roberto Tamassia, David M. Mount.**
    *   Capítulo 8: Árvores.

*   **[5] Artigo/Recurso Online:** GeeksforGeeks - Tree Data Structure (https://www.geeksforgeeks.org/tree-data-structure/)
    *   Um recurso online popular com explicações claras e exemplos de código.

---

**Próxima Aula:** Árvores Binárias de Busca e Percursos.



