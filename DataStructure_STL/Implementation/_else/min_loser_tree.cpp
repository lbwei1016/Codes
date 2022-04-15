/*
***selection sort: min loser tree***
    Description:
        Similar to "winner tree".  
        However, nodes doesn't store "max value" which indicate "loser"; 
        instead, they store "the actual losers" of the matches.
        See https://www.tutorialspoint.com/tournament-trees-winner-trees-and-loser-trees-in-data-structure

    build: O(n)
    sorting: O(n log n)
*/
#include <bits/stdc++.h>
#define LC(V) (2*(v))
#define RC(v) (2*(v)+1)
using namespace std;

const int N = 1<<3, INF = 1e9;
// 1-indexed
struct loserTree {
    int val, at; // 
    int p_val, p_at; // value to be passed to parent (smaller)
} tree[2*N-1];

void build(int v, vector<int> &data) {
    if (v >= N) {
        tree[v] = {.val=data[v-N], .at=v-N, .p_val=data[v-N], .p_at=v-N};
        return;
    }
    build(LC(v), data);
    build(RC(v), data);
    // pass the smaller value to parent
    if (tree[LC(v)].p_val > tree[RC(v)].p_val) {
        tree[v].val = tree[LC(v)].p_val;
        tree[v].at = tree[LC(v)].p_at;
        tree[v].p_val = tree[RC(v)].p_val;
        tree[v].p_at = tree[RC(v)].p_at;
    }
    else {
        tree[v].val = tree[RC(v)].p_val;
        tree[v].at = tree[RC(v)].p_at;
        tree[v].p_val = tree[LC(v)].p_val;
        tree[v].p_at = tree[LC(v)].p_at;
    }
}

vector<int> sort() {
    vector<int> sorted;
    for (int i=0; i<N; ++i) {
        // tree[1].p_val is the final winner; we store the value to be passed
        sorted.push_back(tree[1].p_val);
        int id = tree[1].p_at + N;
        tree[id].val = tree[id].p_val = INF;
        while (id > 0) {
            int par = id / 2;
            // substitute and pass
            if (tree[id].p_val > tree[par].val) {
                tree[par].p_val = tree[par].val;
                tree[par].p_at = tree[par].at;
                tree[par].val = tree[id].p_val;
                tree[par].at = tree[id].p_at;
            }
            else {
                // pass directly
                tree[par].p_val = tree[id].p_val;
                tree[par].p_at = tree[id].p_at;
            }
            id = par;
        }
    }
    return sorted;
}

int main() {
    vector<int> data = {45, -8, -798, 10, 2, 65, 9, 778};
    build(1, data);
    auto v = sort();
    for (auto x: v) {
        cout << x << ' ';
    }    
    return 0;
}