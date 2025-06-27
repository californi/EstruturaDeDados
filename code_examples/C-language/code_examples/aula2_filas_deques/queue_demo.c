#include "../include/queue.h"
#include "../include/common.h"

int main() {
    printf("=================================================\n");
    printf("     ESTRUTURAS DE DADOS EM C - AULA 2\n");
    printf("          FILAS (QUEUES) E DEQUES\n");
    printf("=================================================\n");
    
    printf("\nEste programa demonstra três implementações:\n");
    printf("1. Fila com Array Circular (alocação estática)\n");
    printf("2. Fila com Lista Ligada (alocação dinâmica)\n");
    printf("3. Deque - Fila de Dupla Extremidade\n");
    
    printf("\nPressione Enter para começar a demonstração...");
    getchar();
    
    // Demonstração da fila com array
    demonstrate_queue_array();
    
    printf("\n\nPressione Enter para continuar...");
    getchar();
    
    // Demonstração da fila com lista ligada
    demonstrate_queue_linked();
    
    printf("\n\nPressione Enter para continuar...");
    getchar();
    
    // Demonstração do deque
    demonstrate_deque();
    
    printf("\n\n");
    print_separator("COMPARAÇÃO ENTRE AS IMPLEMENTAÇÕES");
    
    printf("\nFILA COM ARRAY CIRCULAR:\n");
    printf("  Vantagens:\n");
    printf("    - Acesso rápido (O(1))\n");
    printf("    - Uso eficiente do espaço (circular)\n");
    printf("    - Implementação mais simples\n");
    printf("  Desvantagens:\n");
    printf("    - Tamanho fixo (limitado)\n");
    printf("    - Pode desperdiçar memória\n");
    
    printf("\nFILA COM LISTA LIGADA:\n");
    printf("  Vantagens:\n");
    printf("    - Tamanho dinâmico (ilimitado)\n");
    printf("    - Usa apenas a memória necessária\n");
    printf("  Desvantagens:\n");
    printf("    - Overhead de ponteiros\n");
    printf("    - Possível fragmentação de memória\n");
    
    printf("\nDEQUE (FILA DUPLA):\n");
    printf("  Vantagens:\n");
    printf("    - Inserção/remoção em ambas as extremidades\n");
    printf("    - Mais flexível que fila simples\n");
    printf("    - Pode simular pilha ou fila\n");
    printf("  Desvantagens:\n");
    printf("    - Maior complexidade de implementação\n");
    printf("    - Overhead adicional de ponteiros duplos\n");
    
    printf("\n");
    print_separator("APLICAÇÕES PRÁTICAS");
    
    printf("\nFILAS:\n");
    printf("1. Sistemas de impressão (spooling)\n");
    printf("2. Processamento de tarefas em SO\n");
    printf("3. Algoritmos de busca (BFS)\n");
    printf("4. Simulação de filas de atendimento\n");
    printf("5. Buffer de dados em comunicação\n");
    printf("6. Gerenciamento de processos\n");
    
    printf("\nDEQUES:\n");
    printf("1. Implementação de algoritmos de janela deslizante\n");
    printf("2. Histórico de navegação (frente/trás)\n");
    printf("3. Algoritmos de otimização\n");
    printf("4. Processamento de palíndromos\n");
    printf("5. Implementação de outras estruturas\n");
    
    printf("\n");
    print_separator("COMPLEXIDADE DAS OPERAÇÕES");
    
    printf("\nTodas as operações básicas têm complexidade O(1):\n");
    printf("  FILAS:\n");
    printf("    - Enqueue (inserir no final)\n");
    printf("    - Dequeue (remover do início)\n");
    printf("    - Front (consultar primeiro)\n");
    printf("    - IsEmpty/Size\n");
    
    printf("\n  DEQUES:\n");
    printf("    - Push Front/Rear (inserir)\n");
    printf("    - Pop Front/Rear (remover)\n");
    printf("    - Front/Rear (consultar)\n");
    printf("    - IsEmpty/Size\n");
    
    printf("\n");
    print_separator("PRINCÍPIOS FUNDAMENTAIS");
    
    printf("\nFILA (QUEUE):\n");
    printf("  - Princípio: FIFO (First In, First Out)\n");
    printf("  - Primeiro a entrar é o primeiro a sair\n");
    printf("  - Inserção no final, remoção no início\n");
    
    printf("\nDEQUE (DOUBLE-ENDED QUEUE):\n");
    printf("  - Princípio: Inserção/remoção em ambas as extremidades\n");
    printf("  - Combina características de pilha e fila\n");
    printf("  - Maior flexibilidade operacional\n");
    
    printf("\n\nPrograma finalizado. Continue estudando estruturas de dados!\n");
    
    return 0;
}

