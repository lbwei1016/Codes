/*
***bit***
*/
#include <bits/stdc++.h>
using namespace std;

bool check(int n, int k) {
    // snap 一次就是加一 (1: ON; 0: OFF)；k 必須有連續 n 位低位元為 1 
    for(int i=0; i<n; ++i) {
        if(!(k & (1<<i))) return false;
    }
    return true;
}
int main() {
    int t, n, k;
    cin >> t;
    for(int i=1; i<=t; ++i) {
        cin >> n >> k;
        if(check(n, k)) printf("Case #%d: ON\n", i);
        else printf("Case #%d: OFF\n", i);
    }
    return 0;
}