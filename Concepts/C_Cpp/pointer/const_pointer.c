#include <stdio.h>

int main() {
    const int m = 10; // m cannot be modified directly
    int *p = (int *)&m;
    // const int *p (int *)&m: this preserves "const" attribute
    *p += 1; // but m can be modified by a pointer 
    printf("%x %x\n", p, &m);
    printf("%d %d", *p, m);
    return 0;
}