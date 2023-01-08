#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int LEN = 105;
int dp[LEN][LEN];
string s;
 
int palin_subseq(int l, int r, string &s) {
    if (l > r) return  0;
    if (l == r) return 1;
    if (dp[l][r] != -1) return dp[l][r];

    if (s[l] == s[r]) 
        dp[l][r] = palin_subseq(l+1, r-1, s) + 2;
    else {
        dp[l][r-1] = palin_subseq(l, r-1, s); 
        dp[l+1][r] = palin_subseq(l+1, r, s);
        dp[l][r] = dp[l+1][r] > dp[l][r-1] ? dp[l+1][r] : dp[l][r-1];
    }
    return dp[l][r];
}

int main() {
    // io;
    // string s;
    cin >> s;
    memset(dp, -1, sizeof(dp));
    cout << palin_subseq(0, s.size()-1, s) << '\n';
    return 0;
}