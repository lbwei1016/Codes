/*
***Sweep Line***
    Solution:
        自右而左，因從右方來，所以 x 座標已知遞減，再來就只需要檢查
        y 座標是否大於目前最大值(不被控制)

    O(N * log N)
*/
#include <bits/stdc++.h>
using namespace std;

struct P {int x, y; } ;
bool cmp(P &p1, P &p2) {
    return p1.x > p2.x;
}
int main() {
    int n;
    scanf("%d" ,&n);
    vector<P> p(n);
    for(int i=0; i<n; i++) {
        scanf("%d", &p[i].x);
    }
    for(int i=0; i<n; i++) {
        scanf("%d", &p[i].y);
    }
    //x 遞減
    sort(p.begin(), p.end(), cmp);
    int res = 0, max_y = -1;
    for(auto i : p) {
        int y = i.y;
        if(y > max_y) {
            res++;
            max_y = y;
        }
    }
    printf("%d\n", res);
    return 0;
}