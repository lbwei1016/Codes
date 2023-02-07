/*
***Range sum query*** -- offline (without BIT or segment tree)
    Solution:
        將問題轉化為二維偏序。重點在於，merge 時，只有左邊要加值、只有
        右邊要 query (因為其他情形在 subtask 就計算過了)。

        Assign value 改成加上與前次值的差 (實作方便很多)。
    O(nlogn)
*/
#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int N = 2e5 + 5, INF = 1e9 + 5;
struct P {
    ll pos, x;
};

vector<P> v(3 * N);
vector<ll> res(N), val(N);

void dac(int l, int r) {
    if (r - l <= 1) return;
    int mid = (l + r) / 2;
    dac(l, mid); dac(mid, r);
    vector<P> tmp; tmp.reserve(r - l);
    
    int j = mid;
    ll sum = 0;
    for (int i = l; i < mid; ++i) {
        while (j < r && v[j].pos < v[i].pos) {
            if (abs(v[j].x) >= INF) {
                int sign = v[j].x > 0 ? 1 : -1;
                res[abs(v[j].x) - INF] += sign * sum;
            }
            tmp.push_back(v[j++]);
        }
        if (abs(v[i].x) < INF) {
            sum += v[i].x;
        }
        tmp.push_back(v[i]);
    }
    for (int i = l; i < j; ++i) v[i] = tmp[i - l];
    while (j < r) {
        if (abs(v[j].x) >= INF) {
            int sign = v[j].x > 0 ? 1 : -1;
            res[abs(v[j].x) - INF] += sign * sum;
        }
        ++j;
    }
}

int main() {
    io;
    int n, q;
    cin >> n >> q;
    int at = 0;
    while (at < n) {
        cin >> val[at];
        v[at] = P{at, val[at]};
        at++;
    }

    int qcnt = 0;
    for (int i = 0; i < q; ++i) {
        int op; cin >> op;
        if (op == 1) {
            int pos, x; cin >> pos >> x;
            --pos;
            v[at++] = P{pos, x - val[pos]};
            val[pos] = x;
        }
        else {
            int a, b; cin >> a >> b;
            --a; --b;
            v[at++] = P{a - 1, -(INF + qcnt)};
            v[at++] = P{b, INF + qcnt++};
        }
    }
    dac(0, at);
    for (int i = 0; i < qcnt; ++i) cout << res[i] << '\n';
    return 0;
}
/*
8 4
3 2 4 5 1 1 5 3
2 1 4
2 5 6
1 3 2
2 1 4
---------
14
2
11
*/