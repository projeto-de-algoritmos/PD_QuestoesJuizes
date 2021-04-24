#include <bits/stdc++.h>

using namespace std;

long long int POSSIBILIDADES[200001][2];
vector<int> VALORES;
int N, CORRETAGEM;

//dAtual - É o dia atual
//compra - 0 se nao foi comprado, 1 se foi comprado
long long int calcula(int dAtual, int compra){
    long long int resultado;

    if(dAtual >= N) return 0;

    // Se já temos os valores apenas os retorna
    if(POSSIBILIDADES[dAtual][compra] != -1){
        return POSSIBILIDADES[dAtual][compra];
    } 

    // Se esta comprado: calcula a possibilidade se ele manteu a empresa / vendeu a empresa
    if(compra == 1){
        resultado = max(calcula(dAtual+1,1), calcula(dAtual+1, 0) + VALORES[dAtual]);
    
    }// Se não esta comprado: calcula se nao denovo / comprou a empresa agora 
    else {
        resultado = max(calcula(dAtual+1, 0), calcula(dAtual+1, 1) - (VALORES[dAtual] + CORRETAGEM));
    }
    return POSSIBILIDADES[dAtual][compra] = resultado;
}

int main() {  
    int aux;

    memset(POSSIBILIDADES, -1, sizeof(POSSIBILIDADES[0][0]) * 200001 * 2);

    cin >> N >> CORRETAGEM;

    for(int i = 0; i < N; i++){
        cin >> aux;
        VALORES.push_back(aux);
    }
    
    printf("%lld\n", calcula(0,0));

    return 0;
}