#include <stdio.h>

int main() {
    int type, a, b;
    scanf("%d", &type);
    switch(type) {
        case 1:
            scanf("%d%d", &a, &b); 
            for(int i=0; i<a; ++i) {
                for(int j=0; j<b; ++j)
                    putchar('*');
                puts("");
            }
            break;
        case 2:
            scanf("%d", &a);
            for(int i=0; i<a; ++i) {
                for(int j=0; j<a; ++j)
                    putchar('*');
                puts("");
            }
            break;
        case 3:
            scanf("%d", &a);
            for(int i=1; i<=a; ++i) {
                for(int j=0; j<a-i; ++j) putchar(' ');
                for(int j=0; j<2*i-1; ++j) putchar('*');
                puts("");
            }
            break;
        default:
            puts("Please input 1, 2 or 3!");
            return 0;
    }
    return 0;
}