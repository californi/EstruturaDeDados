class StackArray:
    def __init__(self):
        self.items = []

    def isEmpty(self):
        return self.items == []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        if self.isEmpty():
            raise IndexError("Pilha vazia: não é possível remover elementos.")
        return self.items.pop()

    def peek(self):
        if self.isEmpty():
            raise IndexError("Pilha vazia: não há elementos para visualizar.")
        return self.items[len(self.items)-1]

    def size(self):
        return len(self.items)

# Exemplo de uso:
if __name__ == "__main__":
    print("\n--- Testando StackArray ---")
    s_array = StackArray()
    print(f"Pilha vazia? {s_array.isEmpty()}")
    s_array.push(10)
    s_array.push(20)
    s_array.push(30)
    print(f"Tamanho da pilha: {s_array.size()}")
    print(f"Elemento no topo: {s_array.peek()}")
    print(f"Removendo: {s_array.pop()}")
    print(f"Elemento no topo após pop: {s_array.peek()}")
    print(f"Pilha vazia? {s_array.isEmpty()}")


