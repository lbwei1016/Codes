/*
***Maximum s-t Flow*** -- Ford-Fulkerson Algorithm

    Solution:
        Convert the description to a graph like:
            s -> Foods -> Cows -> Cows -> Drinks -> t
        where two "Cows" are identical, and then calculate
        the maximum flow from s to t (each edge's capacity is 1)
    
    O(Flow * (F+N+D))
        Flow : Maximum flow
        (F+N+D) : edges
*/
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX_N = 100+5;
const int MAX_F = 100+5;
const int MAX_D = 100+5;
const int MAX_V = 2 * MAX_N + MAX_F + MAX_D + 5;

int N, F, D;
bool likeF[MAX_N][MAX_F];
bool likeD[MAX_N][MAX_D];

struct edge { int to, cap, rev; };
vector<edge> G[MAX_V];
bool used[MAX_V];

void add_edge(int u, int v, int cap) {
    G[u].push_back((edge){v, cap, G[v].size()});
    G[v].push_back((edge){u, 0, G[u].size()-1});
}
int dfs(int v, int t, int f) {
    if(v == t) return f;
    used[v] = true;
    for(int i=0; i<G[v].size(); i++) {
        edge &e = G[v][i];
        if(!used[e.to] && e.cap > 0) {
            int d = dfs(e.to, t, min(f, e.cap));
            if(d > 0) {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}
int max_flow(int s, int t) {
    int flow = 0;
    while(true) {
        memset(used, 0, sizeof(used));
        int f = dfs(s, t, 1e9);
        if(f == 0) return flow;
        flow += f;
    }
    return flow;
}

void solve() {
    /*
        0 ~ N-1: cows on food side
        N ~ 2N-1: cows on drink side
        2N ~ 2N+F-1: food
        2N+F ~ 2N+F+D-1: drink
    */
    int s = 2*N + F + D;
    int t = s + 1;

    //connecting "s" and food
    for(int i=0; i<F; i++) {
        add_edge(s, 2*N+i, 1);
    }
    //connecting drink and "t"
    for(int i=0; i<D; i++) {
        add_edge(2*N+F+i, t, 1);
    }
    //connecting cow and cow
    for(int i=0; i<N; i++) {
        add_edge(i, i+N, 1);

        for(int j=0; j<F; j++) {
            if(likeF[i][j])
                add_edge(2*N+j, i, 1);
        }
        for(int j=0; j<D; j++) {
            if(likeD[i][j])
                add_edge(i+N, 2*N+F+j, 1);
        }
    }
    printf("%d\n", max_flow(s, t));
}

int main() {
    scanf("%d%d%d", &N, &F, &D);
    for(int i=0; i<N; i++) {
        int f, d;
        scanf("%d%d", &f, &d);
        for(int j=0; j<f; j++) {
            int food;
            scanf("%d", &food);
            likeF[i][food-1] = true;
        }
        for(int j=0; j<d; j++) {
            int drink;
            scanf("%d", &drink);
            likeD[i][drink-1] = true;
        }
    }
    solve();
    return 0;
}