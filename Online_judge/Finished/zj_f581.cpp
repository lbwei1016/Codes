/*
***Binary Search***

    O() > O(M * logN)
*/
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 200000;
const int MAX_M = 20000;
int N, M;
int P[MAX_N], Q[MAX_M];
int ps[MAX_N];

void solve() {
    ps[0] = P[0];
    for(int i=0; i<N-1; i++) {
        ps[i+1] = ps[i] + P[i+1];
    }
    
    int *pos;
    pos = lower_bound(ps, ps+N, Q[0]);
    int prev = pos - ps;
    for(int i=1; i<M; i++) {
        pos = lower_bound(ps, ps+N, Q[i]+ps[prev]);
        if(pos == ps+N) {
            Q[i] -= ps[N-1];
            i--;
            continue;
        }
        prev = pos - ps;
    }
    printf("%d\n", (pos-ps+1) % N);
}

int main() {
    scanf("%d%d", &N, &M);
    for(int i=0; i<N; i++) {
        scanf("%d", &P[i]);
    }
    for(int i=0; i<M; i++) {
        scanf("%d", &Q[i]);
    }
    solve();
    
    return 0;
}