#include <stdio.h>

void merge_sort(int l, int r, int arr[]) {
    if(r-l == 1) return;
    int mid = (l+r) >> 1;
    merge_sort(l, mid, arr); merge_sort(mid, r, arr);
    int tmp[r-l], j = mid;
    for(int i=l, k=0; i<mid; ++i) {
        while(j<r && arr[j]<arr[i]) {
            tmp[k++] = arr[j++];
        }
        tmp[k++] = arr[i];
    }
    for(int i=l; i<j; ++i) {
        arr[i] = tmp[i-l];
    }
}
int main() {
    int n;
    scanf("%d", &n);
    if(n <= 0) {
        putchar(',');
        return 0;
    }
    int arr[n];
    for(int i=0; i<n; ++i) scanf("%d,", arr+i);
    merge_sort(0, n, arr);
    for(int i=0; i<n; ++i) {
        printf("%d,", arr[i]);
    }
    puts("");
    return 0;
}