/*
***Divide and Conquer***
    Description:
        Given n 3-tuples, each is of the form (x, y, z). For all i, find the 
        number of tuples such that xi < xj, yi < yj, and zi < zj, where i != j.
        Note that there may exist identical tuples, and xi may equal to xj (yi and
        yj, zi and zj) for all i != j.
    Solution:
        最麻煩的地方在於，兩個 tuple 的值可能一樣，尤其 xi = xj。若要使得 xi = xj 不
        被算到，需要從 "遞迴區間" 來著手；解決 yi = yj，merge 過程的判斷是 "v[j].y <= v[i].y"；
        解決 zi = zj，只要 BIT query 的值減一即可。
    Note:
        如果出現的值不可能相等，就簡單多了。
    O(nlog^2(n))
*/
#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int N = 1e5 + 5;
struct P {
    int x, y, z, id;
    bool operator<(const P &p) const {
        if (x == p.x) 
            return y == p.y ? z < p.z : y < p.y;
        else return x < p.x;
    }
};

vector<P> v(N);
vector<ll> res(N);

int bit[N];

void add(int i, int x) {
    while (i < N) {
        bit[i] += x;
        i += (i & -i);
    }
}

int query(int i) {
    int res = 0;
    while (i > 0) {
        res += bit[i];
        i -= (i & -i);
    }
    return res;
}

void dac(int l, int r) {
    // 若 x value 一樣，該區間直接忽略
    if (v[l].x == v[r - 1].x) return;
    int mid = (l + r) / 2, at = 0;
    // 找出距離 mid 最近的 "x 相等區間的邊界" (Divide and conquer 盡量切中間)
    // 若 x 值相同，必定會被歸在同一邊 (重要！！)
    for (int i = l + 1; i < r; ++i) {
        if (v[i].x != v[i - 1].x) 
            if (abs(i - mid) < abs(at - mid))
                at = i;
    }
    mid = at;
    dac(l, mid); dac(mid, r);
    vector<P> tmp;
    vector<int> op;
    tmp.reserve(r - l); op.reserve(mid - l);

    int i = l, j = mid;
    for (;v[i].y < v[j].y; ++i) {
        add(v[i].z, 1);
        op.push_back(v[i].z);
        tmp.push_back(v[i]);
    }
    for (;i < mid; ++i) {
        for (;j < r && v[j].y <= v[i].y; ++j) {
            res[v[j].id] += query(v[j].z - 1);
            tmp.push_back(v[j]);
        }
        add(v[i].z, 1);
        op.push_back(v[i].z);
        tmp.push_back(v[i]);
    }
    for (int k = l; k < j; ++k) v[k] = tmp[k - l];
    for (; j < r; ++j) res[v[j].id] += query(v[j].z - 1);
    for (auto &x: op) add(x, -1);
}

int main() {
    io;
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        x = N - x, y = N - y, z = N - z;
        v[i] = {x, y, z, i};
    }
    sort(v.begin(), v.begin() + n);
    dac(0, n);
    for (int i = 0; i < n; ++i) cout << res[i] << '\n';
    return 0;
}