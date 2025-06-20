class QueueArray:
    def __init__(self):
        self.items = []

    def isEmpty(self):
        return self.items == []

    def enqueue(self, item):
        self.items.insert(0, item) # Inserção no início para simular o rear

    def dequeue(self):
        if self.isEmpty():
            raise IndexError("Fila vazia: não é possível remover elementos.")
        return self.items.pop() # Remoção do final para simular o front

    def peek(self):
        if self.isEmpty():
            raise IndexError("Fila vazia: não há elementos para visualizar.")
        return self.items[len(self.items)-1]

    def size(self):
        return len(self.items)

# Exemplo de uso:
if __name__ == "__main__":
    print("\n--- Testando QueueArray ---")
    q_array = QueueArray()
    print(f"Fila vazia? {q_array.isEmpty()}")
    q_array.enqueue("primeiro")
    q_array.enqueue("segundo")
    q_array.enqueue("terceiro")
    print(f"Tamanho da fila: {q_array.size()}")
    print(f"Elemento no front: {q_array.peek()}")
    print(f"Removendo: {q_array.dequeue()}")
    print(f"Elemento no front após dequeue: {q_array.peek()}")
    print(f"Fila vazia? {q_array.isEmpty()}")


