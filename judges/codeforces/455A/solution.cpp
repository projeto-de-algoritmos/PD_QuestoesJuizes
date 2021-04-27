#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_V 100003
 
long long repeti[MAX_V];
int ja_calculei[MAX_V];
long long respostas[MAX_V];
 
long long dfs(long long u) {
    if(u<=0) return 0;
    if(ja_calculei[u]) return respostas[u];
    
    ja_calculei[u] = 1;
    
    return respostas[u] = max(dfs(u-1), repeti[u]*u + dfs(u-2));
}
 
int main(){
	memset(ja_calculei, 0, sizeof ja_calculei);
	memset(repeti, 0, sizeof repeti);
    long long n;
    cin >> n;
    while(n--){
        long long m;
        cin >> m;
        repeti[m]++;
    }
    cout << dfs(MAX_V-1) << endl;
	return 0;
}
