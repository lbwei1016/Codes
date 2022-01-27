#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int INF = 1e9;

struct P {
    char name[35];
    int chl_num, par_num, st, up, dn;
    struct P *chl[35];
    struct P *par[5];
};

struct P *peo[65];
int n;
int peo_cnt;

void trav_up(struct P*);
void trav_down(struct P*);

int find_name(char *s) {
    for(int i=0; i<peo_cnt; ++i) {
        if(!strcmp(s, peo[i]->name)) return i;
    }
    return -1;
}

void trav_down(struct P *at) {
    at->dn = 1;
    for(int i=0; i<at->chl_num; ++i) {
        if(at->chl[i]->st != INF) continue;
        at->chl[i]->st = at->st + 1;
        trav_down(at->chl[i]);
    }
    if(at->up) return;
    at->up = 1;
    trav_up(at);
}
void trav_up(struct P *at) {
    at->up = 1;
    for(int i=0; i<at->par_num; ++i) {
        if(at->par[i]->st != INF) continue;
        at->par[i]->st = at->st - 1;
        trav_up(at->par[i]);
    }
    if(at->dn) return;
    at->dn = 1;
    trav_down(at);
}

int main() {
    scanf("%d", &n);
    while(n--) {
        char s[2][35];
        int at[2];
        scanf("%s %s", s[0], s[1]);
        for(int i=0; i<2; ++i) {
            at[i] = find_name(s[i]);
            if(at[i] < 0) {
                at[i] = peo_cnt;
                peo[peo_cnt] = (struct P*)calloc(1, sizeof(struct P));

                strcpy(peo[peo_cnt]->name, s[i]);
                if(!strcmp(s[i], "Dong")) peo[peo_cnt]->st = 0;
                else peo[peo_cnt]->st = INF;
                ++peo_cnt;
            }
        }
        peo[at[0]]->par[(peo[at[0]]->par_num)++] = peo[at[1]];
        peo[at[1]]->chl[(peo[at[1]]->chl_num)++] = peo[at[0]];
    }
    int dong;
    for(int i=0; i<peo_cnt; ++i) {
        if(peo[i]->st == 0) {
            dong = i;
            break;
        }
    }

    trav_up(peo[dong]);
    for(int i=0; i<peo_cnt; ++i) {
        if(!strcmp(peo[i]->name, "Dong")) continue;

        printf("%s ", peo[i]->name);
        if(peo[i]->st < 0) puts("elder");
        else if(peo[i]->st == 0) puts("same");
        else if(peo[i]->st == INF) puts("unknown");
        else puts("younger");
    }
    return 0;
}