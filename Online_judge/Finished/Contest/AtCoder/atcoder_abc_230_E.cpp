/*
***Math*** (*)
    Description:
        Find sum(from i to n)([N/i])
    O(sqrt(n))
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll N, res;

int main() {
    cin >> N;
    ll pre = N;
    res = N;
    // i-1 代表現在的商，i=N/pre 代表下一個商
    for(ll i=2; pre!=1; i=N/pre + 1) {
        // 商 * 個數
        res += (i-1) * (pre - N/i);
        pre = N / i;
    }
    cout << res << '\n';
    return 0;
}