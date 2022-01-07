#include <stdio.h>
#include <stdlib.h>
/*
    prototype for qsort():
    void qsort(void *base, size_t nmemb, size_t size, 
            int (*cmp)(const void*, const void*)) 
*/
struct S {
    int val, id;
};
int cmp(const void *p, const void *q) {
    // negtive: p->val < q->val, etc
    // same as strcmp()
    // cast (struct S *) to p
    return (((struct S *)p)->val - ((struct S *)q)->val);
}
int main() {
    struct S some[100];
    // input "some", sort first 50 elements
    qsort(some, 50, sizeof(struct S), cmp);
    return 0;
}