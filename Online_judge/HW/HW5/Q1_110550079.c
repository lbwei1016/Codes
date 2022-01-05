#include <stdio.h>
#include<string.h>
#include <stdbool.h>

typedef struct {
    int rep;
    char s[20]; 
} STR;

char table[200];

void init() {
    for(int i='A', num=10; i<='H'; ++i) {
        table[i] = num++;
    }
    for(int i='J', num=18; i<='N'; ++i) {
        table[i] = num++;
    }
    for(int i='P', num=23; i<='V'; ++i) {
        table[i] = num++;
    }
    table['X'] = 30, table['Y'] = 31;
    table['W'] = 32, table['Z'] = 33;
    table['I'] = 34, table['O'] = 35;

}
char check(char *s) {
    if(s[0]<'A' || s[0]>'Z') return 'F';
    if(s[1] != '1' && s[1] != '2') return 'F';
    int sum = table[s[0]]/10 + 9*(table[s[0]]%10);
    for(int i=1; i<9; ++i) {
        sum += (9-i) * (s[i]-'0');
    }
    sum += (s[9] - '0');
    if(sum % 10) return 'F';
    else return 'T';
}
bool no_same(STR *S, STR *S2, int cnt) {
    for(int i=0; i<cnt; ++i) {
        // puts(S2->s);
        // puts(S[i].s);
        if(strcmp(S[i].s, S2->s) == 0) {
            ++S[i].rep;
            return false;
        }
    }
    S2->rep = 1;
    return true;
}
int main() {
    init();
    STR S[20];
    int cnt = 0;
    for(int i=0; i<10; ++i) {
        scanf("%s", &S[cnt].s);
        // puts(S[cnt].s);
        if(no_same(S, &S[cnt], cnt)) {
            ++cnt;
        }
    }
    for(int i=0; i<cnt; ++i) {
        char c = check(S[i].s);
        printf("%s (%c, %d)\n", S[i].s, c, S[i].rep);
    }
    return 0;

}