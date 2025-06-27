#include "../include/common.h"

void print_error(ErrorCode error) {
    switch(error) {
        case STACK_EMPTY:
            printf("Erro: Pilha vazia!\n");
            break;
        case STACK_FULL:
            printf("Erro: Pilha cheia!\n");
            break;
        case QUEUE_EMPTY:
            printf("Erro: Fila vazia!\n");
            break;
        case QUEUE_FULL:
            printf("Erro: Fila cheia!\n");
            break;
        case LIST_EMPTY:
            printf("Erro: Lista vazia!\n");
            break;
        case LIST_FULL:
            printf("Erro: Lista cheia!\n");
            break;
        case INVALID_POSITION:
            printf("Erro: Posição inválida!\n");
            break;
        case MEMORY_ERROR:
            printf("Erro: Falha na alocação de memória!\n");
            break;
        default:
            printf("Erro desconhecido!\n");
    }
}

void print_separator(const char* title) {
    printf("\n");
    printf("=================================================\n");
    printf("  %s\n", title);
    printf("=================================================\n");
}

void pause_execution(void) {
    printf("\nPressione Enter para continuar...");
    getchar();
}

