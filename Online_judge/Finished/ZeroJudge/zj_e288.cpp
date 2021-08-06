/*
***Bitmask*** 
    
    Solution:
        There are 38 conditions to operate, so use "long long" instead of "int".
        Then, use "Difference(-)" to access the counterpart of our target；actually
        "XOR(~)" is okay as well.
    
    O(N * log N)
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
map<ll, int> rec;
int m, n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n;
    ll X = 0;
    for(int i=0; i<m; i++) {
        X |= (1LL << i);
    }
    ll res = 0;
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        ll p = 0;
        for(int j=0; j<s.size(); j++) {
            if(s[j] < 'a') {
                //"1LL" is mandatory for long long
                p |= (1LL << (s[j]-'A'));
            }
            else {
                p |= (1LL << ((s[j]-'a')+26));
            }
        }
        if(rec.find(p) == rec.end()) rec[p] = 0;
        rec[p]++; 
        res += rec[X-p];
        //reduce memory usage
        if(rec[X-p] == 0) rec.erase(X-p);
    }
    cout << res << '\n';
    return 0;
}