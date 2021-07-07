/*
***Stack*** --- Arithmetic Operations
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    char s[20000];
    int neg = 1;
    stack<int> S;
    scanf("%s", s);
    int len = strlen(s);
    for(int i=0; i<len; i++) {
        if(s[i] == '-') {
            neg = -1;
            continue;
        } else if(s[i] == '*') {
            int k = S.top(); S.pop();
            S.push(k*(s[i+1]-'0'));
            i++;
        } else if(s[i] == '/') {
            int k = S.top(); S.pop();
            S.push(k/(s[i+1]-'0'));
            i++;
        } else if(s[i] != '+') {
            S.push((s[i] - '0')*neg);
            neg = 1;
        }
    }
    int res = 0;
    while(!S.empty()) {
        res += S.top(); S.pop();
    }
    printf("%d\n", res);
    return 0;
}