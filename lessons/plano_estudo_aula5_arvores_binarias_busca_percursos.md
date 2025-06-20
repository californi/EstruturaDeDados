### Aula 5: Árvores Binárias de Busca e Percursos

**Duração Estimada:** 90 minutos

**Objetivos de Aprendizagem:**

Ao final desta aula, você será capaz de:

*   Compreender o conceito e as propriedades de uma Árvore Binária de Busca (ABB).
*   Implementar as operações básicas em uma ABB: inserção, busca e remoção.
*   Dominar os diferentes tipos de percursos em árvores binárias: em-ordem, pré-ordem e pós-ordem.
*   Analisar a complexidade de tempo das operações e percursos em ABBs.
*   Reconhecer aplicações práticas de ABBs e percursos em algoritmos.

---

#### 1. Árvores Binárias de Busca (ABBs) (30 minutos)

**1.1. O que é uma Árvore Binária de Busca?**

Uma Árvore Binária de Busca (ABB), ou Binary Search Tree (BST), é um tipo especial de árvore binária que mantém seus elementos em uma ordem específica, facilitando operações de busca, inserção e remoção. A propriedade fundamental de uma ABB é:

*   Para qualquer nó `N` na árvore:
    *   Todos os valores na subárvore esquerda de `N` são menores que o valor de `N`.
    *   Todos os valores na subárvore direita de `N` são maiores que o valor de `N`.
    *   Não há valores duplicados na árvore (embora algumas implementações permitam, com regras específicas).

Essa propriedade garante que, ao buscar um elemento, podemos eliminar metade da árvore a cada passo, similar à busca binária em arrays ordenados.

**1.2. Operações Básicas em ABBs:**

*   **`search(valor)`:** Busca um `valor` na ABB. Começa na raiz e compara o `valor` com o nó atual. Se o `valor` for menor, move para a subárvore esquerda; se for maior, move para a subárvore direita. Repete até encontrar o valor ou chegar a um nó nulo.

*   **`insert(valor)`:** Insere um novo `valor` na ABB. Similar à busca, percorre a árvore até encontrar a posição correta onde o novo nó deve ser inserido como uma folha.

*   **`delete(valor)`:** Remove um `valor` da ABB. Esta é a operação mais complexa, pois existem três casos a considerar:
    1.  **Nó Folha:** Simplesmente remove o nó.
    2.  **Nó com um Filho:** Substitui o nó pelo seu único filho.
    3.  **Nó com Dois Filhos:** Substitui o nó pelo seu sucessor (o menor valor na subárvore direita) ou pelo seu predecessor (o maior valor na subárvore esquerda) e então remove o sucessor/predecessor.

**Exemplo de Código (Python - ABB):**

```python
class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

class BinarySearchTree:
    def __init__(self):
        self.root = None

    def insert(self, key):
        self.root = self._insert_recursive(self.root, key)

    def _insert_recursive(self, node, key):
        if node is None:
            return Node(key)
        if key < node.key:
            node.left = self._insert_recursive(node.left, key)
        elif key > node.key:
            node.right = self._insert_recursive(node.right, key)
        return node

    def search(self, key):
        return self._search_recursive(self.root, key)

    def _search_recursive(self, node, key):
        if node is None or node.key == key:
            return node
        if key < node.key:
            return self._search_recursive(node.left, key)
        return self._search_recursive(node.right, key)

    def delete(self, key):
        self.root = self._delete_recursive(self.root, key)

    def _delete_recursive(self, node, key):
        if node is None:
            return node

        if key < node.key:
            node.left = self._delete_recursive(node.left, key)
        elif key > node.key:
            node.right = self._delete_recursive(node.right, key)
        else: # Nó encontrado
            # Caso 1: Nó folha ou com um filho
            if node.left is None:
                return node.right
            elif node.right is None:
                return node.left

            # Caso 2: Nó com dois filhos
            # Encontra o sucessor (menor na subárvore direita)
            temp = self._min_value_node(node.right)
            node.key = temp.key
            node.right = self._delete_recursive(node.right, temp.key)
        return node

    def _min_value_node(self, node):
        current = node
        while current.left is not None:
            current = current.left
        return current

# Exemplo de uso:
print("\n--- Testando BinarySearchTree ---")
bst = BinarySearchTree()
bst.insert(50)
bst.insert(30)
bst.insert(70)
bst.insert(20)
bst.insert(40)
bst.insert(60)
bst.insert(80)

print(f"Buscando 40: {bst.search(40).key if bst.search(40) else 'Não encontrado'}") # Saída: Buscando 40: 40
print(f"Buscando 90: {bst.search(90).key if bst.search(90) else 'Não encontrado'}") # Saída: Buscando 90: Não encontrado

bst.delete(50)
print(f"Buscando 50 após exclusão: {bst.search(50).key if bst.search(50) else 'Não encontrado'}") # Saída: Buscando 50 após exclusão: Não encontrado

```

