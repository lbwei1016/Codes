/*
***Binary Search / Greedy***

    O(N * log N)
*/
#include <bits/stdc++.h>
using namespace std;

int N, K;
int p[50005];
bool enough(int r) {
    int prev = p[0], k = 1;
    for(int i=0; i<N; i++) {
        if(p[i] <= prev+r) continue;
        prev = p[i];
        if(++k > K) return false;
    }
    return true;
}
int main() {
    scanf("%d%d", &N, &K);
    for(int i=0; i<N; i++) {
        scanf("%d", &p[i]);
    }
    sort(p, p+N);
    int lb = -1, ub = p[N-1] - p[0];
    while(ub - lb > 1) {
        int mid = (lb+ub) / 2;
        if(enough(mid)) ub = mid;
        else lb = mid;
    }
    printf("%d\n", ub);
    return 0;
}
/* Jump
int len = 0, L = p[N-1] - p[0];
for(int jump=L/2; jump>0; jump>>=1) {
    while(len+jump<L && !enough(len+jump)) {
        len += jump;
    }
}
*/