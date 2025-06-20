class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.adj = {i: [] for i in range(vertices)}

    def add_edge(self, u, v, is_directed=False):
        self.adj[u].append(v)
        if not is_directed:
            self.adj[v].append(u)

# Exemplo de uso:
if __name__ == "__main__":
    print("\n--- Testando Representação de Grafo (Lista de Adjacência) ---")
    g = Graph(4) # Grafo com 4 vértices (0, 1, 2, 3)
    g.add_edge(0, 1)
    g.add_edge(0, 2)
    g.add_edge(1, 3)
    g.add_edge(2, 3)
    print(f"Lista de Adjacência: {g.adj}")


