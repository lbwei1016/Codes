#include <bits/stdc++.h>

using namespace std;

int m;
int num[10+1];
int dp[20][20];

void calc() {
    for(int j=0; j<20; j++) dp[0][j] = 1;
    for(int i=0; i<20; i++) dp[i][0] = 1;

    for(int i=1; i<20; i++) {
        for(int j=1; j<20; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
}

void solve(int x) {
    for(int i=0; i<20; i++) {
        int p = i-1 >= 0 ? dp[i-1][1] : 0;
        for(int j=i+1; j<20; j++) {
            int q = j-2 >= 0 ? dp[j-2][2] : 0;
            for(int k=j+1; k<20; k++) {
                int r = k-3 >= 0 ? dp[k-3][3] : 0;
                if(p+q+r == x) {
                    // if(p == 0) i--;
                    // if(q == 0) j--;
                    // if(r == 0) k--;
                    printf("%d%d%d\n", k, j, i);
                    return;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    calc();
    cin >> m;
    for(int i=0; i<m; i++)
        cin >> num[i];
    for(int i=0; i<m; i++)
        solve(num[i]);
    
    return 0;
}