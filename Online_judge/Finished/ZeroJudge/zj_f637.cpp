#include <bits/stdc++.h>

using namespace std;

string s;
int N;
int res = 0;

int dfs(int from, int d, int r) {
    for(int i=from; i<s.size(); i++) {
        if(s[i] == '2') {
            d++;
            i = dfs(i+1, 0, r/2);
        } else {
            if(s[i] == '1') res += r * r;
            d++;
        }

        if(d == 4) return i;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    cin >> N;
    dfs(0, 0, N);
    cout << res << '\n';
    return 0;
}