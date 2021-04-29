#include <bits/stdc++.h>
 
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
 
#ifndef ONLINE_JUDGE
#define W(x) cerr << "\033[31m" << #x << " = " << x << "\033[0m" << "\n";
#else
#define W(x) 42;
#endif
 
using namespace std;
 
int t, k, a, b, prime = max;
ll fib[100100], ans[100100];
 
int main(){
	scanf("%d %d", &t, &k);
 
	for (int i = 0; i < 100100; ++i){
		if(i < k) fib[i] = 1;
		else{
			fib[i] = (fib[i-1]+fib[i-k])%prime;
		}
	}
 
	for (int i = 1; i < 100100; ++i){
		if(i == 1) ans[i] = fib[i];
		else ans[i] = (ans[i-1] + fib[i])%prime;
	}
 
	while(t--){
		scanf("%d %d", &a, &b);
 
		printf("%lld\n", (ans[b]+prime - ans[a-1])%prime);
	}
	
	return 0;
}
