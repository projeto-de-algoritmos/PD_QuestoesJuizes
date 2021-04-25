#include <bits/stdc++.h>

using namespace std;

#define MAX_W 1000
#define MAX_V 1000
#define MAX_ITENS 1000

// pesos e valores
int W[MAX_ITENS];
int V[MAX_ITENS];

// matriz de memorização
int memo[MAX_W][MAX_V];

int knapsack(int i, int w) {

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

int main() {
    // Inicialização da matriz de memoização com -1
    
    int n,t, i = 0, num = 0;
    while(cin >> n >> t, n){
        memset(memo, -1, sizeof memo);
        memset(W, 0, sizeof W);
        memset(V, 0, sizeof V);
        num++;
        i = 0;
        while(i<n){
            cin >> W[i] >> V[i];
            i++;
        }   
        cout << "Instancia " << num << "\n"; 
        cout << knapsack(n-1,t) << endl;
        cout << endl;
    }    
    
    return 0;    
}
