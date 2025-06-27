#ifndef TREE_H
#define TREE_H

#include "common.h"
#include "queue.h"
#include <stdint.h>

// Estrutura do nó da árvore binária
typedef struct TreeNode {
    DataType data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Estrutura da árvore binária de busca
typedef struct {
    TreeNode* root;
    int size;
} BinarySearchTree;

// Operações básicas da árvore
TreeNode* tree_create_node(DataType value);
void tree_destroy_node(TreeNode* node);

// Operações da árvore binária de busca
void bst_init(BinarySearchTree* bst);
bool bst_is_empty(BinarySearchTree* bst);
int bst_insert(BinarySearchTree* bst, DataType value);
int bst_remove(BinarySearchTree* bst, DataType value);
bool bst_search(BinarySearchTree* bst, DataType value);
TreeNode* bst_find_min(TreeNode* root);
TreeNode* bst_find_max(TreeNode* root);
int bst_size(BinarySearchTree* bst);
int bst_height(TreeNode* root);
void bst_clear(BinarySearchTree* bst);

// Percursos da árvore
void tree_inorder(TreeNode* root);
void tree_preorder(TreeNode* root);
void tree_postorder(TreeNode* root);
void tree_level_order(TreeNode* root);

// Funções auxiliares
TreeNode* bst_insert_recursive(TreeNode* root, DataType value);
TreeNode* bst_remove_recursive(TreeNode* root, DataType value);
TreeNode* bst_search_recursive(TreeNode* root, DataType value);
void tree_destroy_recursive(TreeNode* root);

// Função de demonstração
void demonstrate_binary_search_tree(void);

#endif // TREE_H

