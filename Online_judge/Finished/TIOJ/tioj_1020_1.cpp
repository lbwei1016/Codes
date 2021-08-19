/*
***Linked List*** -- std::list
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
list<int> L, best(31, -1);
int n;
ll cnt;

void dfs(int d) {
    if(d == n+1) {
        ++cnt;
        auto it1 = L.begin(), it2 = best.begin();
        for(; it1!=L.end() && it2!=best.end(); ++it1, ++it2) {
            if(*it1 > *it2) {
                best = L; return;
            }
            else if(*it1 < *it2) return;
        }
    }
    auto ed = L.end(); --ed;
    for(auto it=L.begin(); it!=ed; ++it) {
        auto nt = next(it, 1);
        if(d % (*it+*nt) == 0) {
            L.insert(nt, d);
            dfs(d+1);
            L.erase(next(it, 1));
        }
    }
}
int main() {
    scanf("%d", &n);
    auto it = L.begin();
    L.insert(it, 0); L.insert(it, 1);
    dfs(2);
    printf("%lld\n", cnt);
    for(auto x : best) printf("%d ", x);
    puts("");
    return 0;
}