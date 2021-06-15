/*
    TLE
*/
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int MAX_N = 2500+5;

vector<int> G[MAX_N]; //ad. list
bool used[MAX_N][MAX_N]; //edges
int n;
//int cnt;

// void dfs(int v, int dep, int prev) {
//     if(dep == 2) {
//         cnt++;
//         return;
//     }

//     //prev -> v -> to
//     for(int i=0; i<G[v].size(); i++) {
//         int to = G[v][i];
//         if(to > prev && !used[prev][to]) {
//             if(dep == 1)
//                 used[prev][to] = true;
//             dfs(to, dep+1, v);
//         }
//     }
// }

long solve(int v) {
    long res = 0;

    for(int i=0; i<G[v].size(); i++) {
        int to = G[v][i];
        for(int j=0; j<G[to].size(); j++) {
            int u = G[to][j];
            if(u > v && !used[v][u]) {
                res++;
                used[v][u] = true;
            }
        }
    }

    return res;
}

int main() {

    memset(used, 0, sizeof(used));
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        int d;
        scanf("%d", &d);
        G[i].resize(d);
        for(int j=0; j<d; j++) {
            scanf("%d", &G[i][j]);
        }
    }

    //cnt = 0;
    long res = 0;
    for(int i=1; i<n; i++) {
        res += solve(i);
    }

    printf("%d\n", res);
    
    return 0;
}