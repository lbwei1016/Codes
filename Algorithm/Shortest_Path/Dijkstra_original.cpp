/*
    Dijkstra's algorithm: (Greedy)
        Find the shortest path from a single point to others, 
        through the selections of the nearest vertex.(single source)
    O(V * V)

    note: This algorithm can only tackle graph "without negative edges".
        reason: If negative edges exist, that means d[u] can be constantly
                decrease by going past the negative ones, which will result 
                in the loop keeping going.
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX_V 1000
#define INF 1e7

int cost[MAX_V][MAX_V]; //cost[i][j] means the cost from i to j
int d[MAX_V]; //d[i] means the shortest distance from "start" to i
int previ[MAX_V]; // prev[u] represents the previous vertex of u
bool used[MAX_V]; //whether a vertex is visited
int V;

void dijkstra(int s)
{
    fill(d, d+V, INF);
    fill(used, used+V, false);
    fill(previ, previ+V, -1);
    d[s] = 0;

    while(true)
    {
        int v = -1;
        //search from the closet (nearest to "start") vertex
        for(int u=0; u<V; u++)
            if(!used[u] && (v==-1 || d[u] < d[v]))
                v = u;
        
        //if no updates, break
        if(v == -1) break;
        used[v] = true;

        for(int u=0; u<V; u++)
        {
            //from v to every vertex
            if(d[u] > d[v] + cost[v][u]);
            {
                d[u] = d[v] + cost[v][u];
                previ[u] = v;
            }
        }
    }
}
//get the shortest path to t
vector<int> get_path(int t)
{
    vector<int> path;
    //backtrack the path through previ[]
    for(; t!=-1; t=previ[t]) path.push_back(t);
    reverse(path.begin(), path.end());
    return path; 
}
int main()
{
    //input cost[][], V
    dijkstra(0);
    return 0;
}