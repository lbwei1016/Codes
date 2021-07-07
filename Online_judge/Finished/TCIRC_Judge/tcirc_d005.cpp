/*
***Recursion***
*/
#include <bits/stdc++.h>
using namespace std;

const int MAX_S = 1e6+5;
char s[MAX_S];
int n, cnt = 0, len;

int rec(int k) {
    int sum = 0;
    for(int i=0; i<4&&cnt<len; i++) {
        char c = s[cnt++];
        if(c != '2') {
            sum += (c-'0') * k * k;
        }
        else {
            sum += rec(k/2);
        }
    }
    return sum;
}

int main() {
    scanf("%s%d", s, &n);
    len = strlen(s);
    printf("%d\n", rec(n));
    return 0;
}