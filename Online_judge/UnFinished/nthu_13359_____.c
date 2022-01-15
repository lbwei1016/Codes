#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_N 100005

int N, A, B, Ma, Mb;
bool ka[MAX_N], kb[MAX_N];
int pooh_canwin[MAX_N]; // jars left
int pig_canwin[MAX_N];

bool pooh(int);
bool pig(int);

bool pooh(int jars) {
    if(pooh_canwin[jars] == 0) return false;
    if(jars<=A || ka[jars]) 
        return pooh_canwin[jars] = true;
    if(pooh_canwin[jars] < 0) pooh_canwin[jars] = 0;

    for(int i=1; i<=A; ++i) {
        if(pig_canwin[jars-i] >= 0)
            pooh_canwin[jars] |= !pig_canwin[jars-i];
        else
            pooh_canwin[jars] |= !pig(jars-i);
        if(pooh_canwin[jars]) break;
    }
    return pooh_canwin[jars];
}

bool pig(int jars) {
    if(pig_canwin[jars] == 0) return false;
    if(jars<=B || kb[jars]) 
        return pig_canwin[jars] = true;
    if(pig_canwin[jars] < 0) pig_canwin[jars] = 0;

    for(int i=1; i<=B; ++i) {
        if(pooh_canwin[jars-i] >= 0)
            pig_canwin[jars] |= !pooh_canwin[jars-i];
        else
            pig_canwin[jars] |= !pooh(jars-i);
        if(pig_canwin[jars]) break;
    }
    return pig_canwin[jars];
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        char s[10];
        bool firstwin;
        memset(pooh_canwin, -1, sizeof(pooh_canwin));
        memset(pig_canwin, -1, sizeof(pig_canwin));
        memset(ka, 0, sizeof(ka));
        memset(kb, 0, sizeof(kb));
        scanf("%d %d %d %d %d %s", &N, &A, &B, &Ma, &Mb, s);
        for(int i=0; i<Ma; ++i) {
            int tmp;
            scanf("%d", &tmp);
            ka[tmp] = 1;
        }
        for(int i=0; i<Mb; ++i) {
            int tmp;
            scanf("%d", &tmp);
            kb[tmp] = 1;
        }

        if(s[3] == 'h') firstwin = pooh(N);
        else firstwin = pig(N);

        if((firstwin && s[3]=='h') || (!firstwin && s[3]!='h')) puts("Pooh");
        else puts("Piglet");
    }
    return 0;
}