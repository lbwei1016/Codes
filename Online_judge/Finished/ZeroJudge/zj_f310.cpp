/*
***Union and Find*** 
    Solution:
        To make two people friends, unite(x, y)；
        to make them enemies, unite(x, y+n), unite(y, x+n), since "enemy's enemy is friend"
        Note: x, y are the roots
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, c, x, y;
int p[2*N]; // 0~n-1: friend id；n~2n-1: enemy id

int find(int x) {
    return p[x] < 0 ? x : p[x]=find(p[x]);
}
void unite(int x, int y) {
    int r1 = find(x);
    int r2 = find(y);
    if(r1 == r2) return;
    if(p[r1] < p[r2]) {
        p[r1] += p[r2];
        p[r2] = r1;
    }
    else {
        p[r2] += p[r1];
        p[r1] = r2;    
    }
}
bool are_friend(int x, int y) {
    return find(x) == find(y);
}
bool are_enemy(int x, int y) {
    return find(x) == find(y+n) || find(y) == find(x+n);
}
bool set_friend(int x, int y) {
    int ex = find(x+n), ey = find(y+n);
    int fx = find(x), fy = find(y);
    if(ex == fy || ey == fx) return false; // are enemies

    unite(fx, fy); // make friends
    unite(ex, ey); // enemy's enemy is friend
    return true;
}
bool set_enemy(int x, int y) {
    int ex = find(x+n), ey = find(y+n);
    int fx = find(x), fy = find(y);
    if(fx == fy) return false; // are friends

    unite(fx, ey); // enemy's enemy is friend 
    unite(fy, ex); // enemy's enemy is friend
    return true;
}

int main() {
    scanf("%d", &n);
    memset(p, -1, sizeof(p));

    while(scanf("%d%d%d", &c, &x, &y)) {
        if(c == 0) break;
        if(c == 1) {
            if(!set_friend(x, y)) 
                puts("-1");
        }
        else if(c == 2) {
            if(!set_enemy(x, y)) 
                puts("-1");
        }
        else if(c == 3) {
            are_friend(x, y) ? puts("1") : puts("0");
        }
        else {
            are_enemy(x, y) ? puts("1") : puts("0");
        }
    }
    return 0;
}