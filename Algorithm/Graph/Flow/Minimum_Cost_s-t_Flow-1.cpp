/*
***Minimum_Cost_s-t_Flow*** --Bellman-Ford

    Why Bellman-Ford? That is because while calculating flows, "reverse"
    edges are adopted(whose cost are negative values), which means "negative"
    edges occurs, we cannot use "Dijkstra".

    However, with the concept of "Potential", Dijkstra is fine as well!

    O(F * V * E)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge{ int to, cap, cost, rev; };
const int MAX_V = 10;
const int INF = 0x7fffffff;

int V;
vector<edge> G[MAX_V]; //adjacent list
int dist[MAX_V]; //shortest path(i.e. minimum cost)
int prevv[MAX_V], preve[MAX_V]; //previous vertex, previous edge

void add_edge(int from , int to, int cap, int cost) {
    G[from].push_back((edge){to, cap, cost, G[to].size()});
    G[to].push_back((edge){from, 0, -cost, G[from].size()-1}); //rev
}

//calculating the minimum cost from "s" to "t" with flow "f"
int min_cost(int s, int t, int f) {
    int res = 0;
    //Bellman-Ford for shortest pathes
    while(f > 0) {
        fill(dist, dist+V, INF); //init before every flow
        dist[s] = 0; //every flow starts from "s"
        bool update = true;
        while(update) {
            update = false;
            for(int v=0; v<V; v++) {
                if(dist[v] == INF) continue;
                for(int i=0; i<G[v].size() ;i++) {
                    edge &e = G[v][i];
                    if(e.cap > 0 && dist[e.to] > dist[v] + e.cost) {
                        dist[e.to] = dist[v] + e.cost;
                        prevv[e.to] = v;
                        preve[e.to] = i; //record the index
                        update = true;
                    }
                }
            }
        }
        //no flows anymore, but "f" hasn't yet been fulfilled
        if(dist[t] == INF) {
            return -1;
        }

        int d = f;
        //backtrack the shortest path determined above, and flow maximally
        for(int v=t; v!=s; v=prevv[v]) {
            d = min(d, G[prevv[v]][preve[v]].cap);
        }
        //the amount "d" has flowed
        f -= d;
        res += d * dist[t];
        for(int v=t; v!=s; v=prevv[v]) {
            edge &e = G[prevv[v]][preve[v]];
            //the amount "d" has flowed
            e.cap -= d;
            G[v][e.rev].cap += d;
        }
    }
    return res;
}

int main() {

    cin >> V; //include s, t
    int from, to, cap, cost;
    while(cin >> from >> to >> cap >> cost) {
        if(cap == 0)
            break;
        add_edge(from, to, cap, cost);
    }
    int f;
    cin >> f;
    cout << min_cost(0, 4, f) << '\n';
    
    return 0;
}
/*
    input:
        5
        0 1 10 2
        0 2 2 4
        1 2 6 6
        1 3 6 2
        2 4 5 2
        3 2 3 3
        3 4 8 6
        0 0 0 0
        9
*/