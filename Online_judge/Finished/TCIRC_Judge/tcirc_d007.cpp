/*
***Recursion***
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, P;
int A[26+1];
ll res = 0;

void rec(int i, ll sum) {
    if(i >= n) {
        if(sum <= P && sum > res) res = sum;
        return;
    }
    rec(i+1, sum+A[i]);
    rec(i+1, sum);
    return;
}

int main() {
    scanf("%d%d", &n, &P);
    for(int i=0; i<n; i++) {
        scanf("%d", &A[i]);
    }
    rec(0, 0);
    printf("%d\n", res);
    return 0;
}