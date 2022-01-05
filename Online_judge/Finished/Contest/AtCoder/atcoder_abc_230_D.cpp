#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
struct L { int l, r; } line[N];
int n, d;

// 依右邊界排序，而非左
inline bool cmp(L l1, L l2) {
    return l1.r == l2.r ? l1.l < l2.l : l1.r < l2.r;
}
int main() {
    scanf("%d %d", &n, &d);
    for(int i=0; i<n; ++i) {
        scanf("%d %d", &line[i].l, &line[i].r);
    }
    sort(line, line+n, cmp);
    int pre = line[0].r, cnt = 0;
    for(int i=1; i<n; ++i) {
        while(i<n && line[i].l<pre+d) ++i;
        ++cnt;
        if(i == n) break;
        pre = line[i].r;
        --i;
    }
    printf("%d\n", cnt);
    return 0;
}