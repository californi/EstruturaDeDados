# Aula 1: Pilhas (Stacks)

## Objetivos de Aprendizagem

Ao final desta aula, você será capaz de:
- Compreender o conceito e funcionamento de pilhas
- Implementar pilhas usando arrays e listas ligadas em C
- Analisar a complexidade das operações de pilha
- Identificar aplicações práticas de pilhas
- Resolver problemas usando pilhas

## 1. Introdução ao Conceito

### O que é uma Pilha?

Uma **pilha** (stack) é uma estrutura de dados linear que segue o princípio **LIFO** (Last In, First Out - Último a Entrar, Primeiro a Sair). Imagine uma pilha de pratos: você sempre adiciona um prato no topo e sempre remove o prato do topo.

### Características Principais

- **Acesso restrito**: Só é possível acessar o elemento do topo
- **Operações principais**: Push (inserir) e Pop (remover)
- **Estrutura dinâmica**: O tamanho pode variar durante a execução
- **Memória**: Pode ser implementada com alocação estática ou dinâmica

## 2. Operações Básicas

### Operações Fundamentais

1. **Push**: Inserir um elemento no topo da pilha
2. **Pop**: Remover e retornar o elemento do topo
3. **Peek/Top**: Consultar o elemento do topo sem removê-lo
4. **IsEmpty**: Verificar se a pilha está vazia
5. **Size**: Obter o número de elementos na pilha

### Operações Auxiliares

- **IsFull**: Verificar se a pilha está cheia (apenas para implementação com array)
- **Clear**: Remover todos os elementos da pilha
- **Print**: Exibir todos os elementos da pilha

## 3. Implementações em C

### 3.1 Implementação com Array (Alocação Estática)

```c
typedef struct {
    DataType data[MAX_SIZE];
    int top;
} StackArray;

// Vantagens:
// - Acesso rápido O(1)
// - Menor uso de memória por elemento
// - Implementação mais simples

// Desvantagens:
// - Tamanho fixo
// - Possível desperdício de memória
```

### 3.2 Implementação com Lista Ligada (Alocação Dinâmica)

```c
typedef struct StackNode {
    DataType data;
    struct StackNode* next;
} StackNode;

typedef struct {
    StackNode* top;
    int size;
} StackLinked;

// Vantagens:
// - Tamanho dinâmico
// - Usa apenas memória necessária

// Desvantagens:
// - Overhead de ponteiros
// - Possível fragmentação de memória
```

## 4. Análise de Complexidade

### Complexidade Temporal

| Operação | Array | Lista Ligada |
|----------|-------|--------------|
| Push     | O(1)  | O(1)         |
| Pop      | O(1)  | O(1)         |
| Peek     | O(1)  | O(1)         |
| IsEmpty  | O(1)  | O(1)         |
| Size     | O(1)  | O(1)         |

### Complexidade Espacial

- **Array**: O(n) onde n é o tamanho máximo
- **Lista Ligada**: O(n) onde n é o número de elementos atual

## 5. Aplicações Práticas

### 5.1 Avaliação de Expressões Matemáticas

```c
// Exemplo: Conversão infixa para pós-fixa
// Infixa: (3 + 4) * 5
// Pós-fixa: 3 4 + 5 *
```

### 5.2 Verificação de Parênteses Balanceados

```c
// Exemplo: Verificar se "((()))" está balanceado
bool isBalanced(char* expression) {
    StackArray stack;
    stack_array_init(&stack);
    
    for (int i = 0; expression[i]; i++) {
        if (expression[i] == '(') {
            stack_array_push(&stack, expression[i]);
        } else if (expression[i] == ')') {
            if (stack_array_is_empty(&stack)) {
                return false;
            }
            DataType temp;
            stack_array_pop(&stack, &temp);
        }
    }
    
    return stack_array_is_empty(&stack);
}
```

### 5.3 Outras Aplicações

1. **Chamadas de Função**: Call stack do sistema operacional
2. **Navegação em Browsers**: Histórico de páginas visitadas
3. **Operações de Desfazer**: Undo em editores de texto
4. **Algoritmos de Backtracking**: Exploração de soluções
5. **Compiladores**: Análise sintática e semântica
6. **Recursão**: Simulação de chamadas recursivas

## 6. Atividade Prática

### Exercício 1: Implementação Básica
Compile e execute o programa `stack_demo.c` para ver as implementações em ação.

```bash
gcc -o stack_demo code_examples/aula1_pilhas/stack_demo.c lib/stack.c lib/common.c -I include
./stack_demo
```

### Exercício 2: Verificador de Parênteses
Implemente uma função que verifica se uma expressão com parênteses, colchetes e chaves está balanceada.

### Exercício 3: Calculadora Pós-fixa
Implemente uma calculadora que avalia expressões em notação pós-fixa usando uma pilha.

### Exercício 4: Conversão de Base
Use uma pilha para converter números decimais para binário.

## 7. Problemas Comuns e Soluções

### 7.1 Stack Overflow
- **Problema**: Tentar inserir em uma pilha cheia (array)
- **Solução**: Verificar se a pilha está cheia antes de inserir

### 7.2 Stack Underflow
- **Problema**: Tentar remover de uma pilha vazia
- **Solução**: Verificar se a pilha está vazia antes de remover

### 7.3 Memory Leaks
- **Problema**: Não liberar memória alocada (lista ligada)
- **Solução**: Sempre chamar `free()` ao remover nós

## 8. Comparação entre Implementações

| Aspecto | Array | Lista Ligada |
|---------|-------|--------------|
| **Velocidade** | Mais rápida | Ligeiramente mais lenta |
| **Memória** | Fixa | Dinâmica |
| **Simplicidade** | Mais simples | Mais complexa |
| **Flexibilidade** | Limitada | Alta |
| **Fragmentação** | Não há | Possível |

## 9. Dicas de Implementação

### 9.1 Boas Práticas
- Sempre verificar ponteiros nulos
- Implementar verificações de erro
- Usar nomes descritivos para variáveis
- Documentar o código adequadamente

### 9.2 Otimizações
- Para arrays: usar índices em vez de ponteiros
- Para listas: manter referência ao tamanho
- Implementar operações inline quando apropriado

## 10. Referências e Leitura Complementar

### Livros Recomendados
1. **"Algoritmos: Teoria e Prática"** - Cormen, Leiserson, Rivest, Stein
2. **"Estruturas de Dados e Algoritmos em C"** - Mark Allen Weiss
3. **"The C Programming Language"** - Kernighan & Ritchie

### Artigos e Recursos Online
- [Stack Data Structure - GeeksforGeeks](https://www.geeksforgeeks.org/stack-data-structure/)
- [Stack Implementation in C - Programiz](https://www.programiz.com/dsa/stack)

### Vídeos Educacionais
- MIT OpenCourseWare: Introduction to Algorithms
- Khan Academy: Algorithms Course

## Resumo da Aula

Nesta aula, você aprendeu:
- ✅ Conceito fundamental de pilhas (LIFO)
- ✅ Implementação com arrays e listas ligadas
- ✅ Análise de complexidade das operações
- ✅ Aplicações práticas importantes
- ✅ Problemas comuns e suas soluções

**Próxima aula**: Filas (Queues) e Deques - estruturas FIFO e suas variações.

---

**Tempo estimado de estudo**: 90 minutos  
**Dificuldade**: Iniciante  
**Pré-requisitos**: Conhecimentos básicos de C, ponteiros e alocação de memória

