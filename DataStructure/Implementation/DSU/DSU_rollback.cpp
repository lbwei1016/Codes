/*
***DSU*** -- with rollback
    Description:
        Use an array to store "original roots" of united DSUs.
    Note:
        DON'T do path compression, since this would alter the original 
        roots of DSUs, resulting in "rollback" failure. (original roots
        cannot be restored)
    Space Complexity:
        O(k); k: number of unions carried out
*/
#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int N = 2e5+5;
int p[N];
int dsus; // # of disjoint sets
int now; // # of unions having been carried out
vector<int> ch; // check point
vector<int> pre_p; // previous parent

int find(int x) {
    if (p[x] == x) return x;
    return find(p[x]);
}

bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (rand() % 2) swap(x, y);
    p[y] = x;
    pre_p.push_back(y);
    --dsus;
    return true;
}

void rollback(int t) {
    for (int i=now; i>t; --i) {
        int y = pre_p.back(); pre_p.pop_back();
        p[y] = y;
        dsus++;
    }
}

int main() {
    io;
    int n, m;
    cin >> n >> m;
    for (int i=1; i<=n; ++i) p[i] = i;
    dsus = n;
    while (m--) {
        string s;
        cin >> s;
        if (s == "union") {
            int u, v;
            cin >> u >> v;
            now += unite(u, v);
            cout << dsus << '\n';
        }
        else if (s == "persistent") {
            ch.push_back(now);
        }
        else {
            rollback(ch.back()); now = ch.back();
            ch.pop_back();
            cout << dsus << '\n';
        }   
    }
    return 0;
}