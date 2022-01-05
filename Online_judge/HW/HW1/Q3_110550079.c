#include <stdio.h>
#include <stdbool.h>

int main() {
    int n;
    bool p;
    scanf("%d", &n);
    if(n == 0) {
        puts("NULL");
        return 0;
    }
    for(int i=0; i<n; ++i) {
        if(i & 1) p = 0;
        else p = 1;
        for(int j=0; j<=i; ++j) {
            printf("%d", p);
            p = !p;
        }
        puts("");
    }
    return 0;
}