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