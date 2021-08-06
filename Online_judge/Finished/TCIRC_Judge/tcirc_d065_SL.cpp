/*
***Sweep Line***
    Solution:
        將大樓依遞增高度放置於 stack 內；每當遇見一棟比堆疊頂低的，
        即連續取出使堆疊恢復遞增順序，並在這過程中計算到目前為止比
        自己高的大樓所圍出的面積
    O(n)
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    int n;
    ll h[100005];
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%lld", &h[i]);
    }
    //邊界處理
    h[0] = -1; 
    h[n+1] = 0;
    stack<int> inc; //increasing subsequence；index
    inc.push(0);
    ll res = 0;
    for(int i=1; i<=n+1; i++) {
        if(h[i] > h[inc.top()]) inc.push(i);
        if(h[i] >= h[inc.top()]) continue;
        while(h[inc.top()] >= h[i]) {
            ll height = h[inc.top()]; inc.pop();
            //計算 (inc.top(), i) 之間區域的面積
            res = max(res, (i-inc.top()-1)*height);
        }
        inc.push(i);
    }
    printf("%lld\n", res);
    return 0;
}