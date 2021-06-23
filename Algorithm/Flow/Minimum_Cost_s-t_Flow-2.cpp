/*
***Minimum_Cost_s-t_Flow*** --Dijkstra

    Prerequisite:
        First, define: h(v) is the shortest path from "s" to "v". ("h" is called "potential")
        As is known, h(v) <= h(u) + d(e) (s -> u -> v), where d(e) is the cost of e(v, u).
        Then, define: d'(e) = d(e) + h(u) - h(v) >= 0¡FSince new cost "d'(v)" is never 
        negative, Dijkstra become feasible in this problem.

        Moreover, since d'(e) = d(e) + h(u) - h(v), and h(u) - h(v) is a constant, 
        the new cost is equivalent to the old one.

    O(F * E * logV) or O(F * V^2)
*/
#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

typedef pair<int, int> P; //first: shortest path¡Fsecond: No. of vertices
struct edge { int to, cap, cost, rev; };
const int MAX_V = 10;
const int INF = 0x7fffffff;

int V;
vector<edge> G[MAX_V]; //adjacent list
int h[MAX_V]; //potential¡Fh[v] is the shortest path from "s" to "v"
int dist[MAX_V]; // modified shortest path¡Fdist[e.to] = dist[v] + e.cost + h[v] - h[e.to]
int prevv[MAX_V], preve[MAX_V]; //previous vertex and edge

void add_edge(int from, int to, int cap, int cost) {
    G[from].push_back((edge){to, cap, cost, G[to].size()});
    G[to].push_back((edge){from, 0, -cost, G[from].size()-1});
}

int min_cost(int s, int t, int f) {
    int res = 0;
    fill(h, h+V, 0);
    //Dijkstra
    while(f > 0) {
        priority_queue<P, vector<P>, greater<P> > pq;
        fill(dist, dist+V, INF);
        dist[s] = 0;
        pq.push(P(0, s));
        while(!pq.empty()) {
            P p = pq.top(); pq.pop();
            int v = p.second;
            if(dist[v] < p.first) continue;
            for(int i=0; i<G[v].size(); i++) {
                edge &e = G[v][i];
                if(e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
                    dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                    prevv[e.to] = v;
                    preve[e.to] = i;
                    pq.push(P(dist[e.to], e.to)); 
                }
            }
        }

        if(dist[t] == INF) {
            return -1;
        }

        /*
            update: dist[v] = £Ue_cost - h[v]
            => new_h[v] = h[v] + dist[v] = h[v] + (£Ue_cost - h[v]) = £Ue_cost = shortest distance
        */
        for(int v=0; v<V; v++) {
            h[v] += dist[v];
        }

        int d = f;
        for(int v=t; v!=s; v=prevv[v]) {
            d = min(d, G[prevv[v]][preve[v]].cap);
        }
        f -= d;
        res += d * h[t];
        for(int v=t; v!=s; v=prevv[v]) {
            edge &e = G[prevv[v]][preve[v]];
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