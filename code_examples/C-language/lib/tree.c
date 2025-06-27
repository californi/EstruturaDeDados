#include "../include/tree.h"

// ========================================
// FUNÇÕES BÁSICAS DE NÓS
// ========================================

TreeNode* tree_create_node(DataType value) {
    TreeNode* new_node = (TreeNode*)malloc(sizeof(TreeNode));
    if (new_node == NULL) {
        print_error(MEMORY_ERROR);
        return NULL;
    }
    
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;
    
    return new_node;
}

void tree_destroy_node(TreeNode* node) {
    if (node != NULL) {
        free(node);
    }
}

// ========================================
// OPERAÇÕES DA ÁRVORE BINÁRIA DE BUSCA
// ========================================

void bst_init(BinarySearchTree* bst) {
    if (bst == NULL) return;
    bst->root = NULL;
    bst->size = 0;
}

bool bst_is_empty(BinarySearchTree* bst) {
    if (bst == NULL) return true;
    return bst->root == NULL;
}

int bst_insert(BinarySearchTree* bst, DataType value) {
    if (bst == NULL) return FAILURE;
    
    bst->root = bst_insert_recursive(bst->root, value);
    if (bst->root != NULL) {
        bst->size++;
        return SUCCESS;
    }
    
    return FAILURE;
}

TreeNode* bst_insert_recursive(TreeNode* root, DataType value) {
    // Caso base: árvore vazia
    if (root == NULL) {
        return tree_create_node(value);
    }
    
    // Inserir recursivamente
    if (value < root->data) {
        root->left = bst_insert_recursive(root->left, value);
    } else if (value > root->data) {
        root->right = bst_insert_recursive(root->right, value);
    }
    // Se value == root->data, não inserir (sem duplicatas)
    
    return root;
}

int bst_remove(BinarySearchTree* bst, DataType value) {
    if (bst == NULL || bst_is_empty(bst)) return FAILURE;
    
    TreeNode* old_root = bst->root;
    bst->root = bst_remove_recursive(bst->root, value);
    
    if (bst->root != old_root || bst_search(bst, value) == false) {
        bst->size--;
        return SUCCESS;
    }
    
    return FAILURE;
}

TreeNode* bst_remove_recursive(TreeNode* root, DataType value) {
    if (root == NULL) return root;
    
    if (value < root->data) {
        root->left = bst_remove_recursive(root->left, value);
    } else if (value > root->data) {
        root->right = bst_remove_recursive(root->right, value);
    } else {
        // Nó encontrado - remover
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            tree_destroy_node(root);
            return temp;
        } else if (root->right == NULL) {
            TreeNode* temp = root->left;
            tree_destroy_node(root);
            return temp;
        }
        
        // Nó com dois filhos
        TreeNode* temp = bst_find_min(root->right);
        root->data = temp->data;
        root->right = bst_remove_recursive(root->right, temp->data);
    }
    
    return root;
}

bool bst_search(BinarySearchTree* bst, DataType value) {
    if (bst == NULL) return false;
    return bst_search_recursive(bst->root, value) != NULL;
}

TreeNode* bst_search_recursive(TreeNode* root, DataType value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    
    if (value < root->data) {
        return bst_search_recursive(root->left, value);
    }
    
    return bst_search_recursive(root->right, value);
}

TreeNode* bst_find_min(TreeNode* root) {
    if (root == NULL) return NULL;
    
    while (root->left != NULL) {
        root = root->left;
    }
    
    return root;
}

TreeNode* bst_find_max(TreeNode* root) {
    if (root == NULL) return NULL;
    
    while (root->right != NULL) {
        root = root->right;
    }
    
    return root;
}

int bst_size(BinarySearchTree* bst) {
    if (bst == NULL) return 0;
    return bst->size;
}

int bst_height(TreeNode* root) {
    if (root == NULL) return -1;
    
    int left_height = bst_height(root->left);
    int right_height = bst_height(root->right);
    
    return 1 + (left_height > right_height ? left_height : right_height);
}

void bst_clear(BinarySearchTree* bst) {
    if (bst == NULL) return;
    
    tree_destroy_recursive(bst->root);
    bst->root = NULL;
    bst->size = 0;
}

void tree_destroy_recursive(TreeNode* root) {
    if (root != NULL) {
        tree_destroy_recursive(root->left);
        tree_destroy_recursive(root->right);
        tree_destroy_node(root);
    }
}

