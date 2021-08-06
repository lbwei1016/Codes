/*
***Graph***
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int n, mx;
int C[N];
map<int, int> rec;
vector<int> chl[N];

void dfs(int v) {
    mx = max(mx, ++rec[C[v]]); //每當撿取一新寶石時，檢查是否超過最大值
    for(int u : chl[v]) {
        dfs(u);
    }
    rec[C[v]]--; //backtracking
    return;
}

int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &C[i]);
    }
    for(int i=1; i<n; i++) {
        int s, t;
        scanf("%d%d", &s, &t);
        chl[s].push_back(t);
    }
    dfs(0);
    printf("%d\n", mx);
    return 0;
}