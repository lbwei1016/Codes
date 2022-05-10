/*
This can also be solved with "hashing".
See ./Algorithm/Hash/mt19937_hash.cpp
*/
#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

int main() {
    // io;
    int n, q;
    cin >> n;
    set<int> S;
    vector<int> szA(n+1), szB(n+1);
    vector<int> A, B;
    for (int i=1; i<=n; ++i) {   
        int x; cin >> x;
        S.insert(x);
        szA[i] = S.size();
        A.push_back(x);
    }
    S.clear();
    for (int i=1; i<=n; ++i) {
        int x; cin >> x;
        S.insert(x);
        szB[i] = S.size();
        B.push_back(x);
    }

    set<int> visA, visB;
    S.clear();
    int mk = min(szA.back(), szB.back());
    auto ita = A.begin();
    auto itb = B.begin();
    vector<bool> res(mk+1);
    // "k" is the size of possible sets
    for (int k=1; k<=mk; ++k) {
        while (ita != A.end() && visA.count(*ita)) ++ita;
        visA.insert(*ita);
        if (S.count(*ita)) S.erase(*ita);
        else S.insert(*ita);

        while (itb != B.end() && visB.count(*itb)) ++itb;
        visB.insert(*itb);
        if (S.count(*itb)) S.erase(*itb);
        else S.insert(*itb);

        // set with size "k" of A and B are identical
        res[k] = !(S.size());
    }

    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        if (szA[x] != szB[y]) puts("No");
        else {
            printf("%s\n", res[szA[x]] ? "Yes" : "No");
        }
    }

    return 0;
}