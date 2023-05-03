/*
***Minimum weight matching***
    O(V^4)
*/
#include <iostream>
#include <vector>
#include <bitset>
#define io ios_base::sync_with_stdio(false), cin.tie(nullptr)
using namespace std;

const int N = 505, INF = 1e6 + 1;

int n;
int W[N][N];
vector<int> match_l(N, -1), match_r(N, -1);
vector<int> weight_l(N, -INF), weight_r(N, -INF);
bitset<N> vis_l, vis_r;

bool dfs(int u) {
    vis_l[u] = 1;
    for (int v=1; v<=n; ++v) {
        if (W[u][v] != weight_l[u] + weight_r[v]) continue;
        if (vis_r[v]) continue;
        vis_r[v] = 1;
        if (match_r[v] == -1 || dfs(match_r[v])) {
            match_l[u] = v;
            match_r[v] = u;
            return true;
        }
    }
    return false;
}

// modify vertex weights
void weight_update() {
    int eps = INF;
    for (int u=1; u<=n; ++u) {
        for (int v=1; v<=n; ++v) {
            if (vis_l[u] && !vis_r[v]) {
                eps = min(eps, weight_l[u] + weight_r[v] - W[u][v]);
            }
        }
    }

    for (int u=1; u<=n; ++u) {
        if (vis_l[u]) weight_l[u] -= eps;
        if (vis_r[u]) weight_r[u] += eps;
    }
}

int matching() {
    int tot_weight = 0;
    for (int u=1; u<=n; ++u) {
        if (match_l[u] == -1) {
            vis_l.reset(); vis_r.reset();

            while (!dfs(u)) {
                weight_update();
                vis_l.reset(); vis_r.reset();
            }
        }
    }
    for (int i=1; i<=n; ++i) {
        tot_weight += W[i][match_l[i]];
    }
    return tot_weight;
}


int main() {
    io;
    cin >> n;
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j) {
            cin >> W[i][j];
            W[i][j] = -W[i][j]; // finding the MIN, not MAX.
            weight_l[i] = max(weight_l[i], W[i][j]);
        }
        weight_r[i] = 0;
    }


    int res = matching();
    cout << -res << '\n';

    for (int u=1; u<=n; ++u) {
        cout << u - 1 << ' ' << match_l[u] - 1 << '\n';
    }

    return 0;
}

/*
5
7 4 8 12 6
17 89 45 32 63
127 25 74 35 32
121 487 65 12 70
15 98 45 789 65
*/