/*
***second shortest path: Dijkstra***
*/
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

#define MAX_E 100001
#define MAX_V 5001

typedef pair<int, int> pii;
struct edge
{
    int to, cost;
};
vector<edge> Es[MAX_E]; //Es[v] stores edges adjacent to v and their costs
int dist[MAX_V];  //shortest path
int dist2[MAX_V]; //second-shortest path
int E, V; //R, N

void dijkstra()
{
    fill(dist, dist+V+1, 1e9);
    fill(dist2, dist2+V+1, 1e9);

    // first: dist(2)[u]; second: u
    priority_queue<pii, vector<pii>, greater<pii> > pq; 
    dist[1] = 0; //start from 1 to N
    pq.push(pii(dist[1], 1));

    while(!pq.empty())
    {
        pii p = pq.top(); pq.pop();
        int d = p.first,
            v = p.second;
        //if no need to update (dist2[v] is already smaller), continue.
        if(d > dist2[v]) continue;

        int s = Es[v].size();
        for(int i=0; i<s; i++)
        {
            edge e = Es[v][i];
            int to_distance = d + e.cost;
            if(to_distance < dist[e.to])
            {
                swap(to_distance, dist[e.to]);
                pq.push(pii(dist[e.to], e.to));
            }
            if(to_distance < dist2[e.to] && to_distance > dist[e.to])
            {
                dist2[e.to] = to_distance;
                pq.push(pii(dist2[e.to], e.to));
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> V >> E;
    for(int i=0; i<E; i++)
    {
        int u, v, d;
        cin >> u >> v >> d;
        edge ev = {v, d}, //{.to = v, .cost = d}
             eu = {u, d};
        Es[u].push_back(ev);
        Es[v].push_back(eu);
    }
    
    dijkstra();
    int ans = dist2[V];
    cout << ans << '\n';
    return 0;
}