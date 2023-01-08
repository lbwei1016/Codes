/*
    Prim's algorithm: (Greedy)
        Find the Minimum Spanning Tree(MST), 
        through the selections of the nearest vertex to the "current tree".
    O(V * V)

    note: Prim's is similar to Dijkstra's, with the some notable differences:
        1. Dijkstra's searches for the nearest vertex to the previous "vertex", while
           Prim's searches for the nearest vertex to the "current tree(MST)".
        2. Dijkstra's chooses "a particular" vertex as the beginning of "one" "shortest path tree", while
           Prim's chooses "any" vertex as the root of the only "MST(s)".(sometimes MST is not unique)
        3. Dijkstra's "cannot" handle graph with "negative edges", while
           Prim's "can".
*/
#include <iostream>

using namespace std;

#define MAX_V 100
#define INF 1e9

int cost[MAX_V][MAX_V]; //cost[u][v]: the cost of e(u, v)
int mincost[MAX_V]; //minicost[u]: the minimun cost from current tree to u
bool used[MAX_V]; //whether u is contained by current tree
int V;

int prim()
{
    for(int i=0; i<V; i++)
    {
        mincost[i] = INF;
        used[i] = false;
    }

    //choose "0" as the root of MST
    mincost[0] = 0;

    int res = 0;

    while(true)
    {
        int v = -1;
        //searching for the nearest vertex to the current tree
        for(int u=0; u<V; u++)
        {
            if(!used[u] && (v==-1 || mincost[u] < mincost[v]))
                v = u;
        }
        //if v isn't updated
        if(v == -1) break;
        //v is added to the current tree
        used[v] = true;
        //add to the total cost of MST
        res += mincost[v];

        for(int u=0; u<V; u++)
        {
            mincost[u] = min(mincost[u], cost[v][u]);
        }
    }
    return res;
}
int main()
{
    //input V, cost[][]
    int ans = prim();
    return 0;
}