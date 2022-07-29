/*
***Range MEX query*** -- Mo's Algorithm (+ SQRT decomposition)
    Description:
        輸出每個查詢區間 [l, r] 內最小沒出現過的非負整數；離線。
    Solution:
        題意是離線區間查詢，首先想到 Mo's。接著注意到給定序列的值可大至 1e9，
        值域相當大，但觀察後可以發現所有大於 N(序列長度)的值不可能是答案，因為
        即使 0 ~ (N-1) 都恰出現一次，答案也只能是 N；因此，極值降至 (N+1)。

        再來想想 Mo's: 
            我們要維護 "數字 x 出現幾次" 的陣列 S。
            首先設想 MEX 可以隨區間變動而 O(1) 更新。元素移出區間時，只需更新 S，
        並適時更新 MEX 即可；加入元素到區間時，卻沒有相應快速的方法可以更新 MEX
        ，於是隨區間變動更新 MEX 失敗。
            接著就是一次區間變動結束時再更新。由於值域縮小，利用分塊法的想法將
        [0, N+1] 分成數塊，依塊紀錄該塊內有多少數字出現過；如果從小往大看，答案就在
        第一個沒有被填滿的分塊內。所以我們要多維護一個陣列，紀錄每一塊出現了多少
        數字。
    Complexity:
        Mo's: O(n * sqrt(q))
        值域分塊: O(q * (n / sqrt(q))) = O(n * sqrt(q))
        Overall: O(n * sqrt(q))
    Note:
        這裡值域分塊的一塊大小與 Mo's 的塊大小相同。
        另外有離線線段樹和持久化線段樹的解法。
*/
#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

struct P {
    int l, r, id;
};

int K; // size of block
int BLK; // # of blocks
vector<int> sum; // 紀錄值域分塊，一塊所含的數字出現幾種
vector<int> cnt; // 紀錄當前區間甚麼數字出現幾次

void add(int val) {
    if (cnt[val]++ == 0) sum[val/K]++;
}

void del(int val) {
    if (--cnt[val] == 0) sum[val/K]--;
}

int query() {
    for (int i=0; i<BLK; ++i) {
        if (sum[i] < K) {
            int right = (i + 1) * K;
            for (int j=i*K; j<right; ++j) {
                if (!cnt[j]) return j;
            }
        }
    }
    return -1; // shouldn't occur
}

int main() {
    io;
    int n, m; cin >> n >> m;
    K = n / sqrt(m); BLK = n / K + (n % K != 0);
    sum.resize(BLK+5); cnt.resize(n+5);
    vector<int> v(n);
    vector<P> Q(m);
    for (int i=0; i<n; ++i) {
        cin >> v[i];
        if (v[i] > n) v[i] = n + 1;
    }
    for (int i=0; i<m; ++i) {
        int l, r; cin >> l >> r;
        --l; --r;
        Q[i] = {l, r, i};
    }
    sort(Q.begin(), Q.end(), [&](P p1, P p2) {
        int blk1 = p1.l / K, blk2 = p2.l / K;
        if (blk1 == blk2) return p1.r < p2.r;
        return p1.l < p2.l;
    });

    int L = 0, R = -1;
    vector<int> res(m);
    for (int i=0; i<m; ++i) {
        auto p = Q[i];
        while (R < p.r) add(v[++R]);
        while (R > p.r) del(v[R--]);
        while (L < p.l) del(v[L++]);
        while (L > p.l) add(v[--L]);
        res[p.id] = query();
    }

    for (auto x: res) cout << x << '\n';
    return 0;
}