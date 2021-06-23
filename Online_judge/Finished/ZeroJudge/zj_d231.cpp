#include <bits/stdc++.h>

using namespace std;

string s1, s2;

string sub[51][51];
int dp[51][51];

void solve() {
    for(int i=0; i<s1.size(); i++) {
        for(int j=0; j<s2.size(); j++) {
            if(s1[i] == s2[j]) {
                dp[i+1][j+1] = dp[i][j] + 1;
                sub[i+1][j+1] = sub[i][j] + s1[i];
            }
            else {
                if(dp[i+1][j] > dp[i][j+1]) {
                    dp[i+1][j+1] = dp[i+1][j];
                    sub[i+1][j+1] = sub[i+1][j];
                }
                else {
                    dp[i+1][j+1] = dp[i][j+1];
                    sub[i+1][j+1] = sub[i][j+1];
                }
            }
        }
    }
    if(sub[s1.size()][s2.size()] == "")
        cout << "E\n";
    else
        cout << sub[s1.size()][s2.size()] + "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s1 >> s2;
    solve();
    
    return 0;
}