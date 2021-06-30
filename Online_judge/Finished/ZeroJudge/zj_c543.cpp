/*
***DP*** --Pascal's Triangle
*/
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e5+2;
const int MOD = 1e9+7;
int dp[10][MAX_N];
string s;

void calc() {
    for(int i=1; i<10; i++) {
        dp[i][1] = 1;
    }
    for(int j=1; j<MAX_N; j++) {
        dp[9][j] = 1;
    }
    for(int i=8; i>0; i--) {
        for(int j=2; j<MAX_N; j++) {
            dp[i][j] = (dp[i+1][j] + dp[i][j-1]) % MOD;
        }
    }
}

void solve() {
    int d = s.size();
    int res = 0;
    for(int i=1; i<10; i++) {
        for(int j=1; j<d; j++) {
            res = (res + dp[i][j]) % MOD;
        }
    }
    int prev = s[0] - '0';
    for(int i=1; i<prev; i++) {
        res = (res + dp[i][d]) % MOD;
    }
    for(int j=d-1; j>0; j--) {
        int now = s[d-j] - '0';
        if(now >= prev){
            for(int i=prev; i<now; i++) {
                res = (res + dp[i][j]) % MOD;
            }
        }
        else {
            cout << res << '\n';
            return;
        }
        prev = now;
    }
    if(s[d-2] <= s[d-1]) res = (res + 1) % MOD;
    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    calc();

    while(cin >> s) {
        solve();
    }
    
    return 0;
}
/*
***My own version*** 98%
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e5+2;
const int MOD = 1e9+7;
int dp[10][MAX_N+2]; //dp[i][j]: [i * 10^j, (i+1) * 10^j)
string s;

void cal() {
    for(int i=1; i<10; i++) {
        dp[i][0] = 1;
    }
    for(int i=1; i<10; i++) {
        dp[i][1] = 10 - i;
    }
    for(int j=2; j<MAX_N; j++) {
        for(int i=1; i<10; i++) {
            if(i == 1) {
                for(int k=1; k<10; k++) {
                    dp[i][j] = (dp[i][j] + dp[k][j-1]) % MOD;
                }
            } else {
                dp[i][j] = (dp[i-1][j] - dp[i-1][j-1] + MOD) % MOD;
            }
        }
    }
    for(int j=0; j<MAX_N; j++) {
        for(int i=1; i<10; i++) {
            dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
        }
        dp[0][j+1] = (dp[0][j+1] + dp[9][j]) % MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cal();

    while(cin >> s) {
        int dig = s.length()-1;
        if(dig == 0) {
            cout << s << '\n';
            continue;
        }
        int prev = s[0] - '0';
        int res = dp[prev-1][dig];
        bool flag = true;
        for(int i=dig-1; i>=0; i--) {
            int now = s[dig-i] - '0';
            if(now >= prev) {
                res = (res + dp[now-1][i] - dp[prev-1][i]) % MOD;
            }
            else {
                flag = false;
                break;
            }
            prev = now;
        }
        if(flag && s[dig] >= s[dig-1]) res = (res + 1) % MOD;
        cout << res << '\n';
    }
    return 0;
}
*/