#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n;
string G[N];

int main() {
    cin >> n;
    for (int i=0; i<n; ++i) cin >> G[i];
    bool ans = false;
    for (int i=0, cnt; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            if (i+5 < n) {
                cnt = 0;
                for (int k=0; k<6; ++k) 
                    if (G[i+k][j] == '#') ++cnt;
                if (cnt >= 4) {
                    ans = true;
                    break;
                }
            }
            if (j+5 < n) {
                cnt = 0;
                for (int k=0; k<6; ++k) 
                    if (G[i][j+k] == '#') ++cnt;
                if (cnt >= 4) {
                    ans = true;
                    break;
                }
            }
            if (i+5 < n && j+5 < n) {
                cnt = 0;
                for (int k=0; k<6; ++k) 
                    if (G[i+k][j+k] == '#') ++cnt;
                if (cnt >= 4) {
                    ans = true;
                    break;
                }
            }
            if (0 <= i-5 && j+5 < n) {
                cnt = 0;
                for (int k=0; k<6; ++k) 
                    if (G[i-k][j+k] == '#') ++cnt;
                if (cnt >= 4) {
                    ans = true;
                    break;
                }
            }
        }
    }
    if (ans) puts("Yes");
    else puts("No");
    return 0;
}