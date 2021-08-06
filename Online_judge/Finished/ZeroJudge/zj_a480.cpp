/*
***窮舉(method of exhaustion)***
*/
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 1e6+5;

//到第一、第二系統的距離(平方)
struct point {
    int d1, d2;
}ps[MAX_N];

int x1, x2, y1, y2, n;
//以到第一系統的距離為主，逐步擴大窮舉，因此將其對 d1 進行升冪排列
bool comp(const point &p1, const point &p2) {
    return p1.d1 < p2.d1;
}

int main() {
    
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        ps[i].d1 = (x-x1)*(x-x1) + (y-y1)*(y-y1);
        ps[i].d2 = (x-x2)*(x-x2) + (y-y2)*(y-y2);
    }
    
    sort(ps, ps+n, comp);

    //找出其它城市到第二個系統的最遠距離
    for(int j=n-2; j>=0; j--) 
        ps[j].d2 = max(ps[j].d2, ps[j+1].d2);

    ps[n].d2 = 0;
    int ans = 0x7fffffff;
    for(int i=0; i<n; i++) {
        //總能量花費: 第一個系統涵蓋的範圍 + (第一系統沒有涵蓋的)其它城市到第二個系統的最遠距離
        //i 代表第 i 個點
        ans = min(ans, ps[i].d1+ps[i+1].d2);
    }
    //ps[0].d2: 由(x2, y2)涵蓋所有點；ps[n-1].d1: 由(x1, y1)涵蓋所有點
    printf("%d\n", min(ans, ps[0].d2));

    return 0;
}