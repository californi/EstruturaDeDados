import heapq

class PriorityQueueHeap:
    def __init__(self):
        self._queue = []
        self._counter = 0

    def insert(self, item, priority):
        heapq.heappush(self._queue, (priority, self._counter, item))
        self._counter += 1

    def extract_min(self):
        if self.is_empty():
            raise IndexError("Fila de Prioridade vazia: não é possível remover elementos.")
        return heapq.heappop(self._queue)[2]

    def peek_min(self):
        if self.is_empty():
            raise IndexError("Fila de Prioridade vazia: não há elementos para visualizar.")
        return self._queue[0][2]

    def is_empty(self):
        return not self._queue

    def size(self):
        return len(self._queue)

if __name__ == "__main__":
    print("\n--- Testando PriorityQueueHeap (Min-Heap) ---")
    pq_min = PriorityQueueHeap()
    pq_min.insert("Tarefa Baixa", 3)
    pq_min.insert("Tarefa Urgente", 1)
    pq_min.insert("Tarefa Média", 2)
    pq_min.insert("Tarefa Urgente 2", 1)

    print(f"Tamanho da fila: {pq_min.size()}")
    print(f"Próximo a ser processado: {pq_min.peek_min()}")
    print(f"Processando: {pq_min.extract_min()}")
    print(f"Processando: {pq_min.extract_min()}")
    print(f"Processando: {pq_min.extract_min()}")
    print(f"Fila de Prioridade vazia? {pq_min.is_empty()}")


