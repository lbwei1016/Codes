#include <stdio.h>

int outs[1000000], cnt;
int calc(int n) {
    int sum = 0;
    while(n > 0) {
        sum += (n % 10)*(n % 10);
        n /= 10;
    }
    return sum;
}
int main() {
    int n;
    scanf("%d", &n);
    outs[cnt++] = n;
    while(1) {
        n = calc(n);
        if(n == 1) {
            puts("1");
            return 0;
        }
        for(int i=0; i<cnt; ++i) {
            if(outs[i] == n) {
                puts("0");
                return 0;
            }
        }
        outs[cnt++] = n;
    }
    return 0;
}