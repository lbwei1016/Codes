#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 70

int main() {
    srand(time(0));

    bool chosen[N] = {0}; // false: 沒選過；true: 選過了
    for (int i=0; i<5; ++i) {
        int num = rand() % N;
        // 如果 num 選過了，就重選
        while (chosen[num] == true) 
            num = rand() % N;
        chosen[num] = true;
        printf("%d ", num);
    }
    int num = rand() % 11;
    while (chosen[num] == true) 
        num = rand() % 11;
    printf("%d\n", num);
    return 0;
}