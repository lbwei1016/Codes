/*
***Tree*** -- heavy-light decomposition
    Description:
        重鍊剖分。求樹上任兩點路徑中權重最大值；支援單點修改。(權重在點上)

        首先 DFS，找出所有點的最大 subtree (這裡放寬限制，最大的 subtree size 不必
        佔一半以上；只要最大就好)，標記 heavy edge。接著 decompose，重新編號所有點，
        使得同一重鍊上的點的編號連續。重新編號可以讓往後 segment tree 操作方便許多，
        因為 segment tree 擅長操作連續的區間；在此同時，為每個點紀錄所屬重鍊的 "head"
        (類似 DSU root 的概念)，而這是為了 query。

        Query 的時候，一次往上跳一條鍊，直到 a 和 b 在同一條鍊。
        Update 就只是一般線段樹單點更新而已。
        Segment tree 維護的是 disjoint 鍊上的最大值，利用 disjoint segments。
    Complexity:
        initialization: O(n),
        query: O((lg n)^2),
        update: O(lg n).
    Note:
        見 spoj_qtree.cpp。
*/
#include <bits/stdc++.h>
#define LC(v) (2*(v) + 1)
#define RC(v) (2*(v) + 2)
using namespace std;

const int N = 15 + 5;
vector<int> G[N], par, dep;
vector<int> heavy; // heavy[v]: v's next node on the heavy path
vector<int> head; // head[v]: the head of the path v is in

// 同一條鍊上，node 的 pos 會在一連續區間，以利線段樹操作
int cur_pos;
vector<int> pos; 

int n; // number of nodes
vector<int> arr;

int seg[2 * N];
void pull(int v);
void build(int v, int l, int r, vector<int> &arr);
void update(int v, int l, int r, int pos, int val);
int query(int v, int l, int r, int ql, int qr);

// calculate subtree sizes and mark the heavy paths
int dfs(int v) {
    int sz = 1;
    int mx_chlsz = 0;
    for (int u: G[v]) {
        if (u == par[v]) continue;
        par[u] = v;
        dep[u] = dep[v] + 1;
        int chlsz = dfs(u);
        sz += chlsz;
        if (chlsz > mx_chlsz) {
            mx_chlsz = chlsz;
            heavy[v] = u;
        }
    }
    return sz;
}

void decompose(int v, int hd) {
    head[v] = hd;
    pos[v] = cur_pos++;
    // 先把鍊找出來
    if (heavy[v] != -1) decompose(heavy[v], hd);
    for (int u: G[v]) {
        if (u != par[v] && u != heavy[v]) {
            // 脫離現有的鍊，自成一新鍊
            decompose(u, u);        
        }
    }
}

void init() {
    par = vector<int>(n);
    dep = vector<int>(n);
    heavy = vector<int>(n, -1);
    head = vector<int>(n);
    pos = vector<int>(n);
    cur_pos = 0;

    dfs(0);
    decompose(0, 0);

    // 將同一鍊上的 data 放在一起，才能用 segment tree 操作。
    vector<int> rearr(n);  
    for (int i=0; i<n; ++i) {
        rearr[pos[i]] = arr[i];
    }
    build(0, 0, n, rearr);
}

// Query for the maximum value on the path between two vertices a and b.
// Values are assigned to vertices.
int trquery(int a, int b) {
    int res = 0;
    while (head[a] != head[b]) {
        if (dep[head[a]] > dep[head[b]]) 
            swap(a, b);
        // segment tree query
        int cur_heavy_path_mx = query(0, 0, n, pos[head[b]], pos[b] + 1);
        res = max(res, cur_heavy_path_mx);
        b = par[head[b]]; // 往上跳一條鍊
    }

    // 最後判斷，當 a and b 在同一條鍊上的時候
    if (dep[a] > dep[b])
        swap(a, b);
    int last_heavy_path_mx = query(0, 0, n, pos[a], pos[b] + 1);
    res = max(res, last_heavy_path_mx);
    return res;
}

// segment tree
void pull(int v) {
    seg[v] = max(seg[LC(v)], seg[RC(v)]);
}

void build(int v, int l, int r, vector<int> &arr) {
    if (r - l == 1) {
        seg[v] = arr[l];
        return;
    }
    int mid = (r + l) / 2;
    build(LC(v), l, mid, arr);
    build(RC(v), mid, r, arr);
    pull(v);
}

void update(int v, int l, int r, int pos, int val) {
    if (r - l == 1) {
        seg[v] = val;
        return;
    }
    int mid = (r + l) /2;
    if (pos < mid) 
        update(LC(v), l, mid, pos, val);
    else 
        update(RC(v), mid, r, pos, val);
    pull(v);
}

int query(int v, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return seg[v];
    int mid = (r + l) / 2;
    if (qr <= mid) 
        return query(LC(v), l, mid, ql, qr);
    else if (ql >= mid) 
        return query(RC(v), mid, r, ql, qr);
    else {
        return max(query(LC(v), l, mid, ql, qr), query(RC(v), mid, r, ql, qr));
    }
}

int main() {
    cin >> n;
    arr.resize(n);
    // vertex weights
    for (int i=0; i<n; ++i) {
        cin >> arr[i];
    }
    // edges
    for (int i=0; i<n-1; ++i) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    init();

    int q; cin >> q;
    while (q--) {
        int a, b; cin >> a >> b;
        int res = trquery(a, b);
        printf("%d\n", res);
    }
    return 0;
}
/*
13
1 -3 2 6 4 3 9 7 2 0 -2 3 1
0 1
0 11
0 4
1 2
1 3
4 5
4 6
5 7
7 8
7 9
7 10
11 12
*/