/*
***TSP: Traveling Salesperson Problem*** 
    Solution:
        It's a NP-hard problem.The goal is to find a minimum cost to 
        visited all the vertices of a weighed-directed graph, and then 
        go back to where we starts (i.e. find a minimum cost Hamiltonian cycle).
    
    O(2^n*n^2)
*/
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 15;
const int INF = 1e9;

int n;
int d[MAX_N][MAX_N];

/*
    dp[S][v]: 
        The minimum cost to go from current vertex(v) to the rest unvisited
        vertices, and finally go back to where we start.
    (S: the set of visited vertices；v: current vertix)
    
    2022/10/14:
        dp[S][v] 代表 "在走過的點集合是 S (1 走過、0 還沒) 的情況下，
        以 v 當起點走完剩下點所需的 cost"。所以 dp[0][0] 代表 
        "還沒走過任何點，而從 0 出發走完所有點的 cost (還要走回來)。"

    Solution:
        dp[S][0] = 0
        dp[S][v] = min(dp[S][v], dp[S ∪ {u}][u] + d(v, u))

    note: 
        If the size of S is bigger, dp[S][v] can be smaller, for there
        are less vertices to go if S is big.
*/
int dp[1 << MAX_N][MAX_N];

void solve() {

    for(int S=0; S < 1<<n; S++)
        fill(dp[S], dp[S]+n, INF);
    dp[(1 << n) - 1][0] = 0; //where we start

    for(int S=(1<<n)-2; S>=0; S--) {
        for(int v=0; v<n; v++) {
            for(int u=0; u<n ;u++) {
                //if "u" isn't visited
                if(!(S >> u & 1)) {
                    //whether to go to "u" right now
                    //dp[S | (1 << u)][u] represents now is at vertex "u"
                    dp[S][v] = min(dp[S][v], dp[S | (1 << u)][u] + d[v][u]);
                }
            }
        }
    }
    printf("%d\n",dp[0][0]);
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> d[i][j];
        }
    }

    solve();

    return 0;
}

/*
會超時的遞迴版本: (O(n!) 搭配 memoization)
void tsp(int G, int at) {
    if (G == (1<<n) - 1) return;
    for (int i=0; i<n; ++i) {
        if (!((G >> i) & 1)) {
            if (dp[G | (1 << i)][i] == INF)
                tsp(G | (1 << i), i);
            dp[G][at] = min(dp[G][at], dp[G | (1 << i)][i] + d[at][i]);
        }
    }
}

tsp(0, 0); // call function
*/