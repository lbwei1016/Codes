#include <stdio.h>
#include <string.h>
#define N 120

void sort(int l, int r, int C[]) {
    if(r-l <= 1) return;
    int mid = (l+r) / 2;
    sort(l, mid, C); sort(mid, r, C);
    int tmp[r-l], j = mid;
    for(int i=l, k=0; i<mid; ++i) {
        while(j<r && C[j]>C[i]) {
            tmp[k++] = C[j++];
        }
        tmp[k++] = C[i];
    }
    for(int i=l; i<j; ++i) C[i] = tmp[i-l];
}

int main() {
    char s[N];
    // fgets() returns a pointer
    while(fgets(s, 100, stdin) != NULL) {
        // if(feof(stdin)) break;
        int C[N] = {0};
        int col = strlen(s) - 1, row = 0;
        for(int i=0; i<col;++i) {
            if(s[i] == '*') C[i] = 0;
        }
        for(row=1; fgets(s, 100, stdin); ++row) {
            if(s[0] == '\n') break;
            for(int j=0; j<col; ++j) {
                if(s[j] == '*') C[j] = row;
            }
        }
        sort(0, col, C);
        for(int r=0; r<row; ++r) {
            for(int c=0; c<col; ++c) {
                if(C[c] == r) putchar('*');
                else putchar('.');
            }
            putchar('\n');
        }
        putchar('\n');
    }
    return 0;
}