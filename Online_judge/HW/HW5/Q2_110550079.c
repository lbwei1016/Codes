#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct HIE {
    char s[105];
    int chl_num, size;
    struct HIE *chl[405];
};
char deli[2] = "$";

struct HIE* new() {
    struct HIE *p = (struct HIE*)calloc(1, sizeof(struct HIE));
    p->size = -1;
    return p;
}
struct HIE* find(struct HIE* cur, char *cut, char *pre) {
    if(cut == NULL) {
        if(pre == NULL) return cur;
        for(int i=0; i<cur->chl_num; ++i) {
            if(strcmp(cur->chl[i]->s, pre) == 0) {
                return cur->chl[i];
            }
        }
        return NULL;
    }
    for(int i=0; i<cur->chl_num; ++i) {
        if(strcmp(cur->chl[i]->s, pre) == 0) {
            return find(cur->chl[i], strtok(NULL, deli), cut);
        }
    }
    return NULL;
}

struct HIE* add_chl(struct HIE* cur, char *cut, char *pre) {
    if(cut == NULL) {
        // struct HIE *p = (struct HIE*)calloc(1, sizeof(struct HIE));
        struct HIE *p = new();
        cur->chl[(cur->chl_num)++] = p;
        return p;
    }
    for(int i=0; i<cur->chl_num; ++i) {
        if(strcmp(cur->chl[i]->s, pre) == 0) {
            return add_chl(cur->chl[i], strtok(NULL, deli), cut);
        }
    }
    // struct HIE *chl = (struct HIE*)calloc(1, sizeof(struct HIE));
    struct HIE *chl = new();
    strcpy(chl->s, pre);
    cur->chl[cur->chl_num++] = chl;
    return add_chl(chl, strtok(NULL, deli), cut);
}

void calc(struct HIE *cur) {
    int dir = 0, file = 0, size = 0;
    for(int i=0; i<cur->chl_num; ++i) {
        if(cur->chl[i]->size >= 0) {
            ++file;
            size += cur->chl[i]->size;
        }
        else ++dir;
    }
    printf("%d %d %d\n", dir, file, size);
}
int main() {
    struct HIE root = {.chl_num = 0, .size = -1};
    int pa, re;
    scanf("%d", &pa);

    while(pa--) {
        char s[105];
        int size;
        scanf("%s %d", s+1, &size);
        s[0] = '/', s[1] = '$';
        for(int j=1, l=strlen(s); j<l; ++j) {
            if(s[j] == '/') s[j] = '$';
        }
        char *cut = strtok(s, deli);
        char *pre = cut;
        cut = strtok(NULL, deli);
        struct HIE *cur = add_chl(&root, cut, pre);
        if(cur != NULL) {
            cur->size = size;
            while(cut != NULL) {
                pre = cut;
                cut = strtok(NULL, deli);
            }
            strcpy(cur->s, pre);
        }
    }
    
    scanf("%d", &re);
    while(re--) {
        char s[105];
        scanf("%s", s+1);
        s[0] = '/', s[1] = '$';
        for(int j=1, l=strlen(s); j<l; ++j) {
            if(s[j] == '/') s[j] = '$';
        }
        char *cut = strtok(s, deli);
        char *pre = cut;
        cut = strtok(NULL, deli);
        struct HIE *cur = find(&root, cut, pre);
        if(cur == NULL || cur->size >= 0) puts("invalid path");
        else calc(cur);
    }
    return 0;
}