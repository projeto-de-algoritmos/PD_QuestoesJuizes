#include <bits/stdc++.h>

// Conjunto de definicoes muito uteis para ganhar tempo nas maratonas
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vs vector<string>
#define vl vector<ll>
#define vc vector<char>
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second
#define pi 3.14159265359
#define oo 1e9
#define max 1e9+7
 
// Esse daqui eh um truque bem bacana e util. Ajuda a debugar o codigo
// rapidamente, evitando perder tempo apagando os prints adicionados, ja
// que o juiz online vai ignorar os prints gracas ao ifndef. Outra coisa
// bacana eh a cor que ajuda a diferenciar dos prints padroes.
#ifndef ONLINE_JUDGE
#define W(x) cerr << "\033[31m" << #x << " = " << x << "\033[0m" << "\n";
#else
#define W(x) 42;
#endif
 
using namespace std;
 
//  t -> numero de casos de teste
//  k -> tamanho dos grupos
//  a, b -> flores
//  prime -> primo definido na propria questao
int t, k, a, b, prime = max;
// fib -> vetor de memoizacao (o nome dele eh fib porque a programacao dinamica
// parece muito com uma formula de finonacci)
// ans -> vetor que vai armazenar as repostas do problema
ll fib[100100], ans[100100];
 
int main()
{
    scanf("%d %d", &t, &k);
    // t e k sao sempre menores que 10^5 (esses 100 a mais sao so pra evitar dor
    // de cabeca caso o autor do problema tenha deixado algum erro passar nos
    // casos de teste) e, por conta disso, podemos precomputar todas as
    // respostas da questao previamente.
    for (int i = 0; i < 100100; ++i)
    {
        // As folhas brancas so podem ser comidas em grupos de k elementos,
        // sendo assim, so existe uma combinacao possivel para valores menores
        // do que k.
        if(i < k) fib[i] = 1;
        // Aqui esta o pulo do gato, fib[i] nada mais eh do que o fib
        // anterior acrescido de folhas vermelhas mais o fib[i-k] que
        // tem o acrescimo das folhas com k combinacoes.
        // Para ficar mais claro:
        // fib[i-1] -> esse aparece novamente com a unica diferenca de que foram
        // somados novas folhas vermelhas (R) a combinacao
        // fib[i-k] -> mesma ideia do de cima com a diferenca que ao inves de
        // somar 1 folha vermelha em cada, eh somado k folhas brancas em cada
        // grupo.
        else fib[i] = (fib[i-1]+fib[i-k])%prime;
    }
    // O loop anterior ja contem toda a logica essencial para resolver o
    // problema, esse loop a seguir eh responsavel por fazer a soma de
    // todas as solucoes para que, quando for a hora de calcular as
    // combinacoes de um intervalo, seja possivel calcular em O(1).
    for (int i = 1; i < 100100; ++i)
    {
        if(i == 1) ans[i] = fib[i];
        else ans[i] = (ans[i-1] + fib[i])%prime;
    }
    while(t--)
    {
        // Lendo o intervalo
        scanf("%d %d", &a, &b);
        // Calculando as quantidades de combinacoes dentro do intervalo em O(1).
        // O motivo de usar ans[a-1] eh porque ans[a] esta incluso no intervalo
        printf("%lld\n", (ans[b]+prime - ans[a-1])%prime);
    }
    return 0;
}
