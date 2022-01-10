#include <stdio.h>
#include <string.h>
#define min(a, b) ((a)<(b)?(a):(b))

char Ta[6] = {"AEIOU"};

int calc(int who, int cnt[]) {
    char cwho = 'A' + who;
    int who_vow = 0;
    for(int i=0; i<5; ++i) {
        if(cwho == Ta[i]) {
            who_vow = 1;
            break;
        }
    }
    int sum = 0;
    for(int i=0; i<26; ++i) {
        if(!cnt[i] || i==who) continue;
        char cur = 'A' + i;
        int is_vow = 0;
        for(int i=0; i<5; ++i) {
            if(cur == Ta[i]) {
                is_vow = 1;
                break;
            }
        }
        if(is_vow) {
            if(who_vow) sum += 2*cnt[i];
            else sum += cnt[i];
        }
        else {
            if(who_vow) sum += cnt[i];
            else sum += 2*cnt[i];
        }
    }
    return sum;
}
int main() {
    int t;
    scanf("%d", &t);
    for(int i=1; i<=t; ++i) {
        char s[1000];
        int cnt[30] = {0};
        scanf("%s", &s);
        int len = strlen(s), mx = 0;
        char who;
        for(int j=0; j<len; ++j) {
            if(mx < ++cnt[s[j]-'A']) {
                mx = cnt[s[j]-'A'];
                who = s[j];
            }
        }
        int mn = 1e9;
        for(int j=0; j<26; ++j) {
            mn = min(mn, calc(j, cnt));
        }
        printf("Case #%d: %d\n", i, mn);
    }
    return 0;
}