/*
***Stack*** 
    Tip: 
        Build two trees(h=INF) at both left and right boundary to make thing simpler.
    O(N)
*/
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5+5;
int N, L;
int c[MAX_N], h[MAX_N];
stack<int> S; //index of not removed trees

int main() {
    scanf("%d%d", &N, &L);
    for(int i=1; i<=N; i++) {
        scanf("%d", &c[i]);
    }
    for(int i=1; i<=N; i++) {
        scanf("%d", &h[i]);
    }
    S.push(0); //c[0] 永遠不會被砍倒，因此不必檢查 S 為空的情況
    c[0] = 0; h[0] = 1e9;
    c[N+1] = L; h[N+1] = 1e9;
    int mx = 0, total = 0;
    for(int i=1; i<=N; i++) {
        if(c[i]-h[i] >= c[S.top()] || c[i]+h[i] <= c[i+1]) {
            total++;
            mx = max(mx, h[i]);
            while(c[S.top()] + h[S.top()] <= c[i+1]) {
                total++;
                mx = max(mx, h[S.top()]);
                S.pop();
            }
        } else {
            S.push(i);
        }
    }
    printf("%d\n%d\n", total, mx);
    return 0;
}