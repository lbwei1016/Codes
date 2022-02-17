#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5;
char s[N];

bool is_pal(char *s, int len) {
    for(int i=0; i<len/2; ++i) {
        if(s[i] != s[len-i-1]) return false;
    }
    return true;
}

int main() {
    scanf("%s", s);
    int hd = 0, ta = strlen(s);
    while(ta > 0 && s[ta-1] == 'a') --ta;
    while(hd < ta && s[hd] == 'a') ++hd; 

    if(hd <= strlen(s)-ta && is_pal(s+hd, ta-hd)) puts("Yes");
    else puts("No");   
    return 0;
}