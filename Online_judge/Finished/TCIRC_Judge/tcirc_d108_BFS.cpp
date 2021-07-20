/*
***Graph***
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5+5;
int n;
int p[N], deg0[N], deg1[N];
ll w[N], des[N];
ll len;

int main() {
    scanf("%d", &n);
    for(int i=2; i<=n; i++) {
        scanf("%d", &p[i]);
        deg0[p[i]]++;
        deg1[p[i]]++;
    }
    for(int i=2; i<=n; i++) {
        scanf("%lld", &w[i]);
    }
    queue<int> que;
    for(int i=1; i<=n; i++) {
        if(deg0[i] == 0)
            que.push(i);
    }
    while(true) {
        int v = que.front(); que.pop();
        des[v]++;
        if(v == 1) break;
        des[p[v]] += des[v];
        if(--deg0[p[v]] == 0)
            que.push(p[v]);
    }
    que = queue<int>();
    for(int i=1; i<=n; i++) {
        if(deg1[i] == 0)
            que.push(i);
    }
    while(true) {
        int v = que.front(); que.pop();
        if(v == 1) break;
        len += 2LL * des[v] * (ll)(n-des[v]) * w[v];
        if(--deg1[p[v]] == 0) 
            que.push(p[v]);
    }
    printf("%lld\n", len);
    return 0;
}