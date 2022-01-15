#include <stdio.h>
#include <stdlib.h>

struct LL {
    int val;
    struct LL *nex, *pre;
};
typedef struct LL L;

int main() {
    L *cur = (L*)calloc(1, sizeof(L));
    cur->val = 1;
    cur->pre = cur->nex = cur;
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; ++i) {
        char com[100];
        scanf("%s", com);
        if(com[0] == 'W') {
            printf("%d\n", cur->val);
        }
        else if(com[0] == 'I') {
            int v;
            scanf("%d", &v);
            L *node = (L*)calloc(1, sizeof(L));
            node->val = v;
            node->pre = cur;
            node->nex = cur->nex;
            cur->nex->pre = node;
            cur->nex = node; 
            if(cur->pre == cur) cur->pre = node;
        }
        else if(com[0] == 'L') {
            cur = cur->pre;
        }
        else cur = cur->nex;
    }
    return 0;
}