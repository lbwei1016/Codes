/*
***DP*** -- bit
*/
#include <bits/stdc++.h>
using namespace std;

const double INF = 1e10;

struct P { double x, y; };
double dp[1<<17];

inline double squ(double a) { return a*a; };
inline double dist(int j, int k, vector<P> &coor) {
    return sqrt(squ(coor[j].x-coor[k].x) + squ(coor[j].y-coor[k].y));
}

int main() {
    int n, stu;

    for(int cnt=1; cin >> n; ++cnt) {
        if(n == 0) break;
        stu = 2 * n;
        vector<P> coor(stu);
        for(int i=0; i<stu; ++i) {
            string tmp;
            cin >> tmp >> coor[i].x >> coor[i].y;
        }

        // double mn = INF;
        for(int i=0; i<(1<<stu); ++i) dp[i] = INF;
        dp[0] = 0;
        for(int i=0; i<(1<<stu); ++i) {
            /*
                to ensure two people are picked at the same time
            */
            int bit1 = 0, tmp = i;
            while(tmp > 0) {
                if(tmp & 1) ++bit1;
                tmp >>= 1;
            }
            if(bit1 & 1) continue;

            for(int j=0; j<stu; ++j) {
                for(int k=j+1; k<stu; ++k) {
                    if((i>>j)&1 || (i>>k)&1) continue;  
                    int chosen = i | (1<<j) | (1<<k);
                    dp[chosen] = min(dp[chosen], dp[i]+dist(j, k, coor));
                }
            }
        }
        printf("Case %d: %.2lf\n", cnt, dp[(1<<stu)-1]);
    }
    return 0;
}