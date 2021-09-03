/*
***DP / BIT*** (1080 . A.逆序數對) (tcirc_d064)
    Description:
        找出一序列中，符合 arr[i] > arr[j]: i<j 的數對數量 (逆序對)。
    Solution:
        利用 BIT 來儲存某一數字出現過的次數。
        query(x): 找出 <= x 的數目前有多少個
        update(x): x 出現的次數 +1
    O(n logn)
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5+2;
int n, arr[N], harr[N], k;
int bit[N];

void init() {
    memset(bit, 0, sizeof(bit));
}
// 先 hash，因為 arr[i] 可能很大
void __hash() {
    sort(harr, harr+n);
    k = unique(harr, harr+n) - harr;
    for(int i=0; i<n; ++i) {
        arr[i] = lower_bound(harr, harr+k, arr[i]) - harr + 1;
    }
}
void update(int i) {
    while(i <= k) {
        ++bit[i];
        i += i & -i;
    }
}
int query(int i) {
    int num = 0;
    while(i > 0) {
        num += bit[i];
        i -= i & -i;
    }
    return num;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt = 0;
    while(cin >> n && n) {
        init();
        for(int i=0; i<n; ++i) {
            cin >> arr[i];
            harr[i] = arr[i];
        }
        __hash();
        ll res = 0;
        for(int i=0; i<n; ++i) {
            res += i - query(arr[i]);
            update(arr[i]);
        }
        cout << "Case #" << ++cnt << ": " << res << '\n';
    }   
    return 0;
}