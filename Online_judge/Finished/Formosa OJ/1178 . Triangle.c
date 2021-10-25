#include <stdio.h>

int main() {
    int a[3], tmp;
    for(int i=0; i<3; ++i) {
        scanf("%d", a+i);
    }
    for(int i=0; i<3; ++i) {
        for(int j=0; j<3; ++j) {
            if(a[i] < a[j]) {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
    if(a[0]+a[1] <= a[2]) {
        puts("OOPS");
        return 0;
    }
    int k = a[0]*a[0] + a[1]*a[1], t = a[2]*a[2];
    if(k < t) puts("obtuse triangle");
    else if(k > t) puts("acute triangle");
    else puts("right triangle");
    return 0;
}