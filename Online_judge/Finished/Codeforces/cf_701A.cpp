/*
***Greedy***
*/
#include <bits/stdc++.h>
using namespace std;

struct P { int val, id; };
bool cmp(P p1, P p2) {
    return p1.val < p2.val;
}
int main() {
    int n;
    scanf("%d", &n);
    vector<P> v(n);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i].val);
        v[i].id = i+1;
    }
    stable_sort(v.begin(), v.end(), cmp);
    for(int i=0; i<n/2; i++) {
        printf("%d %d\n", v[i].id, v[n-i-1].id); 
    }
    return 0;
}