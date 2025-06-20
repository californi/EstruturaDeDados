def exemplo_complexidade(n):
    count = 0
    for i in range(n):
        for j in range(n):
            count += 1
    for k in range(n):
        count += 1
    return count

if __name__ == "__main__":
    print("\n--- Atividade Prática: Análise de Complexidade de Código ---")
    print("A complexidade de tempo da função `exemplo_complexidade(n)` é O(n^2).")


