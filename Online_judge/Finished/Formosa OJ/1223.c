#include <stdio.h>

void hanoi(char src, char buf, char des, int n, int id) {
    if(n == 1) {
        printf("Move ring %d from %c to %c\n", id, src, des);
        return;
    }
    hanoi(src, des, buf, n-1, id-1);
    hanoi(src, buf, des, 1, id);
    hanoi(buf, src, des, n-1, id-1);
}
int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        hanoi('A', 'B', 'C', n, n);
        puts("finish");
    }
    return 0;
}