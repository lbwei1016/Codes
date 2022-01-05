#include <stdio.h>
#define max(a, b) ((a)>(b)?(a):(b))
#define N 1005

int buy[N], sell[N];

int main() {
    int n, k, p[N];
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; ++i) scanf("%d", p+i);
    
    for(int i=0; i<=k; ++i) buy[i] = -1e9;
    for(int i=0; i<n; ++i) {
        for(int j=1; j<=k; ++j) {
            buy[j] = max(buy[j], sell[j-1]-p[i]);
            sell[j] = max(sell[j], buy[j]+p[i]);
        }
    }
    printf("%d", sell[k]);
    return 0;
}