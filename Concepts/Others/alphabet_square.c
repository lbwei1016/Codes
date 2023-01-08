/*
just for fun
*/
#include <stdio.h>
#include <string.h>
#define N 50

int main() {
    char arr[N][N];
    memset(arr, ' ', sizeof(arr));    
    int n;
    scanf("%d", &n);
    for(int i=0; i<n-2; ++i) {
        char cnt = 'A';
        for(int j=0; j<n-2-i; ++j) {
            arr[i][j] = cnt++;
        }
    }
    for(int i=0; i<n-2; ++i) {
        char cnt = 'A';
        for(int j=2*n-2; j>n+i; --j) {
            arr[i][j] = cnt++;
        }
    }
    
    for(int i=2*n-2; i>n; --i) {
        char cnt = 'A';
        for(int j=0; j<i-n; ++j) {
            arr[i][j] = cnt++;
        }
    }
    for(int i=2*n-2; i>n; --i) {
        char cnt = 'A';
        for(int j=2*n-2; j>3*n-i-2; --j) {
            arr[i][j] = cnt++;
        }
    }

    char c = 'A';
    for(int i=0; i<n; ++i) arr[i][i] = c++;
    --c;
    for(int i=n; i<2*n-1; ++i) arr[i][i] = --c;

    for(int i=0, j=2*n-2; i<n; ++i, --j) {
        arr[i][j] = c++;
    }
    --c;
    for(int i=n, j=n-2; j>=0; ++i, --j) {
        arr[i][j] = --c;
    }

    for(int i=0; i<2*n-1; ++i) {
        for(int j=0; j<2*n-1; ++j) printf("%c ", arr[i][j]);
        puts("");
    }
    return 0;
}