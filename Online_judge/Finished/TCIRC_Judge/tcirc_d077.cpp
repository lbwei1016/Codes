/*
***DP***
*/
#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> c;
deque<int> mn; //index
void put_min(int x) {
    while(!mn.empty() && c[mn.back()]>=c[x])
        mn.pop_back();
    mn.push_back(x);
}
int main() {
    scanf("%d%d", &n, &k);
    c.resize(n);
    for(int i=0; i<n; i++) {
        scanf("%d", &c[i]);
    }
    for(int i=0; i<=k; i++) {
        put_min(i);
    }
    for(int i=k+1; i<n; i++) {
        if(i-mn.front()-1 > 2*k) mn.pop_front();
        c[i] += c[mn.front()]; //累加成本
        put_min(i);
    }
    //無法涵蓋到最後一個點
    while(mn.front()+k < n-1) mn.pop_front();
    printf("%d\n", c[mn.front()]);
    return 0;
}