---

#### 2. Percursos em Árvores Binárias (30 minutos)

Percursos (ou travessias) são métodos para visitar todos os nós de uma árvore binária de forma sistemática. Existem três tipos principais de percursos em profundidade:

**2.1. Percurso Em-Ordem (In-order Traversal):**

Visita os nós na seguinte ordem: **Esquerda -> Raiz -> Direita**. Se a árvore for uma ABB, o percurso em-ordem resultará nos elementos em ordem crescente.

**Exemplo:** Para a árvore:

```
      4
     / \
    2   5
   / \
  1   3
```

O percurso em-ordem seria: `1 -> 2 -> 3 -> 4 -> 5`.

**2.2. Percurso Pré-Ordem (Pre-order Traversal):**

Visita os nós na seguinte ordem: **Raiz -> Esquerda -> Direita**. Útil para criar uma cópia da árvore ou para representar a estrutura da árvore.

**Exemplo:** Para a árvore acima, o percurso pré-ordem seria: `4 -> 2 -> 1 -> 3 -> 5`.

**2.3. Percurso Pós-Ordem (Post-order Traversal):**

Visita os nós na seguinte ordem: **Esquerda -> Direita -> Raiz**. Útil para deletar a árvore (liberar memória) ou para avaliar expressões em árvores de expressão.

**Exemplo:** Para a árvore acima, o percurso pós-ordem seria: `1 -> 3 -> 2 -> 5 -> 4`.

**Exemplo de Código (Python - Percursos):**

```python
# Reutilizando a classe Node da seção 1.2

def inorder_traversal(node):
    if node:
        inorder_traversal(node.left)
        print(node.key, end=" ")
        inorder_traversal(node.right)

def preorder_traversal(node):
    if node:
        print(node.key, end=" ")
        preorder_traversal(node.left)
        preorder_traversal(node.right)

def postorder_traversal(node):
    if node:
        postorder_traversal(node.left)
        postorder_traversal(node.right)
        print(node.key, end=" ")

# Exemplo de uso com a ABB criada anteriormente:
# bst = BinarySearchTree()
# bst.insert(50)
# bst.insert(30)
# bst.insert(70)
# bst.insert(20)
# bst.insert(40)
# bst.insert(60)
# bst.insert(80)

print("\n--- Testando Percursos em ABB ---")
print("Percurso Em-Ordem:")
inorder_traversal(bst.root) # Saída: 20 30 40 60 70 80 (50 foi removido)
print("\nPercurso Pré-Ordem:")
preorder_traversal(bst.root) # Saída: 60 30 20 40 70 80 (50 foi removido, 60 é a nova raiz)
print("\nPercurso Pós-Ordem:")
postorder_traversal(bst.root) # Saída: 20 40 30 80 70 60 (50 foi removido, 60 é a nova raiz)
print("\n")

```

---

#### 3. Análise de Complexidade (10 minutos)

