#include <stdio.h>
#define N 10005

int calc(int n, int k, int arr[]) {
    if(k <= 1) return 0;
    int res = 0, prod = 1;
    int i = 0, j = 0;
    while(1) {
        while(j<n && prod<k) {
            res += (j - i);
            prod *= arr[j++];
        }
        if(prod < k) break;
        prod /= arr[i++];
    }
    res += j - i;
    return res;
}
int main() {
    int n, k, arr[N];
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; ++i) {
        scanf("%d", &arr[i]);
    }
    printf("%d\n", calc(n, k, arr));
    return 0;
}