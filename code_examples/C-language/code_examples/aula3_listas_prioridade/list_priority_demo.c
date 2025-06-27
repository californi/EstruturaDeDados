#include "../include/list.h"
#include "../include/priority_queue.h"
#include "../include/common.h"

int main() {
    printf("=================================================\n");
    printf("     ESTRUTURAS DE DADOS EM C - AULA 3\n");
    printf("   LISTAS LINEARES E FILAS DE PRIORIDADE\n");
    printf("=================================================\n");
    
    printf("\nEste programa demonstra:\n");
    printf("1. Lista Sequencial (Array)\n");
    printf("2. Lista Simplesmente Ligada\n");
    printf("3. Fila de Prioridade com Heap\n");
    
    printf("\nPressione Enter para começar...");
    getchar();
    
    // Demonstração da lista sequencial
    demonstrate_list_array();
    
    printf("\n\nPressione Enter para continuar...");
    getchar();
    
    // Demonstração da lista ligada
    demonstrate_list_linked();
    
    printf("\n\nPressione Enter para continuar...");
    getchar();
    
    // Demonstração da fila de prioridade
    demonstrate_priority_queue();
    
    printf("\n\n");
    print_separator("COMPARAÇÃO ENTRE LISTAS");
    
    printf("\nLISTA SEQUENCIAL (ARRAY):\n");
    printf("  Vantagens:\n");
    printf("    - Acesso direto O(1) por índice\n");
    printf("    - Menor uso de memória\n");
    printf("    - Cache-friendly (localidade)\n");
    printf("  Desvantagens:\n");
    printf("    - Inserção/remoção O(n) no meio\n");
    printf("    - Tamanho fixo\n");
    printf("    - Desperdício de memória\n");
    
    printf("\nLISTA SIMPLESMENTE LIGADA:\n");
    printf("  Vantagens:\n");
    printf("    - Tamanho dinâmico\n");
    printf("    - Inserção/remoção O(1) se tiver referência\n");
    printf("    - Uso eficiente de memória\n");
    printf("  Desvantagens:\n");
    printf("    - Acesso sequencial O(n)\n");
    printf("    - Overhead de ponteiros\n");
    printf("    - Fragmentação de memória\n");
    
    printf("\nFILA DE PRIORIDADE:\n");
    printf("  Vantagens:\n");
    printf("    - Acesso eficiente ao máximo O(1)\n");
    printf("    - Inserção e remoção O(log n)\n");
    printf("    - Ideal para algoritmos gulosos\n");
    printf("  Aplicações:\n");
    printf("    - Algoritmos de grafos (Dijkstra, Prim)\n");
    printf("    - Escalonamento de processos\n");
    printf("    - Simulações de eventos\n");
    
    printf("\n");
    print_separator("COMPLEXIDADE DAS OPERAÇÕES");
    
    printf("\n| Operação    | Array | Lista Ligada | Heap (PQ) |\n");
    printf("|-------------|-------|--------------|----------|\n");
    printf("| Acesso      | O(1)  | O(n)         | O(1)*    |\n");
    printf("| Busca       | O(n)  | O(n)         | O(n)     |\n");
    printf("| Inserção    | O(n)  | O(1)**       | O(log n) |\n");
    printf("| Remoção     | O(n)  | O(1)**       | O(log n) |\n");
    printf("| Espaço      | O(n)  | O(n)         | O(n)     |\n");
    
    printf("\n* Apenas para o elemento de maior prioridade\n");
    printf("** Se tiver referência para o nó\n");
    
    printf("\n");
    print_separator("QUANDO USAR CADA ESTRUTURA");
    
    printf("\nUSE LISTA SEQUENCIAL QUANDO:\n");
    printf("  - Acesso frequente por índice\n");
    printf("  - Tamanho conhecido e limitado\n");
    printf("  - Poucas inserções/remoções no meio\n");
    printf("  - Memória é limitada\n");
    
    printf("\nUSE LISTA LIGADA QUANDO:\n");
    printf("  - Tamanho varia muito\n");
    printf("  - Inserções/remoções frequentes\n");
    printf("  - Acesso sequencial predominante\n");
    printf("  - Flexibilidade é importante\n");
    
    printf("\nUSE FILA DE PRIORIDADE QUANDO:\n");
    printf("  - Precisa sempre do elemento de maior prioridade\n");
    printf("  - Implementando algoritmos gulosos\n");
    printf("  - Escalonamento baseado em prioridade\n");
    printf("  - Simulações de eventos discretos\n");
    
    printf("\n\nPrograma finalizado. Continue estudando!\n");
    
    return 0;
}

