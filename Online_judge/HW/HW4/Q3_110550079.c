#include <stdio.h>
#define N 105

int main() {
    int n, arr[N], zeros = 0;
    scanf("%d", &n);
    for(int i=0; i<n; ++i) {
        scanf("%d", &arr[i]);
        if(!arr[i]) ++zeros;
    }
    for(int i=0; i<n; ++i) {
        if(arr[i]) {
            continue;
        }
        int not0;
        for(int j=i+1; j<n; ++j) {
            if(arr[j]) {
                not0 = j;
                break;
            }
        }
        arr[i] = arr[not0];
        arr[not0] = 0;
    }
    for(int i=0; i<n; ++i) printf("%d%c", arr[i], i==n-1?'\n':' ');
    return 0;
}