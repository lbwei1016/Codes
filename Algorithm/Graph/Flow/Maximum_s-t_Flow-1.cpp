/*
***Maximum s-t Flow*** -- Ford-Fulkerson Algorithm

    Description: 
        Keep searching for (DFS) augmenting pathes until no flow.

    O(F * E)
        F: Max flow
        E: number of edges
*/
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX_V = 100;
const int INF = 1e9;

struct edge { int to, cap, rev; };
vector<edge> G[MAX_V]; //adjacent list for graph
bool used[MAX_V]; //visited

void add_edge(int from, int to, int cap) {
    G[from].push_back((edge){to, cap, G[to].size()}); //(to, cap, rev)
    G[to].push_back((edge){from, 0, G[from].size()-1}); 
}

//search for augmenting path
int dfs(int v, int t, int f) {
    if(v == t) return f;
    used[v] = true; //visited, no loop is permitted, for it wastes cap.

    //traverse edges of "v"
    for(int i=0; i<G[v].size(); i++) {
        edge &e = G[v][i]; //G[v]'s i-th edge
        if(!used[e.to] && e.cap > 0) {
            int d = dfs(e.to, t, min(f, e.cap)); //flow to next vertex 
            if(d > 0) {
                e.cap -= d; //capacity left
                G[e.to][e.rev].cap += d; //the capacity for reverse flow
                return d;
            }
        }
    }
    return 0; //if no flow
}

int max_flow(int s, int t) {
    int flow = 0;
    while(true) {
        memset(used, 0, sizeof(used));
        int f = dfs(s, t, INF);
        if(f == 0)
            return flow;
        flow += f;
    }
}

int main() {
    int s, t;

    return 0;
}