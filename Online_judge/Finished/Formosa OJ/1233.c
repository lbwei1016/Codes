#include <stdio.h>
#define max(a, b) ((a)>(b)?(a):(b))

int t, tar, n, arr[10005];
int cnt;

void print(int p_list) {
    for(int i=0; i<n; ++i) {
        if(p_list & (1<<i)) {
            putchar('O');
        }
        else putchar('X');
    }
    puts("");
}
void rec(int d, int picked, int sum, int p_list) {
    if(d == n || picked == 20) {
        if(sum == tar) {
            print(p_list);
            ++cnt;
        }
        return;
    }
    if(sum+arr[d] <= tar) {
        p_list |= (1 << d);
        rec(d+1, picked+1, sum+arr[d], p_list);
        p_list ^= (1 << d);
    }
    rec(d+1, picked, sum, p_list);
}

int main() {
    scanf("%d", &t);
    while(t--) {
        cnt = 0;
    
        scanf("%d", &tar);
        int tmp, mx = 0;
        for(n=0; scanf("%d", &tmp); ++n) {
            if(tmp == 0) break;
            mx = max(mx, tmp);
            arr[n] = tmp;
        }
        if(20*mx > tar) rec(0, 0, 0, 0);
        if(cnt == 0) puts("no solution");
        else puts("finish");
    }
    return 0;
}