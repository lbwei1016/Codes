/*
***priority queue***

    O(N * log N)
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    int n, m;
    priority_queue<ll> coun; //櫃台
    queue<ll> wait; //先來先服務，等候列
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++) {
        int t;
        scanf("%d", &t);
        wait.push(-t); //由小到大
    }
    for(int i=0; i<m; i++) {
        ll t = wait.front(); wait.pop();
        coun.push(t);
    }
    while(!wait.empty()) {
        ll w = wait.front(); wait.pop();
        ll fin = coun.top(); coun.pop();
        coun.push(fin+w);
    }
    for(int i=coun.size(); i>1; i--) {
        coun.pop();
    }
    //找最大時間
    printf("%lld\n", -coun.top());
    return 0;
}