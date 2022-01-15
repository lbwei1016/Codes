#include <stdio.h>
#include <stdlib.h>

struct LL {
    int val;
    struct LL *nex, *pre;
} ;
int main() {
    int t;
    struct LL node = (struct LL){.val=1};
    struct LL *cur = &node;
    cur->nex = cur->pre = cur;
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
        }
        else if(com[0] == 'L') {
            cur = cur->pre;
        }
        else cur = cur->nex;
    }
    return 0;
}