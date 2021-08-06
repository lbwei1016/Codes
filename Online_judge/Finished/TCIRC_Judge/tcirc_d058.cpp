/*
***Greedy***
    Solution:
        自死線最大的作業開始逐一檢查，證明：
            令 d1 > d2，若先做 1 再做 2，則 2 受到的時間壓力更大，可能無法完成，
            反之，1 即使較晚做風險較小
    
    O(N)
*/
#include <bits/stdc++.h>
using namespace std;

struct Task { int t, d; };
int T, n, t_sum;
vector<Task> v;

bool cmp(Task t1, Task t2) {
    return t1.d > t2.d;
}
bool finish() {
    for(int i=0; i<n; i++) {
        if(v[i].d < t_sum) {
            return false;
        }
        t_sum -= v[i].t;
    }
    return true;
}
int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        t_sum = 0;
        v.resize(n);
        for(int i=0; i<n; i++) {
            scanf("%d", &v[i].t);
            t_sum += v[i].t;
        }
        for(int i=0; i<n; i++) {
            scanf("%d", &v[i].d);
        }
        sort(v.begin(), v.end(), cmp);
        if(finish()) puts("yes");
        else puts("no");
    }
    return 0;
}