def greedy_coin_change(amount, denominations):
    denominations.sort(reverse=True)
    result = {}
    for coin in denominations:
        while amount >= coin:
            result[coin] = result.get(coin, 0) + 1
            amount -= coin
    return result

if __name__ == "__main__":
    print("\n--- Testando Algoritmo Guloso (Troca de Moedas) ---")
    moedas = [25, 10, 5, 1]
    quantia = 67
    print(f"Troco para {quantia} com moedas {moedas}: {greedy_coin_change(quantia, moedas)}")

    moedas_nao_canonicas = [1, 5, 10, 12, 25]
    quantia_nao_canonicas = 29
    print(f"Troco para {quantia_nao_canonicas} com moedas {moedas_nao_canonicas}: {greedy_coin_change(quantia_nao_canonicas, moedas_nao_canonicas)}")


