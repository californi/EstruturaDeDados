#ifndef GRAPH_H
#define GRAPH_H

#include "common.h"
#include "queue.h"
#include "stack.h"

#define MAX_VERTICES 100

// Estrutura para representação por matriz de adjacência
typedef struct {
    int matrix[MAX_VERTICES][MAX_VERTICES];
    int num_vertices;
    bool is_directed;
} GraphMatrix;

// Estrutura para nó da lista de adjacência
typedef struct AdjNode {
    int vertex;
    int weight;
    struct AdjNode* next;
} AdjNode;

// Estrutura para representação por lista de adjacência
typedef struct {
    AdjNode* adj_list[MAX_VERTICES];
    int num_vertices;
    bool is_directed;
} GraphList;

// Operações do grafo com matriz
void graph_matrix_init(GraphMatrix* graph, int num_vertices, bool is_directed);
int graph_matrix_add_edge(GraphMatrix* graph, int src, int dest, int weight);
int graph_matrix_remove_edge(GraphMatrix* graph, int src, int dest);
bool graph_matrix_has_edge(GraphMatrix* graph, int src, int dest);
void graph_matrix_print(GraphMatrix* graph);

// Operações do grafo com lista
void graph_list_init(GraphList* graph, int num_vertices, bool is_directed);
int graph_list_add_edge(GraphList* graph, int src, int dest, int weight);
int graph_list_remove_edge(GraphList* graph, int src, int dest);
bool graph_list_has_edge(GraphList* graph, int src, int dest);
void graph_list_print(GraphList* graph);
void graph_list_clear(GraphList* graph);

// Algoritmos de busca
void graph_bfs(GraphMatrix* graph, int start_vertex);
void graph_dfs(GraphMatrix* graph, int start_vertex);
void graph_dfs_recursive(GraphMatrix* graph, int vertex, bool visited[]);

// Algoritmos de caminho mínimo (básico)
void graph_dijkstra(GraphMatrix* graph, int start_vertex);

// Funções auxiliares
AdjNode* create_adj_node(int vertex, int weight);
void print_path(int parent[], int vertex);

// Funções de demonstração
void demonstrate_graph_matrix(void);
void demonstrate_graph_list(void);
void demonstrate_graph_algorithms(void);

#endif // GRAPH_H

