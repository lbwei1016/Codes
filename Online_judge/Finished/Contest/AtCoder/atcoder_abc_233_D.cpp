/*
***Range Sum***
    Description:
        求區間和為 K 的區間數量。
    Solution:
        定義前 i 項和為 Pi；題意為找出 Pj - Pi = K 的數量 (j > i)；
        技巧在於移項: Pi = Pj - K。
        維護一 hash table，依序存入 Pi (for all i<j)，並記錄值為 Pi 的數量。對於當前前綴和
        Pj，在 tablse 中搜尋 Pj - K 的數量，而所有其數量的和正是答案!
    O(n)
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, k;
    cin >> n >> k;
    ll pre = 0; // 當前前綴和
    ll sum = 0;
    unordered_map<ll, ll> mp;
    mp[0] = 1; // 邊界
    for (int i=1; i<=n; ++i) {
        ll x; cin >> x;
        pre += x;
        if (mp.count(pre-k)) {
            sum += mp[pre-k];
        }
        // pre += x;
        mp[pre]++;
    }
    cout << sum;
    return 0;
}