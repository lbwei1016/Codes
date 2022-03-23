/*
***LPS***
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5;

bool is_pan(char *s, int i, int len) {
    for(int j=0; j<len/2; ++j) {
        if(s[i+j] != s[i+len-1-j]) return 0;
    }
    return 1;
}
void find_pan(char *s) {
    char res[N];
    // len: length of target palindrome (search from the largest)
    for(int sl=strlen(s), len=sl; len>=1; --len) {
        // i: the beginning of palindrome
        for(int i=0; i+len<=sl; ++i) {
            if(is_pan(s, i, len)) {
                memcpy(res, s+i, len);
                puts(res);
                return;
            }
        }
    }
}
int main() {
    char s[N];
    scanf("%s", s);
    find_pan(s);
    return 0;
}