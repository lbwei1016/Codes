#include <stdio.h>

int gcd(int a, int b) {
    int tmp;
    if(a < b) {
        tmp = a;
        a = b;
        b = tmp;
    }
    while(b > 0) {
        tmp = b;
        b = a - (a/b * b);
        a = tmp;
    }
    return a;
}
int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int res = gcd(gcd(a, b), c);
    printf("%d\n", res);
    return 0;
}