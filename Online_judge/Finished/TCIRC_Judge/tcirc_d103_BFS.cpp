/*
***Graph***
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int n, mx_d, mx_step;
vector<int> chl[N];
int len[N], d[N], step[N];

int main() {
    scanf("%d", &n);
    for(int i=1; i<=n-1; i++) {
        int v, w;
        scanf("%d%d", &v, &w);
        chl[v].push_back(i);
        len[i] = w;
    }
    int head = 0;
    vector<int> que;
    que.push_back(0);
    while(head < que.size()) {
        int v = que[head++];
        for(int u : chl[v]) {
            d[u] = d[v] + len[u];
            step[u] = step[v] + 1;
            mx_d = max(mx_d, d[u]);
            mx_step = max(mx_step, step[u]);
            que.push_back(u);
        }
    }
    printf("%d\n%d\n", mx_d, mx_step);
    return 0;
}