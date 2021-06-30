/*
***DP***
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAX_N = 1e5+5;
int arr[MAX_N];
ll dp[MAX_N];
int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i=1; i<=N; i++) {
        cin >> arr[i];
    }
    dp[0] = 0; dp[1] = arr[1];
    for(int i=2; i<=N; i++) {
        dp[i] = min(dp[i-1], dp[i-2]) + (ll)arr[i];
    }
    cout << dp[N] << '\n';
    return 0;
}