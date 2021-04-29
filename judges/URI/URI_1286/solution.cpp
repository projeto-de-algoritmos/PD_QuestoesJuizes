#include <bits/stdc++.h>

using namespace std;

#define MAX_V 310
#define MAX_ITENS 1010

// pesos e valores
int W[MAX_ITENS];
int V[MAX_ITENS];

// matriz de memoização
int memo[MAX_ITENS][MAX_V];

int knapsack(int i, int w)
{
    // Caso o item não exista ou não mais caiba na mochila
    // nenhum valor será agregado
    if (i < 0 || w <= 0) return 0;

    // Caso este estado já tenha sido resolvido
    if (memo[i][w] != -1) return memo[i][w];

    // Caso o item estoure a capacidade da mochila
    // O item não será carregado
    if (W[i] > w) return memo[i][w] = knapsack(i - 1, w);

    // Caso contrário o valor ótimo será o maior valor entre a decisão
    // de não carregar o item e carregar o item
    return memo[i][w] = max(max(knapsack(i, w - W[i]) + V[i], knapsack(i - 1, w - W[i]) + V[i]), knapsack(i - 1, w));
}

int main()
{
    // n -> numero pedidos
    // p -> numero maximo de pizzas
    int n,p;
    // Lendo quantidade de pedidos, se a
    // quantidade for zero o programa acaba
    while(cin >> n, n){
        // Inicializando memoizacao com "infinito"
        memset(memo, -1, sizeof memo);
        // Zerando pesos e valores
        memset(V, 0, sizeof V);
        memset(W, 0, sizeof W);
        // Lendo numero maximo de pizzas
        cin >> p;
        // Lendo pedidos
        int i = 0;
        while(i < n){
            // V[i] -> tempo total para o pedido ser entregue (valor)
            // W[i] -> quantidade de pizzas do pedido (peso)
            cin >> V[i] >> W[i];
            i++;
        }
        // Valor inteiro que determina o tempo que o
        // entregador levara para entregar as pizzas
        cout << knapsack(n-1, p) << " min.\n";
    }
    return 0;
}
