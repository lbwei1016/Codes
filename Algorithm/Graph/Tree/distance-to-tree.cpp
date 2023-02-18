/*
***Tree***
    Description:
        Given the distances between N vertices of a tree, determine the structure
        of the tree. (Output the edges.)
    Solution:
        First, pick an arbitrary root. Then determine the ancestry relationships
        between any pair of vertices, by examining their distances to the root.
        Finally, use BFS to traverse all the vertices in the order of their depth.
    O(N^2)
*/
#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int N = 2505;
int dis[N][N];
unordered_set<int> par[N];

int main() {
    io;
    int n;
    cin >> n;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            cin >> dis[i][j];
        }
    }

    unordered_set<int> S;
    for (int i=0; i<n; ++i) {
        for (int j=i+1; j<n; ++j) {
            if (dis[i][j] == dis[i][0] - dis[j][0]) 
                par[i].insert(j);
            else if (dis[i][j] == dis[j][0] - dis[i][0])
                par[j].insert(i);
        }
        S.insert(i);
    }
    
    vector<pair<int, int>> res;
    queue<pair<int, int>> que;
    res.reserve(n - 1);
    que.push({0, 1});
    while (que.size()) {
        auto p = que.front(); que.pop();
        int v = p.first, dep = p.second;
        vector<int> toErase;
        for (auto &u: S) {
            if (par[u].size() == dep && par[u].count(v)) {
                res.push_back({v, u});
                que.push({u, dep + 1});
                toErase.push_back(u);
            }
        }
        for (auto &x: toErase) S.erase(x);
    }
    for (auto &p: res) cout << p.first + 1 << ' ' << p.second + 1 << '\n';
    return 0;
}