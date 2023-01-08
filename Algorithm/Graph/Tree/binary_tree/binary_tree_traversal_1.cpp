/*
***Graph***
    preorder:
        DFS 進入順序: 4213657
    postorder:
        DFS 離開順序: 1325764
    inorder:
        左 -> 中 -> 右: 1234567

         4
       /   \
      2     6
     / \   / \
    1   3 5   7

    Note:
        下方的實作方式並不明確，因 "G[]" 存的是無向圖，且並無左右概念。
        (於是假設先接到的子節點在左邊)
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 10;
vector<int> pre_n, post_n, in_n;
vector<int> G[N];

void preorder(int v, int par) {
    pre_n.push_back(v);
    for (auto u: G[v]) {
        if (u == par) continue;
        preorder(u, v);
    }
}

void postorder(int v, int par) {
    for (auto u: G[v]) {
        if (u == par) continue;
        postorder(u, v);
    }
    post_n.push_back(v);
}

void inorder(int v, int par) {
    bool left_fin = false;
    for (auto u: G[v]) {
        if (u == par) continue;
        inorder(u, v);
        if (!left_fin) in_n.push_back(v);
        left_fin = true;
    }
    if (G[v].size() == 1)
        in_n.push_back(v);
}

void print(vector<int> &v) {
    for (auto x: v) cout << x << ' ';
    cout << '\n';
}

int main() {
    int V; cin >> V;
    for (int i=0; i<V-1; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    } 

    preorder(4, 0);
    postorder(4, 0);
    inorder(4, 0);

    print(pre_n);
    print(post_n);
    print(in_n);

    return 0;
}
/*
7
1 2
2 3
2 4
4 6
5 6
6 7
*/