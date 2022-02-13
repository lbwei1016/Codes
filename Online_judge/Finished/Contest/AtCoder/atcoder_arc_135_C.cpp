/*
***bitwise***
    Solution:
        計算和時，用單一 bit 的角度，因此複雜度降至 log(MAX_X)。
    O(n * log(MAX_X))
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;

    cin >> n;
    vector<int> v(n), bits(31);
    for(auto &x: v) {
        cin >> x;
        int k = x;
        for(int i=0; k>0; ++i, k>>=1) 
            bits[i] += (k & 1);
    }

    int64_t mx_sum = 0;
    for(auto x: v) mx_sum += x;
    for(auto x: v) {
        int64_t sum = 0, pow2 = 1;
        int cnt = 0;

        // XOR 影響的 bits
        for(int i=0; x>0; ++i, x>>=1, ++cnt, pow2<<=1) {
            int64_t num = abs(bits[i] - n*(x&1));
            sum += pow2 * num;
        }
        // 沒影響到的 bits 也要加進去 sum
        for(int i=cnt; bits[i]; ++i, pow2<<=1) {
            sum += pow2 * bits[i];
        }
        mx_sum = max(mx_sum, sum);
    }
    cout << mx_sum << '\n';
    return 0;
}