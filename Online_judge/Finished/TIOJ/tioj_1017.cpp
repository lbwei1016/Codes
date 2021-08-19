/*
***Sweep Line***
*/
#include <bits/stdc++.h>
using namespace std;

int t, n, a[1000000+1];
int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i=0; i<n; ++i) scanf("%d", &a[i]);
        stack<int> S;
        int premax = a[0], res = 0;

        for(int i=1; i<n; ++i) {
            while(!S.empty() && S.top() >= a[i]) S.pop();
            if(i!=n-1 && a[i] > premax) {
                S.push(a[i]);
                premax = a[i];
            }
        }
        while(!S.empty()) {
            S.pop(); ++res;
        }
        printf("%d\n", res);
    }
    return 0;
}