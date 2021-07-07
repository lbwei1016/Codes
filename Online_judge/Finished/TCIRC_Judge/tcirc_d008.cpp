/*
***Recursion*** -- N-Queen Problem
*/
#include <bits/stdc++.h>
using namespace std;

int n, G[15][15], res;
int p[15]; //-1 means ignored

void nqr(int k, int sum) {
    if(k >= n) {
        res = max(sum, res);
        return;
    }
    bool valid[n];
    for(int i=0; i<n; i++) valid[i] = true;
    for(int i=0; i<k; i++) {
        if(p[i] >= 0) {
            valid[p[i]] = false;
            int j = k - i + p[i];
            if(j < n) valid[j] = false;
            j = p[i] - (k-i);
            if(j >= 0) valid[j] = false;
        }
    }
    //columns
    for(int i=0; i<n; i++) {
        if(valid[i]) {
            p[k] = i;
            nqr(k+1, sum+G[k][i]);
        }
    }
    //ignore this row
    p[k] = -1;
    nqr(k+1, sum);
}

int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &G[i][j]);
        }
    }
    res = 0;
    nqr(0, 0);
    printf("%d\n", res);
    return 0;
}