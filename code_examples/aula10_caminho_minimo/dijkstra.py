import heapq

def dijkstra(graph, start_node):
    distances = {node: float(\'inf\') for node in graph}
    distances[start_node] = 0
    priority_queue = [(0, start_node)]

    while priority_queue:
        current_distance, current_node = heapq.heappop(priority_queue)

        if current_distance > distances[current_node]:
            continue

        for neighbor, weight in graph[current_node].items():
            distance = current_distance + weight

            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(priority_queue, (distance, neighbor))

    return distances

# Exemplo de uso:
if __name__ == "__main__":
    print("\n--- Testando Algoritmo de Dijkstra ---")
    graph_dijkstra = {
        \'A\': {\'B\': 1, \'C\': 4},
        \'B\': {\'A\': 1, \'C\': 2, \'D\': 5},
        \'C\': {\'A\': 4, \'B\': 2, \'D\': 1},
        \'D\': {\'B\': 5, \'C\': 1}
    }
    start_node_dijkstra = \'A\'
    shortest_paths_dijkstra = dijkstra(graph_dijkstra, start_node_dijkstra)
    print(f"Caminhos mínimos a partir de {start_node_dijkstra}: {shortest_paths_dijkstra}")


