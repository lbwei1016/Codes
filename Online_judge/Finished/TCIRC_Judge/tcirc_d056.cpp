/*
***Sweep Line***

    O(N * log N)
*/
#include <bits/stdc++.h>
using namespace std;

struct P { int x, y; };
int n;
multimap<int, int> pre; //(y, x)；左方的點
vector<P> ps; //點集合

bool cmp(P p1, P p2) {
    return p1.x < p2.x;
}
int main() {
    scanf("%d", &n);
    ps.resize(n);
    for(int i=0; i<n; i++) {
        scanf("%d%d", &ps[i].x, &ps[i].y);
    }
    sort(ps.begin(), ps.end(), cmp);
    int min_d = 1e9; 
    //由左而右掃描
    for(int i=0; i<n; i++) {
        int x = ps[i].x, y = ps[i].y;
        //最短距離內的最小 y 座標
        auto it = pre.lower_bound(y - min_d);
        //最短距離內的最大 y 座標 (while 最多執行 8 次)
        while(it!=pre.end() && it->first <= y+min_d) {
            //x 座標超出最小距離，不會再用到
            if(it->second < x - min_d) {
                it = pre.erase(it);
                continue;
            }
            min_d = min(min_d, abs(x-it->second) + abs(y-it->first));
            it++;
        }
        pre.insert({y, x});
    }
    printf("%d\n", min_d);
    return 0;
}