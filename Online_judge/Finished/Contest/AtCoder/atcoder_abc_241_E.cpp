#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e5+5;
ll n, k, sum;
bool vis[N];

int main() {
    cin >> n >> k;
    vector<ll> A(n), seq;
    for (auto &x: A) {
        cin >> x;
    }    
    ll cycle = 0, c_num = 0, remain = 0;
    for (ll i=0; i<k; ++i) {
        ll r = sum  % n;
        if (vis[r]) {
            int at = 0;
            while (seq[at] != r) ++at;
            for (; at<seq.size(); ++at) {
                cycle += A[seq[at]];
                ++c_num;
            }
            // cycle += A[seq[at]];
            // ++c_num;
            remain = at - c_num;
            break;
        }
        sum += A[r];
        seq.push_back(r);
        vis[r] = true;
    }
    if (cycle != 0) {
        ll p = (k-remain) / c_num;
        sum += (p-1) * (cycle);
        for (ll i=0; i<k-p*c_num-remain; ++i) {
            sum += A[seq[remain+i]];
        }
    }
    
    cout << sum << '\n';
    return 0;
}