/*
    Read Book again!!!
*/
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> Pii; //(dist, vertex)
const int MAX_N = 100+1;
const int MAX_M = 100+1;
const int MAX_V = MAX_N + MAX_M + 1;
const int INF = 1e9;
struct edge { int to, cap, cost, rev; };

int N, M;
int X[MAX_N], Y[MAX_N], B[MAX_N];
int P[MAX_M], Q[MAX_M], C[MAX_M];
int E[MAX_N][MAX_M]; //given plan

int g[MAX_V][MAX_V];
int _prev[MAX_V][MAX_V];
bool used[MAX_V];

void solve() {
    int V = N + M + 1;
    for(int i=0; i<V; i++) {
        fill(g[i], g[i]+V, INF);
    }
    for(int j=0; j<M; j++) {
        int sum = 0;
        for(int i=0; i<N; i++) {
            int cost = abs(X[i] - P[j]) + abs(Y[i] - Q[j]) + 1;
            g[i][N+j] = cost;
            if(E[i][j] > 0) g[N+j][i] = -cost;
            sum += E[i][j];
        }
        if(sum > 0) {
            g[N+M][N+j] = 0;
        }
        if(sum < C[j]) {
            g[N+j][N+M] = 0;
        }
    }

    for(int i=0; i<V; i++) {
        for(int j=0; j<V; j++) {
            _prev[i][j] = i;
        }
    }

    for(int k=0; k<V; k++) {
        for(int i=0; i<V; i++) {
            for(int j=0; j<V; j++) {

            }
        }
    }
}

int main() {
    
    return 0;
}