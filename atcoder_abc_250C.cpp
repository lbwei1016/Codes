#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

int main() {
    // io;
    int N, Q;
    cin >> N >> Q;
    vector<int> who(N+1), pos(N+1);
    for (int i=1; i<=N; ++i) 
        who[i] = pos[i] = i;
    while (Q--) {
        int x;
        cin >> x;
        int x_at = pos[x];
        // if (x_at == N) x_at = 0;
        int nxt = x_at + 1;
        if (nxt > N) nxt = N-1;
        int nxt_who = who[nxt];
        pos[nxt_who] = x_at;
        pos[x] = nxt;
        who[x_at] = nxt_who;
        who[nxt] = x;
    }
    for (int i=1; i<=N; ++i) cout << who[i] << ' ';
    return 0;
}