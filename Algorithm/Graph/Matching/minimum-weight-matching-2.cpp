/*
***Minimum Weight Matching***
    Credit: https://web.ntnu.edu.tw/~algo/Matching.html#8
    Note:
        原本嘗試用 DFS 找 augmenting path，但漏洞很多，故參考演算法筆記，改為 BFS。
        這個演算法是用來找 maximum weight，但為了找 min，所以權重加了負號。
    O(V^3)
*/
#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false), cin.tie(nullptr)
using namespace std;
using ll = long long;

const int N = 505;
const ll INF = 1e18 + 1;

int n;
ll W[N][N];
vector<int> match_l(N, -1), match_r(N, -1);
vector<ll> weight_l(N, -INF), weight_r(N, -INF);
bitset<N> vis_l, vis_r;

vector<ll> slack_r(N, INF), slack_from_l(N, -1);
vector<int> prev_l(N, -1);

queue<int> que;

inline void relax(int u) {
    for (int v=1; v<=n; ++v) {
        if (weight_l[u] + weight_r[v] - W[u][v] < slack_r[v]) {
            slack_r[v] = weight_l[u] + weight_r[v] - W[u][v];
            slack_from_l[v] = u;
        }
    }
}

// modify vertex weights
void weight_update() {
    ll eps = INF; 
    for (int u=1; u<=n; ++u) {
        if (!vis_r[u]) eps = min(eps, slack_r[u]);
    }

    for (int u=1; u<=n; ++u) {
        if (vis_l[u]) weight_l[u] -= eps;
        if (vis_r[u]) weight_r[u] += eps;
        else slack_r[u] -= eps;
    }
}

void augment(int u, int v) {
    while (u != -1) {
        int tmp = match_l[u];
        match_l[u] = v;
        match_r[v] = u;
        u = prev_l[u];
        v = tmp;
    }
}

// find augmenting path
bool bfs() {
    while (que.size()) {
        int u = que.front(); que.pop();
        for (int v=1; v<=n; ++v) {
            if (!vis_r[v] && weight_l[u] + weight_r[v] == W[u][v]) {
                vis_r[v] = 1;
                if (match_r[v] == -1) {
                    augment(u, v);
                    return true;
                }    

                int mv = match_r[v];
                assert(mv > 0);
                que.push(mv); prev_l[mv] = u;
                vis_l[mv] = 1; relax(mv);
            }
        }
    }
    return false;
}

// add new edge(s), after adjusting vertex weights
bool add_edge() {
    for (int v=1; v<=n; ++v) {
        if (!vis_r[v] && slack_r[v] == 0) {
            vis_r[v] = 1;
            if (match_r[v] == -1) {
                augment(slack_from_l[v], v);
                return true;
            }

            int mv = match_r[v];

            assert(mv > 0);
            que.push(mv); prev_l[mv] = slack_from_l[v];
            vis_l[mv] = 1; relax(mv);
        }
    }
    return false;
}

ll matching() {
    for (int u=1; u<=n; ++u) {
        vis_l.reset(); vis_r.reset();
        slack_r = vector<ll>(N, INF);
        prev_l = vector<int>(N, -1);
        while (que.size()) que.pop();

        que.push(u); prev_l[u] = -1;
        vis_l[u] = 1; relax(u);
        while (true) {
            if (bfs()) break;
            weight_update();
            if (add_edge()) break;
        }
    }

    ll tot_weight = 0;
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


    ll res = matching();
    cout << -res << '\n';

    for (int u=1; u<=n; ++u) {
        cout << u - 1 << ' ' << match_l[u] - 1 << '\n';
    }

    return 0;
}

/*
T1:
5
7 4 8 12 6
17 89 45 32 63
127 25 74 35 32
121 487 65 12 70
15 98 45 789 65

A1:
103
*/