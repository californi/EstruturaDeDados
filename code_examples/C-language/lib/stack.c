#include "../include/stack.h"

// ========================================
// IMPLEMENTAÇÃO DA PILHA COM ARRAY
// ========================================

void stack_array_init(StackArray* stack) {
    if (stack == NULL) return;
    stack->top = -1;
}

bool stack_array_is_empty(StackArray* stack) {
    if (stack == NULL) return true;
    return stack->top == -1;
}

bool stack_array_is_full(StackArray* stack) {
    if (stack == NULL) return true;
    return stack->top == MAX_SIZE - 1;
}

int stack_array_push(StackArray* stack, DataType value) {
    if (stack == NULL) return FAILURE;
    
    if (stack_array_is_full(stack)) {
        print_error(STACK_FULL);
        return FAILURE;
    }
    
    stack->top++;
    stack->data[stack->top] = value;
    return SUCCESS;
}

int stack_array_pop(StackArray* stack, DataType* value) {
    if (stack == NULL || value == NULL) return FAILURE;
    
    if (stack_array_is_empty(stack)) {
        print_error(STACK_EMPTY);
        return FAILURE;
    }
    
    *value = stack->data[stack->top];
    stack->top--;
    return SUCCESS;
}

int stack_array_peek(StackArray* stack, DataType* value) {
    if (stack == NULL || value == NULL) return FAILURE;
    
    if (stack_array_is_empty(stack)) {
        print_error(STACK_EMPTY);
        return FAILURE;
    }
    
    *value = stack->data[stack->top];
    return SUCCESS;
}

int stack_array_size(StackArray* stack) {
    if (stack == NULL) return 0;
    return stack->top + 1;
}

