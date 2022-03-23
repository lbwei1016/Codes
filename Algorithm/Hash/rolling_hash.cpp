/*
***Hash***
    Decription:
        Refer to 建中 Hash_Greedy 講義.
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7, Base = 257;

int solve(string::iterator begin, string::iterator end) {
    int n = end - begin, r = n;
    int64_t pre_hash = 0, suf_hash = 0, p = 1;
    deque<char> pre, suf;

    if(n == 0) return 0;

    for(int i=0; i<n/2; ++i) {
        pre.push_back(*(begin + i));
        suf.push_front(*(end - i - 1));
        // rolling hash is here
        pre_hash = (pre_hash + int64_t(*(begin + i)) * p) % MOD;
        suf_hash = (suf_hash * Base + int64_t(*(end - i - 1))) % MOD;
        p = p * Base % MOD;

        // 即使 hash 值相同，仍檢查字串是否相同 (避免碰撞但沒偵測到)
        if(pre_hash == suf_hash && pre == suf) {
            r = i + 1;
            break;
        }
    }
    if(r == n) return 1;
    return 2 + solve(begin + r, end - r);
}
int main() {
    string s;
    cin >> s;
    cout << solve(s.begin(), s.end()) << '\n';
    return 0;
}