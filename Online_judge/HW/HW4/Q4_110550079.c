#include <stdio.h>
#define N 105
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))

int main() {
    int n, h[N];
    scanf("%d", &n);
    for(int i=0; i<n; ++i) scanf("%d", &h[i]);

    int V = 0;
    for(int i=0; i<n; ++i) {
        for(int j=i+1; j<n; ++j) {
            V = max(V, (j-i)*min(h[i], h[j]));
        }
    } 
    printf("%d\n", V);
    return 0;
}