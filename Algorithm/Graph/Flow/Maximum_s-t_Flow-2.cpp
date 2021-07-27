/*
***Maximum s-t Flow*** -- Dinic Algorithm

    Description:
        A enhanced version of Ford-Fulkerson and Edmond-Karp Algorithm

        Before each DFS search, BFS first to determine the distance 
        from "s" to each vertex, and then DFS according to their distance
        (start from the shortest). After a round of DFS, update the distance
        with BFS once again.

    O(E * V^2)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX_V = 100;
const int INF = 0x7fffffff;

struct edge { int to, cap, rev; };

vector<edge> G[MAX_V]; //adjacent list
int level[MAX_V]; //distance to s
int iter[MAX_V]; //record of visited or not

void add_edge(int u, int v, int cap) {
    G[u].push_back((edge){v, cap, G[v].size()});
    G[v].push_back((edge){u, 0, G[u].size()-1});
}
//find every vertex's current distance to s
void bfs(int s) {
    memset(level, -1, sizeof(level));
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while(!que.empty()) {
        int v = que.front(); que.pop();
        for(int i=0; i<G[v].size(); i++) {
            edge &e = G[v][i];
            //accessible and not visited yet
            if(e.cap > 0 && level[e.to] < 0) {
                level[e.to] = level[v] + 1;
                que.push(e.to);
            }
        }
    }
}
//adding augmenting path
int dfs(int v, int t, int f) {
    if(v == t) return f;
    for(int &i=iter[v]; i<G[v].size(); i++) {
        edge &e = G[v][i];
        if(e.cap > 0 && level[v] < level[e.to]) {
            int d = dfs(e.to, t, min(e.cap, f));
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
        bfs(s); //update distance

        //"t" is unreachable
        if(level[t] < 0) return flow;

        memset(iter, 0, sizeof(iter));
        int f;
        while((f = dfs(s, t, INF)) > 0) {
            flow += f;          
        }
    }
}
int main() {
    int s, t;

    return 0;
}