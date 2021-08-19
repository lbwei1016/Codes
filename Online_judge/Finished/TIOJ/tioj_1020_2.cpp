/*
***Linked List*** -- std::forward_list
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
forward_list<int> L(1, 0), best(31, -1);
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
    for(auto it=L.begin();; ++it) {
        auto nt = next(it);
        if(nt == L.end()) break;
        if(d % (*it+*nt) == 0) {
            L.insert_after(it, d);
            dfs(d+1);
            L.erase_after(it);
        }
    }
}
int main() {
    scanf("%d", &n);
    L.insert_after(L.begin(), 1);
    dfs(2);
    printf("%lld\n", cnt);
    for(auto x : best) printf("%d ", x);
    puts("");
    return 0;
}