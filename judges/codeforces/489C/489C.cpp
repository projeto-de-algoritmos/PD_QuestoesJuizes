#include <bits/stdc++.h>
//inspired by https://github.com/jackiehluo/practice/blob/master/codeforces/400s/489c-given-length-and-sum-of-digits.cpp
 
using namespace std;
 
int main(){
    
    int m, s, t, i;
    string maximum="", minimum="";
    scanf("%d %d", &m, &s);
 
    if(s == 0){
        if(m == 1) printf("0 0\n");
        else printf("-1 -1\n");
        return 0;
    }
 
    for(i = 0; i < m; i++){
        t = min(s, 9);
        maximum += t + '0';
        s -= t;
    }
 
    if(s!=0){
        printf("-1 -1\n");
        return 0;
    }
 
    minimum += maximum;
    reverse(minimum.begin(), minimum.end());
 
    for(i = 0; minimum[i]=='0'; i++);
    //increases the first '0' to '1' and then decreases the first number higher than '0' in '1'
    //if the first number is not a '0' nothing happens
    minimum[i]--;
    minimum[0]++;
    
    cout << minimum << " " << maximum << endl;
 
    return 0;
}
