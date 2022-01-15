#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    char com[100005];
    scanf("%d", &t);
    while(t--) {
        scanf("%s\n%d\n", com, &n);
        int arr[n];
        if(n == 0) getchar();
        for(int i=0; i<n; ++i) {
            scanf("%*c%d", &arr[i]);
        }
        getchar();

        int he = 0, ta = n;
        bool rev = false;
        for(int i=0, l=strlen(com); i<l; ++i) {
            if(com[i] == 'R') {
                rev ^= 1;
            }
            else {
                if(rev) --ta;
                else ++he;
            }
        }  

        if(ta < he) {
            puts("error");
            continue;
        }
        if(rev) reverse(arr+he, arr+ta);
        putchar('[');
        for(int i=he; i<ta; ++i) {
            printf("%d", arr[i]);
            if(i < ta-1) putchar(',');
        }
        puts("]");
    }
    return 0;
}