#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    if(n <= 0) puts("Please enter a positive number!");
    else if(n > (int)1e6) puts("You might have entered something bigger than 1 million.");
    else if(n == 1) puts("0");
    else {
        printf("0\t1");
        n -= 2;
        int a = 0, b = 1, tmp;
        while(n--) {
            tmp = a;
            a = b;
            b += tmp;
            printf("\t%d", b);
        }
        puts("");
    }
    
    return 0;
}