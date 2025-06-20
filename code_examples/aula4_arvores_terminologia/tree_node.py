class TreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

# Exemplo de criação de uma árvore simples:
if __name__ == "__main__":
    print("\n--- Exemplo de Criação de Árvore Simples ---")
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)

    # Para visualizar a estrutura (apenas para demonstração, não é parte da classe TreeNode)
    print(f"Raiz: {root.data}")
    print(f"Filho esquerdo da raiz: {root.left.data}")
    print(f"Filho direito da raiz: {root.right.data}")
    print(f"Filho esquerdo de {root.left.data}: {root.left.left.data}")
    print(f"Filho direito de {root.left.data}: {root.left.right.data}")


