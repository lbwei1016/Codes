/*
***Divide and Conquer / String***
    Solution:
        轉換字串為「與他等價的字典序最小的字串」！！！
        兩個字串是等價的若且唯若：把兩個字串都換成與他等價的字典序最小的字串，兩字串相等。
    O(n * log n) (?)
*/
#include <bits/stdc++.h>
using namespace std;

void to_min(char *s, int n) {
    if(n & 1) return;
    int n2 = n / 2;
    to_min(s, n2); to_min(s+n2, n2);
    bool change = 0;
    for(int i=0; i<n2; ++i) {
        if(s[i] != s[i+n2]) {
            if(s[i] < s[i+n2]) return;
            change = 1;
            break;
        }
    }
    if(change) {
        for(int i=0; i<n2; ++i) swap(s[i], s[i+n2]);
    }
}

int main() {
    char s1[200005], s2[200005];
    scanf("%s%s", s1, s2);
    int size = strlen(s1);
    to_min(s1, size); to_min(s2, size);
    for(int i=0; i<size; ++i) {
        if(s1[i] != s2[i]) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}