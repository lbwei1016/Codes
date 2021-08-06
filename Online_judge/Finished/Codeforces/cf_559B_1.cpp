/*
***Divide and Conquer / String***
    Solution:
        直接拆開去遞迴
    O(n ^ 2) (?)
*/
#include <bits/stdc++.h>
using namespace std;

bool div(char *s1, char *s2, int n) {
    bool same = true;
    for(int i=0; i<n; ++i) {
        if(s1[i] != s2[i]) {
            same = false;
            break;
        }
    }
    if(same) return true;
    if(n & 1) return false;
    int m = n / 2;
    if(div(s1, s2, m)  && div(s1+m, s2+m, m)) return true;
    if(div(s1+m, s2, m) && div(s1, s2+m, m)) return true;
    return false;
}

int main() {
    char s1[200005], s2[200005];
    scanf("%s%s", s1, s2);
    if(div(s1, s2, strlen(s1))) puts("YES");
    else puts("NO");
    return 0;
}