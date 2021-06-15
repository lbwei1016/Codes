/*
    Floyd-Warshall's algorithm: (DP)
        Find the shortest path for each vertex to the others.(multiple source)
    O(V * V * V)
*/
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_V 1000
#define INF 1e7

//the distance from "u" to "v"
int d[MAX_V][MAX_V]; 
int V;

//init the cost(distance) of e(u, v); if e(u, v) doesn't exist => INF, and d[u][u] = 0;
void init()
{
    for(int i=0; i<V; i++)
    {
        for(int j=0; j<V; j++)
        {
            if(i == j)
                d[i][j] = 0;
            else 
                d[i][j] = INF;
        }
    }
}
void floyd_warshall()
{
    for(int k=0; k<V; k++) //whether includes the (k-1)th vertex 
        for(int i=0; i<V; i++)
            for(int j=0; j<V; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

}
int main()
{
    init();
    //input V, cost[][]
    floyd_warshall();
    return 0;
}