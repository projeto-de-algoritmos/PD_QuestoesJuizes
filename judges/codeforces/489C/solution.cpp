#include <bits/stdc++.h>
using namespace std;
 
int main(){
    
    // m -> quantidade de digitos
    // s -> soma de todos os digitos
    // t -> auxiliar para manipular digitos
    // i -> auxiliar nos loops
    int m, s, t, i;
    string maximum="", minimum="";
    scanf("%d %d", &m, &s);
 
    // Caso base
    if(s == 0)
    {
        if(m == 1) printf("0 0\n");
        else printf("-1 -1\n");
        return 0;
    }
 
    // Gerar os digitos que serao usados nos numeros
    // de tamanho minimo e maximo.
    for(i = 0; i < m; i++)
    {
        // A operacao de minimo serve para excluir
        // valores maiores do que um digito e pegar
        // os valores que resultarao na soma s.
        t = min(s, 9);
        // Convertendo o numero obtido para string
        maximum += t + '0';
        // Atualizando soma restante
        s -= t;
    }
 
    // Se nao for possivel gerar um numero que some ate s...
    if(s!=0)
    {
        printf("-1 -1\n");
        return 0;
    }
 
    // minimum eh o inverso do maximum
    minimum += maximum;
    reverse(minimum.begin(), minimum.end());

    // Itera procurando o primeiro digito diferente de zero.
    // A ideia eh de que o primeiro digito nunca pode ser nulo
    // (caso acontecesse teria menos digitos). Se o primeiro
    // digito nao for zero entao nada acontece.
    for(i = 0; minimum[i]=='0'; i++);
    minimum[i]--;
    minimum[0]++;

    // printando os numeros
    cout << minimum << " " << maximum << endl;

    return 0;
}
