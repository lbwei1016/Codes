/*
***Graph*** -- topology
    Solution:
        從終點逆著做 topological sort
*/
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 10005;
int n, E, out[MAX_N];
char st[20];
bitset<MAX_N> win;

int main() {
    while(scanf("%d%d", &n, &E) == 2) {
        if(n == 0) break;

        vector<int> pre[MAX_N];
        memset(out, 0, sizeof(out));
        win.reset();
        for(int i=0; i<E; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            pre[v].push_back(u);
            ++out[u];
        }
        win[n] = 0; // 0 是先手
        queue<int> que;
        que.push(n);
        while(!que.empty()) {
            int v = que.front(); que.pop();
            for(auto u : pre[v]) {
                if(win[v] == 0) win[u] = 1;
                if(--out[u] == 0) que.push(u);
            }
        }
        scanf("%s", st);
        if(!win[1] && st[1]=='i' || win[1] && st[1]=='o')
            puts("Mimi");
        else 
            puts("Moumou");
    }
    return 0;
}