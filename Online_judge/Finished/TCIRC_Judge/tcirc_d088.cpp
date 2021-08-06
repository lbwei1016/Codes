/*
***DP*** (*)
    O(n)
*/
#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e6+5;
int n, res;
int h[N], v[N];
int dp0[N], dp1[N]; //截至自己 (以自己為高點) 的左方累積值；自己加上前方累積值
int lh[N]; //在自己左方，最接近自己且比自己高的點
stack<int> S; //decreasing height

int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d", &h[i]);
    }
    for(int i=1; i<=n; i++) {
        scanf("%d", &v[i]);
    }

    S.push(0); 
    h[0] = 2e9;
    //先找自己的高點
    for(int i=1; i<=n; i++) {
        while(h[S.top()] <= h[i]) 
            S.pop();
        lh[i] = S.top();
        S.push(i);
    }
    S = stack<int>(); S.push(0);
    for(int i=1; i<=n; i++) {
        dp1[i] = dp0[lh[i]] + v[i];
        dp0[i] = dp0[S.top()];
        while(h[S.top()] < h[i]) {
            //更新左方累積值
            dp0[i] = max(dp0[i], dp1[S.top()]);
            S.pop();
        }
        if(h[S.top()] == h[i]) {
            dp0[i] = max(dp0[i], dp0[S.top()]);
            //因為目前只更新左方累積值，有可能 dp1[S.top] > dp1[i]
            //因此還不能 pop
            //S.pop();
        }
        S.push(i);
        res = max(res, dp1[i]);
    }
    printf("%d\n", res);
    return 0;
}