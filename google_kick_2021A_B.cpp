/*
    O(T * N^3)
*/
#include <bits/stdc++.h>
using namespace std;

const int MAX_R = 1e3+5;
struct P {
    int r, c;
    bool operator<(P p) const {
        return r==p.r ? c<p.c : r<p.r;
    }
};
int R, C;
int G[MAX_R][MAX_R];

// b is in row_seg
int len_valid(int a, int b) {
    int mx = max(a, b);
    int mn = min(a, b);
    // 長的必須是短的兩倍 (短的也可以在長的 seg 找到更短的)
    /*
        e.g. (5, 4)
            1. (4, 2)
            2. (2, 4): (短的在長的 seg 找到更短的)
    */
    return min(mx/2, mn) - 1 + (mn/2) - 1;
}

int solve() {
    // 座標, 該座標的合法最大 seg 長度 (列)
    map<P, vector<int> > row_seg;
    int cnt = 0;
    for (int i=0; i<R; ++i) {
        int len = 0;
        for (int j=0; j<=C; ++j) {
            // the end of a segment
            if (G[i][j] == 0) {
                for (int k=j-len; k<j; ++k) {
                    // 以座標 (i, j) 為端點，可以有兩種長度
                    int l1 = j - k, l2 = len-l1+1;
                    if (l1 > 1)
                        row_seg[P{i, k}].push_back(l1);
                    if (l2 > 1)
                        row_seg[P{i, k}].push_back(l2); 
                }
                len = 0;
            }
            else {
                ++len;
            }
        }
    }
    for (int i=0; i<C; ++i) {
        int len = 0;
        for (int j=0; j<=R; ++j) {
            if (G[j][i] == 0) {
                for (int k=j-len; k<j; ++k) {
                    int l1 = j - k, l2 = len-l1+1;
                    if (l1 > 1) {
                        auto it = row_seg.find(P{k, i});
                        if (it != row_seg.end()) {
                            for (auto x: it->second) {
                                cnt += len_valid(l1, x);
                            }
                        }
                    }
                    if (l2 > 1) {
                        auto it = row_seg.find(P{k, i});
                        if (it != row_seg.end()) {
                            for (auto x: it->second) {
                                cnt += len_valid(l2, x);
                            }
                        }
                    }
                }
                len = 0;
            }
            else {
                ++len;
            }
        }
    }
    return cnt;
}

int main() {
    int t;
    cin >> t;
    for (int i=1; i<=t; ++i) {
        cin >> R >> C;
        memset(G, 0, sizeof(G));
        for (int i=0; i<R; ++i) {
            for (int j=0; j<C; ++j) {
                cin >> G[i][j];
            }
        }
        printf("Case #%d: %d\n", i, solve());
    }    
}