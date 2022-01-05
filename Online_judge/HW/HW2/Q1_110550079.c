#include <stdio.h>
#define N 100

int main() {
    int m, n1, n2, p;
    int A[N][N], B[N][N], C[N][N] = {0};
    scanf("%d,%d", &m, &n1);
    for(int i=0; i<m; ++i) {
        for(int j=0; j<n1; ++j) {
            scanf("%d,", &A[i][j]);
        }
    }
    scanf("%d,%d", &n2, &p);
    for(int i=0; i<n2; ++i) {
        for(int j=0; j<p; ++j) {
            scanf("%d,", &B[i][j]);
        }
    }
    if(n1 != n2) {
        puts("Wrong dimensions!");
        return 0;
    }
    for(int i=0; i<m; ++i) {
        for(int j=0; j<n1; ++j) {
            for(int k=0; k<p; ++k) {
                C[i][k] += A[i][j] * B[j][k];
            }
        }
    }
    for(int i=0; i<m; ++i) {
        for(int j=0; j<p; ++j) {
            printf("%d,", C[i][j]);
        }
        putchar('\n');
    }
    return 0;
}