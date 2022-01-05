/*
***Recursion***
    Solution:
        依條件窮舉。
*/
#include <bits/stdc++.h>
using namespace std;

int T, n, m, cnt;
vector<string> Cs, best;
map<string, set<string> > hid;
set<int> chosen;

void count(int d, string pre) {
    if(d == n) {
        ++cnt;
        return;
    }
    for(int i=0; i<n; ++i) {
        if(chosen.count(i)) continue;
        auto it = hid.find(Cs[i]);
        if(it!=hid.end() && it->second.count(pre)) continue;
        chosen.insert(i);
        if(cnt == 0) {
            best.push_back(Cs[i]);
        }
        count(d+1, Cs[i]);
        chosen.erase(i);
        if(cnt == 0) {
            best.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    Cs.reserve(15);
    while(T--) {
        cnt = 0;
        Cs.clear();
        hid.clear();
        chosen.clear();
        best.clear();

        cin >> n;
        for(int i=0; i<n; ++i) {
            string tmp;
            cin >> tmp;
            Cs.push_back(tmp);
        }
        cin >> m;
        for(int i=0; i<m; ++i) {
            string t1, t2;
            cin >> t1 >> t2;
            hid[t1].insert(t2);
            hid[t2].insert(t1);
        }
        count(0, "$");
        cout << cnt << '\n';
        for(auto x : best) cout << x+' ';
        cout << '\n';
    }
    return 0;
}