void stack_array_print(StackArray* stack) {
    if (stack == NULL) {
        printf("Pilha inválida!\n");
        return;
    }
    
    if (stack_array_is_empty(stack)) {
        printf("Pilha vazia!\n");
        return;
    }
    
    printf("Pilha (topo -> base): ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

void stack_array_clear(StackArray* stack) {
    if (stack == NULL) return;
    stack->top = -1;
}

// ========================================
// IMPLEMENTAÇÃO DA PILHA COM LISTA LIGADA
// ========================================

void stack_linked_init(StackLinked* stack) {
    if (stack == NULL) return;
    stack->top = NULL;
    stack->size = 0;
}

bool stack_linked_is_empty(StackLinked* stack) {
    if (stack == NULL) return true;
    return stack->top == NULL;
}

int stack_linked_push(StackLinked* stack, DataType value) {
    if (stack == NULL) return FAILURE;
    
    StackNode* new_node = (StackNode*)malloc(sizeof(StackNode));
    if (new_node == NULL) {
        print_error(MEMORY_ERROR);
        return FAILURE;
    }
    
    new_node->data = value;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
    
    return SUCCESS;
}

int stack_linked_pop(StackLinked* stack, DataType* value) {
    if (stack == NULL || value == NULL) return FAILURE;
    
    if (stack_linked_is_empty(stack)) {
        print_error(STACK_EMPTY);
        return FAILURE;
    }
    
    StackNode* temp = stack->top;
    *value = temp->data;
    stack->top = temp->next;
    free(temp);
    stack->size--;
    
    return SUCCESS;
}

int stack_linked_peek(StackLinked* stack, DataType* value) {
    if (stack == NULL || value == NULL) return FAILURE;
    
    if (stack_linked_is_empty(stack)) {
        print_error(STACK_EMPTY);
        return FAILURE;
    }
    
    *value = stack->top->data;
    return SUCCESS;
}

int stack_linked_size(StackLinked* stack) {
    if (stack == NULL) return 0;
    return stack->size;
}

void stack_linked_print(StackLinked* stack) {
    if (stack == NULL) {
        printf("Pilha inválida!\n");
        return;
    }
    
    if (stack_linked_is_empty(stack)) {
        printf("Pilha vazia!\n");
        return;
    }
    
    printf("Pilha (topo -> base): ");
    StackNode* current = stack->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void stack_linked_clear(StackLinked* stack) {
    if (stack == NULL) return;
    
    DataType temp;
    while (!stack_linked_is_empty(stack)) {
        stack_linked_pop(stack, &temp);
    }
}

// ========================================
// FUNÇÕES DE DEMONSTRAÇÃO
// ========================================

void demonstrate_stack_array(void) {
    print_separator("DEMONSTRAÇÃO: PILHA COM ARRAY");
    
    StackArray stack;
    stack_array_init(&stack);
    
    printf("1. Pilha inicializada\n");
    printf("   Vazia? %s\n", stack_array_is_empty(&stack) ? "Sim" : "Não");
    printf("   Tamanho: %d\n", stack_array_size(&stack));
    
    printf("\n2. Inserindo elementos: 10, 20, 30, 40, 50\n");
    stack_array_push(&stack, 10);
    stack_array_push(&stack, 20);
    stack_array_push(&stack, 30);
    stack_array_push(&stack, 40);
    stack_array_push(&stack, 50);
    
    printf("   ");
    stack_array_print(&stack);
    printf("   Tamanho: %d\n", stack_array_size(&stack));
    
    DataType value;
    printf("\n3. Consultando o topo (peek)\n");
    if (stack_array_peek(&stack, &value) == SUCCESS) {
        printf("   Topo: %d\n", value);
    }
    
    printf("\n4. Removendo 2 elementos\n");
    if (stack_array_pop(&stack, &value) == SUCCESS) {
        printf("   Removido: %d\n", value);
    }
    if (stack_array_pop(&stack, &value) == SUCCESS) {
        printf("   Removido: %d\n", value);
    }
    
    printf("   ");
    stack_array_print(&stack);
    printf("   Tamanho: %d\n", stack_array_size(&stack));
    
    printf("\n5. Limpando a pilha\n");
    stack_array_clear(&stack);
    printf("   ");
    stack_array_print(&stack);
    printf("   Vazia? %s\n", stack_array_is_empty(&stack) ? "Sim" : "Não");
}

void demonstrate_stack_linked(void) {
    print_separator("DEMONSTRAÇÃO: PILHA COM LISTA LIGADA");
    
    StackLinked stack;
    stack_linked_init(&stack);
    
    printf("1. Pilha inicializada\n");
    printf("   Vazia? %s\n", stack_linked_is_empty(&stack) ? "Sim" : "Não");
    printf("   Tamanho: %d\n", stack_linked_size(&stack));
    
    printf("\n2. Inserindo elementos: 100, 200, 300, 400, 500\n");
    stack_linked_push(&stack, 100);
    stack_linked_push(&stack, 200);
    stack_linked_push(&stack, 300);
    stack_linked_push(&stack, 400);
    stack_linked_push(&stack, 500);
    
    printf("   ");
    stack_linked_print(&stack);
    printf("   Tamanho: %d\n", stack_linked_size(&stack));
    
    DataType value;
    printf("\n3. Consultando o topo (peek)\n");
    if (stack_linked_peek(&stack, &value) == SUCCESS) {
        printf("   Topo: %d\n", value);
    }
    
    printf("\n4. Removendo 3 elementos\n");
    for (int i = 0; i < 3; i++) {
        if (stack_linked_pop(&stack, &value) == SUCCESS) {
            printf("   Removido: %d\n", value);
        }
    }
    
    printf("   ");
    stack_linked_print(&stack);
    printf("   Tamanho: %d\n", stack_linked_size(&stack));
    
    printf("\n5. Limpando a pilha\n");
    stack_linked_clear(&stack);
    printf("   ");
    stack_linked_print(&stack);
    printf("   Vazia? %s\n", stack_linked_is_empty(&stack) ? "Sim" : "Não");
}

