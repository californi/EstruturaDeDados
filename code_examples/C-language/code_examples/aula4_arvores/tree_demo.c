#include "../include/tree.h"
#include "../include/common.h"

int main() {
    printf("=================================================\n");
    printf("     ESTRUTURAS DE DADOS EM C - AULA 4\n");
    printf("           ÁRVORES BINÁRIAS DE BUSCA\n");
    printf("=================================================\n");
    
    printf("\nEste programa demonstra:\n");
    printf("1. Árvore Binária de Busca (BST)\n");
    printf("2. Operações básicas (inserir, remover, buscar)\n");
    printf("3. Percursos da árvore\n");
    printf("4. Propriedades da árvore\n");
    
    printf("\nPressione Enter para começar...");
    getchar();
    
    // Demonstração da árvore binária de busca
    demonstrate_binary_search_tree();
    
    printf("\n\n");
    print_separator("PROPRIEDADES DAS ÁRVORES BINÁRIAS DE BUSCA");
    
    printf("\nPROPRIEDADE FUNDAMENTAL:\n");
    printf("  Para qualquer nó N:\n");
    printf("  - Todos os nós na subárvore esquerda têm valores < N\n");
    printf("  - Todos os nós na subárvore direita têm valores > N\n");
    printf("  - Esta propriedade se aplica recursivamente\n");
    
    printf("\nCOMPLEXIDADE DAS OPERAÇÕES:\n");
    printf("  Melhor caso (árvore balanceada):\n");
    printf("    - Busca: O(log n)\n");
    printf("    - Inserção: O(log n)\n");
    printf("    - Remoção: O(log n)\n");
    printf("  Pior caso (árvore degenerada):\n");
    printf("    - Busca: O(n)\n");
    printf("    - Inserção: O(n)\n");
    printf("    - Remoção: O(n)\n");
    
    printf("\nPERCURSOS E SUAS APLICAÇÕES:\n");
    printf("  In-order (esquerda, raiz, direita):\n");
    printf("    - Produz sequência ordenada\n");
    printf("    - Usado para imprimir elementos em ordem\n");
    printf("  Pre-order (raiz, esquerda, direita):\n");
    printf("    - Usado para copiar/clonar árvore\n");
    printf("    - Expressões em notação prefixada\n");
    printf("  Post-order (esquerda, direita, raiz):\n");
    printf("    - Usado para deletar árvore\n");
    printf("    - Expressões em notação pós-fixada\n");
    printf("  Level-order (por níveis):\n");
    printf("    - Usado para imprimir árvore por níveis\n");
    printf("    - Busca em largura\n");
    
    printf("\n");
    print_separator("APLICAÇÕES PRÁTICAS");
    
    printf("\nÁRVORES BINÁRIAS DE BUSCA SÃO USADAS EM:\n");
    printf("1. Sistemas de banco de dados (índices)\n");
    printf("2. Compiladores (tabelas de símbolos)\n");
    printf("3. Sistemas de arquivos\n");
    printf("4. Algoritmos de busca eficientes\n");
    printf("5. Implementação de conjuntos e mapas\n");
    printf("6. Expressões matemáticas\n");
    printf("7. Árvores de decisão\n");
    
    printf("\nVARIAÇÕES IMPORTANTES:\n");
    printf("1. Árvores AVL (auto-balanceadas)\n");
    printf("2. Árvores Rubro-Negras\n");
    printf("3. Árvores B e B+\n");
    printf("4. Árvores Splay\n");
    printf("5. Treaps\n");
    
    printf("\n");
    print_separator("VANTAGENS E DESVANTAGENS");
    
    printf("\nVANTAGENS:\n");
    printf("  ✓ Busca eficiente O(log n) em média\n");
    printf("  ✓ Inserção e remoção dinâmicas\n");
    printf("  ✓ Percurso in-order produz sequência ordenada\n");
    printf("  ✓ Estrutura hierárquica natural\n");
    printf("  ✓ Não requer reorganização como arrays\n");
    
    printf("\nDESVANTAGENS:\n");
    printf("  ✗ Pode degenerar para O(n) se não balanceada\n");
    printf("  ✗ Overhead de ponteiros\n");
    printf("  ✗ Não tem acesso direto por índice\n");
    printf("  ✗ Cache-unfriendly comparado a arrays\n");
    printf("  ✗ Complexidade de implementação\n");
    
    printf("\n");
    print_separator("DICAS DE IMPLEMENTAÇÃO");
    
    printf("\nBOAS PRÁTICAS:\n");
    printf("1. Sempre verificar ponteiros nulos\n");
    printf("2. Implementar remoção corretamente (3 casos)\n");
    printf("3. Usar recursão para simplicidade\n");
    printf("4. Considerar balanceamento para performance\n");
    printf("5. Liberar memória adequadamente\n");
    
    printf("\nCASOS DE REMOÇÃO:\n");
    printf("1. Nó folha (sem filhos): simplesmente remover\n");
    printf("2. Nó com um filho: substituir pelo filho\n");
    printf("3. Nó com dois filhos: substituir pelo sucessor in-order\n");
    
    printf("\n\nPrograma finalizado. Continue estudando árvores!\n");
    
    return 0;
}

