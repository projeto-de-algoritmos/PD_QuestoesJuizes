#include <bits/stdc++.h>
 
#define ll long long
#define prime 1000000000+7
#ifndef ONLINE_JUDGE
#define W(x) cerr << "\033[31m" << #x << " = " << x << "\033[0m" << "\n";
#else
#define W(x) 42;
#endif

using namespace std;
 
int n, m;
int ans[1000002];
// n -> numero de instancias
// m -> numero de tipos de blocos
// ans -> vetor utilizado na memoizacao
 
// OBJETIVO
// Para cada instancia, imprima o numero minimo de blocos
// necessarios para obter um bloco de comprimento m.
int main(){
    // Lendo o numero de instancias
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        int value;
        // value -> comprimento desejado pelo artista
        scanf("%d %d", &m, &value);
        // Inicializando um vetor com todos os comprimentos dos tipos
        int values[m];
        // Lendo os comprimentos de cada tipo
        for(int j = 0; j<m; ++j)
            scanf("%d", &values[j]);
        // Definindo comprimento "infinito" na memoizacao
        memset(ans, 999999, sizeof(ans));
        // O numero minimo de blocos para obter um comprimento 0 é 0
        ans[0] = 0;
        // Percorrendo todos os tipos de bloco
        for(int j = 0; j<m; ++j)
            // Para cada tipo j, percorrer do valor k do comprimento
            // de tipo j ate atingir um valor k desejado
            for(int k = values[j]; k<=value; k++)
                // Para calcular o comprimento minimo na posicao k,
                // eh preciso comparar o comprimento na posicao k com
                // o comprimento na posicao k sem o acrescimo do tipo j.
                // comprimento k -> ans[k]
                // comprimento k - tipo j -> ans[k-values[j]]
                // A ideia do +1 eh de acrescentar o tipo j nessa comparacao
                ans[k] = min(ans[k], ans[k-values[j]]+1);
        // Ao final de todas as iteracoes basta acessar
        // a posicao com o comprimento desejado (todas
        // as posicoes percorridas possuem valor minimo
        printf("%d\n", ans[value]);
    }
    return 0;
}
