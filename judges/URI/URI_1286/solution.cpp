#include <bits/stdc++.h>

using namespace std;

#define MAX_V 310
#define MAX_ITENS 1010

int W[MAX_ITENS];
int V[MAX_ITENS];

// matriz de memoização
int memo[MAX_ITENS][MAX_V];

int knapsack(int i, int w) {

    if (i < 0 || w <= 0) return 0;

    if (memo[i][w] != -1) return memo[i][w];

    if (W[i] > w) return memo[i][w] = knapsack(i - 1, w);

    return memo[i][w] = max( knapsack(i - 1, w - W[i]) + V[i], knapsack(i - 1, w));
}

int main() {

    int n,p;
    while(cin >> n, n){
        memset(memo, -1, sizeof memo);
        memset(V, 0, sizeof V);
        memset(W, 0, sizeof W);
        cin >> p;
        int i = 0;
        while(i < n){
            cin >> V[i] >> W[i];
            i++;
        }
        cout << knapsack(n-1,p) << " min.\n";
    }
    
    return 0;    
}
