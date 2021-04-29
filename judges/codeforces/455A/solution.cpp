#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_V 100003
 
// histograma
long long repeti[MAX_V];
// para obter um melhor desempenho foi
// criado 2 vetores para a memoizacao
int ja_calculei[MAX_V];
long long respostas[MAX_V];
 
long long dfs(long long u) {
    // u -> posicao no vetor
    if(u<=0) return 0;
    if(ja_calculei[u]) return respostas[u];
    ja_calculei[u] = 1;
    
    // Essa eh a linha mais importante de todo o algoritmo, alem de memorizar
    // as respostas, eh calculado o maximo entre remover a posicao anterior,
    // remover a posicao atual e remover a posicao posterior (o codigo comeca do
    // ultimo elemento do vetor e por isso chama dfs nas posicoes u-1 e u-2).
    // A resposta retornada sera a da posicao MAX_V-1 que ira possuir o maximo
    // calculado apos comparar com todas as demais operacoes nao repetidas
    return respostas[u] = max(dfs(u-1), repeti[u]*u + dfs(u-2));
}
 
int main(){
    // Inicializando vetores de memoizacao. Nessa questao nao era necessario
    // esses memset, dado que os vetores foram criados globalmente e, nas
    // arquiteturas e compiladores usados pelo codeforces, vetores declarados
    // globalmente sao declarados zerados (preferi escrever esse comentario ao
    // inves de remover os memset a titulo de curiosidade)
	memset(ja_calculei, 0, sizeof ja_calculei);
	memset(repeti, 0, sizeof repeti);
    // n -> quantos numeros tem a sequencia
    long long n;
    cin >> n;
    while(n--){
        // m -> numero da sequencia
        long long m;
        cin >> m;
        // Ao inves de armazenar os valores da sequencia, esse histograma
        // fornece em O(1) quantos elementos iguais estao na sequencia
        repeti[m]++;
    }
    // Exibe um inteiro com o numero de pontos maximo que Alex pode obter
    cout << dfs(MAX_V-1) << endl;
	return 0;
}
