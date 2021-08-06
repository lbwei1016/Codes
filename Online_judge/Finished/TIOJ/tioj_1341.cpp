/*
***Binary Search*** (*) -- interactive
    Note: long long is good!!
*/
#include <bits/stdc++.h>
//#include "1341_aliens.h"
//#include "lib1341.h"
using namespace std;

typedef long long ll;
// l: distance to the left border of current red square；r, u: right, up
ll N, X, Y, M, l, r, u;
// lu: left-up diagonal；ld, ru, rd: left-down, right-up, right-down
ll lu, ld, ru, rd;

ll search_m() {
    ll lb = -1, ub = 1;
    while(X+ub<=N && Examine(X+ub, Y)) {
        ub <<= 1;
    }
    while(ub - lb > 1) {
        ll mid = (lb + ub) >> 1;
        if(X+mid<=N && Examine(X+mid, Y)) 
            lb = mid;
        else ub = mid;
    }
    r = lb, lb = -1, ub = 1;

    while(X-ub>=1 && Examine(X-ub, Y)) {
        ub <<= 1;
    }
    while(ub - lb > 1) {
        ll mid = (lb + ub) >> 1;
        if(X-mid>=1 && Examine(X-mid, Y)) 
            lb = mid;
        else ub = mid;
    }
    l = lb, lb = -1, ub = 1;

    while(Y+ub <= N && Examine(X, Y+ub)) {
        ub <<= 1;
    }
    while(ub - lb > 1) {
        ll mid = (lb + ub) >> 1;
        if(Y+mid<=N && Examine(X, Y+mid)) 
            lb = mid;
        else ub = mid;
    }
    u = lb, lb = -1, ub = 1;
    return l+r+1;
}
void search_diagonal() {
    ll x = X, y = Y;
    while(x+M<=N && y+M<=N && Examine(x+M, y+M)) {
        x += M, y += M;
        ru++;
    }
    x = X, y = Y;
    while(x+M<=N && y-M>=1 && Examine(x+M, y-M)) {
        x += M, y -= M;
        rd++;
    }
    x = X, y = Y;
    while(x-M>=1 && y+M<=N && Examine(x-M, y+M)) {
        x -= M, y += M;
        lu++;
    }
    x = X, y = Y;
    while(x-M>=1 && y-M>=1 && Examine(x-M, y-M)) {
        x -= M, y -= M;
        ld++;
    }
}
int main() {
    Init((int*)&N, (int*)&X, (int*)&Y);
    M = search_m();
    search_diagonal();
    // printf("%d %d %d %d\n", M, l, r, u); 
    // printf("%d %d %d %d\n", lu, ld, ru, rd);

    X = X + r - M/2, Y = Y + u - M/2;
    //printf("X: %d Y: %d\n", X, Y);

    //從對角線情形來判斷自身所處位置
    if(lu == rd && ru == ld) Solution((int)X, (int)Y);
    else if(lu == rd && ru > ld) {
        X += ru/2 * M;
        Y += ru/2 * M;
    } else if(lu == rd && ru < ld) {
        X -= ld/2 * M;
        Y -= ld/2 * M;
    } else if(ru == ld && lu > rd) {
        X -= lu/2 * M;
        Y += lu/2 * M;
    } else if(ru == ld && lu < rd) {
        X += rd/2 * M;
        Y -= rd/2 * M;
    } 
    else if(ru == rd && ru > 0) X += 2*M;
    else if(ld == rd && ld > 0) Y -= 2*M;
    else if(lu == ld && lu > 0) X -= 2*M;
    else if(lu == ru && lu > 0) Y += 2*M;
    Solution((int)X, (int)Y);
    return 0;
}