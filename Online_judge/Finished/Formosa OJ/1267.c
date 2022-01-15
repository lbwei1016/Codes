#include <stdio.h>
#include <stdlib.h>

struct LL {
    int val;
    struct LL *nex, *pre;
};

int main() {
    int t;
    struct LL *cur = (struct LL*)calloc(1, sizeof(struct LL));
    cur->val = 1, cur->nex = cur->pre = cur;
    scanf("%d", &t);
    while(t--) {
        char com[10];
        scanf("%s", com);
        if(com[0] == 'W') {
            printf("%d\n", cur->val);
        }
        else if(com[0] == 'I') {
            int d;
            scanf("%d", &d);
            struct LL *new_ = (struct LL*)calloc(1, sizeof(struct LL));
            new_->val = d;
            new_->nex = cur->nex; 
            new_->pre = cur;
            cur->nex->pre = new_;
            cur->nex = new_; 
            if(cur->pre == cur) cur->pre = new_;
        }
        else if(com[0] == 'L') {
            cur = cur->pre;
        }
        else if(com[0] == 'R') {
            cur = cur->nex;
        }
        else {
            cur->pre->nex = cur->nex;
            cur->nex->pre = cur->pre;
            struct LL *tmp = cur;
            cur = cur->nex;
            free(tmp);
        }
    }
    return 0;
}