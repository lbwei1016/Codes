/*
***Union and Find*** 
*/
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 50005;
int n, k, d, x, y, cnt;
int p[3*N]; // a, b, c

inline int get_a(int x) { return x; };
inline int get_b(int x) { return x+n; };
inline int get_c(int x) { return x+2*n; };
int find(int x) {
    return p[x] < 0 ? x : p[x]=find(p[x]);
}
void unite(int x, int y) {
    int rx = find(x), ry = find(y);
    if(rx == ry) return;
    if(p[rx] < p[ry]) {
        p[rx] += p[ry];
        p[ry] = rx;
    }
    else {
        p[ry] += p[rx];
        p[rx] = ry;
    }
}
bool set_same(int x, int y) {
    int xa = find(get_a(x)), xb = find(get_b(x)), xc = find(get_c(x));
    int ya = find(get_a(y)), yb = find(get_b(y)), yc = find(get_c(y));
    // 當 x 吃 y 或 y 吃 x，不合 (只需檢驗 a, b, c 其中一種，因為他們是連帶成立的)
    if(xa == yb || xa == yc) return false;

    unite(xa, ya);
    unite(xb, yb);
    unite(xc, yc);
    return true;
}
bool set_eat(int x, int y) {
    if(x == y) return false;
    int xa = find(get_a(x)), xb = find(get_b(x)), xc = find(get_c(x));
    int ya = find(get_a(y)), yb = find(get_b(y)), yc = find(get_c(y));
    // 當 x, y 是同類或 y 吃 x，不合 (只需檢驗 a, b, c 其中一種，因為他們是連帶成立的)
    if(xa == ya || xa == yc) return false;

    unite(xa, yb);
    unite(xb, yc);
    unite(xc, ya);
    return true;
}

int main() {
    scanf("%d%d", &n, &k);
    memset(p, -1, sizeof(p));
    while(k--) {
        scanf("%d%d%d", &d, &x, &y);
        if(x > n || x < 1 || y > n || y < 1) {
            ++cnt; continue;
        }
        if(d == 1) {
            if(!set_same(x, y)) ++cnt;
        }
        else if(!set_eat(x, y)) ++cnt;
    }
    printf("%d\n", cnt);
    return 0;
}