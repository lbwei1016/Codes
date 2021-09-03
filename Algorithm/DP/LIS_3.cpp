/*
***DP***
    O(n)
*/
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> lis;
int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int t;
        scanf("%d", &t);
        auto it = lower_bound(lis.begin(), lis.end(), t);
        if(it == lis.end()) lis.push_back(t);
        else *it = t;
    }
    printf("%d\n", (int)lis.size());
    return 0;
}
/* multiset version -- slower for maintaining unecessary sorted order
int n;
scanf("%d", &n);
multiset<int> ms;
while(n--) {
    int t;
    scanf("%d", &t);
    auto it = ms.lower_bound(t);
    if(it != ms.end()) ms.erase(it);
    ms.emplace(t);
}
*/