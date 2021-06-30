/*
***prefix-suffix sum***
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAX_N = 50000+5; 
int N, K;
int p[MAX_N];
ll lps[MAX_N], rps[MAX_N]; //left and right prefix sum

//[l, r]
int dfs(int L, int R, int k) {
    if(k == K) return 0;
    if(R - L < 2) return 0;
    ll d = 0;

    //update everytime
    lps[L] = 0;
    for(int i=L+1; i<=R-1; i++) {
        d += p[i-1];
        lps[i] = lps[i-1] + d;
    }
    d = 0;
    rps[R] = 0;
    for(int i=R-1; i>=L+1; i--) {
        d += p[i+1];
        rps[i] = rps[i+1] + d;
    }

    int cut = 0;
    ll mn = 1e18;
    for(int i=L+1; i<=R-1; i++) {
        if(abs(rps[i] - lps[i]) < mn) {
            mn = abs(rps[i] - lps[i]);
            cut = i;
        }
    }
    return p[cut] + dfs(L, cut-1, k+1) + dfs(cut+1, R, k+1);
}

int main() {
    scanf("%d%d", &N, &K);
    for(int i=1; i<=N; i++) {
        scanf("%d", &p[i]);
    }
    int ans = dfs(1, N, 0);
    printf("%d\n", ans);
    return 0;
}