// ========================================
// PERCURSOS DA ÁRVORE
// ========================================

void tree_inorder(TreeNode* root) {
    if (root != NULL) {
        tree_inorder(root->left);
        printf("%d ", root->data);
        tree_inorder(root->right);
    }
}

void tree_preorder(TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        tree_preorder(root->left);
        tree_preorder(root->right);
    }
}

void tree_postorder(TreeNode* root) {
    if (root != NULL) {
        tree_postorder(root->left);
        tree_postorder(root->right);
        printf("%d ", root->data);
    }
}

void tree_level_order(TreeNode* root) {
    if (root == NULL) return;
    
    // Usar fila para percurso em nível
    QueueLinked queue;
    queue_linked_init(&queue);
    
    // Inserir raiz na fila (usando ponteiro como int - simplificação)
    queue_linked_enqueue(&queue, (DataType)(intptr_t)root);
    
    while (!queue_linked_is_empty(&queue)) {
        DataType temp;
        queue_linked_dequeue(&queue, &temp);
        TreeNode* current = (TreeNode*)(intptr_t)temp;
        
        printf("%d ", current->data);
        
        if (current->left != NULL) {
            queue_linked_enqueue(&queue, (DataType)(intptr_t)current->left);
        }
        if (current->right != NULL) {
            queue_linked_enqueue(&queue, (DataType)(intptr_t)current->right);
        }
    }
    
    queue_linked_clear(&queue);
}

// ========================================
// FUNÇÃO DE DEMONSTRAÇÃO
// ========================================

void demonstrate_binary_search_tree(void) {
    print_separator("DEMONSTRAÇÃO: ÁRVORE BINÁRIA DE BUSCA");
    
    BinarySearchTree bst;
    bst_init(&bst);
    
    printf("1. Árvore inicializada\n");
    printf("   Vazia? %s\n", bst_is_empty(&bst) ? "Sim" : "Não");
    printf("   Tamanho: %d\n", bst_size(&bst));
    
    printf("\n2. Inserindo elementos: 50, 30, 70, 20, 40, 60, 80\n");
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    int num_values = sizeof(values) / sizeof(values[0]);
    
    for (int i = 0; i < num_values; i++) {
        bst_insert(&bst, values[i]);
    }
    
    printf("   Tamanho: %d\n", bst_size(&bst));
    printf("   Altura: %d\n", bst_height(bst.root));
    
    printf("\n3. Percursos da árvore:\n");
    printf("   In-order (crescente): ");
    tree_inorder(bst.root);
    printf("\n");
    
    printf("   Pre-order: ");
    tree_preorder(bst.root);
    printf("\n");
    
    printf("   Post-order: ");
    tree_postorder(bst.root);
    printf("\n");
    
    printf("   Level-order: ");
    tree_level_order(bst.root);
    printf("\n");
    
    printf("\n4. Buscas na árvore:\n");
    int search_values[] = {40, 25, 80, 90};
    int num_searches = sizeof(search_values) / sizeof(search_values[0]);
    
    for (int i = 0; i < num_searches; i++) {
        bool found = bst_search(&bst, search_values[i]);
        printf("   Buscar %d: %s\n", search_values[i], found ? "Encontrado" : "Não encontrado");
    }
    
    printf("\n5. Encontrando mínimo e máximo:\n");
    TreeNode* min_node = bst_find_min(bst.root);
    TreeNode* max_node = bst_find_max(bst.root);
    if (min_node) printf("   Mínimo: %d\n", min_node->data);
    if (max_node) printf("   Máximo: %d\n", max_node->data);
    
    printf("\n6. Removendo elementos: 20, 30, 50\n");
    int remove_values[] = {20, 30, 50};
    int num_removes = sizeof(remove_values) / sizeof(remove_values[0]);
    
    for (int i = 0; i < num_removes; i++) {
        printf("   Removendo %d...\n", remove_values[i]);
        bst_remove(&bst, remove_values[i]);
        printf("   In-order: ");
        tree_inorder(bst.root);
        printf("\n");
    }
    
    printf("\n   Tamanho final: %d\n", bst_size(&bst));
    
    printf("\n7. Limpando a árvore\n");
    bst_clear(&bst);
    printf("   Vazia? %s\n", bst_is_empty(&bst) ? "Sim" : "Não");
}

