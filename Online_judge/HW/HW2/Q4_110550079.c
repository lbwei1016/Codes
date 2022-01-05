#include <stdio.h>
#include <stdbool.h>

bool arrived;
void rec(int arr[], int at, const int n) {
    if(arrived) return;
    if(at == n-1) {
        arrived = true;
        return;
    }
    for(int i=1; i<=arr[at]; ++i) {
        rec(arr, at+i, n);
    }
}
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; ++i) scanf("%d", arr+i);
    rec(arr, 0, n);
    if(arrived) puts("true");
    else puts("false");
    return 0;
}