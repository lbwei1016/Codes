/*
***DP***
*/
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e5+5;
int N, T;
int n[MAX_N][2]; //two lucky numbers of each stage
int dp[MAX_N][2]; //dp[i][j]: go through stage "i" with one(j) of the two lucky numbers

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> T;
    for(int i=1; i<=N; i++) {
        cin >> n[i][0] >> n[i][1];
    }
    dp[1][0] = abs(T - n[1][0]); dp[1][1] = abs(T - n[1][1]);
    for(int i=2; i<=N; i++) {
        for(int j=0; j<2; j++) {
            dp[i][j] = min(abs(n[i-1][0]-n[i][j]) + dp[i-1][0], 
                            abs(n[i-1][1]-n[i][j]) + dp[i-1][1]);
        }
    }
    cout << min(dp[N][0], dp[N][1]) << '\n';
    return 0;
}