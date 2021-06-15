/*
    Dijkstra's algorithm: (Greedy)
        Find the shortest path from a single point to others, 
        through the selections of the nearest vertex.(single source)
    O(E * logV)

    note: This algorithm can only tackle graph without negative edges.
        reason: If negative edges exist, that means d[u] can be constantly
                decrease by going past the negative ones, which will result 
                in the loop keeping going.
*/
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX_V 1000
#define INF 1e7

typedef pair<int, int> pii;
typedef struct
{
    int to, cost;
}edge;

vector<edge> edges[MAX_V]; //recording the edges
int d[MAX_V]; //d[i] means the shortest distance from "start" to i
int V;

void dijkstra(int s)
{
    //first: d[v]; second: v
    //sorted by d[i] (first), and take the minimum one
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    fill(d, d+V, INF);
    d[s] = 0;
    pq.push(pii(0, s));

    while(!pq.empty())
    {
        pii p = pq.top(); pq.pop();
        int v = p.second;
        
        //not sure why below if-statement is needed???
        if(d[v] < p.first) continue;

        //edges[v].size() represents how many edges are adjacent to v
        for(int i=0; i<edges[v].size(); i++)
        {
            edge e = edges[v][i];
            if(d[e.to] > d[v] + e.cost)
            {
                d[e.to] = d[v] + e.cost;
                pq.push(pii(d[e.to], e.to));
            }
        }
    }
}
int main()
{
    //input edges[][], V
    dijkstra(0);
    return 0;
}