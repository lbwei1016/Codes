/*
***Recursion***
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX_N = 1e5;
int N, L;
ll p[MAX_N];
//以切割點編號進行遞迴 (因為是以切割點決定遞迴是否結束)
ll cut(int l, int r) {
    if(r-1 <= l) return 0; //沒有切割點了
    ll mid = (p[l] + p[r]) / 2; //找中點
    int m = lower_bound(p+l, p+r, mid) - p;
    //找距離終點近且編號小的
    if(p[m-1] - p[l] >= p[r] - p[m]) m--;
    return p[r] - p[l] + cut(l, m) + cut(m, r);
}

int main() {
    scanf("%d%d", &N, &L);
    for(int i=1; i<=N; i++) {
        scanf("%lld", &p[i]);
    }
    p[0] = 0, p[N+1] = L;
    printf("%lld\n", cut(0, N+1));
    return 0;
}