/*
***Binary Search / Greedy***
    Solution:
        找最小可能解 (二分性質)
*/
#include <bits/stdc++.h>
using namespace std;

const int MAX_A = 50005, MAX_T = 1e6+5;
struct P { int w, s; };
int A, B, T;
// tw[]: how many times can "W" robot be used
int W[MAX_A], S[MAX_A], tw[MAX_A], ts[MAX_A];
P toy[MAX_T];

inline bool cmp(P &p1, P &p2) {
    return p1.w < p2.w;
}
bool check(int time) {
    fill(tw, tw+A, time);
    fill(ts, ts+B, time);
    priority_queue<int> pq; // decreasing

    int pos = 0; // pos of toy
    for(int i=0; i<A; ++i) {
        while(pos < T && toy[pos].w < W[i]) // can be taken care of by "W"
            pq.push(toy[pos++].s);
        while(!pq.empty() && --tw[i] >= 0) 
            pq.pop(); // pop from ones with large "toy[].s"
    }
    while(pos < T) pq.push(toy[pos++].s); 
    if(!pq.empty() && pq.top() >= S[B-1]) return false; // no "S" can do the job
    for(int i=B-1; i>=0; --i) {
        while(!pq.empty() && pq.top()<S[i] && --ts[i]>=0) 
            pq.pop();
    }
    return pq.empty(); 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> A >> B >> T;
    for(int i=0; i<A; ++i) cin >> W[i];
    for(int i=0; i<B; ++i) cin >> S[i];
    for(int i=0; i<T; ++i) cin >> toy[i].w >> toy[i].s;
    sort(W, W+A);
    sort(S, S+B);
    sort(toy, toy+T, cmp); // increasing by "w"

    int lb = 0, ub = T+1, ans = -1;
    while(ub - lb > 1) {
        int mid = (lb+ub) >> 1;
        if(check(mid)) {
            ans = mid;
            ub = mid;
        }
        else lb = mid;
    }
    cout << ans << '\n';
    return 0;
}
/* Another Solution, 以幾毫秒之差 TLE  
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;

struct P { int w, s; };
int A, B, T;
long long W;
vector<P> toys;
multimap<int, int> S;

inline bool cmp(P &p1, P &p2) {
    return p1.w == p2.w ? p1.s>p2.s : p1.w>p2.w;
}
inline bool putaway(int time) {
    W = 0;
    multimap<int, int> tmp(S);
    for(auto &x : tmp) x.second = time; //有 time 秒代表同一之機器人最多可以用 time 次
    P x;
    // x 可能是 機器人 或是 物品
    for(auto x : toys) {
        //若是機器人，留著備用
        if(x.s < 0) W += time;
        else {
            auto it = tmp.upper_bound(x.s);
            if(it != tmp.end()) {
               if(--(it->second) == 0) tmp.erase(it);
            }
            else if(--W < 0) return false; //沒有機器人可搬
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> A >> B >> T;
    toys.resize(A+T);
    for(int i=0; i<A; ++i) {
        int t;
        cin >> t;
        toys[i] = {t, -1}; //把弱雞型(W)和要搬的物品放在一起
    }    
    for(int i=0; i<B; ++i) {
        int t; 
        cin >> t;
        S.emplace(t, 1);
    }
    for(int i=0; i<T; ++i) {
        cin >> toys[i+A].w >> toys[i+A].s;
    }

    sort(toys.begin(), toys.end(), cmp); //依重量排序 (大到小)
    int lb = 0, ub = T+1, ans = -1;
    //找最小可能解 (二分性質)
    while(ub - lb > 1) {
        int mid = (lb+ub) >> 1;
        if(putaway(mid)) {
            ans = mid;
            ub = mid;
        }
        else lb = mid;
    }
    cout << ans << '\n';
    return 0;
}
*/