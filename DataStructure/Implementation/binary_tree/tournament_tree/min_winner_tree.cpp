/*
***selection tree: winner tree***
    Description:
        Can be used for "external sorting".
    Note: It is a complete binary tree.

    build: O(n)
    sorting: O(n log n)
*/
#include <bits/stdc++.h>
#define LC(v) (2*(v))
#define RC(v) (2*(v)+1)
using namespace std;

const int N = 1<<3, INF = 1e9;
// i-indexed
struct winnerTree {
    int val, at;
} tree[2*N-1];

void pull(int v) {
    int k = tree[LC(v)].val < tree[RC(v)].val ? LC(v) : RC(v);
    tree[v] = tree[k];
}

void build(int v, vector<int> &data) {
    if (v >= N) {
        tree[v] = (winnerTree){data[v-N], v-N};
        return;
    }
    build(LC(v), data);
    build(RC(v), data);
    pull(v);
}

void sort(vector<int> &sorted) {
    for (int i=0; i<N; ++i) {
        sorted.push_back(tree[1].val);
        int id = tree[1].at + N;
        tree[id].val = INF;
        while (id > 0) {
            int v = id / 2;
            pull(v);
            id = v;
        }
    }
}

int main() {  
    vector<int> data = {56454, 21, -465, 1, 65, 21, 78889, -98};
    build(1, data);
    vector<int> sorted;
    sort(sorted);
    for (auto x: sorted) {
        cout << x << ' ';
    }
    return 0;
}