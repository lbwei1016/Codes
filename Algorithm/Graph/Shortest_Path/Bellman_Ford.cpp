/*
    Bellman-Ford's algorithm:
        Find the shortest path from a single point to others.(single source)
    Note:
        Bellman-Ford 關注的是"邊"，而以 heap 優化的 Dijkstra 關注的
        則是"點"。
    O(V * E)
*/
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_E 1000
#define MAX_V 1000
#define INF 1e7

typedef struct 
{
    int from, to, cost;
} edge;

edge es[MAX_E];
int d[MAX_V];
int E, V;

//to find out the shortest path from "s" to each v(vertex)
//return whether there is a negative loop; if yes, return false
bool bellman_ford(int s)
{
    fill(d, d+V, INF);
    d[s] = 0;
    int cnt_v = 0;
    
    //keep checking for shortest path
    while(true)
    {
        bool update = false;
        cnt_v++;
        for(int i=0; i<E; i++)
        {
            edge e = es[i];
            /*
                1. "from" != INF, which means "from" is previously accessible
                2. "to" > "from" + "cost" means e[i] is the shorter path 
            */
            if(d[e.from] != INF && d[e.to] > d[e.from] + d[e.cost])
            {
                d[e.to] = d[e.from] + d[e.cost]; //apply to the shorter path
                update = true;
                /*
                    If there isn't a negative loop, while(true){} will only
                    be executed "V-1" times; so, if cnt_v = V, then the loop
                    must exists.
                */
                if(cnt_v == V) return false;
            }
        }
        //when no shorter path can be applied, break
        if(!update) break;
    }
    return true;
}
//a similar way to find out whether a negative loop exists
bool find_negative_loop() {
    for(int i=0; i<V; i++) {
        for(int j=0; j<E; j++) {
            edge &e = es[j];
            if(d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
            }

            if(j == V-1) return true;
        }
    }
    return false;
}

int main()
{
    //input es[], E, V
    if(bellman_ford(0))
        cout << d[V-1] << '\n';
    else
        cout << "Negative loop exists\n";
    return 0;
}