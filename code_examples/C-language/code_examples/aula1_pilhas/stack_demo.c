#include "../include/stack.h"
#include "../include/common.h"

int main() {
    printf("=================================================\n");
    printf("     ESTRUTURAS DE DADOS EM C - AULA 1\n");
    printf("              PILHAS (STACKS)\n");
    printf("=================================================\n");
    
    printf("\nEste programa demonstra duas implementações de pilha:\n");
    printf("1. Pilha com Array (alocação estática)\n");
    printf("2. Pilha com Lista Ligada (alocação dinâmica)\n");
    
    printf("\nPressione Enter para começar a demonstração...");
    getchar();
    
    // Demonstração da pilha com array
    demonstrate_stack_array();
    
    printf("\n\nPressione Enter para continuar com a próxima demonstração...");
    getchar();
    
    // Demonstração da pilha com lista ligada
    demonstrate_stack_linked();
    
    printf("\n\n");
    print_separator("COMPARAÇÃO ENTRE AS IMPLEMENTAÇÕES");
    
    printf("\nPILHA COM ARRAY:\n");
    printf("  Vantagens:\n");
    printf("    - Acesso rápido (O(1))\n");
    printf("    - Menor uso de memória por elemento\n");
    printf("    - Implementação mais simples\n");
    printf("  Desvantagens:\n");
    printf("    - Tamanho fixo (limitado)\n");
    printf("    - Pode desperdiçar memória\n");
    
    printf("\nPILHA COM LISTA LIGADA:\n");
    printf("  Vantagens:\n");
    printf("    - Tamanho dinâmico (ilimitado)\n");
    printf("    - Usa apenas a memória necessária\n");
    printf("  Desvantagens:\n");
    printf("    - Overhead de ponteiros\n");
    printf("    - Possível fragmentação de memória\n");
    
    printf("\n");
    print_separator("APLICAÇÕES PRÁTICAS DAS PILHAS");
    
    printf("\n1. Avaliação de expressões matemáticas\n");
    printf("2. Conversão de notação infixa para pós-fixa\n");
    printf("3. Verificação de parênteses balanceados\n");
    printf("4. Implementação de recursão\n");
    printf("5. Navegação em browsers (histórico)\n");
    printf("6. Operações de desfazer (Undo) em editores\n");
    printf("7. Chamadas de função (call stack)\n");
    
    printf("\n");
    print_separator("COMPLEXIDADE DAS OPERAÇÕES");
    
    printf("\nTodas as operações básicas têm complexidade O(1):\n");
    printf("  - Push (inserir)\n");
    printf("  - Pop (remover)\n");
    printf("  - Peek/Top (consultar topo)\n");
    printf("  - IsEmpty (verificar se vazia)\n");
    printf("  - Size (obter tamanho)\n");
    
    printf("\n\nPrograma finalizado. Obrigado por estudar estruturas de dados!\n");
    
    return 0;
}

