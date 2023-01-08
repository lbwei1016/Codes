/*
***DP***
    O(nlogn)
*/
#include <bits/stdc++.h>
using namespace std;

struct P { 
    int val, at; 
    bool operator<(const P &p) const {
        return val < p.val;
    }
};
int n;
vector<P> lis;
vector<int> seq, pre; // 指向前一數

int main() {
    cin >> n;
    pre.resize(n, -1);
    seq.resize(n);
    for(int i=0; i<n; i++) {
        cin >> seq[i];
        P p = P{seq[i], i};
        auto it = lower_bound(lis.begin(), lis.end(), p);
        if(it == lis.end()) {
            if (lis.size()) pre[p.at] = lis.back().at;
            lis.push_back(p);
        }
        else {
            if (it != lis.begin()) pre[p.at] = next(it, -1)->at;
            *it = p;
        }
    }

    cout << "LIS length: " << lis.size() << '\n';
    vector<int> res;
    for (int k=lis.back().at; k!=-1; k=pre[k]) {
        res.push_back(seq[k]);
    }
    reverse(res.begin(), res.end());
    cout << "LIS: ";
    for (auto x: res) cout << x << ' ';
    cout << '\n';
    return 0;
}
/*
8
-7 10 9 2 3 8 8 1
*/