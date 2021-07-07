/*
***Binary Search / Prefix Sum*** -- tcirc_d073

    O(M^2 * N * log N)
*/
#include <bits/stdc++.h>
using namespace std;

int K, M, N;
int A[55][30005];

int main() {
    scanf("%d%d%d", &K, &M, &N);
    for(int i=1; i<=M; i++) {
        for(int j=1; j<=N; j++) {
            scanf("%d", &A[i][j]);
            if(i > 0) A[i][j] += A[i-1][j];
        }
    }
    int res = 0;
    for(int i=0; i<M; i++) {
        for(int j=i+1; j<=M; j++) {
            set<int> S({0});
            int psum = 0;
            for(int k=1; k<=N; k++) {
                psum += A[j][k] - A[i][k];
                auto it = S.lower_bound(psum - K);
                if(it != S.end()) res = max(res, psum-*it);
                S.insert(psum);
            }
        }
    }
    printf("%d\n", res);
    return 0;
}