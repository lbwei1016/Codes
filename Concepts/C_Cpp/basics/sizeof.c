#include <stdio.h>
#include <stdlib.h>

int main() {
    int len = 10;
    // no explicit conversion is needed
    int *p = malloc(sizeof *p * len);
    // sizeof is an operator!!!
    printf("sizeof &main: %d\n", sizeof &main);

    return 0;
}