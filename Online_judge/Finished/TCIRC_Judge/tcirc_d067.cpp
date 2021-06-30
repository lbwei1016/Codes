/*
***DP*** 

    Solution:
        use two variables to store conditions instead of array
*/
#include <bits/stdc++.h>

using namespace std;

int N;
int pay;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int p = 0, pp = 0;
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> pay;
        pay = max(p, pp+pay);
        pp = p;
        p = pay;
    }
    cout << pay << '\n';
    return 0;
}