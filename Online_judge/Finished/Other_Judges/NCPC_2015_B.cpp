/*
***DFS***
*/
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 30+5;

struct edge { 
    int to, cost; 
};
int N, S, C;
int E;
vector<edge> G[MAX_N];
int Z;
int earn[MAX_N];
bool to[MAX_N];
bool visited[MAX_N];

void dfs(vector<edge> &v, int at, int coin) {
    visited[at] = true;
    if(coin == 0) return;

    for(int i=0; i<v.size(); i++) {
        edge &e = v[i];
        if(coin >= e.cost) {
            if(earn[at] + earn[e.to] > 2*e.cost) {
                coin = 1e9;
                earn[e.to] = -1e9;
                to[at] = false;
                to[e.to] = true;
                dfs(G[e.to], e.to, coin);
                //to[e.to] = false;
            }
            else if(!to[e.to]) {
                to[e.to] = true;
                dfs(G[e.to], e.to, coin-e.cost+earn[e.to]);
                to[e.to] = false;
            }
        }
    }
    return;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        for(int i=1; i<=N; i++) {
            G[i].clear();
        }
        memset(earn, 0, sizeof(earn));
        memset(visited, 0, sizeof(visited));
        memset(to, 0, sizeof(to));
        scanf("%d%d%d", &N, &S, &C);
        scanf("%d", &E);
        for(int i=0; i<E; i++) {
            int from, to, cost;
            scanf("%d%d%d", &from, &to, &cost);
            G[from].push_back((edge){to, cost});
            G[to].push_back((edge){from, cost});
        }
        scanf("%d", &Z);
        for(int i=0; i<Z; i++) {
            int p, c;
            scanf("%d%d", &p, &c);
            earn[p] = c;
        }
        C += earn[S];
        to[S] = true;
        dfs(G[S], S, C);
        int cnt = 0;
        for(int i=1; i<=N; i++) {
            if(!visited[i]) cnt++;
        }
        printf("%d\n", cnt);
    }
    
    return 0;
}
/*
case 1:
1
5 1 2
7
1 5 2
1 2 3
5 2 1
2 3 2
5 3 3
5 4 1
4 3 1
2
2 2
5 1
ans: 0

case 2:
1
4 1 2
3
1 2 1
2 3 9999
1 4 5
2
1 2
2 2
ans: 0
*/