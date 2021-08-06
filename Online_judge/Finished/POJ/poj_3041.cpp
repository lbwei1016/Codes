/*
***Bipartite Matching***
    Solution: Find Maximum matching

    O(V * E) -> O(N * K)
*/
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int MAX_N = 500+5;
const int MAX_K = 10000+5;

int N, K, V;
int R[MAX_K], C[MAX_K];
vector<int> G[2 * MAX_N]; //0 ~ N-1: R；N ~ 2*N-1: C
int match[2* MAX_N];
bool used[2 * MAX_N];

void add_edge(int r, int c) {
    G[r].push_back(c);
    G[c].push_back(r);
}

bool dfs(int v) {
    used[v] = true;
    for(int i=0; i<G[v].size(); i++) {
        int u = G[v][i], w = match[u];
        if(w < 0 || !used[w] && dfs(w)) {
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    return false;
}

int bipartite_matching() {
    int res = 0;
    memset(match, -1, sizeof(match));
    for(int v=0; v<V; v++) {
        if(match[v] < 0) {
            memset(used, 0, sizeof(used));
            if(dfs(v)) {
                res++;
            }
        }
    }
    return res;
}

void solve() {
    V = N * 2;
    for(int i=0; i<K; i++) {
        add_edge(R[i]-1, N + C[i]-1);
    }
    printf("%d\n", bipartite_matching());
}

int main() {
    scanf("%d%d", &N, &K);
    for(int i=0; i<K; i++) {
        scanf("%d%d", &R[i], &C[i]);
    }
    solve();
    
    return 0;
}