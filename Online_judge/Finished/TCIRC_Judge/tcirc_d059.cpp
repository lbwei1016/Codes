/*
***priority queue / Binary Search*** -- advanced version of tcirc_d053

    O(N * (log N)^2)
*/
#include <bits/stdc++.h>
using namespace std;

int n, D;
vector<int> t;

bool enough(int c) {
    priority_queue<int, vector<int>, greater<int> > counter;
    queue<int> wait;
    for(int i=0; i<c; i++) {
        counter.push(t[i]);
    }
    for(int i=c; i<n; i++) {
        wait.push(t[i]);
    }
    while(!wait.empty()) {
        int fin = counter.top(); counter.pop();
        int go = wait.front(); wait.pop();
        counter.push(fin+go);
    }
    for(; c>1; c--) {
        counter.pop();
    }
    if(counter.top() <= D) return true;
    else return false;
}
int main() {
    scanf("%d%d", &n, &D);
    t.resize(n);
    for(int i=0; i<n; i++) {
        scanf("%d", &t[i]);
    }
    int lb = 0, ub = n;
    while(ub - lb > 1) {
        int mid = (lb+ub) / 2;
        if(enough(mid)) ub = mid;
        else lb = mid;
    }
    printf("%d\n", ub);
    return 0;
}