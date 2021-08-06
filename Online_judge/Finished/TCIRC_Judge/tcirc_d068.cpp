/*
***DP***
    Solution I:
        dp[i]: 選擇第 i 個監視器情況下的最低成本。
    Solution II :
        dp0[i]: 「不」選擇第 i 個監視器情況下的最低成本；
        dp1[i]:  選擇第 i 個監視器情況下的最低成本。
    
    O(N)
*/
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e5+5;
int N;
int dp[MAX_N], c[MAX_N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> c[i];
    }
    dp[0] = c[0], dp[1] = c[1], dp[2] = c[2] + min(c[1], c[0]);
    for(int i=3; i<N; i++) {
        dp[i] = c[i] + min(dp[i-1], min(dp[i-2], dp[i-3]));
    }
    cout << min(dp[N-1], dp[N-2]) << '\n';
    
    return 0;
}
/* Sol II:
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e5+5;
int N;
int dp0[MAX_N], dp1[MAX_N];
int c[MAX_N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> c[i];
    }
    dp0[0] = 1e9, dp0[1] = c[0];
    dp1[0] = c[0], dp1[1] = c[1];
    for(int i=2; i<N; i++) {
        dp0[i] = min(dp1[i-1], dp0[i-1]+c[i-1]);
        dp1[i] = c[i] + min(dp0[i-1], dp0[i-2]);
    }
    cout << min(dp0[N-1], dp1[N-1]) << '\n';
   
    
    return 0;
}
*/