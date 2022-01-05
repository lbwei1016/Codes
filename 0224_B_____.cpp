#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 3e5+5;
struct ROPE {
    // int le, ri, h, len;
    int len, to;
    // bool climbed[MAX_N]; // for monkey i
};
struct POS {
    // int x, y, p1, p2;
    int p1, p2;
};
struct MON {
    int t_up, t_rope;
};
int N, H, R, B;
// vector<ROPE> rope; 
map<pair<int, int>, ROPE> rope; // pair: x, y
// vector<spe_pos> pos;
map<pair<int, int>, POS> pos;
vector<MON> mon;

// inline bool cmp_rope(const ROPE &r1, const ROPE &r2) {
//     return r1.h < r2.h;
// }
void climb_up() {

}
void climb_rope();
int solve() {
    int cnt = 0;
    // sort(rope.begin(), rope.end(), cmp_rope);
    for(int i=1; i<=N; ++i) {
        int x = i, y = 0;
        double timer = 0;
        bool c_roped = false;
        while(y <= H) {
            auto at = pos.find(make_pair(x, y));
            if(at != pos.end()) {
                int lb = (timer-0.5) / (at->second.p1 + at->second.p2);
                int ub = (timer-0.5-at->second.p1) / (at->second.p1 + at->second.p2);
                if(lb > ub) ++cnt;
            }
            
            auto it = rope.find(make_pair(x, y));
            if(it!=rope.end() && /*!(it->second.climbed[i])*/!c_roped) {
                // it->second.climbed[i] = true;
                // climb_rope();
                c_roped = true;
                timer += it->second.len * mon[i].t_rope;
                x = it->second.to;
            }
            else {
                // climb_up();
                timer += mon[i].t_up;
                ++y;
                c_roped = false;
            }
        }
    }
    return cnt;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> H >> R >> B;
    // rope.reserve(R+5);
    // pos.reserve(B+5);
    mon.resize(N+5);
    for(int i=0; i<R; ++i) {
        int len, le, ri, h;
        cin >> len >> le >> ri >> h;
        // rope.push_back(ROPE{le, ri, h, len});
        rope[make_pair(le, h)] = ROPE{.len = len, .to=ri};
        rope[make_pair(ri, h)] = ROPE{.len = len, .to=le};
    }
    for(int i=1; i<=N; ++i) {
        int c, d;
        cin >> c >> d;
        mon[i] = (MON{c, d});
    }
    for(int i=0; i<B; ++i) {
        int x, y, p1, p2;
        cin >> x >> y >> p1 >> p2;
        // pos.push_back(spe_pos{x, y, p1, p2});
        pos[make_pair(x, y)] = POS{p1, p2};
    }
    cout << solve() << '\n';
    return 0;
}