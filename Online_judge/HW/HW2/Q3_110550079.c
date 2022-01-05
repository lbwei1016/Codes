#include <stdio.h>
#include <stdbool.h>

int main() {
    int n;
    scanf("%d", &n);
    int price[n+1];
    for(int i=0; i<n; ++i) scanf("%d", price+i);
    price[n] = -1e9;
    int sum = 0;
    bool bought = 0;
    for(int i=0; i<n; ++i) {
        if(price[i+1] > price[i]) {
            if(!bought) {
                bought = 1;
                sum -= price[i];
            }
            else {
                continue;
            }
        }
        else {
            if(!bought) continue;
            else {
                sum += price[i];
                bought = 0;
            }
        }
    }
    printf("%d\n", sum);
    return 0;
}