/*
***Graph*** -- Euler tour
    Description:
        Euler Tour 的應用:
        首先，在一棵樹上，如果把每一條樹邊想像成兩條邊一去一回，那麼在這棵樹上就有
        Euler tour。將一棵 N 個點的有根樹依照 DFS 順序編號，可以得到一 2(N-1) + 1
        = 2N - 1 長的序列 E。而原樹上的 LCA 問題可以轉變成求該序列的 RMQ 問題:
            如果點 v 在 E 中出現的位置是 Pv（任意一次都可以；取第一次），兩個點 a, 
            b 的 LCA 就會是 E 中 [Pa, Pb] 範圍內的最小值。
    Complexity:
        建構: O(n)
        查詢: O(log n)
    Note:
        這裡沒有做原本點編號和後來 tour 編號的對應，要小心。
*/
#include <bits/stdc++.h>
#define LC(v) (2*(v)+1)
#define RC(v) (2*(v)+2)
using namespace std;

const int MAXV = 100 + 5;
struct Edge {
    int to;
};
vector<Edge> G[MAXV];

vector<int> occur(MAXV);

void dfs(int at, int par, int &cnt, vector<int> &seq) {
    int id = cnt++;        
    seq.push_back(id);
    occur[at] = seq.size() - 1;
    for (auto u: G[at]) {
        if (u.to == par) continue;
        dfs(u.to, at, cnt, seq);
        seq.push_back(id);
    }
}

// For RMQ
vector<int> seg(2*MAXV);
void build(int v, int l, int r, vector<int> &arr) {
    if (r - l == 1) {
        seg[v] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(LC(v), l, mid, arr); build(RC(v), mid, r, arr);
    seg[v] = min(seg[LC(v)], seg[RC(v)]);
}
int query(int v, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return seg[v];
    int mid = (l + r) / 2;
    if (qr <= mid) return query(LC(v), l, mid, ql, qr);
    else if (ql >= mid) return query(RC(v), mid, r, ql, qr);
    else return min(query(LC(v), l, mid, ql, qr), query(RC(v), mid, r, ql, qr));
}
// End of RMQ

int main() {
    int V, E;
    cin >> V >> E;
    for (int i=0; i<E; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back({v});
        G[v].push_back({u});
    }

    // build
    vector<int> seq; seq.reserve(2*V);
    int cnt = 0;
    dfs(1, 0, cnt, seq); // 1 is root
    build(0, 0, seq.size(), seq);

    int Q; cin >> Q;
    while (Q--) {
        cout << "Query for LCA(u, v):\n";
        int u, v; cin >> u >> v;
        if (occur[u] > occur[v]) swap(u, v);
        cout << query(0, 0, seq.size(), occur[u], occur[v]+1)+1 << '\n';
    }
    return 0;
}
/*
Input: 
10 9
1 2
2 3
3 4
3 5
1 6
6 7
6 8
6 10
8 9
10
*/