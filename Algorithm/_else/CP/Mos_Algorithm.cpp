/*
***Mo's Algorithm (Off-line)***
    Description:
        區間眾數。
    Solution:
        Mo's Algorithm 處理的是「區間問題」，使用的手法是排序和分塊；
        將要操作的整個序列平方分塊後，將要查詢的區間依左界排列，若左界
        落在同一分塊內，則依照右界排列。還要維護兩個指標，指向當前查詢
        的區間左右界。

        Mo's Algorithm 有效的原因在於「節省指標移動」:
            當兩區間的左界在同一區塊，左指標最多移動 K 次(K 是區塊
        大小)，就能由一查詢抵達另一查詢；而跨區間的查詢最大也只會跨
        越整個序列(N)，因此左指標最多移動 qK + N 次(注意，在同一區
        塊中左指標可能來回移動，因為在同一區塊內的排序依據是右界，但
        跨區塊移動則必往右)。
            因為在同一區塊中的右界是遞增的，所以最糟只會從序列最右
        移到最左(N)，而共有 N/K 塊，因此右指標最多移動 N^2/K 次。
        複雜度因此是 O(qK + N + N^2/K)；因為 K = N 無意義，因此複
        雜度又可寫成 O(qK + N^2/K)。依據算幾不等式，取 qK = N^2/K, 
        K = N/sqrt(q) 可使複雜度最小化，於是: O(N * sqrt(q))。
    O(q * log(q) + N * sqrt(q)) (N <= 1e5; q <= 1e6)
*/
#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

struct P {
    int l, r, id;
};

int main() {
    io;
    int n, m; cin >> n >> m;
    int K = n / sqrt(m); // 分塊大小，見頁首註解
    vector<int> v(n+1), tmp(n);
    vector<P> seg(m);
    for (int i=0; i<n; ++i) cin >> v[i];
    for (int i=0; i<m; ++i) {
        int l, r; cin >> l >> r;
        --l; --r;
        seg[i] = {l, r, i};
    }

    sort(seg.begin(), seg.end(), [&](P p1, P p2) {
        int blk1 = p1.l / K, blk2 = p2.l / K;
        if (blk1 == blk2) return p1.r < p2.r;
        else return p1.l < p2.l;
    });

    int L = 0, R = -1;
    vector<int> cnt(n+1); // x 出現幾次
    vector<int> ks(n+1); // 出現次數為 k 的數有幾種
    vector<pair<int, int>> res(m);
    int mx = 0;
    for (int i=0; i<m; ++i) {
        auto p = seg[i];
        while (R > p.r) {
            --ks[cnt[v[R]]];
            --cnt[v[R]];
            ++ks[cnt[v[R]]];
            if (ks[cnt[v[R]]+1] == 0 && mx == cnt[v[R]]+1) {
                mx = cnt[v[R]];
            }
            --R;
        }
        while (R < p.r) {
            ++R;
            --ks[cnt[v[R]]];
            ++cnt[v[R]];
            ++ks[cnt[v[R]]];
            if (cnt[v[R]] > mx) {
                mx = cnt[v[R]];
            }
        }
        while (L < p.l) {
            --ks[cnt[v[L]]];
            --cnt[v[L]];
            ++ks[cnt[v[L]]];
            if (ks[cnt[v[L]]+1] == 0 && mx == cnt[v[L]]+1) {
                mx = cnt[v[L]];
            }
            ++L;
        }
        while (L > p.l) {
            --L;
            --ks[cnt[v[L]]];
            ++cnt[v[L]];
            ++ks[cnt[v[L]]];
            if (cnt[v[L]] > mx) {
                mx = cnt[v[L]];
            }
        }
        res[p.id] = {mx, ks[mx]};
    }
    for (auto x: res) {
        cout << x.first << ' ' << x.second << '\n';
    }
    return 0;
}