A complexidade das operações em ABBs depende da altura da árvore. No melhor caso (árvore balanceada), a altura é O(log n). No pior caso (árvore degenerada, como uma lista encadeada), a altura é O(n).

**Tabela de Complexidade (ABBs):**

| Operação | Melhor Caso (Árvore Balanceada) | Pior Caso (Árvore Degenerada) |
| :------- | :------------------------------ | :---------------------------- |
| `search` | O(log n)                        | O(n)                          |
| `insert` | O(log n)                        | O(n)                          |
| `delete` | O(log n)                        | O(n)                          |

Os percursos (em-ordem, pré-ordem, pós-ordem) visitam cada nó exatamente uma vez, portanto, sua complexidade de tempo é sempre O(n), onde n é o número de nós na árvore.

---

#### 4. Aplicações Práticas (10 minutos)

*   **Dicionários e Mapas:** ABBs são a base para a implementação de estruturas de dados que armazenam pares chave-valor, permitindo busca e inserção eficientes.
*   **Indexação de Banco de Dados:** Utilizadas para criar índices que aceleram a recuperação de registros.
*   **Ordenação:** O percurso em-ordem de uma ABB produz os elementos em ordem crescente.
*   **Sistemas de Arquivos:** Embora árvores mais complexas (como B-trees) sejam usadas, o conceito de organização hierárquica é similar.
*   **Compiladores:** Árvores de sintaxe abstrata (ASTs) são árvores que representam a estrutura de um programa.

---

#### 5. Atividade Prática (10 minutos)

**Exercício:** Implemente uma função que, dada a raiz de uma Árvore Binária de Busca, encontre o menor valor na árvore (o nó mais à esquerda).

**Dicas:**
1.  Comece pela raiz.
2.  Sempre vá para a esquerda até não ser mais possível.

**Solução (para referência, não mostre ao aluno antes da tentativa):**

```python
# Reutilizando a classe Node da seção 1.2

def find_min_value(node):
    current = node
    while current and current.left is not None:
        current = current.left
    return current.key if current else None

# Testes
print("\n--- Testando find_min_value em ABB ---")
# Usando a bst criada anteriormente (após algumas operações)
print(f"Menor valor na ABB: {find_min_value(bst.root)}") # Saída: 20

bst_empty = BinarySearchTree()
print(f"Menor valor em ABB vazia: {find_min_value(bst_empty.root)}") # Saída: None

bst_single = BinarySearchTree()
bst_single.insert(100)
print(f"Menor valor em ABB com um nó: {find_min_value(bst_single.root)}") # Saída: 100

```

---

#### 6. Referências e Leitura Complementar

*   **[1] Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009). *Introduction to Algorithms* (3rd ed.). MIT Press.**
    *   Capítulo 12: Árvores Binárias de Busca.

*   **[2] Goodrich, M. T., Tamassia, R., & Goldwasser, M. H. (2014). *Data Structures and Algorithms in Python*. John Wiley & Sons.**
    *   Capítulo 11: Árvores de Busca.

*   **[3] Sedgewick, R., & Wayne, K. (2011). *Algorithms* (4th ed.). Addison-Wesley Professional.**
    *   Capítulo 3: Elementary Data Structures (seção sobre Árvores de Busca).

*   **[4] Livro: Estruturas de Dados e Algoritmos em C++ - Michael T. Goodrich, Roberto Tamassia, David M. Mount.**
    *   Capítulo 11: Árvores de Busca.

*   **[5] Artigo/Recurso Online:** GeeksforGeeks - Binary Search Tree (BST) (https://www.geeksforgeeks.org/binary-search-tree-data-structure/)
    *   Recurso online abrangente sobre ABBs.

*   **[6] Artigo/Recurso Online:** GeeksforGeeks - Tree Traversals (https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/)
    *   Recurso online sobre os diferentes tipos de percursos em árvores.

---

**Próxima Aula:** Árvores AVL e Árvores Rubro-Negras.



