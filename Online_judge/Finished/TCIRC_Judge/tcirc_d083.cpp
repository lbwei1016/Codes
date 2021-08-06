/*
***DP*** -- weighted LIS
    Solution:
        先依照 c 由大到小排序 (m 也可以)，然後依照此順序在動態的資料結構中使
        當前 m 在不小於先前的 m 的情況下 (因為 c 已經比先前任一元素小)，增加權重。
        假如 m 大而權重小，發展潛力小，要將其移除，因此該動態的資料結構具有單調性
        (m 越大 P 越大)
    O(n * log n)
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
struct Mem { int p, c, m; } seq[N];
int n;

bool cmp(Mem m1, Mem m2) {
    return (m1.c == m2.c ? m1.m < m2.m : m1.c > m2.c);
}
int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &seq[i].p);
    }
    for(int i=0; i<n; i++) {
        scanf("%d", &seq[i].c);
    }
    for(int i=0; i<n; i++) {
        scanf("%d", &seq[i].m);
    }
    sort(seq, seq+n, cmp);

    map<int, int> M; //(m, P), increasing 
    M.insert({-1, 0}); //boundary
    //從遞減的 c 當中，使 m 在不違反限制的情況下最大化權重
    for(int i=0; i<n; i++) {
        auto it = M.upper_bound(seq[i].m);
        it--; //seq[i] 可以接上的地方 (it->first < seq[i].m)
        int w = it->second + seq[i].p;
        it = M.insert(it, {seq[i].m, w}); //插入失敗而且當前權重較高
        if(it->second < w) {
            it->second = w;
        }
        it++;
        //維持遞增的單調性
        while(it!=M.end() && it->second<=w) {
            it = M.erase(it);
        }
    }
    auto it = M.end(); it--;
    printf("%d\n", it->second);
    return 0;
}