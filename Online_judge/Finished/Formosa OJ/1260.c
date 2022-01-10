#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, K, Q;
    scanf("%d", &N);
    int **arr = (int**)calloc(N, sizeof(int*));
    for(int i=0; i<N; ++i) {
        scanf("%d", &K);
        arr[i] = (int*)malloc(sizeof(int)*K);
        for(int j=0; j<K; ++j) {
            scanf("%d", arr[i]+j);
        }
    }
    scanf("%d", &Q);
    while(Q--) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", arr[a][b]);
    }
    return 0;
}