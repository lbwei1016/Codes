/*
***Union and Find*** 
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int n, k;
int mx = 0, mn = 1e9;
int a[N], p[N]; //parent
multiset<int> ms; //紀錄目前所有長度組合

int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}
void unite(int x, int y) {
    int r1 = find(x);
    int r2 = find(y);
    if(r1 == r2) return;

    ms.erase(ms.find(-p[r1]));
    ms.erase(ms.find(-p[r2]));
    if(p[r1] < p[r2]) {
        p[r1] += p[r2];
        p[r2] = r1;
        ms.insert(-p[r1]);
    } else {
        p[r2] += p[r1];
        p[r1] = r2;
        ms.insert(-p[r2]);
    }
}
int main() {
    scanf("%d%d", &n, &k);
    for(int i=1; i<=n; i++) {
        scanf("%d", a+i);
        p[i] = -1;
    }
    for(int i=1; i<=n; i++) {
        if(a[i] && p[i] == -1) {
            int cnt = 1;
            for(int j=i+1; a[j]; j++) {
                p[j] = i; 
                cnt++;
            }
            p[i] = -cnt;
            ms.insert(cnt);
        }
    }
    int mn_sum = *ms.begin(), mx_sum = *(--ms.end()), t;
    while(k--) {
        scanf("%d", &t);
        a[t] = 1;
        ms.insert(1);
        for(int i=-1; i<=1; i+=2) {
            if(!a[t+i]) continue;
            unite(t, t+i);
        }
        mn_sum += *ms.begin();
        mx_sum += *(--ms.end());
    }
    printf("%d\n%d\n", mx_sum, mn_sum);
    return 0;
}