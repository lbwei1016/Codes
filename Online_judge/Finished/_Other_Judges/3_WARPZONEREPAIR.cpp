#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5;
int n, arr[N], rev[N], cnt = 0;

void dfs(int i) {
    if(arr[i] == i) return;
    arr[rev[i]] = arr[i];
    rev[arr[i]] = rev[i];
    arr[i] = i;
    rev[i] = i;
    ++cnt;
    //dfs(rev[i]);
}
int main() {
    cin >> n;
    // int res = 0;
    for(int i=1; i<=n; ++i) {
        cin >> arr[i];
        rev[arr[i]] = i;
    }
    for(int i=1; i<=n; ++i) {
        if(arr[i] == i) continue;
        dfs(i);
    }
    cout << cnt << '\n';
    return 0;
}