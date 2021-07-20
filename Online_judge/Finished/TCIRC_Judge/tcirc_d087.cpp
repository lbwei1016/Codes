/*
***DP*** -- LIS
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    multiset<int> ms;
    while(n--) {
        int s, t;
        scanf("%d%d", &s, &t);
        auto it = ms.upper_bound(t);
        if(it != ms.end()) ms.erase(it);
        ms.insert(s);
    }
    printf("%d\n", ms.size());
    return 0;
}